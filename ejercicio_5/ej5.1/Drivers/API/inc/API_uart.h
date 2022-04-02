/*
 * API_uart.c
 *
 *  Created on: 2 abr. 2022
 *      Author: gaston
 */

#ifndef API_INC_API_UART_C_
#define API_INC_API_UART_C_
#include <stdbool.h>



bool uartinit();
void uartsendString(uint8_t * pstring);
void uartSendStringSize(uint8_t * pstring, uint16_t size);
void uartReceiveStringSize(uint8_t * pstring, uint16_t size);
bool getRx() ;
void setRx() ;
#endif /* API_INC_API_UART_C_ */
