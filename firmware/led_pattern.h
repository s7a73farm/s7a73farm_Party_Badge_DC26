/***********************************************************************
* FILENAME: led_pattern.h
* AUTHOR: s7a73farm, gr3yR0n1n
* DATE: 07.07.2018
*
* Copyright s7a73farm 2018.  All rights reserved.
***********************************************************************/


#ifndef LED_PATTERN_H 
#define LED_PATTERN_H 


#include "light_ws2812/light_ws2812.h"


void led_init();


void fade();
void computations();


void ashen_colored_wanderer();
void mk();
void mrs_s7a73farm();
void lets_party();
void phantom();
void green_phantom();
void lets_party2();
void no_party();
void lady_bug();
void knight_rider();
void rainbow_fade();


extern int g_up;
extern int g_index;
extern uint8_t data_array[1];
extern uint8_t q;
extern uint8_t temp;
extern uint8_t led_phase;


#endif
