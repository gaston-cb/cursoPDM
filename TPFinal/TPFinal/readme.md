# TP Final de Programación de microcontroladores 

El presente proyecto calcula la hora siderea al presionar un pulsador. El puerto del pulsador se puede seleccionar mediante el código. 
Para realizar la compilación utilizando el template de la cátedra se deben modificar la función systemClock, se deben agregar 
las siguientes lineas. 


 - En el archivo stm32hal.x se debe descomentar la linea 65 del archivo stm32f4xx_hal_config.h, 
dentro de la carpera Drivers/STM32F4xx_HAL_Driver.   
 - Se debe realizar la compilacion del linker con la -u print__float,a continuación se dejan las imágenes del procedimiento 


![propiedades](stm_1.png)  
![flag de linker](stm_2.png)  

Para que el proyecto pueda configura el clock correctamente usando la 
placa nucleo 144 se debe dejar sin comentar la linea 29 del main.c (flag de compilacion)



	