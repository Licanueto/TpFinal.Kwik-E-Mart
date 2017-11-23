#include "libTpFinal.h"
#ifndef LIBTPFINAL_H_INCLUDED
#define LIBTPFINAL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/////////////////////////////////////////////////////////////////////////////////////////////////
/*                                  Prototipado de Listas                                       */
/////////////////////////////////////////////////////////////////////////////////////////////////


/*
typedef struct{
        stPersona cliente;
        struct nodo* siguiente;
        struct nodo* anterior;
}nodo;
*/
nodo* inicLista();
nodo* crearNodoLista (stPersona cliente);
nodo* buscaUltimoNodo (nodo* lista);
nodo* buscaNodoSegunNombre (nodo* lista,char nombre[]);
nodo* agregarAlPrincipio (nodo* lista,nodo* nuevoNodo);
nodo* agregarAlFinal (nodo* lista, nodo* nuevoNodo);
nodo* borrarNodo (nodo* lista, char nombres[]);
void mostrarLista (nodo* lista);
void mostrarNodo (nodo* nodin);



/////////////////////////////////////////////////////////////////////////////////////////////////
/*                                   Prototipado de Filas                                       */
/////////////////////////////////////////////////////////////////////////////////////////////////


/*
typedef struct{
        struct nodo* inicio;
        struct nodo* finall; // final me lo toma como palabra reservada
} Fila;
*/
void inicFila (Fila* fila);
void agregar (Fila* fila,stPersona cliente);
stPersona quitar (Fila* fila);
Fila* mostrar();
Fila* filaVacia();



#endif // LIBTPFINAL_H_INCLUDED
