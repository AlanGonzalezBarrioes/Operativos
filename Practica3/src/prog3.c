
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
//! se declaran los prototipos de las funciones que se ocuparan
void SO();
//! inicia el main
int main () 
{
//! se asocia la señal que se genera cuando se presiona Ctl+C con la funcion SO
    signal (SIGINT, SO);
//! se crea el bucle infinito mientra el valor del entero bucle sea igual a 1
    while (1)
//! mientras se esta en el bucle se estara imprimiendo en pantalla el texto aqui estoy con su respectivo numero de proceso
	printf("Process id (%d): Aqui estoy\n", getpid());
//! se descativa la deteccion  de la señal de Ctl+c
    signal (SIGINT, SIG_IGN);
    return 0;

}

//! se inicializa la funcion SO que esta asociada a la señal del Ctl+C
void SO()
{
//! se desactiva la señal de Ctl+C
    signal (SIGINT, SIG_IGN);
//! una vez que se detecto el Ctl+C se imprimira la cadena interrupcion
    printf ("Terminación por interrupciñon del S.O.\n");
//! termina el programa
    exit(0);
}
 
