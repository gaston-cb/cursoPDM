/*
 * API_uart.c
 *
 *  Created on: 2 abr. 2022
 *      Author: gaston
 */

#ifndef API_INC_API_UART_C_
#define API_INC_API_UART_C_
#include <stdint.h>
#include <rtc.h>


/**
 * @brief Configura los parámetros iniciales del periferico UART
 *
 * @param baud_rate: configura la velocidad de transmisión del periferico UART de la placa nucleo
 * @return: 0xFF ERROR
 * 			0x01 inicio correcto
 */
uint8_t uartInit(uint32_t baud_rate) ;
// Calcula el tiempo sidereo a partir de la hora que brinda el dispositivo RTC, y luego la envia
// utilizando el protocolo UART
uint8_t sendSiderealTime();
#endif /* API_INC_API_UART_C_ */
