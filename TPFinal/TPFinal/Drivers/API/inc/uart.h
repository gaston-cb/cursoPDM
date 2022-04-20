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



uint8_t uartInit(uint32_t baud_rate) ;
uint8_t sendSiderealTime();
#endif /* API_INC_API_UART_C_ */
