#include "libArbol.h"

    /// EnA ~ "En (los archivos de) Arbol" ///

char archivoUsuariosEnA[]={"usuarios.dat"};
char archivoPersonasEnA[]={"personas.dat"};

int test;//
/////////////////////////////////////////////////////////////////////////////////////////////////
/*                                    Funciones de Arbol                                        */
/////////////////////////////////////////////////////////////////////////////////////////////////



//  Inicia Arbol
nodoArbol* inicArbol()
{
    return NULL;
}

//  Crea nodo Arbol
nodoArbol* crearNodoArbol (stPersona cliente)
{
    nodoArbol* aux = (nodoArbol*)malloc(sizeof(nodoArbol));
    aux->p = cliente;
    //printf("\n Se crea el nodo del cliente %s",cliente.nombres);//
    aux->izq = NULL;
    aux->der = NULL;
    return aux;
}
//  Inserta persona en arbol
nodoArbol* insertarNodoArbol (nodoArbol* arbol,stPersona personaAinsertar)
{
    if (arbol == NULL)
    {
        arbol = crearNodoArbol(personaAinsertar);
    }
    else
    {
        stPersona personaEnArbol = arbol->p;
        if (strcmp(personaAinsertar.nombres,personaEnArbol.nombres) > 0)
            arbol->der = insertarNodoArbol (arbol->der,personaAinsertar);       ///    Nótese la recursividad
        else
            arbol->izq = insertarNodoArbol (arbol->izq,personaAinsertar);
    }
    return arbol;
}


//  Carga perosnas al Arbol desde el archivo
nodoArbol* cargaPersonasAlArbol(nodoArbol* arbol)
{
    stPersona cliente;
    FILE* archi = fopen(archivoPersonasEnA,"r+b");

    if (archi == NULL)
        printf("\n\n  Se encontro un error al cargar el arbol. Cierre el programa y contacte a su administrador. (Error:%d)",errno);
    else
    {
       while (fread(&cliente,sizeof(stPersona),1,archi) > 0)
        {
            mostrarPersonaEnA(cliente); /// Para ver si al menos al cliente se lo lee bien
            arbol = insertarNodoArbol(arbol,cliente); /// He aqui el problema
        }
    }
    return arbol;
}

// Mostrar
void mostrarArbol(nodoArbol* arbol, int modo) /// 1:preOrder  2:inOrder  3:postOrder
{
    if (modo == 1)
        mostrarPreOrder(arbol);
    if (modo == 2)
        mostrarInOrder(arbol);
    if (modo == 3)
        mostrarPostOrder(arbol);
    if (modo!=1 && modo!=2 && modo!=3)
        puts("\n Ha ocurrido un error, por favor conacte a su administrador.\n Error: Se est\xA0 llamando a la función mostrarArbol con un modo fuera de rango");
    puts("\n\n  ");
    fflush(stdin);
    getchar();
}
void mostrarPersonaEnA(stPersona a)
{
    printf("\n\n     Nombres: %s", a.nombres);
    printf("\n    Apellido: %s", a.apellido);
    printf("\n  Prioridad : %d", a.tipoCliente);
    printf("\n       Abona: %d  ",a.medioPago);
    printf("\n ---------------------");
}
void mostrarPreOrder (nodoArbol* arbol){
    if (arbol != NULL)
    {
        mostrarPersonaEnA (arbol->p);
        mostrarPreOrder (arbol->izq);
        mostrarPreOrder (arbol->der);
    }
}
void mostrarInOrder (nodoArbol* arbol){
    if (arbol != NULL)
    {
        mostrarInOrder (arbol -> izq);
        mostrarPersonaEnA (arbol->p);
        mostrarInOrder (arbol -> der);
    }
}
void mostrarPostOrder (nodoArbol* arbol){
    if (arbol != NULL)
    {
        mostrarPostOrder (arbol -> izq);
        mostrarPostOrder (arbol -> der);
        mostrarPersonaEnA(arbol->p);
    }
}

// Borrar
nodoArbol* NMD(nodoArbol* raiz)/// devuelve el "nodo más a la derecha"
{
    if(raiz->der != NULL)
    {
        raiz = NMD(raiz->der);
    }
    return raiz;
}
nodoArbol* NMI(nodoArbol* raiz) /// devuelve el "nodo más a la izquierda"
{
    if(raiz->izq != NULL)
    {
        raiz = NMI(raiz->izq);
    }
    return raiz;
}
nodoArbol* borrarUnNodoArbol(nodoArbol* arbol,char nombres[])
{
    stPersona clienteAux = arbol->p;
    if (arbol != NULL) ///else, nada
    {
        printf("\n El nombre a buscar es %s y se lo compara con %s",nombres,clienteAux.nombres); //
        if (strcmp(nombres,clienteAux.nombres) == 0)
        {
            printf(" ..Los nombres son iguales");

            if (arbol->izq != NULL)
            {
                nodoArbol* masDer = NMD(arbol->izq);
                arbol->p = masDer->p;
                clienteAux = masDer->p; /// Uso al clienteAux para poder pasar el nombre en la sig
                arbol->izq = borrarUnNodoArbol(arbol->izq,clienteAux.nombres);
            }
            else if (arbol->der != NULL)
            {
                nodoArbol* masIzq = NMI(arbol->der);
                arbol->p = masIzq->p;
                clienteAux = masIzq->p;
                arbol->der = borrarUnNodoArbol(arbol->der,clienteAux.nombres);
            }
            else /// Cuando 'arbol' es hoja
            {
                free (arbol);
                arbol = NULL;
            }
        }
        if (strcmp(nombres,clienteAux.nombres) > 0)
            arbol->der = borrarUnNodoArbol(arbol->der,nombres);

        if (strcmp(nombres,clienteAux.nombres) < 0)
            arbol->izq = borrarUnNodoArbol(arbol->izq,nombres);
    }
    return arbol;
}

// Pasa de Arbol a Cajas
void arbolToLineaDeCajas(nodoArbol* arbol,caja cajas[])
{
    int subOpcion = -1;
    while(subOpcion!=0 && subOpcion!=1 && subOpcion!=2 && subOpcion!=3)
    {
        system("cls");
        printf("\n\n   ______________________\n   | Modo Administrador |\n   ----------------------\n\n\n");
        printf("  \xA8\x42\x61\x6A\x6F qu\x82 criterio desea recorrer el arbol para la carga de cajas?\n\n 1. PreOrder\n 2. InOrder\n 3. PostOrder\n\n 0. Volver al men\xA3 de Administrador\n\n  ");
        fflush(stdin);
        scanf("%d",&subOpcion);

        switch (subOpcion)
        {
            case 0: break;
            case 1: arbolToLineaDeCajas_preOrder(arbol,cajas);
                    printf("\n  Las cajas han sido cargadas satisfactoriamente!\n\n  ");
                    fflush(stdin);
                    getchar();
                    break;
            case 2: arbolToLineaDeCajas_inOrder(arbol,cajas);
                    printf("\n  Las cajas han sido cargadas satisfactoriamente!\n\n  ");
                    fflush(stdin);
                    getchar();
                    break;
            case 3: arbolToLineaDeCajas_postOrder(arbol,cajas);
                    printf("\n  Las cajas han sido cargadas satisfactoriamente!\n\n  ");
                    fflush(stdin);
                    getchar();
                    break;
            default: printf("\n La opci\xA2n ingresada es inv\xA0lida!");
                    Sleep(1000);
                    break;
        }
    }
}

void arbolToLineaDeCajas_preOrder(nodoArbol* arbol,caja cajas[])
{
    if (arbol != NULL)
    {
        agregarClienteACaja(arbol->p,cajas);
        arbolToLineaDeCajas_preOrder(arbol->izq,cajas);
        arbolToLineaDeCajas_preOrder(arbol->der,cajas);
    }
}
void arbolToLineaDeCajas_inOrder(nodoArbol* arbol,caja cajas[])
{
    if (arbol != NULL)
    {
        arbolToLineaDeCajas_inOrder(arbol->izq,cajas);
        agregarClienteACaja(arbol->p,cajas);
        arbolToLineaDeCajas_inOrder(arbol->der,cajas);
    }
}
void arbolToLineaDeCajas_postOrder(nodoArbol* arbol,caja cajas[])
{
    if (arbol != NULL)
    {
        arbolToLineaDeCajas_postOrder(arbol->izq,cajas);
        arbolToLineaDeCajas_postOrder(arbol->der,cajas);
        agregarClienteACaja(arbol->p,cajas);
    }
}















//  Busqueda Sin terminar, sirve para eliminar, creo
/*nodoArbol* buscarArbolPor (nodoArbol * arbol)
{
    nodoArbol* rta = NULL;

    if (arbol != NULL)
    {
        if (legajo == arbol -> legajo)
            rta = arbol;

        else if (legajo > arbol -> legajo)
            buscarArbol (arbol -> der);

        else buscarArbol(arbol -> izq);
    }
    return rta;
}
*/

















/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////









