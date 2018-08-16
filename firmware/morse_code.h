/***********************************************************************
* FILENAME: morse_code.h
* AUTHOR: s7a73farm, gr3yR0n1n
* DATE: 07.07.2018
*
* Copyright s7a73farm 2018.  All rights reserved.
***********************************************************************/


#ifndef MORSE_CODE_H 
#define MORSE_CODE_H 


#include <util/delay.h>
#include "light_ws2812/light_ws2812.h"
#include "color.h"


// Off
void off(int);


// A-Z
void morse_a(color);
void morse_b(color);
void morse_c(color);
void morse_d(color);
void morse_e(color);
void morse_f(color);
void morse_g(color);
void morse_h(color);
void morse_i(color);
void morse_j(color);
void morse_k(color);
void morse_l(color);
void morse_m(color);
void morse_n(color);
void morse_o(color);
void morse_p(color);
void morse_q(color);
void morse_r(color);
void morse_s(color);
void morse_t(color);
void morse_u(color);
void morse_v(color);
void morse_w(color);
void morse_x(color);
void morse_y(color);
void morse_z(color);


// 1-0
void morse_1(color);
void morse_2(color);
void morse_3(color);
void morse_4(color);
void morse_5(color);
void morse_6(color);
void morse_7(color);
void morse_8(color);
void morse_9(color);
void morse_0(color);


#endif
