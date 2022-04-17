/*
 * API_debounce.h
 *
 *  Created on: 26 mar. 2022
 *      Author: gaston
 */

#ifndef API_INC_API_DEBOUNCE_H_
#define API_INC_API_DEBOUNCE_H_
/**
 * @brief Inicializa una FSM para realizar un antirrebotes
 *
 */
void debounceFSM_init();
/**
 * @brief verifica y cambia los estados de la FSM para evitar
 *  	  los rebotes de un pulsador
 *
 */
void debounceFSM_update();
/**
 * @brief verifica si el boton se ha presionado o no
 *
 * @return true-> boton presionado
 * 		  false-> boton no presionado, o lectura del boton presionado
 *
 */
bool_t readKey();



#endif /* API_INC_API_DEBOUNCE_H_ */
