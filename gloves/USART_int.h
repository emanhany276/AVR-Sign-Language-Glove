/*
 * USART_int.h
 *
 *  Created on: Nov 30, 2023
 *      Author: Eman
 */

#ifndef USART_INT_H_
#define USART_INT_H_


void Uart_vidInit(void);
void Uart_vidSend(uint8_t copy_data);
uint8_t Uart_vidRecieve(uint8_t *copy_data);

#endif /* USART_INT_H_ */
