#include "Lista.h" 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

nodo* inicLista()
{
    return NULL;
}

nodo* crearNodo (char nombre[], int edad)
{
    nodo* aux = (nodo*)malloc(sizeof(nodo));
    aux->edad = edad;
    strcpy(aux->nombre,nombre);
    aux->siguiente = NULL;
    return aux;
}

nodo* agregarAlPrincipio (nodo* lista,nodo* nuevoNodo)
{
    if (lista == NULL)
        lista = nuevoNodo;
    else
    {
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
    }
}
nodo* agregarAlFinal (nodo* lista, nodo* nuevoNodo)
{
    nodo* ultimoNodo = buscaUltimoNodo(lista);
    ultimoNodo->siguiente = nuevoNodo;
    return (lista);
}

nodo* buscaUltimoNodo (nodo* lista)
{
    nodo* ultimoNodo = lista;
    if (ultimoNodo != NULL)
    {
           while (ultimoNodo->siguiente != NULL)
            ultimoNodo = ultimoNodo->siguiente;
    }
    return ultimoNodo;
}

nodo* buscaNodoSegunNombre (nodo* lista,char nombre[])
{
    nodo* seg = lista;
    nodo* found = NULL;
    if (seg != NULL)
    {
        while (seg->siguiente != NULL)
        {
            if (strcmp(seg->nombre,nombre) == 0)
                found = seg;
            else seg = seg->siguiente;
        }
    }
    return found;
}

nodo* borrarNodo (nodo* lista, char nombre[])
{
    nodo* seg = lista;
    nodo* anterior;
    if (lista!= NULL && strcmp(lista->nombre,nombre) == 0)
    {
        lista = lista->siguiente;
        free(seg); // libera el primer nodo
    }
    else
    {
        while (seg != NULL && strcmp(seg->nombre,nombre)!= 0)
        {
            anterior = seg;
            seg = seg->siguiente;
        }
        if (seg != NULL)
        {
            anterior->siguiente = seg->siguiente;
            free(seg);
        }
    }
    return lista;
}

void mostrarLista (nodo* lista)
{
    nodo* seg = lista;
    while (seg != NULL)
    {
        mostrarNodo(seg);
        seg = seg->siguiente;
    }
}

void mostrarNodo (nodo* nodin)
{
    printf("\n\n                       Id :  %d",nodin->id);
    printf("\n                 Apellido :  %s",nodin->apeliido);
    printf("\n                  Nombres :  %s",nodin->nombres);
    printf("\n          Tipo de Cliente :  %d",nodin->tipoCliente);
    printf("\n            Medio de pago :  %d",nodin->medioPago);
    printf("\n    Cantidad de Articulos :  %d",nodin->cantArticulos);
    printf("\n         Tiempo de Espera :  %d",nodin->tiempoEspera);
    printf("\n         Tiempo Procesado :  %d",nodin->tiempoProcesado);
    printf("\n                Eliminado :  %d",nodin->eliminado);
}
