#include "E:\IEEE  workshop\system\LIB\STD_TYPES.h"
#include "E:\IEEE  workshop\system\LIB\BIT_MATH.h"

#include "E:\IEEE  workshop\system\MCAL\RCC\RCC_INTERFACE.h"
#include "E:\IEEE  workshop\system\MCAL\RCC\RCC_PRIVATE.h"
#include "E:\IEEE  workshop\system\MCAL\RCC\RCC_CONFIG.h"


Std_ReturnType RCC_InitSysClock(void)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    #if RCC_CLK_SRC == RCC_CLKSRC_HSE_CRYSTAL
        SET_BIT(RCC_CR, RCC_CR_HSEON);
        CLR_BIT(RCC_CR, RCC_CR_HSEBYP);

        while(!GET_BIT(RCC_CR, RCC_CR_HSERDY));
        RCC_CFGR = 0x00000001;

        Local_FunctionStatus = E_OK;

    #elif RCC_CLK_SRC == RCC_CLKSRC_HSE_RC
        SET_BIT(RCC_CR, RCC_CR_HSEON);
        SET_BIT(RCC_CR, RCC_CR_HSEBYP);

        while(!GET_BIT(RCC_CR, RCC_CR_HSERDY));
        RCC_CFGR = 0x00000001;

        Local_FunctionStatus = E_OK;

    #elif RCC_CLK_SRC == RCC_CLKSRC_HSI
        SET_BIT(RCC_CR, RCC_CR_HSION);

        while(!GET_BIT(RCC_CR, RCC_CR_HSIRDY));
        RCC_CFGR = 0x00000000;

        Local_FunctionStatus = E_OK;

    #elif RCC_CLK_SRC == RCC_CLKSRC_PLL

        #if RCC_PLL_INPUT == RCC_PLL_HSE

        #elif RCC_PLL_INPUT == RCC_PLL_HSE_DIV_2

        #elif RCC_PLL_INPUT == RCC_PLL_HSI_DIV_2

        #endif

    #endif

    return Local_FunctionStatus;

}



Std_ReturnType RCC_EnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    if (Copy_u8PerId <= 31)
    {
        switch (Copy_u8BusId)
        {
            case RCC_AHB :
                SET_BIT(RCC_AHBENR, Copy_u8PerId);
                Local_FunctionStatus = E_OK;
                break;

            case RCC_APB1:
                SET_BIT(RCC_APB1ENR, Copy_u8PerId);
                Local_FunctionStatus = E_OK;
                break;

            case RCC_APB2:
                SET_BIT(RCC_APB2ENR, Copy_u8PerId);
                Local_FunctionStatus = E_OK;
                break;

            default:
                Local_FunctionStatus = E_NOT_OK;
                break;
        }


    }

    return Local_FunctionStatus;

}



Std_ReturnType RCC_DisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    if (Copy_u8PerId <= 31)
    {
        switch (Copy_u8BusId)
        {
            case RCC_AHB :
                CLR_BIT(RCC_AHBENR, Copy_u8PerId);
                Local_FunctionStatus = E_OK;
                break;

            case RCC_APB1:
                CLR_BIT(RCC_APB1ENR, Copy_u8PerId);
                Local_FunctionStatus = E_OK;
                break;

            case RCC_APB2:
                CLR_BIT(RCC_APB2ENR, Copy_u8PerId);
                Local_FunctionStatus = E_OK;
                break;

            default:
                Local_FunctionStatus = E_NOT_OK;
                break;

        }


    }

    return Local_FunctionStatus;

}
