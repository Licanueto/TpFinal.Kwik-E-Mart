#include "libListasYFilas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/////////////////////////////////////////////////////////////////////////////////////////////////
/*                                    Funciones de Listas                                       */
/////////////////////////////////////////////////////////////////////////////////////////////////

nodo* inicLista()
{
    return NULL;
}

nodo* crearNodoLista (stPersona cliente)
{
    nodo* aux = (nodo*)malloc(sizeof(nodo));
    aux->cliente = cliente;
    aux->siguiente = NULL;
    aux->anterior = NULL;
    return aux;
}

nodo* agregarAlPrincipio (nodo* lista, nodo* nuevoNodo)
{
    nuevoNodo->siguiente = lista;
    if (lista!=NULL)
    {
        lista->anterior = nuevoNodo;
    }
    return nuevoNodo;
}
nodo* agregarAlFinal (nodo* lista, nodo* nuevoNodo)
{

    if (lista == NULL)
        lista = nuevoNodo;
    else
    {
        nodo* ultimoNodo = buscaUltimoNodo(lista);
        ultimoNodo->siguiente = nuevoNodo;
        nuevoNodo->anterior = ultimoNodo;
    }
    return lista;
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
nodo* buscaNodoSegunNombre (nodo* lista,char nombres[])
{
    nodo* seg = lista;
    nodo* encontrado = NULL;
    stPersona personaVariable;

    if (seg != NULL)
    {
        while (seg->siguiente != NULL)
        {
            personaVariable = seg->cliente;
            if (strcmp(personaVariable.nombres,nombres) == 0)
                encontrado = seg;
            else seg = seg->siguiente;
        }
    }
    return encontrado;
}

nodo* borrarNodo (nodo* lista, char nombres[])
{
    nodo* seg = NULL;
    nodo* nodo_a_borrar = NULL;
    nodo* anterior = NULL;  /// se usa en el ultimo if
    nodo* siguiente = NULL; /// se usa en el ultimo if del ultimo if
    stPersona personaVariable;

    if (lista != NULL)
    {
        personaVariable = lista->cliente;
        if (strcmp(personaVariable.nombres,nombres) == 0)
        {
            nodo_a_borrar = lista;
            lista = lista->siguiente;
            if(lista!=NULL)
                lista->anterior = NULL;
            free(seg); // libera el primer nodo
        }
        else
        {
            seg = lista->siguiente;
            personaVariable = seg->cliente;
            while (seg != NULL && strcmp(personaVariable.nombres,nombres)!= 0)
            {
                seg = seg->siguiente;
                personaVariable = seg->cliente;
            }
            if (seg != NULL)
            {
                anterior = seg->anterior;
                anterior->siguiente = seg->siguiente;
                if (seg->siguiente) //si exiset el siguiente nodo
                {
                    siguiente = seg->siguiente;
                    siguiente->anterior = anterior;
                }
                free(seg);
            }
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
    stPersona varPersona = nodin->cliente;
    printf("\n\n                       Id :  %d",varPersona.id);
    printf("\n                 Apellido :  %s",varPersona.apellido);
    printf("\n                  Nombres :  %s",varPersona.nombres);
    printf("\n          Tipo de Cliente :  %d",varPersona.tipoCliente);
    printf("\n            Medio de pago :  %d",varPersona.medioPago);
    printf("\n    Cantidad de Articulos :  %d",varPersona.cantArticulos);
    printf("\n         Tiempo de Espera :  %d",varPersona.tiempoEspera);
    printf("\n         Tiempo Procesado :  %d",varPersona.tiempoProcesado);
    printf("\n                Eliminado :  %d",varPersona.eliminado);
}





/////////////////////////////////////////////////////////////////////////////////////////////////
/*                                    Funciones de Filas                                        */
/////////////////////////////////////////////////////////////////////////////////////////////////

void inicFila (Fila* fila)
{
    fila->inicio = inicLista();
    fila->finall = inicLista();
}

void agregar (Fila* fila,stPersona cliente)
{
    nodo* nuevoNodo = crearNodoLista(cliente);
    if (fila->inicio == NULL)
    {
        fila->inicio = nuevoNodo;
        fila->finall = nuevoNodo;
    }
    else
    {
        fila->inicio = agregarAlFinal(fila->inicio,nuevoNodo);
        fila->finall = nuevoNodo;
    }
}

stPersona quitar (Fila* fila) /// devuelve y saca el elemento que se encuentra al principio
{
    stPersona primerClienteDeLaFila;
    if (fila->inicio != NULL)
    {
        nodo* aux = fila->inicio; /// siendo aux el elemento a extraer
        nodo* siguiente = aux->siguiente; /// y 'siguiente' la nueva punta
        if (fila->inicio != fila->finall)
        {
            siguiente->anterior = NULL;
            fila->inicio = siguiente; /// voici.. siguiente pasa a ser la nueva fila
        }
        else /// cuando hay un solo nodo
        {
            fila->inicio  = NULL;
            fila->finall = NULL;
        }
        primerClienteDeLaFila = aux->cliente;
        free(aux);
    }
    return primerClienteDeLaFila;
}


