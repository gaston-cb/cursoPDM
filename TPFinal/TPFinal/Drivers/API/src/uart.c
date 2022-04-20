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
#include <stdio.h>
#define SIZE_STRING_UART 40
#define ERROR_UART 0xFF
#define NO_ERROR_UART 0x01


static UART_HandleTypeDef uart_handle ;
static void uartSendString( char *uart_tx) ;


uint8_t uartInit(uint32_t baud_rate){
	if (baud_rate == 0){
		return ERROR_UART ;
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
		return ERROR_UART ;
	}
	uartSendString("INICIO CORRECTO\r\n") ;
	return NO_ERROR_UART ;
	// Se deja comentado el siguiente fragmento de código para versiones futuras
	// Se utiliza como interfaz de comunicación para realizar la depuración, por ejemplo
	// conocer los estados de variables, estado de la FSM, ETC. Se deben añadir a pedido del cliente
	//HAL_UART_Receive_IT(&uart_handle, data_rx, 2) ;
	//(&uart_handle, &data_rx, 2) ;
	//HAL_NVIC_SetPriority(USART3_IRQn, 0, 0);
	//HAL_NVIC_EnableIRQ(USART3_IRQn);

}

/**
 * @brief Se comunica con la API de RTC y le solicita los datos de hora siderea
 * Este dato se realiza un doble check.
 *
 * @return Error de envio de tiempo sidereo a partir del RTC y lo transmite por la UART
 */
uint8_t sendSiderealTime(){
	sidereal_t stime ;
	char uart_tx [SIZE_STRING_UART] ; //"hh:mm:ss" ;
	uint8_t get_sidereal_time =computeSiderealTime(&stime) ;

	uint8_t response ;
	if (get_sidereal_time ==0xFF){
		//transmitir "error RTC" por puerto serie
		sprintf(uart_tx,"ERROR AL OBTENER HORA SIDEREAL \r\n") ;
		response = get_sidereal_time ;

	}else if (get_sidereal_time==0x01){
		sprintf(uart_tx,"%02d:%02d:%02d \r\n",stime.h,stime.m,stime.s) ;
    	response = get_sidereal_time ;
   }

	uartSendString(uart_tx) ;
	return response ;

}

/**
 * @brief Envia un string mediante el puerto serial
 *
 * @param uart_tx string a enviar por el puerto serie usando la UART
 */
static void uartSendString(char *uart_tx){

	HAL_UART_Transmit(&uart_handle,uart_tx, strlen(uart_tx), 500) ;

}
