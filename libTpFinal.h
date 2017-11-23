#ifndef LIBTPFINAL_H_INCLUDED
#define LIBTPFINAL_H_INCLUDED

char archivoUsuarios[]={"usuarios.dat"};
char archivoPersonas[]={"personas.dat"};

typedef struct { // Usuario
    int id;
    char usuario[20];
    int pass[3][6];
    int eliminado;  /// indica 1 o 0 si el usuario fue eliminado
} stUsuario;

typedef struct { // Persona
    int id;
    char apellido[30];
    char nombres [40];
    int tipoCliente; 		/// Prioridad 1:embarazada, 2:jubilado y 3:cliente común
    int medioPago;			/// 1:efectivo, 2:crédito y 3:todos
    int cantArticulos;		/// es el tiempo de ejecución
    int tiempoEspera;       /// es el tiempo de respuesta                              | Inicia en 0 por default! |
    int tiempoProcesado;    /// es el tiempo que ya fue procesado en la línea de caja  | Inicia en 0 por default! |
    int eliminado;			/// 1: eliminado, 0: activo
} stPersona;

/// Test: todas las estructuras acá adentro de libtpFinal.h
//  Nodo lista
typedef struct{
        stPersona cliente;
        struct nodo* siguiente;
        struct nodo* anterior;
}nodo;
//  Fila
typedef struct{
        struct nodo* inicio;
        struct nodo* finall; // final me lo toma como palabra reservada
} Fila;

//  Arbol
typedef struct{
    int legajo;
    char nombre[20];
    struct nodoArbol* izq;
    struct nodoArbol* der;
}nodoArbol;






//  Principales
void login();
int admin(); // Retorna 1 cuando se sale del sistema

//  Carga
void cargaUsuarios();
int cargaPersonas(); // retorna el id asignado al cliente
void cargaPersonasAlArchivo();

//  Muestra
void muestraUsuarios();
void mostrarUsuario(stUsuario a);
void muestraPersonas();
void mostrarPersona(stPersona a);
void muestraAmbos(char criterio[]);

//  Modificación
void modificaPersonaPorId ();
int eliminaUsuario();
int eliminaPersonas();

//  Encriptación
void encriptaPass (char pass[11],int *passEnciptada[3][6]);
void decriptaPass (int passEncriptada[3][6],char pass[11]);

//  Consulta
void consultaUsuario();
int cantidadPersonasCargadas();

//  Busqueda
int buscaUsuario (char usuario_a_buscar[]);
int buscaUsuarioPorId (int id_usuario_a_buscar);
int buscaPersonaPorNombre (char persona_a_buscar[]);
int buscaPersonaPorId (int id_persona_a_buscar);











#endif // LIBTPFINAL_H_INCLUDED
