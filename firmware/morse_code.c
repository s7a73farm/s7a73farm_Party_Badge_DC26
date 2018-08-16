/***********************************************************************
* FILENAME: morse_code.c
* AUTHOR: s7a73farm, gr3yR0n1n
* DATE: 07.07.2018
*
* REF: https://en.wikipedia.org/wiki/Morse_code
* Copyright s7a73farm 2018.  All rights reserved.
***********************************************************************/


#include "morse_code.h"
#include "badge_leds.h"


// Off
void off(int delay) {
    int i=0;
    for (i=0; i<NUM_LEDS; i++) {
	led[i].r=0; led[i].g=0; led[i].b=0;
    }
    ws2812_setleds(led,NUM_LEDS);

    switch(delay) {
	case 100:
	    _delay_ms(100);
	    break;
	case 200:
	    _delay_ms(200);
	    break;
	case 300:
	    _delay_ms(300);
	    break;
	case 400:
	    _delay_ms(400);
	    break;
	case 500:
	    _delay_ms(500);
	    break;
	case 600:
	    _delay_ms(600);
	    break;
	case 700:
	    _delay_ms(700);
	    break;
	case 800:
	    _delay_ms(800);
	    break;
	case 900:
	    _delay_ms(900);
	    break;
	case 1000:
	    _delay_ms(1000);
	    break;
	default :
	    _delay_ms(100);
    }
}


// dot
void dot(color c) {
    // dot
    int i=0;
    for (i=0; i<NUM_LEDS; i++) {
	led[i].r=c.r;
	led[i].g=c.g;
	led[i].b=c.b;
    }
    ws2812_setleds(led,NUM_LEDS);
    _delay_ms(100);

    off(100);
}


// dash
void dash(color c) {
    // dash
    int i=0;
    for (i=0; i<NUM_LEDS; i++) {
	led[i].r=c.r;
	led[i].g=c.g;
	led[i].b=c.b;
    }
    ws2812_setleds(led,NUM_LEDS);
    _delay_ms(200);
    off(100);
}


// A-Z
// A .-
void morse_a(color c) { dot(c); dash(c); }

// B -...
void morse_b(color c) { dash(c); dot(c); dot(c); dot(c); }

// C -.-.
void morse_c(color c) { dash(c); dot(c); dash(c); dot(c); }

// D -..
void morse_d(color c) { dash(c); dot(c); dot(c); }
 
// E .  
void morse_e(color c) { dot(c); }
 
// F ..-.
void morse_f(color c) { dot(c); dot(c); dash(c); dot(c); }
 
// G --.
void morse_g(color c) { dash(c); dash(c); dot(c); }
 
// H ....
void morse_h(color c) { dot(c); dot(c); dot(c); dot(c); }
 
// I ..
void morse_i(color c) { dot(c); dot(c); }

// J .---
void morse_j(color c) { dot(c); dash(c); dash(c); dash(c); }
 
// K -.-
void morse_k(color c) { dash(c); dot(c); dash(c); }
 
// L .-.. 
void morse_l(color c) { dot(c); dash(c); dot(c); dot(c); }
 
// M -- 
void morse_m(color c) { dash(c); dash(c); } 
 
// N -. 
void morse_n(color c) { dash(c); dot(c); } 
 
// O --- 
void morse_o(color c) { dash(c); dash(c); dash(c); } 
 
// P .--. 
void morse_p(color c) { dot(c); dash(c); dash(c); dot(c); } 
 
// Q --.- 
void morse_q(color c) { dash(c); dash(c); dot(c); } 
 
// R .-. 
void morse_r(color c) { dot(c); dash(c); dot(c); } 
 
// S ... 
void morse_s(color c) { dot(c); dot(c); dot(c); } 
 
// T - 
void morse_t(color c) { dash(c); } 
 
// U ..- 
void morse_u(color c) { dot(c); dot(c); dash(c); } 
 
// V ...- 
void morse_v(color c) { dot(c); dot(c); dot(c); dash(c); } 
 
// W .--
void morse_w(color c) { dot(c); dash(c); dash(c); } 
 
// X -..-
void morse_x(color c) { dash(c); dot(c); dot(c); dash(c); } 
 
// Y -.--
void morse_y(color c) { dash(c); dot(c); dash(c); dash(c); } 
 
// Z --..
void morse_z(color c) { dash(c); dash(c); dot(c); dot(c); } 
 

// 1-0
// 1 .---- 
void morse_1(color c) { dot(c); dash(c); dash(c); dash(c); dash(c); } 
 
// 2 ..--- 
void morse_2(color c) { dot(c); dot(c); dash(c); dash(c); dash(c); } 
 
// 3 ...-- 
void morse_3(color c) { dot(c); dot(c); dot(c); dash(c); dash(c); } 
 
// 4 ....- 
void morse_4(color c) { dot(c); dot(c); dot(c); dot(c); dash(c); } 
 
// 5 ..... 
void morse_5(color c) { dot(c); dot(c); dot(c); dot(c); dot(c); } 
 
// 6 -.... 
void morse_6(color c) { dash(c); dot(c); dot(c); dot(c); dot(c); } 
 
// 7 --... 
void morse_7(color c) { dash(c); dash(c); dot(c); dot(c); dot(c); } 
 
// 8 ---.. 
void morse_8(color c) { dash(c); dash(c); dash(c); dot(c); dot(c); } 
 
// 9 ----. 
void morse_9(color c) { dash(c); dash(c); dash(c); dash(c); dot(c); } 
 
// 0 ----- 
void morse_0(color c) { dash(c); dash(c); dash(c); dash(c); dash(c); } 
