/*
 * API_delay.c
 *
 *  Created on: 19 mar. 2022
 *      Author: gaston
 */
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "stm32f4xx_hal.h"
#include "API_delay.h"


void delayInit( delay_t * delay, tick_t duration )
{

	// si no hay puntero, o la duración es cero, no configura el clock
	if (delay == NULL || duration == 0){
		return ;
	}
	delay->duration = duration ;

}


/*
 * delay_t campo running false-> lo cambia a true, y toma el valor del system tick.En este caos
 * 								la rta es false, porque recien inicia
 * delay_t campo running true -> realiza la cuenta system_tick - startTime: si es mayor o igual al campo duration, responde true
 * 								en caso contrario false
 * */
bool_t delayRead( delay_t * delay )
{
	bool_t response = false ; // respuesta de la función readDelay
	// no se considera el caso de duration= 0 , porque no podría ocurrir
	if (delay == NULL){
		return response ;
	}
	// si el puntero no es nulo
	// como recien inicia, entonces la respuesta es false
	if (delay->running == false){
		delay->startTime = (tick_t )HAL_GetTick();
		delay->running = true ;
		response = false ;
	}else{

		response = ((tick_t) HAL_GetTick() - delay->startTime)>= delay->duration?true:false ;
		if (response == true){
			delay->startTime = (tick_t )HAL_GetTick() ;
		}
	}

	return response ;


}

/*
 * tick_t duration: cambia la duración del retardo
 * delay_t delay: clock dek sistema que se debe cambiar la duración */
void delayWrite( delay_t * delay, tick_t duration )
{

	// si la duración es cero o no hay puntero asignado, retorna la función

	if (delay == NULL || duration ==  0){
		return ;
	}
	if (delay->duration != duration){
		delay->duration = duration ;
	}


}




