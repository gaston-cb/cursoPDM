/*
 * API_debounce.c
 *
 *  Created on: 26 mar. 2022
 *      Author: gaston
 */
#include <stdbool.h>
#include "API_delay.h"
#include "stm32f4xx_hal.h"  		/* <- HAL include */
#include "stm32f4xx_nucleo_144.h" 	/* <- BSP include */
#define  STATE_BUTTON_PRESS 0
#define  STATE_BUTTON_NO_PRESS 1
#define  TIME_FALLING_READ 40 //time unit is ms -> TIME USING BASSED IN EXPERIENCE

static void buttonPressed() ;
static void buttonReleased() ;
typedef enum{
	BUTTON_UP,
	BUTTON_FALLING,
	BUTTON_DOWN,
	BUTTON_RAISING
}debounceState_t ;


bool_t button_key = false ;
debounceState_t state_button ;
delay_t time_read_state_fsm ;


/// debe cargar el estado inicial
void debounceFSM_init(){
	state_button = BUTTON_UP ;
}


/**
 * @brief
 * FSM QUE REALIZA UN SISTEMA ANTIREBOTES DE UN PULSADOR
 * Se implementa una máquina de estados de la siguientes estados
 * Estado inicial: BUTTON_UP
 * BUTTON_UP <-> BUTTON_FALLING <->BUTTON_DOWN <-> BUTTON_RAISING ->BUTTON_UP
 *
 */
void debounceFSM_update(){
	// Devuelve 0 sin presionar, 1  con boton presionado


	switch(state_button)
	{
		case BUTTON_UP:
			if (BSP_PB_GetState(BUTTON_USER) == STATE_BUTTON_PRESS)
			{
				state_button = BUTTON_FALLING ;
				delayInit(&time_read_state_fsm,TIME_FALLING_READ) ;
				delayRead(&time_read_state_fsm) ; // init the timer count
			}
			break ;
		case BUTTON_FALLING:
			//espera 40 ms y lee el estado del boton
			if (delayRead(&time_read_state_fsm)==true)
			{
				time_read_state_fsm.running = false ;
				if (BSP_PB_GetState(BUTTON_USER) == STATE_BUTTON_PRESS)
				{
					buttonPressed() ;
				}else{
					state_button = BUTTON_UP ;
				}
			}
			break ;
		case BUTTON_DOWN:
			if (BSP_PB_GetState(BUTTON_USER) == STATE_BUTTON_NO_PRESS)
			{
				state_button = BUTTON_RAISING ;
				delayInit(&time_read_state_fsm,TIME_FALLING_READ) ;
				delayRead(&time_read_state_fsm) ; // init the timer count
			}
			break ;
		case BUTTON_RAISING:
			if (delayRead(&time_read_state_fsm)==true)
			{
				if (BSP_PB_GetState(BUTTON_USER) == STATE_BUTTON_NO_PRESS)
				{
					state_button = BUTTON_UP ;
					time_read_state_fsm.running = false ;
					buttonReleased();
				}else state_button = BUTTON_DOWN ;
			}
			break ;
		default:
			debounceFSM_init() ;
		break ;

	}

}


/**
 * @brief
 * Evento al presionar el pulsador, idealmente debe recibir un puntero a funcion
 * pone button_key en true cuando se detecta un flanco descendente !
 */

static void buttonPressed() {
	state_button = BUTTON_DOWN;
	button_key = true ;


}

/**
 * @brief evento que ocurre al realizar el paso entre RAISING y UP
 *
 */
static void buttonReleased(){
	state_button = BUTTON_UP;
	button_key = false  ;

}
/**
 * @brief Si hay flanco descendente, se cambia de true a false, para detectar una sola
 * 		  vez la pulsación de la tecla
 *
 * @return true: flanco descendente
 */
bool_t readKey(){
//	button_key = false ??
	bool_t response = button_key ;
	if (button_key == true ){
		button_key = false ;
	}
	return response ;
}
