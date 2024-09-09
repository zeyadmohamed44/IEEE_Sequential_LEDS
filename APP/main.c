// includes:
#include "E:\IEEE  workshop\system\LIB\STD_TYPES.h"
#include "E:\IEEE  workshop\system\LIB\BIT_MATH.h"

#include "E:\IEEE  workshop\system\MCAL\RCC\RCC_INTERFACE.h"
#include "E:\IEEE  workshop\system\MCAL\RCC\RCC_PRIVATE.h"
#include "E:\IEEE  workshop\system\MCAL\RCC\RCC_CONFIG.h"

#include "E:\IEEE  workshop\system\MCAL\GPIO\GPIO_INTERFACE.h"
#include "E:\IEEE  workshop\system\MCAL\GPIO\GPIO_PRIVATE.h"
#include "E:\IEEE  workshop\system\MCAL\GPIO\GPIO_CONFIG.h"



// delay function:
	void delay(int x)
	{
		int i ;
		for(i=0 ; i<x ; i++);
	}

// variables:

	u8 Button_On = 1 ;
	u8 button_Off = 0 ;
	u8 Button_Status  ;




// main:
int main(void){

// clock init:

	RCC_InitSysClock();
	RCC_EnableClock(RCC_APB2, RCC_APB2ENR);

// GPIO init:

	MCAL_GPIO_voidsetPinMode(GPIOA, GPIO_PIN10, GPIO_INPUT_PULL_UP_DOWN);
	MCAL_GPIO_voidsetPinMode(GPIOA, GPIO_PIN1, GPIO_OUTPUT_PUSH_PULL_20MHZ);
	MCAL_GPIO_voidsetPinMode(GPIOA, GPIO_PIN3, GPIO_OUTPUT_PUSH_PULL_20MHZ);
	MCAL_GPIO_voidsetPinMode(GPIOA, GPIO_PIN5, GPIO_OUTPUT_PUSH_PULL_20MHZ);
	MCAL_GPIO_voidsetPinMode(GPIOA, GPIO_PIN7, GPIO_OUTPUT_PUSH_PULL_20MHZ);


while(1)
{
	//Get Button status:

	Button_Status = MCAL_GPIO_u8GetPinValue (GPIOA,GPIO_PIN10);
	if(Button_Status == 1)
	{
		MCAL_GPIO_voidsetPinValue(GPIOA,GPIO_PIN1,GPIO_HIGH);
		delay(2500);
		MCAL_GPIO_voidsetPinValue(GPIOA,GPIO_PIN3,GPIO_HIGH);
		delay(2500);
		MCAL_GPIO_voidsetPinValue(GPIOA,GPIO_PIN5,GPIO_HIGH);
		delay(2500);
		MCAL_GPIO_voidsetPinValue(GPIOA,GPIO_PIN7,GPIO_HIGH);
	}
	else
	{
		MCAL_GPIO_voidsetPinValue(GPIOA,GPIO_PIN1,GPIO_LOW);
		delay(2500);
		MCAL_GPIO_voidsetPinValue(GPIOA,GPIO_PIN3,GPIO_LOW);
		delay(2500);
		MCAL_GPIO_voidsetPinValue(GPIOA,GPIO_PIN5,GPIO_LOW);
		delay(2500);
		MCAL_GPIO_voidsetPinValue(GPIOA,GPIO_PIN7,GPIO_LOW);
	}
}
return 0 ;
}
