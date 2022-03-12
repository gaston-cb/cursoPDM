# Respuestas a preguntas 

## 1 - Se pueden cambiar los tiempos de encendido de cada led fácilmente en un solo lugar del código o estos están hardcodeados?
Si, se puede. En el archivo "main.c", tiene tres macros definidas de la siguiente forma: 

```c11

	#define TIME_TOOGLE_LED1 
	#define TIME_TOOGLE_LED2 
	#define TIME_TOOGLE_LED3 
```
	

## 2 - ¿Qué bibliotecas estándar se debieron agregar a API_delay.h para que el código compile? Si las funcionalidades de una API propia crecieran, habría que pensar cuál sería el mejor lugar para incluir esas bibliotecas y algunos typedefs que se usan en el ejercicio.

Las bibliotecas añadidas son "stdbool" y "stdint", que contienen las definiciones  
## 3 - ¿Es adecuado el control de los parámetros pasados por el usuario que se hace en las funciones implementadas? ¿Se controla que sean valores válidos? ¿Se controla que estén dentro de los rangos correctos?
No, ya que se pueden pasar valores negativos, y pueden provocar errores, o tiempos de retardo excesivos, esto depende de si 
usa CA2 o CA1. 
De hecho, para ver este efecto, se puede usar el debug. Aparentemente C, no tiene soporte para verificar los tipos de datos, 
intente con typename, pero no paso nada. En mi caso, para evitar esto, se utilizo la siguiente directiva de compilación 

```c11


#if TIME_TOOGLE_LED_1<0 || TIME_TOOGLE_LED_2<0  || TIME_TOOGLE_LED_3<0
	#error "los valores de retardo son negativos "
#else
  delayInit(&toogle_led[LED1], TIME_TOOGLE_LED_1) ;
  delayInit(&toogle_led[LED2], TIME_TOOGLE_LED_1) ;
  delayInit(&toogle_led[LED3], TIME_TOOGLE_LED_3) ;
#endif 
```


