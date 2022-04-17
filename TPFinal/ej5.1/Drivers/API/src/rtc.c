/**
 *
 * rtc.c
 *
 *  Created on: 16 abr. 2022
 *      Author: gaston
 *
 */
#include "stm32f4xx_hal.h"

#include "stm32f4xx_hal_rtc.h"
#include "stm32f4xx_hal_rtc_ex.h"
#include <stdio.h>
#include "API_uart.h"
#include "rtc.h"



static RTC_HandleTypeDef rtc ;


static void setDayAndHour(void) ;

void rtcInit()
{
	__HAL_RCC_PWR_CLK_ENABLE() ;
	HAL_PWR_EnableBkUpAccess() ;
	__HAL_RCC_RTC_CONFIG(RCC_RTCCLKSOURCE_LSE) ;
	__HAL_RCC_RTC_ENABLE();
	//HAL_PWR_EnableBkUpAccess() ;

	rtc.Instance = RTC;
	rtc.Init.HourFormat = RTC_HOURFORMAT_12;
	rtc.Init.AsynchPrediv = 127;
	rtc.Init.SynchPrediv = 255;
	rtc.Init.OutPut = RTC_OUTPUT_DISABLE;
	rtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
	rtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;

	if (HAL_RTC_Init(&rtc) != HAL_OK)
	{
	    uartsendString("\r\nerrorRTCInit\r\n") ;

	}
	setDayAndHour() ;
	HAL_PWR_DisableBkUpAccess() ;

}


static void setDayAndHour(void)
{

	  RTC_TimeTypeDef sTime = {0};
	  RTC_DateTypeDef sDate = {0};
	  sTime.Hours = 10;
	  sTime.Minutes = 10;
	  sTime.Seconds = 10;
	  sTime.TimeFormat = RTC_HOURFORMAT12_AM;
	  sTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
	  sTime.StoreOperation = RTC_STOREOPERATION_SET;
	  if (HAL_RTC_SetTime(&rtc, &sTime, RTC_FORMAT_BIN) != HAL_OK)
	  {
	     uartsendString("\r\nerror set Time\r\n") ;
	   }
	   sDate.WeekDay = RTC_WEEKDAY_MONDAY;
	   sDate.Month = RTC_MONTH_JANUARY;
	   sDate.Date = 1;
	   sDate.Year = 50;

	   if (HAL_RTC_SetDate(&rtc, &sDate, RTC_FORMAT_BIN) != HAL_OK)
	   {
		 uartsendString("error set Date\r\n") ;
	   }
	   /** Enable the reference Clock input
	   */
	   if (HAL_RTCEx_SetRefClock(&rtc) != HAL_OK)
	   {
		   uartsendString("SET REF ERROR\r\n") ;
	   }
	   /* USER CODE BEGIN RTC_Init 2 */
	  // HAL_RTCEx_BKUPWrite(&rtc,  RTC_BKP_DR1, 0x32F2);
	   /* USER CODE END RTC_Init 2 */

}


//uint8_t aShowTime[50] = {0};
//uint8_t aShowDate[50] = {0};
void printRTCParameters(){
	uint8_t aShowTime[50] = {0};
	uint8_t aShowDate[50] = {0};
	static RTC_DateTypeDef 	sdatestructureget ;;
	static RTC_TimeTypeDef stimestructureget ;
	/* USER CODE END WHILE */
	if (HAL_RTC_GetTime(&rtc, &stimestructureget, RTC_FORMAT_BIN) != HAL_OK)
	{
		uartsendString("error get time \r\n") ;
	}else{
		if(HAL_RTC_GetDate(&rtc, &sdatestructureget, RTC_FORMAT_BIN) == HAL_OK)
		{
			sprintf((char *)aShowDate, "lh: %2d:%2d:%2d  ", stimestructureget.Hours, stimestructureget.Minutes, stimestructureget.Seconds);
	    	sprintf((char *)aShowTime, "fecha: %2d-%2d-%2d\r\n", sdatestructureget.Month, sdatestructureget.Date, 2000 + sdatestructureget.Year);
	    	//HAL_UART_Transmit(&huart3, aShowTime, 51, 500);;
	    	uartsendString(aShowDate) ;
	    	uartsendString(aShowTime) ;
	    }
	}
}

