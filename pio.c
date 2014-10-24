/*
 * pio.c
 *
 * Created: 2014-03-23 10:35:40 AM
 *  Author: Derek
 */ 


#include "pio.h"


void digitalWrite(volatile uint8_t *port, uint8_t pin, uint8_t state)
{
	if (state == HIGH)
	{
		*port |= pin;
	}else
	{
		*port &= ~pin;
	}
}
