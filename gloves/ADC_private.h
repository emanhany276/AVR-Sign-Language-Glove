/*
 * ADC_private.h
 *
 *  Created on: Feb 18, 2024
 *      Author: el bostan
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

/*define for ADC registers*/
#define ADC_u8_ADMUX_REG        *((volatile uint8_t * )0x27)
#define ADC_u8_ADCSRA_REG       *((volatile uint8_t * )0x26)
#define ADC_u8_ADCH_REG         *((volatile uint8_t * )0x25)
#define ADC_u8_ADCL_REG         *((volatile uint8_t * )0x24)
#define ADC_u16_ADC_REG          *((volatile u16_t *)0x24)
#define ADC_u8_SFIOR_REG        *((volatile uint8_t * )0x50) //which source will trigger ADC conversion
#endif /* ADC_PRIVATE_H_ */
