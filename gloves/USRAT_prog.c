/*
 * USRAT_prog.c

 *
 *  Created on: Nov 30, 2023
 *      Author: Eman
 */
#include"std_types.h"
#include"bit_math.h"
#include"USART_reg.h"
#include"USART_int.h"

#define E_OK  (uint8_t)0
#define E_NOK  (uint8_t)1
#define NULL  -1

void Uart_vidInit(void)
{
	uint8_t UCSRC_VALUE =0b10000000;  //to ensure the MSB is high
	u16_t UBRR_VALUE =51;             //baud rate value =9600
    //NORMAL MODE
	CLR_BIT(UCSRA,1);
	CLR_BIT(UCSRA,0);

	//BAUD RATE=9600
	UBRRL = (uint8_t)UBRR_VALUE;
	UBRRH =(uint8_t)(UBRR_VALUE >> 8);

	//ENABLE TX,RX
	SET_BIT(UCSRB,4);
	SET_BIT(UCSRB,3);
	//CHOOSE 8BITS
	CLR_BIT(UCSRB,2);
	SET_BIT(UCSRC_VALUE,2);
	SET_BIT(UCSRC_VALUE,1);
	//asyn
	CLR_BIT(UCSRC_VALUE,6);
	//PARITY BIT(disable)
	CLR_BIT(UCSRC_VALUE,5);


	CLR_BIT(UCSRC_VALUE,4);
	//STOP BIT
	SET_BIT(UCSRC_VALUE,3);
	UCSRC = UCSRC_VALUE;

}
void Uart_vidSend(uint8_t copy_data)
{
	//we should wait until TX transmitter is empty
	while((GET_BIT(UCSRA,5))==0);
	//send data
	UDR =copy_data;


}
uint8_t Uart_vidRecieve(uint8_t *copy_data)
{
	uint8_t ERROR_STATE = E_NOK;
	if(copy_data != NULL )
	{
		//wait until data is received
		while((GET_BIT(UCSRA,7))==0);
		*copy_data=UDR;
		ERROR_STATE = E_OK;
	}
	return ERROR_STATE;
}

