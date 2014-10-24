/*
 * aip.c
 *
 * Created: 2014-03-26 9:30:23 PM
 *  Author: Derek
 */ 

/********************************************************************************
Includes
********************************************************************************/
#include "aip.h"


void aipInitalize()
{
		ADCSRA = 0x8F;			// Enable the ADC and its interrupt feature
		// and set the ACD clock pre-scalar to clk/128
		ADMUX |= (1 << ADLAR);
		ADMUX |= (1 << REFS0);			// Select AVCC with external capacitor at AREF pin
		ADCSRA |= (1 << ADEN);	
}

void aipStartConversion()
{
	ADCSRA |= 1<<ADSC;		// Start Conversion
		
}

uint16_t aipRead()
{
	return (ADCL >> 6) | (ADCH << 2);
}
