/*!
 *	\author: Alan Ernesto González Barrios
 *	\date 2019-03-20
 *	\mainpage Practica 3
 *	\section Programa 1  
 *	Seccion de la modificacion numero 1 de la practica 3
 * 	\warning declaration on getpid
 *	\section Programa 2  
 *	Seccion de la modificacion numero 2 de la practica 3
 * 	\warning declaration on getpid
 * 	\warning declaration on alarm
 *	\section Programa 3  
 *	Seccion la modificacion numero 3 de la practica 3
 * 	\warning declaration on getpid
*/



#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

int main () 
{
//! se crea el bucle infinito mientra el valor del entero bucle sea igual a 1
    while (1)
//! mientras se esta en el bucle se estara imprimiendo en pantalla el texto aqui estoy con su respectivo numero de proceso
	printf("Process id (%d): Aqui estoy\n", getpid());
    return 0;

}


