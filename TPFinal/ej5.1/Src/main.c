 /**
  ******************************************************************************
  * @file    main.c
  * @author  Gastón Valdez
  * @brief   Trabajo final para la catedra de Programación de microcontroladores del
  * 		 la FIUBA
  * 		 Cálculo de hora siderea en base a hora local usando el RTC de la
  * 		 placa nucleo 144
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_hal.h"
#include "rtc.h"
#include <uart.h>

/** @addtogroup STM32F4xx_HAL_Examples
  * @{
  */

/** @addtogroup UART_Printf
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/



/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/



/* Private function prototypes -----------------------------------------------*/
static void SystemClock_Config(void);
static void Error_Handler(void);
void selectPortButton(char p, uint8_t num_port);
uint32_t selectGPIOport(uint8_t numport) ;
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
	/* STM32F4xx HAL library initialization:
       - Configure the Flash prefetch
       - Systick timer is configured by default as source of time base, but user 
         can eventually implement his proper time base source (a general purpose 
         timer for example or other time source), keeping in mind that Time base 
         duration should be kept 1ms since PPP_TIMEOUT_VALUEs are defined and 
         handled in milliseconds basis.
       - Set NVIC Group Priority to 4
       - Low Level Initialization
     */
	HAL_Init();

	/* Configure the system clock to 180 MHz */
	SystemClock_Config();
	rtcInit()  ;
    /* Infinite loop */

	while (1)
    {
		//GPIO_PinState
    }

}



/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow : 
  *            System Clock source            = PLL (HSE)
  *            SYSCLK(Hz)                     = 180000000
  *            HCLK(Hz)                       = 180000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 4
  *            APB2 Prescaler                 = 2
  *            HSE Frequency(Hz)              = 8000000
  *            PLL_M                          = 8
  *            PLL_N                          = 360
  *            PLL_P                          = 2
  *            PLL_Q                          = 7
  *            PLL_R                          = 2
  *            VDD(V)                         = 3.3
  *            Main regulator output voltage  = Scale1 mode
  *            Flash Latency(WS)              = 5
  * @param  None
  * @retval None
  */
static void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct = {0};
	RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

	/** Configure the main internal regulator output voltage
	*/
	__HAL_RCC_PWR_CLK_ENABLE();
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
	  /** Initializes the RCC Oscillators according to the specified parameters
	  * in the RCC_OscInitTypeDef structure.
	  */
	  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE|RCC_OSCILLATORTYPE_LSE;
	  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
	  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
	  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	  RCC_OscInitStruct.PLL.PLLM = 8;
	  RCC_OscInitStruct.PLL.PLLN = 360;
	  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	  RCC_OscInitStruct.PLL.PLLQ = 7;
	  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  /** Activate the Over-Drive mode
	  */
	  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
	  {
	    Error_Handler();
	  }
	  /** Initializes the CPU, AHB and APB buses clocks
	  */
	  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
	                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
	  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
	  {
	    Error_Handler();
	  }
}
/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
static void Error_Handler(void)
{
  /* Turn LED2 on */
  BSP_LED_Init(LED2) ;
  BSP_LED_On(LED2);
  while (1)
  {
	  BSP_LED_Toggle(LED2);
	  HAL_Delay(100) ;
  }
}


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

uint32_t selectGPIOport(uint8_t numport){
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



#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
