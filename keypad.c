/*
 * Date : 09.08.2022
 * Project : PAYGO LINK & TOKEN
 * Author : Dale LIM
 * Name : Keypad.c
 */


#include "keypad.h"

// Keypad 3x4
#if KEYPAD3X4
static uint8_t keys[12]={
		'1', '2', '3',
		'4', '5', '6',
		'7', '8', '9',
		'*', '0', '#'
};
// keypad 4x4
#elif KEYPAD4X4
static uint8_t keys[16]={
		'1', '2', '3', 'A',
		'4', '5', '6', 'B',
		'7', '8', '9', 'C',
		'*', '0', '#', 'D'
};
#endif

uint8_t key = 0;
void keypad_Init(void){
	GPIO_InitTypeDef GPIO_InitStruct;
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOD_CLK_ENABLE();
	__HAL_RCC_GPIOE_CLK_ENABLE();

	GPIO_InitStruct.Pin = r1_pin|r2_pin|r3_pin|r4_pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(RPort, &GPIO_InitStruct);

	//
	#if KEYPAD3X4
	GPIO_InitStruct.Pin = c1_pin|c2_pin|c3_pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(CPort, &GPIO_InitStruct);
	#elif KEYPAD4X4
	GPIO_InitStruct.Pin = c1_pin|c2_pin|c3_pin|c4_pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(CPort, &GPIO_InitStruct);
	#endif

	for(uint8_t i = 0; i < Rs; i++){
		HAL_GPIO_WritePin(RPort, RPin[i], GPIO_PIN_SET);
	}
}
char readkey(void){
	for(uint8_t i = 0; i < Rs; i++){
		HAL_GPIO_WritePin(RPort, RPin[i], GPIO_PIN_RESET);
		for(uint8_t j = 0; j < Cs; j++){
			if(!HAL_GPIO_ReadPin(CPort, CPin[j])){
				while(!HAL_GPIO_ReadPin(CPort, CPin[j]));

				// CHECK KEYPAD
				#if KEYPAD3X4
				key = keys[i * 3 + j];
				#elif KEYPAD4X4
				key = keys[i * 4 + j];
				#endif
				return key;
			}
		}
		HAL_GPIO_WritePin(RPort, RPin[i], GPIO_PIN_SET);
	}
	return '\0';
}



































