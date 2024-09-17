/*
 * bit_math.h
 *
 *  Created on: Dec 5, 2023
 *      Author: el bostan
 */


#define SET_BIT(Reg,bit_no) (Reg|=(1<<bit_no))
#define CLR_BIT(Reg,bit_no) (Reg&=~(1<<bit_no))
#define TOG_BIT(Reg,bit_no) (Reg^=(1<<bit_no))
#define GET_BIT(Reg,bit_no) ((Reg>>bit_no)&1)//we need adujst...Now it is adjusted...
