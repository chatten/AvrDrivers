/*
 * aip.h
 *
 * Created: 2014-03-26 9:30:49 PM
 *  Author: Derek
 */ 


#ifndef AIP_H_
#define AIP_H_

#include <avr/io.h>
#include <inttypes.h>
#include <stdio.h>
#include <util/delay.h>

void aipInitalize();
void aipStartConversion();
uint16_t aipRead();



#endif /* AIP_H_ */