/*****************************************************************************
 *   $Id:: gpio.h 4790 2010-09-03 23:35:38Z nxp21346                        $
 *   Project: NXP LPC11xx software example
 *
 *   Description:
 *     This file contains definition and prototype for GPIO.
 *
 ****************************************************************************
 * Software that is described herein is for illustrative purposes only
 * which provides customers with programming information regarding the
 * products. This software is supplied "AS IS" without any warranties.
 * NXP Semiconductors assumes no responsibility or liability for the
 * use of the software, conveys no license or title under any patent,
 * copyright, or mask work right to the product. NXP Semiconductors
 * reserves the right to make changes in the software without
 * notification. NXP Semiconductors also make no representation or
 * warranty that such application will be suitable for the specified
 * use without further testing or modification.
****************************************************************************/
#ifndef __GPIO_H 
#define __GPIO_H
#if CONFIG_ENABLE_DRIVER_GPIO==1

#define PORT0		0
#define PORT1		1
#define PORT2		2
#define PORT3		3

typedef enum gpio_function {
	GPIO_PIO,
	GPIO_FUNC1,
	GPIO_FUNC2
} gpio_function_t;

static LPC_GPIO_TypeDef (* const LPC_GPIO[4]) = { LPC_GPIO0, LPC_GPIO1, LPC_GPIO2, LPC_GPIO3 };

void PIOINT0_IRQHandler(void);
void PIOINT1_IRQHandler(void);
void PIOINT2_IRQHandler(void);
void PIOINT3_IRQHandler(void);
void GPIO_Init( void );
void GPIO_SetInterrupt( uint32_t portNum, uint32_t bitPosi, uint32_t sense,
		uint32_t single, uint32_t event );

void GPIO_IntEnable( uint32_t portNum, uint32_t bitPosi );
void GPIO_IntDisable( uint32_t portNum, uint32_t bitPosi );
uint32_t GPIO_IntStatus( uint32_t portNum, uint32_t bitPosi );
void GPIO_IntClear( uint32_t portNum, uint32_t bitPosi );
void GPIO_SetValue( uint32_t portNum, uint32_t bitPosi, uint32_t bitVal );
void GPIO_ToggleValue( uint32_t portNum, uint32_t bitPosi);
uint32_t GPIO_GetValue( uint32_t portNum, uint32_t bitPosi);
void GPIO_SetDir( uint32_t portNum, uint32_t bitPosi, uint32_t dir );
void GPIO_SetFunction(uint32_t port, uint32_t bit, uint32_t func);

#endif
#endif /* end __GPIO_H */



/*****************************************************************************
**                            End Of File
******************************************************************************/
