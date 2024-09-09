/*
* Author: Zeyad mohamed
*Date: 29/8/2024
* version: V01
*
*/

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

// Ports:
#define GPIOA 0
#define GPIOB 1
#define GPIOC 2

// Pins:
#define GPIO_PIN0 			0
#define GPIO_PIN1 			1
#define GPIO_PIN2 			2
#define GPIO_PIN3 			3
#define GPIO_PIN4 			4
#define GPIO_PIN5 			5
#define GPIO_PIN6 			6
#define GPIO_PIN7 			7
#define GPIO_PIN8 			8
#define GPIO_PIN9 			9
#define GPIO_PIN10 			10
#define GPIO_PIN11 			11

#define GPIO_LOW 0
#define GPIO_HIGH 1

// Modes:
#define GPIO_INPUT_ANALOG   	 		 0b0000
#define GPIO_INPUT_FLOATING  			 0b0100
#define GPIO_INPUT_PULL_UP_DOWN 		 0b1000

#define GPIO_OUTPUT_PUSH_PULL_10MHZ		 0b0001
#define GPIO_OUTPUT_OPEN_DRAIN_10MHZ	 0b0001

#define GPIO_OUTPUT_PUSH_PULL_20MHZ		 0b0010
#define GPIO_OUTPUT_OPEN_DRAIN_20MHZ	 0b0101

#define GPIO_OUTPUT_PUSH_PULL_50MHZ		 0b0011
#define GPIO_OUTPUT_OPEN_DRAIN_50MHZ	 0b0111


// Functions:
void MCAL_GPIO_voidsetPinMode(u8 copy_u8Port, u8 Copy_u8Pin , u8 Copy_u8Mode);

void MCAL_GPIO_voidsetPinValue(u8 copy_u8Port, u8 Copy_u8Pin , u8 Copy_u8value);

u8 MCAL_GPIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_Copy_u8Pin);

#endif
