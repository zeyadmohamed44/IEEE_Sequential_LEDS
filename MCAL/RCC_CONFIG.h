/*
* Author: Zeyad mohamed
*Date: 29/8/2024
* version: V01
*
*/

#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/*      Choose clock source            */
/* Options:     RCC_CLKSRC_HSE_CRYSTAL */
/*              RCC_CLKSRC_HSE_RC      */
/*              RCC_CLKSRC_HSI         */
/*              RCC_CLKSRC_PLL         */

#define RCC_CLK_SRC    RCC_CLKSRC_HSE_CRYSTAL


/*      Choose PLL input               */
/* Options:     RCC_PLL_HSE_DIV_2      */
/*              RCC_PLL_HSI_DIV_2      */
/*              RCC_PLL_HSE            */

/* Note: Select value only if you choose PLL to be your clock source*/

#if RCC_CLK_SRC == RCC_CLKSRC_PLL
#define RCC_PLL_INPUT    RCC_PLL_HSE
#endif



#endif
