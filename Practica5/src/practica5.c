/*!
*	\author Alan Ernesto González Barrios
*	\Practica  5
*	\date 2019-04-09
*	\mainpage Practica 5
*	\section Introduction
*	Este codigo fue desarrollado para la practica 5
*	\section compile_sec Compilation
*	Aqui se muestra como compilar el codigo usando Makefile
*	\subsection Step1 compile
*	En la terminal escribe compile
*	\subsection Step2 run
*	En la terminal escribe run	
*
*
*
*/


#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]){

	int h1p[2], ph1[2], h2p[2], ph2[2], n, i, aux=0, a, b;	
	int leidos=0;
	printf("Ingresa un número mayor a 0\n");
	scanf("%d",&n);
	while(n==0){
		printf("Ingresa otro valor mayor a 0");
//! recibe n
		scanf("%d",&n);
	}
//! se crean los pipes
	pipe(h1p);
	pipe(ph1);
	pipe(h2p);
	pipe(ph2);
//! se crea el hijo 1
	if(fork()==0){
//! se cierran los canales
		close(h1p[0]);
		close(ph1[1]);
//! en un ciclo infinito escucha lo que le manda padre
		while(1){
			read(ph1[0],&a,sizeof(int));
			printf("Soy hijo 1, recibí de padre: %d\n",a);
//! incrementa
			aux+=a;
			if(a==0){
//! manda la suma total a padre y se cierra cuando recibe 0
				write(h1p[1],&aux,sizeof(int));
				exit(0);
			}
		}
	}else{
//! se crea el hijo 2
		if(fork()==0){
//! se cierran los canales
			close(h2p[0]);
			close(ph2[1]);
//! escucha indefinidamente
			while(1){
				read(ph2[0],&a,sizeof(int));
				printf("Soy hijo 2, recibí de padre: %d\n",a);
//! incrementa
				aux+=a;
				if(a==0){
//! manda a padre la suma total y se cierra cuando llega 0
					write(h2p[1],&aux,sizeof(int));
					exit(0);
				}
			}
//! continua el proceso original (padre)
		}else{	
//! cierra los canales que no se usan con su hijo, lectura y escritura
			close(h1p[1]);
			close(ph1[0]);
			close(h2p[1]);
			close(ph2[0]);
			srand(time(NULL));
			for(i=0;i<n;i++){
//! se hacen los randoms
				aux=rand()%8+1;
				if(aux%2==0){
					printf("envié a hijo 1: %d\n",aux);
//! si es par lo manda a hijo 1
					write(ph1[1],&aux,sizeof(int));				
				}else{
					printf("envié a hijo 2: %d\n",aux);
//! si es impar lo manda a hijo 2
					write(ph2[1],&aux,sizeof(int));				
				}			
			}
//! manda 0's para decirles que ya eso era todo
			write(ph1[1],&leidos,sizeof(int));
			write(ph2[1],&leidos,sizeof(int));
			read(h1p[0],&a,sizeof(int));
//! imprime la suma total de hijo 1
			printf("recibí la suma total de mijo 1: %d\n",a);
			read(h2p[0],&b,sizeof(int));
//! imprime la suma total de hijo 2
			printf("recibí la suma total de mijo 2: %d\n",b);
		}
	}
	return 0;
}

