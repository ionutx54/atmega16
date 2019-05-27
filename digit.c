
/*
 * digit.c
 *
 * Created: 4/15/2019 8:07:14 PM
 *  Author: Loca
 */ 
#define F_CPU 1000000UL
#include <stdint.h>
#include <avr/io.h>
//#include<util/delay.h>

#include "digit.h"

	//mapare cifre afisaj
	static const uint8_t digitmap[16] = {
		0xC0,
		0xF9,
		0xA4,
		0xB0,
		0x99,
		0x92,
		0x82,
		0xF8,
		0x80,
		0x90,
		0x88,
		0x83,
		0xC6,
		0xA1,
		0x86,
		0x8E
	};

	void init_digit(){
		//setare data direction pe PORTA
		DDRA = 0XFF;
	}
	
	void display_digit(uint8_t digit){
		PORTA = digitmap[digit];
	}
	
	void clear_digit(){
		PORTA = 0x00;//digitmap[5];
	}
	
	
	