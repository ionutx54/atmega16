/*
 * 4x4keyb.c
 *
 * Created: 4/22/2019 12:38:22 PM
 * Author : Loca
 */ 

#define F_CPU 14745600UL 
#include <avr/io.h>
#include <util/delay.h>
#include "keypad.h"
#include "digit.h"

 int main(void){
	 init_digit();
	 init_keypad();
	 while(1){
		 scanare();
	 }
 }

		