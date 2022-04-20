/*
 * API_debounce.h
 *
 *  Created on: 26 mar. 2022
 *      Author: gaston
 */

#ifndef API_INC_DEBOUNCE_H_
#define API_INC_DEBOUNCE_H_
#include <stdbool.h>



void initFSMButton(char p, uint8_t num_port)  ;
void debounceFSM_update() ;
bool getPressButton(void );

#endif /* API_INC_DEBOUNCE_H_ */
