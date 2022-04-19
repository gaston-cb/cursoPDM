/*
 * API_uart.c
 *
 *  Created on: 2 abr. 2022
 *      Author: gaston
 *
 *
 */
#include <stm32f4xx_hal.h>
#include <stm32f4xx_hal_uart.h>
#include <stm32f4xx_hal_usart.h>
#include <string.h>
#include <uart.h>
//#define ERROR_UART



//static void uartSendString( char *uart_tx) ;

UART_HandleTypeDef uart_handle ;

uint8_t uartInit(uint32_t baud_rate){
	if (baud_rate == 0){
		return 0xFF ;
	}

	uart_handle.Instance 		  = USART3;
	uart_handle.Init.BaudRate     = baud_rate;
	uart_handle.Init.WordLength   = UART_WORDLENGTH_8B;
	uart_handle.Init.StopBits     = UART_STOPBITS_1;
	uart_handle.Init.Parity       = UART_PARITY_NONE ;
	uart_handle.Init.HwFlowCtl    = UART_HWCONTROL_NONE;
	uart_handle.Init.Mode         = UART_MODE_TX_RX;
	uart_handle.Init.OverSampling = UART_OVERSAMPLING_16;
	if (HAL_UART_Init(&uart_handle)){
		return 0xFF ;
	}
	uartSendString("INICIO CORRECTO\r\n") ;
	return 1 ;
	// dejar para futuras versiones . Resuelve la ISR de RX deUART
	//HAL_UART_Receive_IT(&uart_handle, data_rx, 2) ;
	//(&uart_handle, &data_rx, 2) ;
	//HAL_NVIC_SetPriority(USART3_IRQn, 0, 0);
	//HAL_NVIC_EnableIRQ(USART3_IRQn);


}


uint8_t sendSiderealTime(){
	sidereal_t stime ;
	char uart_tx [10] ; //"hh:mm:ss" ;
	uint8_t get_sidereal_time =computeSiderealTime(&stime) ;
	uint8_t response ;
	if (get_sidereal_time ==0xFF){
		//transmitir "error RTC" por puerto serie
		sprintf(uart_tx,"%02d:%02d:%02d",stime.h,stime.m,0) ;
		response = 0xFF ;

	}else if (get_sidereal_time==0x01){
		sprintf(uart_tx,"%02d:%02d:%02d",stime.h,stime.m,0) ;
		response = 0x01 ;
	}


	uartSendString(uart_tx) ;
	return response ;

}

//uint8_t uartSendString(const char *uart_tx)
//static void uartSendString( char *uart_tx)
void uartSendString( char *uart_tx)
{

	HAL_UART_Transmit(&uart_handle,uart_tx, strlen(uart_tx), 500) ;

}
