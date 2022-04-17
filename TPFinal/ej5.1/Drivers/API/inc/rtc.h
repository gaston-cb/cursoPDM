/*
 * rtc.h
 *
 *  Created on: 16 abr. 2022
 *      Author: gaston
 */

#ifndef API_INC_RTC_H_
#define API_INC_RTC_H_

typedef struct {
	uint8_t h;
	uint8_t m;
	uint8_t s;
}sidereal_t ;

void rtcInit(void ) ;
void printRTCParameters() ;
uint8_t computeSiderealTime(sidereal_t *sidereal_time) ;


#endif /* API_INC_RTC_H_ */
