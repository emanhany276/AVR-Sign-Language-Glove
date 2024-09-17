
#include"util/delay.h"

void DFPlayer_SendCommand(char command,int parameter)
{
	int checksum = -(0xFF + 0x06 + command + (parameter >> 8) + (parameter & 0xFF));
	    Uart_vidSend(0x7E);       // Start code
	    _delay_ms(100);
	    Uart_vidSend(0xFF);       // Version
	    _delay_ms(100);
	    Uart_vidSend(0x06);       // Length
	    _delay_ms(100);
	    Uart_vidSend(command);    // Command
	    _delay_ms(100);
	    Uart_vidSend(0x00);       // Length
	    _delay_ms(100);
	    Uart_vidSend(parameter >> 8);    // Parameter high byte
	    _delay_ms(100);
	    Uart_vidSend(parameter & 0xFF);  // Parameter low byte
	    _delay_ms(100);
	    Uart_vidSend(checksum >> 8);     // Checksum high byte
	    _delay_ms(100);
	    Uart_vidSend(checksum & 0xFF);   // Checksum low byte
	    _delay_ms(100);
	    Uart_vidSend(0xEF);       // End code
	    _delay_ms(100);
}
void DFPlayer_PlayTrack(int track)
{
	DFPlayer_SendCommand(0x03,track);

}
void DFPlayer_SetVolume(int volume)
{
	DFPlayer_SendCommand(0x06,volume);  //it will change the parameter
}
