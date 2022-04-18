/*
 * API_debounce.c
 *
 *  Created on: 26 mar. 2022
 *      Author: gaston
 */
#include <stdint.h>
#include "stm32f4xx_hal.h"
#include "stm32f4xx_nucleo_144.h"
#include <debounce.h>


static uint32_t selectGPIOport(uint8_t numport);

void selectPortButton(char p, uint8_t num_port){

	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT ;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Pin = selectGPIOport(num_port);
	// if port== 0 - port0 , port == 1 , port1 ....


	switch(p){
	case 'a':
	case 'A':
    	__HAL_RCC_GPIOA_CLK_ENABLE();
    	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
    	break ;
	case 'b':
	case 'B':
		__HAL_RCC_GPIOB_CLK_ENABLE();
    	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

		break ;
	case 'c':
	case 'C':
		__HAL_RCC_GPIOC_CLK_ENABLE();
    	HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

		break ;
	case 'd':
	case 'D':
		__HAL_RCC_GPIOD_CLK_ENABLE();
    	HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

		break ;
	case 'e':
	case 'E':
		__HAL_RCC_GPIOE_CLK_ENABLE();
    	HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

		break ;
	case 'f':
	case 'F':
		__HAL_RCC_GPIOF_CLK_ENABLE();
    	HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

		break ;
	case 'g':
	case 'G':
		__HAL_RCC_GPIOG_CLK_ENABLE();
    	HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

		break ;
	case 'h':
	case 'H':
		__HAL_RCC_GPIOH_CLK_ENABLE();
    	HAL_GPIO_Init(GPIOH, &GPIO_InitStruct);

		break ;
	case 'i':
	case 'I':
		__HAL_RCC_GPIOI_CLK_ENABLE();
    	HAL_GPIO_Init(GPIOI, &GPIO_InitStruct);

		break ;
	case 'j':
	case 'J':
		__HAL_RCC_GPIOJ_CLK_ENABLE();
    	HAL_GPIO_Init(GPIOJ, &GPIO_InitStruct);

		break ;
	case 'k':
	case 'K':
		__HAL_RCC_GPIOK_CLK_ENABLE();
    	HAL_GPIO_Init(GPIOK, &GPIO_InitStruct);

		break ;
	default:
		//management of error
		break ;
	}

}

static uint32_t selectGPIOport(uint8_t numport){
	uint32_t responsePortNumber ;
	switch(numport){
	case 0:
		responsePortNumber = GPIO_PIN_0 ;
		break ;
	case 1:
		responsePortNumber = GPIO_PIN_1 ;
		break ;
	case 2:
		responsePortNumber = GPIO_PIN_2 ;
		break ;
	case 3:
		responsePortNumber = GPIO_PIN_3 ;
		break ;
	case 4:
		responsePortNumber = GPIO_PIN_4 ;
		break ;
	case 5:
		responsePortNumber = GPIO_PIN_5 ;
		break ;
	case 6:
		responsePortNumber = GPIO_PIN_6 ;
		break ;
	case 7:
		responsePortNumber = GPIO_PIN_7 ;
		break ;
	case 8:
		responsePortNumber = GPIO_PIN_8 ;
		break ;
	case 9:
		responsePortNumber = GPIO_PIN_9 ;
		break ;
	case 10:
		responsePortNumber = GPIO_PIN_10 ;
		break ;
	case 11:
		responsePortNumber = GPIO_PIN_11 ;
		break ;
	case 12:
		responsePortNumber = GPIO_PIN_12 ;
		break ;
	case 13:
		responsePortNumber = GPIO_PIN_13;
		break ;
	case 14:
		responsePortNumber = GPIO_PIN_14 ;
		break ;
	case 15:
		responsePortNumber = GPIO_PIN_14 ;
		break ;
	default:
		responsePortNumber = -1 ;
		break ;
	}
	return responsePortNumber ;

}
