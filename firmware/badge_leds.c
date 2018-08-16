/***********************************************************************
* FILENAME: badge_leds.c
* AUTHOR: s7a73farm, gr3yR0n1n
* DATE: 07.07.2018
*
* Copyright s7a73farm 2018.  All rights reserved.
***********************************************************************/


#include "light_ws2812/light_ws2812.h"
#include "badge_leds.h"


// LEDs
// Define the array of leds
const int LED_TOP[3] = {0,1,2};					// Top 3
const int LED_BOTTOM[3] = {5,4,3};				// Bottom 3
const int LED_LEFT[3] = {7,6,8}; 				// Left 3
const int LED_CENTER[3] = {11,10,9};				// Center 3
const int LED_RIGHT[3] = {13,14,12};				// Right 3
const int LED_PRIM[12] = {0,1,2, 13,14,12, 3,4,5, 8,6,7};	// Prim 
const int LED_TOPLINE[6] = {7,0,1,2,13,14};			// Top Line
const int LED_CENTERLINE[7] = {14,12,11,9,8,6};			// Middle Line

