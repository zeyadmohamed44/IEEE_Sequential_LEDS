/*
* Author: Zeyad mohamed
*Date: 29/8/2024
* version: V01
*
*/


#include "E:\IEEE  workshop\system\LIB\STD_TYPES.h"
#include "E:\IEEE  workshop\system\LIB\BIT_MATH.h"

#include "E:\IEEE  workshop\system\MCAL\GPIO\GPIO_INTERFACE.h"
#include "E:\IEEE  workshop\system\MCAL\GPIO\GPIO_PRIVATE.h"
#include "E:\IEEE  workshop\system\MCAL\GPIO\GPIO_CONFIG.h"

void MCAL_GPIO_voidsetPinMode(u8 Copy_u8Port, u8 Copy_u8Pin , u8 Copy_u8Mode)
{
	switch (Copy_u8Port)
	{
		case GPIOA :
			if (Copy_u8Pin <8)
			{
				GPIOA_CRL &= ~(0b1111<< (Copy_u8Pin * 4));
				GPIOA_CRL |= ~(Copy_u8Mode << (Copy_u8Pin * 4));
			}
			else if (Copy_u8Pin <16)
			{
				Copy_u8Pin -= 8;
				GPIOA_CRH &= ~(0b1111<< (Copy_u8Pin * 4));
				GPIOA_CRH |= ~(Copy_u8Mode << (Copy_u8Pin * 4));
			}
		break ;
		case GPIOB :
					if (Copy_u8Pin <8)
					{
						GPIOB_CRL &= ~(0b1111<< (Copy_u8Pin * 4));
						GPIOB_CRL |= ~(Copy_u8Mode << (Copy_u8Pin * 4));
					}
					else if (Copy_u8Pin <16)
					{
						Copy_u8Pin -= 8;
						GPIOB_CRH &= ~(0b1111<< (Copy_u8Pin * 4));
						GPIOB_CRH |= ~(Copy_u8Mode << (Copy_u8Pin * 4));
					}
		break ;
		case GPIOC :
							if (Copy_u8Pin <8)
							{
								GPIOC_CRL &= ~(0b1111<< (Copy_u8Pin * 4));
								GPIOC_CRL |= ~(Copy_u8Mode << (Copy_u8Pin * 4));
							}
							else if (Copy_u8Pin <16)
							{
								Copy_u8Pin -= 8;
								GPIOC_CRH &= ~(0b1111<< (Copy_u8Pin * 4));
								GPIOC_CRH |= ~(Copy_u8Mode << (Copy_u8Pin * 4));
							}
		break ;
	}
}
void MCAL_GPIO_voidsetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin , u8 Copy_u8Value)
{
	switch(Copy_u8Port)
	    {
	        case GPIOA:
	            if(Copy_u8Value)
	            SET_BIT(GPIOA_ODR,Copy_u8Pin);
	            else
	            CLR_BIT(GPIOA_ODR,Copy_u8Pin);
	        break;

	        case GPIOB:
	            if(Copy_u8Value == GPIO_HIGH)
	            SET_BIT(GPIOB_ODR,Copy_u8Pin);
	            else if(Copy_u8Value == GPIO_LOW)
	            CLR_BIT(GPIOB_ODR,Copy_u8Pin);

	        break;

	        case GPIOC:
	            if(Copy_u8Value == GPIO_HIGH)
	            SET_BIT(GPIOC_ODR,Copy_u8Pin);
	            else if(Copy_u8Value == GPIO_LOW)
	            CLR_BIT(GPIOC_ODR,Copy_u8Pin);
	        break;

	    }

}

u8 MCAL_GPIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin)
{
	u8 Local_u8Value;

	    switch(Copy_u8Port)
	    {
	        case GPIOA:
	            Local_u8Value=	GET_BIT(GPIOA_IDR,Copy_u8Pin);
	        break;
	        case GPIOB:
	            Local_u8Value=	GET_BIT(GPIOB_IDR,Copy_u8Pin);
	        break;
	        case GPIOC:
	            Local_u8Value=	GET_BIT(GPIOC_IDR,Copy_u8Pin);
	        break;
	    }

	    return Local_u8Value;

}
