/*
 * ADC_proj.c
 *
 *  Created on: Feb 18, 2024
 *      Author: el bostan
 */

#include "std_types.h"
#include "bit_math.h"
#include "dio_int.h"
#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"

void ADC_voidInit(void)
{
	/*1.select Vref=Avcc
	 * 2.Right adjust
	 * 3.disable autotrigger
	 * 4.select clk (50khz:200khz)as we work with 10 bits
	 * prescalar 64
	 * 5.enable ADC
	 */
	CLR_BIT(ADC_u8_ADMUX_REG,7);
	SET_BIT(ADC_u8_ADMUX_REG,6);
	CLR_BIT(ADC_u8_ADMUX_REG,5);
	CLR_BIT(ADC_u8_ADCSRA_REG,5);
	SET_BIT(ADC_u8_ADCSRA_REG,2);//prescalar 64
	SET_BIT(ADC_u8_ADCSRA_REG,1);
	CLR_BIT(ADC_u8_ADCSRA_REG,0);
	SET_BIT(ADC_u8_ADCSRA_REG,7);//enable peripheral

}

uint8_t   ADC_u8GetDigitalValue(uint8_t Copy_u8ChannelNb, u16_t * Copy_pu16DigitalValue)
{
	uint8_t error_state=E_OK;
	if(Copy_u8ChannelNb<32)
	{
		/* clear MUX 0:4
		 * select channel
		 * start conversion
		 */
	ADC_u8_ADMUX_REG &=0b11100000;
	ADC_u8_ADMUX_REG |= Copy_u8ChannelNb;
	SET_BIT(ADC_u8_ADCSRA_REG,6);
	//wait flag=1  polling
	while(GET_BIT(ADC_u8_ADCSRA_REG,4)==0);
	//clear flag
	SET_BIT(ADC_u8_ADCSRA_REG,4);
	//read digital value
	*Copy_pu16DigitalValue=ADC_u16_ADC_REG;
	}
	else
	{
		error_state=E_NOK;
	}


return error_state;
}


