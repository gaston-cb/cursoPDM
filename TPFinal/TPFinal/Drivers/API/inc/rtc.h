/*
 * rtc.h
 *
 *  Created on: 16 abr. 2022
 *      Author: gaston
 */

#ifndef API_INC_RTC_H_
#define API_INC_RTC_H_


/**
 * @brief tipo de dato destinado a almacenar la hora siderea.
 *
 */
typedef struct {
	uint8_t h;
	uint8_t m;
	uint8_t s;
}sidereal_t ;

void rtcInit(void ) ;
uint8_t computeSiderealTime(sidereal_t *sidereal_time) ;


#endif /* API_INC_RTC_H_ */
