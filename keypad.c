/*
 * keypad.c
 *
 * Created: 4/22/2019 8:50:57 PM
 *  Author: Loca
 */ 
#define F_CPU 14745600UL
#include <avr/io.h>
#include <util/delay.h>
#include "digit.h"

void init_keypad(){
	//initializare data direction ptr keypad
	DDRB = 0b00001111; //0,1,2,3 -> ouptut; 4,5,6,7 -> input
	PORTB = 0b11110000;
}
void scanare(){
	//buton apasat?
	if(PINB == 0b11110000) return 
	_delay_ms(100); //debouncing delay
	
	//scanare keypad
	uint8_t scanCode = PINB;
	DDRB ^= 0b11111111; //coloane ca input
	PORTB ^= 0b11111111;
	
	_delay_ms(10);
	scanCode |= PINB;
	
	if(scanCode == 0b11101110) 
		display_digit(1);
	if(scanCode == 0b11011110)
		display_digit(2);
	if(scanCode == 0b10111110)
		display_digit(3);	
	if(scanCode == 0b01111110)
		display_digit(4);
	if(scanCode == 0b11101101)
		display_digit(5);
	if(scanCode == 0b11011101)
		display_digit(6);
	if(scanCode == 0b10111101)
		display_digit(7);
	if(scanCode == 0b01111101)
		display_digit(8);
	if(scanCode == 0b11101011)
		display_digit(9);
	if(scanCode == 0b11011011)
		display_digit(10);
	if(scanCode == 0b10111011)
		display_digit(11);
	if(scanCode == 0b01111011)
		display_digit(12);
	if(scanCode == 0b11100111)
		display_digit(13);
	if(scanCode == 0b11010111)
		display_digit(14);
	if(scanCode == 0b10110111)
		display_digit(15);
	if(scanCode == 0b01110111)
		display_digit(16);	
}

