#include "libArbol.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inicia Arbol
nodoArbol* inicArbol()
{
    return NULL;
}

// Crea nodo Arbol
nodoArbol* crearNodoArbol (int legajo, char nombre[20])
{   /// Esta funcion no se usa en el main, es necesaria para las funciones de inserción
    nodoArbol * aux = (nodoArbol*)malloc(sizeof(nodoArbol));
    aux -> legajo = legajo;
    strcpy(aux -> nombre, nombre);
    aux -> izq = NULL;
    aux -> der = NULL;
    return aux;
}

nodoArbol* insertarNodoArbol (nodoArbol * arbol, int legajo, char nombre[20])
{
    if (arbol == NULL)
    {
        arbol = crearNodoArbol (legajo,nombre   );
    }
    else
    {
        if (legajo > arbol->legajo)
            arbol->der = insertarNodoArbol (arbol->der,legajo,nombre);       ///    Nótese la recursividad
        else arbol->izq = insertarNodoArbol (arbol->izq,legajo,nombre);
    }
    return arbol;
}

void preOrder (nodoArbol * arbol)
{
    if (arbol != NULL)
    {
        printf(" %d", arbol -> legajo);
        preOrder (arbol -> izq);
        preOrder (arbol -> der);
    }
}

void inOrder (nodoArbol * arbol)
{
    if (arbol != NULL)
    {
        inOrder (arbol -> izq);
        printf(" %d", arbol -> legajo);
        inOrder (arbol -> der);
    }
}

void postOrder (nodoArbol * arbol)
{
    if (arbol != NULL)
    {
        postOrder (arbol -> izq);
        postOrder (arbol -> der);
        printf(" %d",arbol -> legajo);
    }
}

nodoArbol* buscarArbol (nodoArbol * arbol, int legajo)
{
    nodoArbol* rta = NULL;

    if (arbol != NULL)
    {
        if (legajo == arbol -> legajo)
            rta = arbol;

        else if (legajo > arbol -> legajo)
            buscarArbol (arbol -> der, legajo);

        else buscarArbol (arbol -> izq, legajo);
    }
    return rta;
}


int sumaArbol (nodoArbol* arbol)
{
    int suma = 0;
    if (arbol)
        suma = arbol->legajo + sumaArbol(arbol->izq) + sumaArbol(arbol->der);
    return suma;
}





/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////









