#ifndef LIBARBOLESHEADER_H_INCLUDED
#define LIBARBOLESHEADER_H_INCLUDED
#include "libTpFinal.h"

/////////////////////////////////////////////////////////////////////////////////////////////////
/*                                    Prototipado de Arbol                                      */
/////////////////////////////////////////////////////////////////////////////////////////////////


//  Arbol
typedef struct{
    int legajo;
    char nombre[20];
    struct nodoArbol* izq;
    struct nodoArbol* der;
}nodoArbol;

//  Funciones Básicas
nodoArbol* inicArbol();
nodoArbol* crearNodoArbol (int legajo, char nombre[20]);
nodoArbol* insertarNodoArbol (nodoArbol * arbol, int legajo, char nombre[20]);

//  Orders
void preOrder (nodoArbol* arbol);
void inOrder (nodoArbol* arbol);
void postOrder (nodoArbol* arbol);

//  Busqueda
nodoArbol* buscarArbol (nodoArbol * arbol, int legajo); /// Devuelve el puntero al nodo que se busca

//  Suma
int sumaArbol (nodoArbol* arbol); /// Para qué había hecho esta fn?

#endif // LIBARBOLESHEADER_H_INCLUDED
