/*
 * charDisp.h
 *
 * Created: 2014-03-23 10:26:45 AM
 *  Author: Derek
 */ 


#ifndef CHARDISP_H_
#define CHARDISP_H_
/********************************************************************************
Includes
********************************************************************************/
#include <avr/io.h>
#include <inttypes.h>
#include <stdio.h>
#include <util/delay.h>
#include "pio.h"

/********************************************************************************
Macros and Defines
********************************************************************************/
#define CLEAR_SCREEN	0x01
#define BLINK_CURSER	0x0F
#define NO_CURSER		0x0C
#define CURSER_HOME		0x02
#define TWO_LINE		0x38
#define RS (1 << DDD2)
#define RW (1 << DDD3)
#define E (1 << DDD4)
#define DB0 (1 << DDD5)
#define DB1 (1 << DDD6)
#define DB2 (1 << DDD7)
#define DB3 (1 << DDB0)
#define DB4 (1 << DDB1)
#define DB5 (1 << DDB2)
#define DB6 (1 << DDB3)
#define DB7 (1 << DDB4)



/********************************************************************************
Function Prototypes
********************************************************************************/


void writeConfig(int data);
void writeData(int data);
void triggerE();
void writePort(int data);
int charDisp_putchar_printf(char var, FILE *stream);
void initCharDisp();




#endif /* CHARDISP_H_ */