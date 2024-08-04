/*
 * IncFile1.h
 *
 * Created: 18/07/2024 22:47:45
 *  Author: Usuario
 */ 
#include <avr/io.h>
#include <util/delay.h>


#ifndef INCFILE1_H_
#define INCFILE1_H_
void initADC(void);
uint8_t ADC_Read(uint8_t channel);


void ADCs();
void ADCselect(int canal);

#endif /* INCFILE1_H_ */