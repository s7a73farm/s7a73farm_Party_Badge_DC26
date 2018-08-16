/***********************************************************************
* FILENAME: radioPinFunctions.c
* AUTHOR: s7a73farm, gr3yR0n1n
* DATE: 07.07.2018
*
* Copyright s7a73farm 2018.  All rights reserved.
***********************************************************************/

#include <avr/io.h>

#define set_bit(reg,bit) reg |= (1<<bit)
#define clr_bit(reg,bit) reg &= ~(1<<bit)
#define check_bit(reg,bit) (reg&(1<<bit))

/* ------------------------------------------------------------------------- */
void nrf24_setupPins() {
	/*
    set_bit(DDRA,0); // CE output
    set_bit(DDRA,1); // CSN output
    set_bit(DDRA,2); // SCK output
    set_bit(DDRA,3); // MOSI output
    clr_bit(DDRA,4); // MISO input
	*/
	set_bit(DDRA,2); // CE output
	set_bit(DDRA,7); // CSN output
	set_bit(DDRA,4); // SCK output
	set_bit(DDRA,6); // MOSI output
	clr_bit(DDRA,5); // MISO input
}
/* ------------------------------------------------------------------------- */
void nrf24_ce_digitalWrite(uint8_t state) {
    if(state) {
        set_bit(PORTA,2);
    }
    else {
        clr_bit(PORTA,2);
    }
}
/* ------------------------------------------------------------------------- */
void nrf24_csn_digitalWrite(uint8_t state) {
    if(state) {
        set_bit(PORTA,7);
    }
    else {
        clr_bit(PORTA,7);
    }
}
/* ------------------------------------------------------------------------- */
void nrf24_sck_digitalWrite(uint8_t state) {
    if(state) {
        set_bit(PORTA,4);
    }
    else {
        clr_bit(PORTA,4);
    }
}
/* ------------------------------------------------------------------------- */
void nrf24_mosi_digitalWrite(uint8_t state) {
    if(state) {
        set_bit(PORTA,6);
    }
    else {
        clr_bit(PORTA,6);
    }
}
/* ------------------------------------------------------------------------- */
uint8_t nrf24_miso_digitalRead() {
    return check_bit(PINA,5);
}
/* ------------------------------------------------------------------------- */
