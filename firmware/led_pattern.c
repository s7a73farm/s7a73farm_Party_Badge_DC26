/***********************************************************************
* FILENAME: led_pattern.c
* AUTHOR: s7a73farm, gr3yR0n1n
* DATE: 07.07.2018
*
* Copyright s7a73farm 2018.  All rights reserved.
***********************************************************************/


#include <stdlib.h>
#include <util/delay.h>
#include "led_pattern.h"
#include "color.h"
#include "badge_leds.h"
#include "morse_code.h"


// Master Sequences
#define s7a73farm       0x00
#define wife            0x01
#define compukidmike    0x42
#define gr3yR0n1n       0x23


#define MAXPIX 120
#define COLORLENGTH (MAXPIX/2)
#define FADE (256/COLORLENGTH)


int g_index = 0;
int g_up = 1;

uint8_t j = 1;
uint8_t k = 1;


// led init
void led_init() {
    j = 1;
    k = 1;

    // init colors
    colors[0].r=64; colors[0].g=0; colors[0].b=64;
    colors[1].r=64; colors[1].g=0; colors[1].b=0;//red
    colors[2].r=64; colors[2].g=25; colors[2].b=0;//orange
    colors[3].r=25; colors[3].g=64; colors[3].b=0;//yellow
    colors[4].r=0; colors[4].g=64; colors[4].b=0;//green
    colors[5].r=0; colors[5].g=25; colors[5].b=64;//light blue (türkis)
    colors[6].r=0; colors[6].g=0; colors[6].b=64;//blue
    colors[7].r=25; colors[7].g=0; colors[7].b=64;//violet
}


// Random value within range 
int random_value(int min, int max) {
   return (int)(min + rand() / (RAND_MAX / (max - min + 1) + 1));
}


// fade
void fade() {
    int i=0; int j=0;
    int r=0; int g=0; int b=0;

    for (j=0; j<=512; j++) {
        for (i=0; i<NUM_LEDS; i++) {
            led[i].r=r;
            led[i].g=g;
            led[i].b=b;
        }
        ws2812_setleds(led,NUM_LEDS);
        _delay_ms(50);
        if (j>255) { r--; }
        else { r++; }
    }
}


// computations
void computations() {
    int j;
    for (j=0; j<NUM_LEDS; j++) {
        led[j].r=0;led[j].g=0;led[j].b=0;    // Write red to array
    }
    ws2812_setleds(led,NUM_LEDS);
    _delay_ms(100);
    
    g_index = random_value(0, 2);
    led[LED_TOP[g_index]].r=64;
    led[LED_TOP[g_index]].g=0;
    led[LED_TOP[g_index]].b=0;
    
    g_index = random_value(0, 2);
    led[LED_BOTTOM[g_index]].r=0;
    led[LED_BOTTOM[g_index]].g=64;
    led[LED_BOTTOM[g_index]].b=0;
    
    g_index = random_value(0, 2);
    led[LED_LEFT[g_index]].r=0;
    led[LED_LEFT[g_index]].g=0;
    led[LED_LEFT[g_index]].b=64;
    
    g_index = random_value(0, 2);
    led[LED_RIGHT[g_index]].r=64;
    led[LED_RIGHT[g_index]].g=0;
    led[LED_RIGHT[g_index]].b=64;
    
    g_index = random_value(0, 2);
    led[LED_CENTER[g_index]].r=64;
    led[LED_CENTER[g_index]].g=64;
    led[LED_CENTER[g_index]].b=64;
    
    ws2812_setleds(led,NUM_LEDS);
    
    _delay_ms(100);
}


// Knight Rider (Purple Center Line, Back and Forth)
void knight_rider() {
    int j;
    for (j=0; j<NUM_LEDS; j++) {
	led[j].r=0;led[j].g=0;led[j].b=0;    // Write red to array
	ws2812_setleds(led,NUM_LEDS);
    }
    _delay_ms(30);

    led[LED_CENTERLINE[g_index]].r=255;
    led[LED_CENTERLINE[g_index]].g=0;
    led[LED_CENTERLINE[g_index]].b=0;

    ws2812_setleds(led,NUM_LEDS);
    _delay_ms(30);

    if (g_up == 1) {
        if (g_index<5) {
            g_index++;
        }
        else {
            g_up = 0;
            g_index--;
        }
    }
    else {
        if (g_index<=1) {
            g_index = 0;
            g_up = 1;
        }
        else {
            g_index--;
        }
    }
}

// Lady Bug (Red Random)
void lady_bug() {
    int x=0; int i=0;
    for (x=0; x<2; x++) {
        for (i=0; i<15; i++) {
            led[i].r=random_value(128,255);;
            led[i].g=0;
            led[i].b=random_value(128,255);;
            if (i>0) {
                led[i-1].r=0;
                led[i-1].g=0;
                led[i-1].b=0;
            }
            ws2812_setleds(led,NUM_LEDS);
            _delay_ms(50);
            led[14].r=0;led[14].g=0;led[14].b=0;
        }
    }
}


// no party
void no_party() {
	int i = 0;
	for (i=0; i<NUM_LEDS; i++) {
		led[i].r=0;led[i].g=0;led[i].b=0;    // Write red to array
	}
    ws2812_setleds(led,NUM_LEDS);
}


// lets party 2
void lets_party2() {
	int i = 0;
	for (i=0; i<NUM_LEDS; i++) {
		led[i].r=140;led[i].g=140;led[i].b=0;    // Write red to array
	}
    ws2812_setleds(led,NUM_LEDS);
	_delay_ms(500);                         // wait for 500ms.
	
	for (i=0; i<NUM_LEDS; i++) {
		led[i].r=0;led[i].g=0;led[i].b=0;    // Write red to array
	}
    ws2812_setleds(led,NUM_LEDS);
	_delay_ms(500);
}


// phantom
void phantom() {
    int i=0; int j=0;
    int r=2; 

    for (j=4; j<=512; j++) {
        if (j>=255) { 
	    r--; 
	}
        else { 
	    r++; 
	}
	if (r<4) { r=4; }

        for (i=0; i<NUM_LEDS; i++) {
            led[i].r=0;
            led[i].g=0;
            led[i].b=r;
        }
        ws2812_setleds(led,NUM_LEDS);
        _delay_ms(5);
    }
}

// green phantom
void green_phantom() {
    int i=0; int j=0;
    int r=2; 

    for (j=4; j<=512; j++) {
        if (j>=255) { 
	    r--; 
	}
        else { 
	    r++; 
	}
	if (r<4) { r=4; }

        for (i=0; i<NUM_LEDS; i++) {
            led[i].r=0;
            led[i].g=r;
            led[i].b=0;
        }
        ws2812_setleds(led,NUM_LEDS);
        _delay_ms(5);
    }
}


// rainbow fade
void rainbow_fade() {
    //shift all vallues by one led
    uint8_t i=0;
    for(i=15; i>1; i--)
        led[i-1]=led[i-2];
    //change colour when colourlength is reached
    if(k>COLORLENGTH) {
        j++;
        if(j>7) { j=0; }
        k=0;
    }
    k++;
    //loop colouers
       
    //fade red
    if(led[0].r<(colors[j].r-FADE))
    led[0].r+=FADE;

    if(led[0].r>(colors[j].r+FADE))
    led[0].r-=FADE;

    if(led[0].g<(colors[j].g-FADE))
    led[0].g+=FADE;

    if(led[0].g>(colors[j].g+FADE))
    led[0].g-=FADE;

    if(led[0].b<(colors[j].b-FADE))
    led[0].b+=FADE;

    if(led[0].b>(colors[j].b+FADE))
    led[0].b-=FADE;

    _delay_ms(50);
    ws2812_sendarray((uint8_t *)led,MAXPIX*3);
}


// s7a73farm
void lets_party() {
    color c1 = {255,0,0};		// Red
    morse_l(c1);

    color c2 = {0,255,0};		// Green
    morse_e(c2);

    color c3 = {0,0,255};		// Blue
    morse_t(c3);

    color c4 = {255,255,255};		// White
    morse_s(c4);

    off(200);

    color c5 = {255,32,0}; 		// Orange
    morse_p(c5);

    color c6 = {128,0,255};		// Purple
    morse_a(c6);

    color c7 = {0,128,255};		// Teal
    morse_r(c7);

    color c8 = {255,128,0};		// Yellow
    morse_t(c8);

    color c9 = {255,255,255};		// White
    morse_y(c9);

    off(400);
}


// Mrs s7a73farm
// slow fade blue, purple, red
// then dance (party color)
void mrs_s7a73farm() {
    int x=0; int i=0; int k=0; 
    for (x=0; x<2; x++) {
        for (i=0; i<15; i++) {
	    led[i].r=255;
	    led[i].g=255;
	    led[i].b=255;
	    if (i>0) {
	        led[i-1].r=0;
	        led[i-1].g=0;
	        led[i-1].b=0;
	    }
	    ws2812_setleds(led,NUM_LEDS);
	    _delay_ms(50);
	    led[14].r=0;led[14].g=0;led[14].b=0;
        }
    }
    for (j=255; j>0; j--) {
	    for (i=0; i<12; i++) {
	        led[LED_PRIM[i]].r=k;
		led[LED_PRIM[i]].g=0;
		led[LED_PRIM[i]].b=j;
	    }
            for (i=0; i<3; i++) {
	        led[LED_CENTER[i]].r=j;
	        led[LED_CENTER[i]].g=0;
	        led[LED_CENTER[i]].b=k;
            }
	k++;
        ws2812_setleds(led,NUM_LEDS);
        _delay_ms(10);    
    }
    i=0; k=255;
    for (j=0; j<255; j++) {
	    for (i=0; i<12; i++) {
	        led[LED_PRIM[i]].r=k;
		led[LED_PRIM[i]].g=0;
		led[LED_PRIM[i]].b=j;
	    }
            for (i=0; i<3; i++) {
	        led[LED_CENTER[i]].r=j;
	        led[LED_CENTER[i]].g=0;
	        led[LED_CENTER[i]].b=k;
            }
	k--;
        ws2812_setleds(led,NUM_LEDS);
        _delay_ms(10);    
    }
}


// compukidmike
// blue,yellow,off rotate
void mk() {
    uint8_t i = 0;
    int intensity = 128;
    // Prim - blue 
    for (i=0; i<12; i++) { // sizeof(LED_PRIM); i++) {
	led[LED_PRIM[i]].r=0;
	led[LED_PRIM[i]].g=0;
	led[LED_PRIM[i]].b=intensity; 
    }
    // Center - yellow 
    for (i=0; i<3; i++) { // sizeof(LED_CENTER); i++) {
	led[LED_CENTER[i]].r=intensity;
	led[LED_CENTER[i]].g=intensity;
	led[LED_CENTER[i]].b=0;
    }
    ws2812_setleds(led,NUM_LEDS);
    _delay_ms(700);   
	
    // Prim - yellow 
    for (i=0; i<12; i++) { // sizeof(LED_PRIM); i++) {
	led[LED_PRIM[i]].r=intensity;
        led[LED_PRIM[i]].g=intensity;
        led[LED_PRIM[i]].b=0;  
    }
    // Center - blue
    for (i=0; i<3; i++) { // sizeof(LED_CENTER); i++) {
	led[LED_CENTER[i]].r=0;
        led[LED_CENTER[i]].g=0;
        led[LED_CENTER[i]].b=intensity;  
    }
    ws2812_setleds(led,NUM_LEDS);
    _delay_ms(700);
}

// gr3yR0n1n
void ashen_colored_wanderer() {
    color c = {16,0,16};	// Purple
    morse_g(c);			// g
    morse_r(c);			// r
    morse_3(c);			// 3
    morse_y(c);			// y
    morse_r(c);			// R
    morse_0(c);			// 0
    morse_n(c);			// n
    morse_1(c);			// 1
    morse_n(c);			// n

    off(400);
}

