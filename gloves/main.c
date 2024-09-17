#include "std_types.h"
#include "bit_math.h"
#include "dio_int.h"
#include "ADC_interface.h"
#include"lcd_int.h"
#include"lcd_cfg.h"
#include"USART_int.h"
#include"USART_reg.h"
#include"DFPLAYER_int.h"
#include"util/delay.h"

int main(void)
{

	u16_t digital_value,analog_value;
	LCD_vidInit();
	//input pin for adc
   	DIO_u8SetPinMode(PORT_A,0,INPUT);
    //tx for mp3
   	DIO_u8SetPinMode(PORT_D,0,INPUT);
   	//rx for mp3
   	DIO_u8SetPinMode(PORT_D,1,OUTPUT);

   	ADC_voidInit();
    Uart_vidInit();
    DFPlayer_SetVolume(30);

   	while(1)
   	{
   		DFPlayer_PlayTrack(1);
   		_delay_ms(2000);

   	ADC_u8GetDigitalValue(ADC_CHANNEL_0, &digital_value);
   	analog_value=(u16_t)(digital_value*5)/1023;   //range of mv

   	if(digital_value<=250)
   	{
   		LCD_vidDisplayString("Hello");
   		LCD_vidWriteInteger(digital_value);
   		_delay_ms(1000);
   		DFPlayer_PlayTrack(1);
   		_delay_ms(1000);
   		   	LCD_vidClearDisplay();
   		_delay_ms(1000);
   	}
   	else if((digital_value>250) && (digital_value<=500) )
   	{
   		LCD_vidDisplayString("my name is ");
   		LCD_vidWriteInteger(digital_value);
   		   	_delay_ms(1000);
   		   	LCD_vidClearDisplay();

   		    	_delay_ms(1000);

   	}
   	else if(digital_value>500 )
   	   	{
   		LCD_vidDisplayString(" bye ..   ");
   		LCD_vidWriteInteger(digital_value);
   		   	_delay_ms(1000);
   		   	LCD_vidClearDisplay();
   		   	_delay_ms(1000);

   	   	}
   	}
   	return 0;

}
