/***********************************************************************
* FILENAME: badge_leds.h
* AUTHOR: s7a73farm, gr3yR0n1n
* DATE: 07.07.2018
*
* Copyright s7a73farm 2018.  All rights reserved.
***********************************************************************/


#ifndef BADGE_LEDS_H 
#define BADGE_LEDS_H 


#include "light_ws2812/light_ws2812.h"


// LED Count
#define NUM_LEDS 15


// LED
struct cRGB colors[8];
struct cRGB led[NUM_LEDS];


// LEDs
// Define the array of leds
extern const int LED_TOP[3];
extern const int LED_BOTTOM[3];
extern const int LED_LEFT[3];
extern const int LED_CENTER[3];
extern const int LED_RIGHT[3];
extern const int LED_PRIM[12];
extern const int LED_TOPLINE[6];
extern const int LED_CENTERLINE[7];


#endif
