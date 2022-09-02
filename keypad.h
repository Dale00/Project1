/*
 * Created on: 09.08.2022
 * Author : Dale LIM
 * Project : PAYGO LINK AND TOKEN
 * Name : keypad.h
 */


#include "stm32f1xx_hal.h"

#ifndef keypad
#define kaypad
#define KEYPAD3X4 0
#define KEYPAD4X4 1
// DEFINE ROW
#define RPort GPIOA
#define r1_pin GPIO_PIN_0
#define r2_pin GPIO_PIN_1
#define r3_pin GPIO_PIN_2
#define r4_pin GPIO_PIN_3
// DEFINE COLUME
#define CPort GPIOA
#define c1_pin GPIO_PIN_4
#define c2_pin GPIO_PIN_5
#define c3_pin GPIO_PIN_6
#define c4_pin GPIO_PIN_7
//

// OUTPUT
static uint8_t RPin[4]={
		r1_pin, r2_pin, r3_pin, r4_pin
};
//
static uint8_t CPin[4]={
		c1_pin, c2_pin, c3_pin, c4_pin
};
// for keypad 3x4
#if KEYPAD3X4
#define Rs 4 // row 4
#define Cs 3 // colum 3
static uint8_t keys[12]; // sum of keys
// else for keypad 4x4
#elif KEYPAD4X4
#define Rs 4
#define Cs 4
static uint8_t keys[16]; // sum of keys
#endif

// initiallze
void keypad_Init(void);
char readkey(void);


#endif
