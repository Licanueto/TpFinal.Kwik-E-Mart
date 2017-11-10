#ifndef LIBTPFINAL_H_INCLUDED
#define LIBTPFINAL_H_INCLUDED

/////////////////////////////////////////////////////////////////////////////////////////////////
/*                                    Funciones de Listas                                       */
/////////////////////////////////////////////////////////////////////////////////////////////////

nodo* inicLista();
nodo* crearNodo (char nombre[], int edad);
nodo* agregarAlPrincipio (nodo* lista,nodo* nuevoNodo);
nodo* agregarAlFinal (nodo* lista, nodo* nuevoNodo);
nodo* buscaUltimoNodo (nodo* lista);
nodo* buscaNodoSegunNombre (nodo* lista,char nombre[]);
nodo* borrarNodo (nodo* lista, char nombre[]);
void mostrarLista (nodo* lista);
void mostrarNodo (nodo* nodin);



/////////////////////////////////////////////////////////////////////////////////////////////////
/*                                    Funciones de Filas                                       */
/////////////////////////////////////////////////////////////////////////////////////////////////

Fila* inicFila ();
Fila* agregar (nodo* inicio, nodo* final);
Fila* quitar ();
Fila* mostrar();
Fila* filaVacia();



#endif // LIBTPFINAL_H_INCLUDED
