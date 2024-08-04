/*
 * ADC.c
 *
 * Created: 18/07/2024 22:48:03
 *  Author: Usuario
 */ 
#define F_CPU 16000000UL
#include "ADC.h"
#include <util/delay.h>
#include <avr/io.h>



void ADCs()
{
	ADMUX |= (1<<ADLAR); //LOW 8 BITS, HIGH 2 BITS 
	ADMUX |= (1<<REFS0); //Interno 1.1V 
	ADMUX |= (1<<REFS1); // Si es 1, 1.1v. Si es 0 5V externos
	ADCSRA|= (1 << ADPS2);
	//ADCSRA |= (1<<ADIE);
}

uint16_t ADC_read(uint8_t canal)
{
	ADMUX = (ADMUX & 0xF0) | (canal & 0x0F);  // Seleccionar el canal ADC
	ADCSRA |= (1 << ADEN);  // Habilitar ADC
	_delay_us(10);  // Esperar que se estabilice
	ADCSRA |= (1 << ADSC);  // Iniciar la conversi�n

	while (ADCSRA & (1 << ADSC));  // Esperar a que la conversi�n termine

	volatile uint8_t adc_result = ADCH;
	
	ADCSRA &= ~(1 << ADEN);  // Deshabilitar ADC

	return adc_result;
}
void initADC(void)
{
	//Configuraciones para el adc
	ADMUX = 0;
	ADMUX |= (1<<REFS0);
	ADMUX &=~ (1<<REFS1);
	ADMUX |= (1<<ADLAR);
	ADCSRA = 0;
	ADCSRA |= (1<<ADEN);
	ADCSRA |= (1<<ADIE);
	ADCSRA |= (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
	DIDR0 |= (1<<ADC0D);
}

