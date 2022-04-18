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
//PC-13 PORT_BUTTON DE LA PLACA
#define LETTER_PORT 'C'
#define NUMBER_PORT 13
#define GPIOx GPIO ## C
#define GPIO_ GPIO ## C


typedef enum{
 RTCCONFIG ,
 WAITBUTTON,
 SENDSERIALST
}handle_FSM ;

static handle_FSM FSM ; //FIXME: cambiar nombre por un nombre mas representativo

void initFSM(void){
	FSM = RTCCONFIG ;
	selectPortButton('c', 13) ;
}


void FSM_loop(){
	switch(FSM){
	case RTCCONFIG:
		FSM = WAITBUTTON ;
		rtcInit() ;
		break ;
	case WAITBUTTON:

		if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_RESET){
			HAL_Delay(10) ;
			BSP_LED_Toggle(LED1) ;
		}
		break ;
	case SENDSERIALST:
		FSM = WAITBUTTON ;
		break ;
	default:
		FSM = RTCCONFIG ;
		break  ;
	}

}
