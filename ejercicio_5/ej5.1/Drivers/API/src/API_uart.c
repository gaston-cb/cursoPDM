/*
 * API_uart.c
 *
 *  Created on: 2 abr. 2022
 *      Author: gaston
 */
#include <stm32f4xx_hal.h>
#include <stm32f4xx_hal_uart.h>
#include <stdbool.h>
#include <string.h>
#include "API_uart.h"
#define BAUD_RATE 9600

UART_HandleTypeDef uart_handle ;
uint8_t data_rx[30] ;
bool rx_flag = true ;

bool uartinit(){
	uart_handle.Instance 		  = USART3;
	uart_handle.Init.BaudRate     = BAUD_RATE;
	uart_handle.Init.WordLength   = UART_WORDLENGTH_8B;
	uart_handle.Init.StopBits     = UART_STOPBITS_1;
	uart_handle.Init.Parity       = UART_PARITY_ODD;
	uart_handle.Init.HwFlowCtl    = UART_HWCONTROL_NONE;
	uart_handle.Init.Mode         = UART_MODE_TX_RX;
	uart_handle.Init.OverSampling = UART_OVERSAMPLING_16;
	if (HAL_UART_Init(&uart_handle)){
		return false ;
	}
	HAL_UART_Receive_IT(&uart_handle, data_rx, 30) ;
	return true ;
}

void HAL_UART_RxCpltCallback(){
	rx_flag = true ;
}

void setRx(){
	rx_flag = false ;
}

bool getRx(){

	return rx_flag ;

}

void uartsendString(uint8_t * pstring){

	//HAL_UART_Transmit(&uart_handle,pstring, strlen(pstring), 500) ;
}

void uartSendStringSize(uint8_t * pstring, uint16_t size){

	HAL_UART_Transmit(&uart_handle,pstring, size, 500) ;


}
void uartReceiveStringSize(uint8_t * pstring, uint16_t size)
{

}
