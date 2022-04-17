/*
 * API_uart.c
 *
 *  Created on: 2 abr. 2022
 *      Author: gaston
 */
#include <stm32f4xx_hal.h>
#include <stm32f4xx_hal_uart.h>
#include <stm32f4xx_hal_usart.h>

#include <stdbool.h>
#include <string.h>
#include "API_uart.h"
#define BAUD_RATE 9600

UART_HandleTypeDef uart_handle ;
uint8_t data_rx[2] ;
volatile bool rx_flag ;
bool uartinit(){
	rx_flag = false ;
	uint16_t size = 2 ;

	uart_handle.Instance 		  = USART3;
	uart_handle.Init.BaudRate     = BAUD_RATE;
	uart_handle.Init.WordLength   = UART_WORDLENGTH_8B;
	uart_handle.Init.StopBits     = UART_STOPBITS_1;
	uart_handle.Init.Parity       = UART_PARITY_NONE ;
	uart_handle.Init.HwFlowCtl    = UART_HWCONTROL_NONE;
	uart_handle.Init.Mode         = UART_MODE_TX_RX;
	uart_handle.Init.OverSampling = UART_OVERSAMPLING_16;
	if (HAL_UART_Init(&uart_handle)){
		return false ;
	}
	HAL_UART_Transmit(&uart_handle, "inicio correcto", 30, 500) ;
	//HAL_UART_Receive_IT(&uart_handle, data_rx, 2) ;
	//(&uart_handle, &data_rx, 2) ;
	//HAL_NVIC_SetPriority(USART3_IRQn, 0, 0);
	//HAL_NVIC_EnableIRQ(USART3_IRQn);


	return true ;
}


void USART3_IRQHandler(void)
{
  HAL_UART_IRQHandler(&uart_handle);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){

	rx_flag = true ;
	//HAL_UART_Transmit(&uart_handle, "si", 2, 200) ;
	//HAL_NVIC_EnableIRQ(USART3_IRQn);
	HAL_UART_Receive_IT(&uart_handle, data_rx, 2) ;

}



void setRx(){
	rx_flag = false ;
}

bool getRx(){

	return rx_flag ;

}

void uartsendString(uint8_t * pstring){

	HAL_UART_Transmit(&uart_handle,pstring, strlen((char *)pstring), 500) ;

}

void uartSendStringSize(uint8_t * pstring, uint16_t size){

	HAL_UART_Transmit(&uart_handle,pstring, size, 500) ;
	//HAL_UART_Receive_IT(&uart_handle, data_rx, 1) ;


}
void uartReceiveStringSize(uint8_t * pstring, uint16_t size)
{

}
