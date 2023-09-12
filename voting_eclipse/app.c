/*
 * app .c
 *
 *  Created on: Sep 11, 2023
 *      Author: dell
 */
#include <stdint.h>
#include"lcd.h"
#include"keypad.h"
#include"app.h"
#include <util/delay.h>
#include<stdio.h>
#include<stdlib.h>

static void intial_screen(void);
static void check_voting(void);
static void intial_screen(void);
static void main_menu(void);
static  int countA=0;
static  int countB=0;
static  int countC=0;
static  int countD=0;





void init_function(void){
	 LCD_init();
	 LCD_clearScreen();
}


void welcome_screen(void){
	 LCD_clearScreen();
	 LCD_displayString("Welcome ");
	 _delay_ms(1000);
	 LCD_clearScreen();
	 intial_screen();
}

static void intial_screen(void){

	LCD_displayStringRowColumn(0,0,"A=0");
	LCD_displayStringRowColumn(0,10,"B=0");
	LCD_displayStringRowColumn(1,0,"C=0");
	LCD_displayStringRowColumn(1,10,"D=0");
	check_voting();
}



static void main_menu(void){

	LCD_displayStringRowColumn(0,0,"A=");
	LCD_integerToString(countA);
	LCD_displayStringRowColumn(0,10,"B=");
	LCD_integerToString(countB);
	LCD_displayStringRowColumn(1,0,"C=");
	LCD_integerToString(countC);
	LCD_displayStringRowColumn(1,10,"D=");
	LCD_integerToString(countD);

}
static void check_voting(void){

	countA=0;countB=0;countC=0;countD=0;

	for(uint8 i=0;i<20;i++){
		uint8 state	=KEYPAD_getPressedKey();
		_delay_ms(500);
		 if( state==1){
			countA=countA+1;
		}
		 else if( state==2){
			countB=countB+1;
		}
		else if( state==3){
			countC=countC+1;
		}
		else if( state==4){
			countD=countD+1;
		}
		else if( state==5){
			return 0;} // @suppress("Unused return value")

	LCD_clearScreen();
	main_menu();
}
}
