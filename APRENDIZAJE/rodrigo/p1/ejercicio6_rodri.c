#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

#define TAM    80

/**
 * Programa de prueba para probar si se puede acceder a memoria guardada
 * entre procesos hijos y padres.
 */
int main(void){
    int  pid;
    char *cadena = (char *) malloc(sizeof(char) * TAM);

    pid = fork();
    if (pid == 0) {
        printf("Introduzca un nombre: ");
        scanf("%s", cadena);
        exit(EXIT_SUCCESS);
    }
    /*Esperamos en el proceso padre a que se introduzca el nombre*/
    wait(NULL);
    printf("Podemos imprimir el string? %s\n", cadena);
    free(cadena);
    exit(EXIT_SUCCESS);
}
