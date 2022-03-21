/*
 * API_delay.h
 *
 *  Created on: 19 mar. 2022
 *      Author: gaston
 */

#include <stdbool.h>
#include <stdint.h>
typedef uint32_t tick_t;
typedef bool bool_t;
/**
 * @brief Estructura de datos para manejo de retardos no bloqueantes, o
 * 		  control de tiempos.
 *
 */
typedef struct{
   tick_t startTime;
   tick_t duration;
   bool_t running;
} delay_t;

/**
 * @brief Configura un tiempo de duración del tiempo para un clock del sistema pero
 * 		  no lo enciende, es decir, no lo pone a correr.
 *
 * @param delay puntero a un clock del sistema de retardos no bloqueantes
 * @param duration: duración del retardo en este sistema.
 */
void delayInit( delay_t * delay, tick_t duration );


/**
 * @brief si el campo running es false lo cambia a true
 * .En este caso la rta es false, porque recien inicia
 *
 * @param delay: puntero a estructura del tipo delay_t, definida para encapsular
 * 		  el tiempo de uso de un retardo no bloqueante.
 * @return  si el campo running es false lo cambia a true .En este caso la rta es false, porque recien inicia
 *			si el campo running es true -> realiza la cuenta system_tick - startTime: si es mayor o igual al campo duration, responde true
 * 			en caso contrario false
 */
bool_t delayRead( delay_t * delay );




/**
 * @brief toma un puntero al clock, y le cambia la duración, en caso que sea distina
 * 		  de la que tiene, o sea un puntero nulo.
 *
 * @param delay clock del sistema que se debe cambiar la duracuion
 * @param duration: cambia la duraciòn del retardo
 */
void delayWrite( delay_t * delay, tick_t duration );

