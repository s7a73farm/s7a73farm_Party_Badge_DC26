/***********************************************************************
* FILENAME: debounce.c
* AUTHOR: s7a73farm, gr3yR0n1n
* DATE: 07.07.2018
*
* Copyright s7a73farm 2018.  All rights reserved.
***********************************************************************/

#include "debounce.h"

// Bits is set to one if a depounced press is detected.
volatile uint8_t buttons_down;

// Return non-zero if a button matching mask is pressed.
uint8_t button_down(uint8_t button_mask) {
	// ATOMIC_BLOCK is needed if debounce() is called from within an ISR
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
		// And with debounced state for a one if they match
		button_mask &= buttons_down;
		// Clear if there was a match
		buttons_down ^= button_mask;
	}
	// Return non-zero if there was a match
	return button_mask;
}

void debounce_init(void) {
	// Button pins as input
	BUTTON_DDR &= ~(BUTTON_MASK);
	// Enable pullup on buttons
	BUTTON_PORT |= BUTTON_MASK;
}
