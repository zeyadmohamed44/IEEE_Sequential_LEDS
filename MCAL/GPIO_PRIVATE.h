/*
* Author: Zeyad mohamed
*Date: 29/8/2024
* version: V01
*
*/

#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

#define GPIO_PORTA  0x40010800
#define GPIO_PORTB  0x40010C00
#define GPIO_PORTC  0x40011000


#define GPIOA_CRL *((volatile u32*)(GPIO_PORTA + 0x00))
#define GPIOA_CRH *((volatile u32*)(GPIO_PORTA + 0x04))
#define GPIOA_IDR *((volatile u32*)(GPIO_PORTA + 0x88))
#define GPIOA_ODR *((volatile u32*)(GPIO_PORTA + 0x8c))


#define GPIOB_CRL *((volatile u32*)(GPIO_PORTB + 0x00))
#define GPIOB_CRH *((volatile u32*)(GPIO_PORTB + 0x04))
#define GPIOB_IDR *((volatile u32*)(GPIO_PORTB + 0x88))
#define GPIOB_ODR *((volatile u32*)(GPIO_PORTB + 0x8c))


#define GPIOC_CRL *((volatile u32*)(GPIO_PORTC + 0x00))
#define GPIOC_CRH *((volatile u32*)(GPIO_PORTC + 0x04))
#define GPIOC_IDR *((volatile u32*)(GPIO_PORTC + 0x88))
#define GPIOC_ODR *((volatile u32*)(GPIO_PORTC + 0x8c))


#endif
