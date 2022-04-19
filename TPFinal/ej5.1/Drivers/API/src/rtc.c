/**
 *
 * rtc.c
 *
 *  Created on: 16 abr. 2022
 *      Author: gaston
 *
 */
#include "stm32f4xx_hal.h"
#include "stm32f4xx_nucleo_144.h"
#include "stm32f4xx_hal_rtc.h"
#include "stm32f4xx_hal_rtc_ex.h"
#include "math.h"
#include <stdio.h>
#include <uart.h>
#include "rtc.h"
// Constantes para el cálculo de la hora sidereal usando el algoritmo del
// constantes para calculo de día juliano y centuras julianas
#define K1 367.0
#define K2 275.0
#define K3 9.0
#define K4 1721013.5
#define K5 7.0/4.0 ;
#define HOURS_PER_DAY 24.0
#define J200_UT 2451545
#define CENTURIAS_JULIANAS 36525
// constantes para el cálculo de la hora siderea
#define KS1 100.4606184
#define KS2 36000.7700
#define KS3 0.000387933
#define KS4 -2.583E-8

#define UTC_ARGENTINA -3
#define ERROR_RTC_DATE 0x03
#define ERROR_RTC_TIME 0x02
#define NO_ERROR_GET_RTC 0x01
#define ERROR_SIDEREAL 0xFF
#define NO_ERROR_SIDEREAL 0x01

typedef struct {
	uint16_t year;
	uint8_t month;
	uint8_t day  ;
	uint8_t hour	 ;
	uint8_t minute    ;
	uint8_t second    ;
	uint8_t error ;
} fecha_t ;


static RTC_HandleTypeDef rtc ;

static fecha_t getDateTime() ;
static void setDayAndHour(void) ;

void rtcInit()
{
	BSP_LED_Init(LED1) ;
	BSP_LED_Init(LED2) ;
	// HABILITA EL DOMINIO DE BACKUP PARA QUE EL SISTEMA RTC PUEDA SER
	// USADO.
	__HAL_RCC_PWR_CLK_ENABLE() ;
	HAL_PWR_EnableBkUpAccess() ;
	__HAL_RCC_RTC_CONFIG(RCC_RTCCLKSOURCE_LSE) ;
	__HAL_RCC_RTC_ENABLE();
	rtc.Instance = RTC;
	rtc.Init.HourFormat = RTC_HOURFORMAT_24;
	rtc.Init.AsynchPrediv = 127;
	rtc.Init.SynchPrediv = 255;
	rtc.Init.OutPut = RTC_OUTPUT_DISABLE;
	rtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
	rtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;
	// verifica si el RTC se inicia correctamente
	if (HAL_RTC_Init(&rtc) != HAL_OK)
	{
		BSP_LED_On(LED2) ;

	}

	setDayAndHour() ;
	BSP_LED_On(LED1) ;

}


/**
 * @brief: Configura la hora del RTC a partir de la hora de compilación del programa
 * Se usan las macros __TIME__ y __DATE__
 *
 *
 */
static void setDayAndHour(void)
{

	  RTC_TimeTypeDef sTime = {0};
	  RTC_DateTypeDef sDate = {0};
	  // Se obtiene la hora de compilación y se carga como valor inicial en el RTC.
	  // Dado que __TIME__[0] ... son variables de tipo char, se le resta 0x30 para obtener
	  // el entero correspondiente.
	  sTime.Hours = (__TIME__[0] - 0x30)*10 + __TIME__[1] - 0x30 ;
	  sTime.Minutes = (__TIME__[3] - 0x30)*10+ __TIME__[4] - 0x30 ;
	  sTime.Seconds = 10;
	  sTime.TimeFormat = RTC_HOURFORMAT_24;
	  sTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
	  sTime.StoreOperation = RTC_STOREOPERATION_SET; // DEPRECATED ! ??
	  if (HAL_RTC_SetTime(&rtc, &sTime, RTC_FORMAT_BIN) != HAL_OK)
	  {
	     //uartSendString("\r\nerror set Time\r\n") ;
	   }
	   // FECHA EN FORMATO J2000: (1° de enero del año 2000, 12:00:00 GMT)
	   sDate.WeekDay = RTC_WEEKDAY_MONDAY;
	   sDate.Month = RTC_MONTH_JANUARY;
	   sDate.Date = 1;
	   sDate.Year = 50;

	   if (HAL_RTC_SetDate(&rtc, &sDate, RTC_FORMAT_BIN) != HAL_OK)
	   {
	   }
	   /** Enable the reference Clock input
	   */
	   if (HAL_RTCEx_SetRefClock(&rtc) != HAL_OK)
	   {
	   }
	   /* USER CODE BEGIN RTC_Init 2 */
	   // HAL_RTCEx_BKUPWrite(&rtc,  RTC_BKP_DR1, 0x32F2); // HABILITA EL REGISTRO DE GUARDADO
	   /* USER CODE END RTC_Init 2 */

}


/**
 * @brief Calcula la hora siderea a partir de la hora local utilizando el algoritmo de
 * 		  fulanito (http://...)
 *
 * @param sidereal_time: Parámetro donde se va a cargar la hora siderea calculada. En caso de error
 * 		  al realizar el cálculo se carga un parámetro NULL
 * @return Retorna si se ha realizado o no correctamente el cálculo de la hora siderea
 */
uint8_t computeSiderealTime(sidereal_t *sidereal_time){
	fecha_t sd_time = getDateTime() ;
	uint8_t error ;
	uint8_t hs,ms,ss ;
	const float multiplicador_term_negativo = (7.0/4.0) ;
	// j0 calcula el número de dias julianos
	float j0,fract_day,sid_time,jul_cent ; // dia juliano hasta las 12:00:00. JD fraccion de dia para completar el día
	float negative_term ;
	// Error de lectura en día o fecha en el RTC
	if (sd_time.error == ERROR_RTC_DATE ||  sd_time.error == ERROR_RTC_TIME)
	{
		sidereal_time = NULL  ;
		error = ERROR_SIDEREAL ;
	}else{
		//
		// (float)(int): primero se realiza  (int) para cumplir con el algoritmo
		// pide la parte entera del término. Luego se transforma a flotante para realizar
		// la suma
		j0 = K1*sd_time.year + (float) (int )(K2*(float)sd_time.month/K3)
			+ (float) sd_time.day +  K4 ;
		negative_term =(float) (int) (multiplicador_term_negativo *((float )sd_time.year
					   + (int)(float)((sd_time.month+9.0)/12.0))) ;
		j0 = j0-negative_term ;
		fract_day = (float) sd_time.hour +  (float)sd_time.minute/60.0
					+ (float)sd_time.second/3600.0 ;
		// calculo de centurias julianas
		jul_cent = (j0 - 2451545)/36525 ;
		sid_time = KS1 + KS2 * jul_cent + KS3 * pow(jul_cent,2) + KS4 * pow(jul_cent,3) ;
    	// el cálculo anterior sid_time puede ser mayor a 360°. Para quedarnos con el giro que corresponde
		// a la unidad angular restamos 360°. Lo calculado esta a las 12:00:00. Se debe pasar a UTC con UTC/24
		sid_time = sid_time - (float) (int)(sid_time/360.0) * 360.0 ;
		// Puede ser superior a 360°, idem al caso anterior
		sid_time = sid_time + 360.98564724*(fract_day/24.0);
		sid_time = sid_time - (float) (int)(sid_time/360.0) * 360.0 ;
		// transformación a hora, minuto y segundo: 360° -- 24hs, 60min -- 1h y 60s -- 1min
		hs = (uint8_t) ((sid_time*24)/360.0 ) ;
		sidereal_time->h = hs ;
		ms  = (uint8_t)  ((sid_time*24)/360.0  - hs) ;
		sidereal_time->m = ms ;
		error = NO_ERROR_SIDEREAL;

	}
	return error ;

}




/**
 * @brief  Realiza la lectura del sistema RTC para realizar el cálculo de la hora sidereal.
 * 		   Al devolve
 *
 * @return Devuelve la lectura de la hora y fecha del RTC. En caso de error, el campo error
 * 		   de la estructura fecha_t: 2: error al obtener el tiempo
 * 		   							 3:  error al obtener la hora del RTC
 * 		   Al usar esta estructura se prescinde de la libreria "time.h" nativa de C
 *
 */
fecha_t getDateTime()
{
	RTC_DateTypeDef sdatestructureget ;
	RTC_TimeTypeDef stimestructureget ;
	fecha_t response  ;
	/* USER CODE END WHILE */
	if (HAL_RTC_GetTime(&rtc, &stimestructureget, RTC_FORMAT_BIN) != HAL_OK)
	{
		response.error = ERROR_RTC_TIME ;
	}else{
		if(HAL_RTC_GetDate(&rtc, &sdatestructureget, RTC_FORMAT_BIN) == HAL_OK)
		{
			//lectura del RTC de la placa nucleo y carga de valores en fecha_t
			response.year = sdatestructureget.Year ;
			response.day = sdatestructureget.Date;
			response.month = sdatestructureget.Month ;
			response.minute = stimestructureget.Minutes ;
			response.hour = stimestructureget.Hours ;
			response.second = stimestructureget.Seconds ;
			response.error = NO_ERROR_GET_RTC ;// 0x01 --> correct!
		}else{
			response.error = ERROR_RTC_DATE ;
		}
	}
	return response ;
}

