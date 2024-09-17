/*
 * std_types.h
 *
 *  Created on: Dec 5, 2023
 *      Author: el bostan
 */



#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned char  uint8_t; // 0 ==> 255
typedef unsigned short int u16_t  ; // 0 ==> (2^16 -1)
typedef unsigned int u32; // 0 ==> (2^32 -1)
typedef signed char s8;   // 127 ==> (-128)  === (2^8/2)-1 ==>(-2^8/2)
typedef signed short int s16; //  32,767==> (-32,768)  === (2^16/2)-1 ==>(-2^16/2)
typedef signed int s32; //   2,147,483,647 ==> (-2,147,483,648)
typedef float f32;  //  0 ==> (2^32-1)
typedef double f64; // 0 ==> (2^64-1)

typedef unsigned long long int u64;
typedef signed long long int s64;
typedef long double f128;


#endif



