# TP3 Curso programación de microcontroladoes FIUBA 

El programa contiene una API para el manejo de los retardos dentro de la carpeta Drivers/API 

El test se realiza utilizando una secuencia de encendido de leds, con la secuencia a elección del usuario 

La elección la realiza el programador desde el archivo main.c, dentro de la carpeta src. Hay seis secuencias posibles:  
- LED1 LED2 LED3 
- LED1 LED3 LED2 
- LED2 LED1 LED3 
- LED2 LED3 LED2
- LED3 LED1 LED2 
- LED3 LED2 LED1

El tiempo de encendido de cada led, se corresponde con las macros definidas en "main.c", con TIME_LED_ONE, TIME_LED_TWO  y TIME_LED_THREE 

Por ejemplo, si se desea la secuencia LED2, LED1 ,LED3, donde cada duración sea de 100ms, 200ms, y 300ms respectivamente, se debe escribir 
TIME_LED_ONE   100 
TIME_LED_TWO   200 
TIME_LED_THREE 300

 


La elección se realiza descomentando las macro define del archivo, y realizando la compilación.  

##Preguntas TP3 

##1 Se pueden cambiar los tiempos de encendido de cada led fácilmente en un solo lugar del código o estos están hardcodeados? ¿Hay números “mágicos”?
	Si, en el inicio del archivo main.c 
	



##2  ¿Qué bibliotecas estándar se debieron agregar a API_delay.h para que el código compile? Si las funcionalidades de una API propia crecieran, habría que pensar cuál sería el mejor lugar para incluir esas bibliotecas y algunos typedefs que se usan en el ejercicio.
	Las bibliotecas a utilizar son <stdbool>, <stdint> y <stddef> 
##3 ¿Es adecuado el control de los parámetros pasados por el usuario que se hace en las funciones implementadas? ¿Se controla que sean valores válidos? ¿Se controla que estén dentro de los rangos correctos?
	Si, se controlan los parámetros. En el caso de que crezca, se debe ver la forma de implementar metodos getters y setters para modificar
	los parámetros dentro de si misma, y tratando de encapsular la mayor parte del comportamiento cuando sea posible 
	
