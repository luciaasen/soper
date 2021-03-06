/**
 * @file ejercicio5b.c
 * @author Lucia Asencio y Rodrigo de Pool
 * @date 28-2-2017
 * @brief fichero que contiene ej5b de la practica 1 de SOPER.
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define NUM_PROC    3

/**
 * Programa que crea tres procesos hijos procedentes de un padre e imprime
 * por pantalla la informacion de cada proceso hijo.
 */
int main(void){
    int pid = 1;
    int i;
    /*Agregamos la condicion de que un proceso no sea hijo para mantener bucle*/
    for (i = 0; i < NUM_PROC && pid > 0; i++) {
        if ((pid = fork()) < 0) {
            printf("Error al emplear fork\n");
            exit(EXIT_FAILURE);
        }else if (pid == 0) {
            printf("Este es el proceso %d con padre %d\n", getpid(), getppid());
            exit(EXIT_SUCCESS);
        }
    }
    /*Esperamos a que los procesos hijo para cierren para cerrar el padre*/
    for (i = 0; i < NUM_PROC; i++) {
        wait(NULL);
    }
    exit(EXIT_SUCCESS);
}
