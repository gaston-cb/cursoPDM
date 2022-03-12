# Respuestas a preguntas 

## 1 - Se pueden cambiar los tiempos de encendido de cada led fácilmente en un solo lugar del código o estos están hardcodeados?
Si, se puede. En el archivo "main.c", tiene tres macros definidas de la siguiente forma: 

	#define TIME_TOOGLE_LED1 
	#define TIME_TOOGLE_LED2 
	#define TIME_TOOGLE_LED3 
	

## 2 - 
Las bibliotecas añadidas son "stdbool" y "stdint" 
## 3 - ¿Es adecuado el control de los parámetros pasados por el usuario que se hace en las funciones implementadas? ¿Se controla que sean valores válidos? ¿Se controla que estén dentro de los rangos correctos?
No, ya que se pueden pasar valores negativos, y pueden provocar errores, o tiempos de retardo excesivos, esto depende de si 
usa CA2 o CA1. 
De hecho, para ver este efecto, se puede usar el debug. Aparentemente C, no tiene soporte para verificar los tipos de datos, 
intente con typename, pero no paso nada 



