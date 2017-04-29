#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>

#define KEY    1513415


typedef struct _mensaje {
    long type;
    char *info;
    int  end;
}mensaje;

/**
 * Comportamiento explicado en el enunciado. Acabara cuando se acabe el fichero.
 * En el ultimo mensaje indicara que es el ultimo marcando con un 1 el atributo
 * end del mensaje. Los tipos enviados seran marcados con el long 27
 * @param id   id del buzon
 * @param num  tamanio de caracteres dentro de la estructura
 * @param read fichero en el que se lee
 */
void procesoA(int id, int num, FILE *read);
/**
 * Funcionamiento explicado en el enunciado. Cuando envie el ultimo mensaje a
 * C lo dira marcando con un 1 el atributo end del mensaje. Recibira mensaje
 * de tipo 27 y enviara de tipo 42
 * @param id  id del buzon
 * @param num numero de caracteres a leer dentro de la estructura
 */
void procesoB(int id, int num);
/**
 * Funcionamiento explicado en el enunciado. Cuando envie reciba el ultimom
 * mensaje lo escribira y se cerrara. Recibira mensaje de tipo 42
 * @param id    id del buzon
 * @param num   numero de caracteres dentro de la estructura de mensaje
 * @param write fichero en el que se escribe
 */
void procesoC(int id, int num, FILE *write);

/**
 * Funcion que determina cuantos caracteres son 4kb dependiendo de la
 * maquina en que se utiliza
 * @return Entero con el numero de caracteres que representan 4kb
 */
int char4K();
