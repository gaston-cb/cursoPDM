/*
 * API_delay.h
 *
 *  Created on: 19 mar. 2022
 *      Author: gaston
 */
#ifndef API_INC_API_DEBOUNCE_H_
#define API_INC_API_DEBOUNCE_H_

#include <stdbool.h>
#include <stdint.h>

// inicializa la MEF del curso de PDM.
void initFSM(void) ;

// bucle que administra la máquina de estados. Debe incluirse en la función while(1){}
void FSM_loop() ;


#endif
