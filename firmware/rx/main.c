/***********************************************************************
* FILENAME: main.c
* AUTHOR: s7a73farm, gr3yR0n1n
* DATE: 07.07.2018
*
* Copyright s7a73farm 2018.  All rights reserved.
***********************************************************************/


#include <avr/io.h>
#include <stdint.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "../debounce.h"
#include "../nrf24.h"
#include "../led_pattern.h"


// Master Sequences
#define unset           0x00
#define s7a73farm       0x10
#define wife            0x11
#define compukidmike    0x42
#define gr3yR0n1n       0x23


// Max number of patterns
#define LED_PHASE_MAX 4


// Globals
uint8_t led_phase = 0;
uint8_t party_mode = 0x00;
uint8_t party_count = 0x00;
uint8_t data_array[1];
uint8_t tx_address[5] = {0xA2,0xA2,0xA2,0xA2,0xA2};
uint8_t rx_address[5] = {0xD7,0xD7,0xD7,0xD7,0xD7};


// Called at about 100Hz (122Hz)
ISR(TIM0_OVF_vect) {
    // Debounce buttons. debounce() is declared static inline
    // in debounce.h so we will not suffer from the added overhead
    // of a (external) function call
    debounce(); 
    party_count++;
}


// System Init
void SystemInit(void) {
    SREG |= (1 << 7);    // set I bit in SREG

    // Timer0 normal mode, presc 1:256
    TCCR0B = 1<<CS02;
    // Overflow interrupt. (at 8e6/256/256 = 122 Hz)
    TIMSK0 = 1<<TOIE0;

    debounce_init();

    // Enable global interrupts
    sei();

    // Initialize LED
    led_init();
}


// Main
int main() {
    // ini interrupts	
    SystemInit();

    /* init hardware pins */
    nrf24_init();
    
    /* Channel #4 , payload length: 1 */
    nrf24_config(4,1);
 
    /* Set the device addresses */
    nrf24_tx_address(tx_address);
    nrf24_rx_address(rx_address);

    while(1) {
        if (party_count > 10) {
            party_count = 0;
            party_mode = 0x00;
        }

        if (party_mode == 0x00) {
            if(nrf24_dataReady()) {
                nrf24_getData(data_array);
                party_mode = data_array[0];
                
            	if (party_mode == s7a73farm) {		// s7a73farm
                    lets_party();
            	}
            	else if (party_mode == wife) {		// wife  
                    mrs_s7a73farm();
            	}
            	else if (party_mode == compukidmike) {	// compukidmike  
                    mk();
            	}
            	else if (party_mode == gr3yR0n1n) {	// gr3yR0n1n
		    ashen_colored_wanderer();
	    	}
            } 
            else {
                if (button_down(BUTTON1_MASK)) {
                    g_index = 0;
                    g_up = 1;
                    led_phase++;
                    no_party();
                    if (led_phase > LED_PHASE_MAX) { led_phase = 0;}
                }
			
                if (led_phase == 0) {
		    //ashen_colored_wanderer();
                    phantom();
                }
                else if (led_phase == 1) {
                    computations();
                }
                else if (led_phase == 2) {
                    knight_rider();
                }
                else if (led_phase == 3) {
                    lady_bug();
                }
                else if (led_phase == 4) {
                    rainbow_fade();
                }
            }
        } 
        else {
            if (party_mode == s7a73farm) {		// s7a73farm
                lets_party();
            }
            else if (party_mode == wife) {		// wife  
                mrs_s7a73farm();
            }
            else if (party_mode == compukidmike) {	// compukidmike  
                mk();
            }
            else if (party_mode == gr3yR0n1n) {		// gr3yR0n1n
		ashen_colored_wanderer();
	    }
        }
    }
}

