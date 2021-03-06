/**
* @file ejercicio6.c
* @author Lucia Asencio y Rodrigo de Pool
* @date 28-2-2017
* @brief fichero que contiene ej6 de la practica 1 de SOPER para el estudio del uso de memoria entre procesos padre e hijo.
*/

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

/**
*   Funcion main:
*   Este main reserva memoria antes de hacer un fork().
*   Tanto el padre como el hijo alteran el contenido de esta memoria,
*   y se comprueba que ambos deben liberarla despues, y que uno no tiene acceso a la memoria del otro.
*/

int main(){
    int pid, status;
    char *cad = NULL;
    cad = (char *)malloc(80 * sizeof(char));
    if(cad == NULL){
        printf("Error en la reserva de memoria\n");
        return -1;
    }
    pid = fork();
    if(pid == 0){
        printf("Introduce un nombre: ");
        scanf("%s", cad);
        printf("Has introducido %s\n", cad);
    }else{
        wait(&status);
        printf("Esta es la cadena que lee el padre tras el exit del hijo: %s\n", cad);
    }
    free(cad);
    exit(EXIT_SUCCESS);
}
