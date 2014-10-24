/*
 * charDisp.c
 *
 * Created: 2014-03-23 10:27:03 AM
 *  Author: Derek
 */ 

/********************************************************************************
Includes
********************************************************************************/
#include "charDisp.h"
#include "pio.h"




void initCharDisp()
{
	static FILE mystdout = FDEV_SETUP_STREAM(charDisp_putchar_printf, NULL,
	_FDEV_SETUP_WRITE);
	stdout = &mystdout;
	
	writeConfig(TWO_LINE);
	writeConfig(NO_CURSER);
	writeConfig(CLEAR_SCREEN);

}


void writeConfig(int data)
{
	digitalWrite(&PORTD, RS, LOW);
	digitalWrite(&PORTD, RW, LOW);
	writePort(data);
	triggerE();
}
	  
void writeData(int data)
{
	digitalWrite(&PORTD, RS, HIGH);
	digitalWrite(&PORTD,RW, LOW);
	writePort(data);
	triggerE();
}

void triggerE()
{
	_delay_ms(1);
	digitalWrite(&PORTD,E,LOW);
	_delay_ms(1);
	digitalWrite(&PORTD,E,HIGH);
	_delay_ms(1);
	digitalWrite(&PORTD,E,LOW);
}

void writePort(int data)
{
	digitalWrite(&PORTD, DB0, (data & 0x01) >> 0);
	digitalWrite(&PORTD, DB1, (data & 0x02) >> 1);
	digitalWrite(&PORTD, DB2, (data & 0x04) >> 2);
	digitalWrite(&PORTB, DB3, (data & 0x08) >> 3);
	digitalWrite(&PORTB, DB4, (data & 0x16) >> 4);
	digitalWrite(&PORTB, DB5, (data & 0x32) >> 5);
	digitalWrite(&PORTB, DB6, (data & 0x64) >> 6);
	digitalWrite(&PORTB, DB7, (data & 0x128) >> 7);
}
	
	
	
	//TODO  Put next line in here 
int charDisp_putchar_printf(char var, FILE *stream) {
	//if (var == '\n') usart_putchar('\r');    
	writeData(var);
	return 0;
}  