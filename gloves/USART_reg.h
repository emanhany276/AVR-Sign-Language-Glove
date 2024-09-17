/*

 * USART_reg.h
 *
 *  Created on: Nov 30, 2023
 *      Author: Eman
 */

#define     UDR      (*((volatile uint8_t*) 0x2C  ))
#define     UCSRB    (*((volatile uint8_t*) 0x2A  ))
#define     UCSRA    (*((volatile uint8_t*) 0x2B  ))
#define     UCSRC    (*((volatile uint8_t*) 0x40  ))
#define     UBRRH    (*((volatile uint8_t*) 0x40  ))
#define     UBRRL    (*((volatile uint8_t*) 0x29 ))
