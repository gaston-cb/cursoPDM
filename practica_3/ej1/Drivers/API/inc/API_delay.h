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
typedef struct{
   tick_t startTime;
   tick_t duration;
   bool_t running;
} delay_t;

/**
 * @brief
 *
 * @param delay
 * @param duration
 */
void delayInit( delay_t * delay, tick_t duration );
/**
 * @brief
 *
 * @param delay
 * @return valor booleano
 */
bool_t delayRead( delay_t * delay );
/**
 * @brief
 *
 * @param delay
 * @param duration
 */
void delayWrite( delay_t * delay, tick_t duration );

