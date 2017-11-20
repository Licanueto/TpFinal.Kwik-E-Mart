#ifndef LIBTPFINAL_H_INCLUDED
#define LIBTPFINAL_H_INCLUDED

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

//  Principales
void login(char archivoUsuarios[],char archivoPersonas[]);
int admin(char archivoUsuarios[],char archivoPersonas[]); // Retorna 1 cuando se sale del sistema

//  Carga
void cargaUsuarios(char nombre_archivo_usuarios[]);
int cargaPersonas(char nombre_archivo_personas[]); // retorna el id asignado al cliente

//  Muestra
void muestraUsuarios(char nombre_archivo[]);
void mostrarUsuario(stUsuario a);
void muestraPersonas(char nombre_archivo[]);
void mostrarPersona(stPersona a);
void muestraAmbos(char nombre_archivo_usuarios[],char nombre_archivo_personas[],char criterio[]);

//  Modificación
void modificaPersonaPorId (char nombre_archivo_personas[]);
int eliminaUsuario(char nombre_archivo_usuarios[]);
int eliminaPersonas(char nombre_archivo_personas[]);

//  Encriptación
void encriptaPass (char pass[11],int *passEnciptada[3][6]);
void decriptaPass (int passEncriptada[3][6],char pass[11]);

//  Consulta
void consultaUsuario(char archivoUsuarios[],char archivoPersonas[]);

//  Busqueda
int buscaUsuario (char usuario_a_buscar[],char archivoUsuarios[]);
int buscaUsuarioPorId (int id_usuario_a_buscar, char archivoUsuarios[]);
int buscaPersonaPorNombre (char persona_a_buscar[],char archivoPersonas[]);
int buscaPersonaPorId (int id_persona_a_buscar[],char archivoPersonas[]);















#endif // LIBTPFINAL_H_INCLUDED
