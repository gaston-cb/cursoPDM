/*
 * API_delay.c
 *
 *  Created on: 19 mar. 2022
 *      Author: gaston
 */
#include <handle_FSM.h>
#include "stm32f4xx_hal.h"
#include "stm32f4xx_nucleo_144.h"
#include <rtc.h>
#include <debounce.h>
#include <uart.h>

//PC-13 PORT_BUTTON DE LA PLACA -- reconfigurar para leer por alto (tiene rpulldown) el pcb
#define LETTER_PORT 'A'
#define NUMBER_PORT 15
// GPIO_PIN_15

typedef enum{
 RTCCONFIG ,
 WAITBUTTON,
 SENDSERIALST
}handle_FSM ;

static handle_FSM FSM ; //FIXME: cambiar nombre por un nombre mas representativo

void initFSM(void){
	FSM = RTCCONFIG ;
}


void FSM_loop(){
	switch(FSM){
	case RTCCONFIG:
		FSM = WAITBUTTON ;
		rtcInit() ;
		initFSMButton('a', 15) ;
		uartSendString("WAITBUTTON") ;
		break ;
	case WAITBUTTON:
		//uartSendString("updateWAIT\r\n") ;

		debounceFSM_update() ;
		if (getPressButton() == true){
			FSM = SENDSERIALST ;
			uartSendString("cambiowait to st\r\n") ;

		}
		break ;
	case SENDSERIALST:
		sendSiderealTime() ;
		// CODE FOR SEND UART
		uartSendString("sendserialst\r\n") ;
		FSM = WAITBUTTON ;
		break ;
	default:

		FSM = RTCCONFIG ;
		break  ;
	}

}
