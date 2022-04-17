/*
 * API_uart.c
 *
 *  Created on: 2 abr. 2022
 *      Author: gaston
 */
#include <stm32f4xx_hal.h>
#include <stm32f4xx_hal_uart.h>
#include <stm32f4xx_hal_usart.h>

#include <string.h>
#include <uart.h>

static void uartSendString( char *uart_tx) ;

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
	return 1 ;
	// dejar para futuras versiones !
	//HAL_UART_Receive_IT(&uart_handle, data_rx, 2) ;
	//(&uart_handle, &data_rx, 2) ;
	//HAL_NVIC_SetPriority(USART3_IRQn, 0, 0);
	//HAL_NVIC_EnableIRQ(USART3_IRQn);


}

/*
uint8_t sendSiderealTime(sidereal_t serial_st){
	return 1 ;
}
*/
//uint8_t uartSendString(const char *uart_tx)
static void uartSendString( char *uart_tx)
{

	HAL_UART_Transmit(&uart_handle,uart_tx, strlen(uart_tx), 500) ;

}
