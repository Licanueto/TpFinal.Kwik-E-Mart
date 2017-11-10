#ifndef LIBARBOLESHEADER_H_INCLUDED
#define LIBARBOLESHEADER_H_INCLUDED

typedef struct{
    int legajo;
    char nombre[20];
    struct nodoArbol* izq;
    struct nodoArbol* der;
}nodoArbol;

nodoArbol* inicArbol();

nodoArbol* crearNodoArbol (int legajo, char nombre[20]);

nodoArbol* insertarNodoArbol (nodoArbol * arbol, int legajo, char nombre[20]);


void preOrder (nodoArbol* arbol);
void inOrder (nodoArbol* arbol);
void postOrder (nodoArbol* arbol);

nodoArbol* buscarArbol (nodoArbol * arbol, int legajo);

#endif // LIBARBOLESHEADER_H_INCLUDED
