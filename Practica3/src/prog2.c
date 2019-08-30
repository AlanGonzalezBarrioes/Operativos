
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
//! se declaran los prototipos de las funciones que se ocuparan             
void terminar_bucle();
//! declaracion de variable global para el bucle de impresion 
int bucle=1;
//! inicia el main
int main () 
{
    int bucle=1;
//! se asocia la señal que se genera cuando la funcion alarm termina de decrementar los 30 segundos
    signal (SIGALRM, terminar_bucle);
//! se inicializa la funcion alarm con paramentro de 30 segundos el cual servira de temporizador
    alarm(30);
//! se crea el bucle infinito mientra el valor del entero bucle sea igual a 1
    while (bucle==1)
//! mientras se esta en el bucle se estara imprimiendo en pantalla el texto aqui estoy con su respectivo numero de proceso
	printf("Process id (%d): Aqui estoy\n", getpid());
    return 0;

}

//! se declara la funcion a la cual esta asociada la señal de alarm cuando pasen los 30 segundos
void terminar_bucle() {
//! se desactiva la deteccion de la señal alarm
      signal (SIGALRM, SIG_IGN);
//! se cambia el valor del entero bucle a 0 para salir del bucle infinito en el main esto cuando ya terminaron de pasar los 30 segundos
      bucle=0;
//! se imprime la cadena para mostrar que pasaron los 30 seg
      printf ("Terminación normal\n");
//! se sale del programa
      exit(0);
}


