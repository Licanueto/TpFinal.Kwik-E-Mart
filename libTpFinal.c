                                #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "libTpFinal.h"

//  Principales

void login(char archivoUsuarios[],char archivoPersonas[])
{
    int usuarioReconocido=0;
    int salir=0;
    char adminpass[6]="admin";
    char U_ingresado[20];
    char passIngresada[11];
    char passDesncriptadaLocal[11];

    FILE *archiUsuario, *archiPersona;
    stUsuario a;
    stUsuario aux; // prueba usandro struct
    stPersona p;
    archiUsuario=fopen(archivoUsuarios, "rb");
    archiPersona=fopen(archivoPersonas, "rb");

    while (salir != 1)
    {
        system("cls");
        printf("\n\n\n     |  Bienvenido!  |\n\n\n\n  Ingreso de credenciales\n  ------------------------\n\n  Usuario: ");
        fflush(stdin);
        gets(aux.usuario);
        printf("\n  Contrase\xA4\x61: ");
        fflush(stdin);
        gets(passIngresada);
        puts("\n\n");


        // Modo administrador para User: admin Pass:admin
        if ((strcmp(aux.usuario,adminpass) == 0) && strcmp(passIngresada,adminpass) == 0)
        {
            usuarioReconocido=1;
            salir = admin(archivoUsuarios,archivoPersonas);
        }


        // Compara credenciales y muestra (o no) la info del cliente
        if (archiUsuario!=NULL && usuarioReconocido == 0)
        {
            /*  printf("\n\nEl usuario ingresado fue: %s",aux.usuario);
                printf("\nEl usuario leido fue      : %s",a.usuario);
                printf("\nla contrasena ingresada fue: %s",passIngresada);
                printf("\nla contrasenia leida fue   : %s\n\n",passDesncriptadaLocal);
                fflush(stdin);
                getchar();
            */
            while(!feof(archiUsuario) && usuarioReconocido == 0)
            {
                fread(&a,sizeof(stUsuario),1,archiUsuario);
                fread(&p,sizeof(stPersona),1,archiPersona);
                decriptaPass(a.pass,passDesncriptadaLocal); //desencripta para comparar

                if ((strcmp(aux.usuario,a.usuario) == 0) && (strcmp(passIngresada,passDesncriptadaLocal) == 0)) // if pass correcta
                {
                    usuarioReconocido=1;
                    if (a.eliminado == 1)
                    {   printf("  El usuario al que esta intentando acceder parece haber sido dado de baja\n\n  ");} // if usuario eliminado
                    else
                    {
                        puts("\n  Informaci\xA2\x6E del Cliente\n  ---------------------------------------");   // muestra info
                        mostrarPersona(p);
                    }
                }
                if ((strcmp(aux.usuario,a.usuario) == 0) && (strcmp(passIngresada,passDesncriptadaLocal) != 0)) // usuario exista / pass incorrecta
                {
                    usuarioReconocido=1;
                    printf("\n\n  Contrase\xA4\x61 incorrecta!");
                    fflush(stdin);
                    getchar();
                }
            }
            if (usuarioReconocido == 0) // usuario no existe
            {
                printf("  El usuario %s no existe\n\n   ",aux.usuario);
            }
            fflush(stdin);
            getchar();
        }
        usuarioReconocido=0; // permite que el bucle se mantenga
    }
    fclose(archiUsuario);
    fclose(archiPersona);
}

int admin(char archivoUsuarios[],char archivoPersonas[]) // Retorna 1 cuando se sale del sistema
{
    int opcion=-1,subOpcion=-1,orden=0,retorno=0;
    while(opcion!=0)
    {
        system("cls");
        printf("\n\n   ______________________\n   | Modo Administrador |\n   ----------------------\n\n\n");
        printf("  \xA8\x51\x75\x82 desea hacer?\n\n 1. Alta\n 2. Baja\n 3. Modificaci\xA2\x6E\n 4. Consulta\n 5. Listado\n\n 9. Salir del modo administrador\n 0. Salir del sistema\n\n  ");
        fflush(stdin);
        scanf("%d",&opcion);

        switch (opcion)
        {
            case 0:             //  BUG: si se va desde éste menú de vuelta al login 'x' veces y
                system("cls");  //       se vuelve, al salir del sistema hay que salir 'x' veces
                system("color 0F");
                printf("\n\n\n\n\n\n\n                        ||||     Muchas gracias por usar el sistema!    ||||\n\n\n\n\n\n\n\n\n\n");
                retorno=1;
                break;
            case 1://Alta
                while(subOpcion!=1 && subOpcion!=2 && subOpcion!=0)
                {
                    system("cls");
                    printf("\n\n   ______________________\n   | Modo Administrador |\n   ----------------------\n\n\n");
                    printf("  \xA8\x41 qui\x82n desea dar de alta?\n\n 1. Usuario\n 2. Cliente\n\n 0. Volver al men\xA3 de anterior\n\n  ");
                    fflush(stdin);
                    scanf("%d",&subOpcion);
                    switch(subOpcion)
                    {
                        case 0: break;
                        case 1: cargaUsuarios(archivoUsuarios);
                                break;
                        case 2: cargaPersonas(archivoPersonas);
                                break;
                    }
                }
                subOpcion = -1;
                break;
            case 2://Baja
                while(subOpcion!=1 && subOpcion!=2 && subOpcion!=0)
                {
                    system("cls");
                    printf("\n\n   ______________________\n   | Modo Administrador |\n   ----------------------\n\n\n");
                    printf("  \xA8\x41 qui\x82n desea dar de baja?\n\n 1. Usuario\n 2. Cliente\n\n 0. Volver al men\xA3 de anterior\n\n  ");
                    fflush(stdin);
                    scanf("%d",&subOpcion);
                    switch(subOpcion)
                    {
                        case 0: break;
                        case 1: eliminaUsuario(archivoUsuarios);
                                break;
                        case 2: eliminaPersonas(archivoPersonas);
                                break;
                    }
                }
                subOpcion = -1;
                fflush(stdin); //
                getchar(); //
                break;
            case 3://Modificacion
                modificaPersonaPorId(archivoPersonas);
                break;
            case 4://Consulta
                consultaUsuario(archivoUsuarios,archivoPersonas);
                break;
            case 5://Listado
                while(subOpcion!=0 && subOpcion!=1 && subOpcion!=2 && subOpcion!=3) //&& subOpcion!=4 && subOpcion!=5)
                {
                    system("cls");
                    printf("\n\n   ______________________\n   | Modo Administrador |\n   ----------------------\n\n\n");
                    printf("  \xA8\x42\x61\x6A\x6F qu\x82 criterio desea listar a los clientes?\n\n 1. Por id\n 2. Por apellido\n 3. Por domicilio\n\n 9. M\xa0\x73 opciones\n 0. Volver al men\xA3 de Administrador\n\n  ");
                    fflush(stdin);
                    scanf("%d",&subOpcion);
                    do
                    {
                        switch (subOpcion)
                        {
                            case 0: break; // Vuelve a admin
                            case 1: muestraAmbos(archivoUsuarios,archivoPersonas,"porId");
                                    break;
                            case 2: muestraAmbos(archivoUsuarios,archivoPersonas,"porApellido");
                                    break;
                            case 3: muestraAmbos(archivoUsuarios,archivoPersonas,"porDomicilio");
                                    break;
                            case 4: muestraUsuarios(archivoUsuarios);
                                    subOpcion=3; /*evita que vuelva a entrar al do while*/
                                    break;
                            case 5: muestraPersonas(archivoPersonas);
                                    subOpcion=3; /*evita que vuelva a entrar al do while*/
                                    break;
                            case 8: break;
                            case 9: system("cls");
                                    printf("\n\n   ______________________\n   | Modo Administrador |\n   ----------------------\n\n\n");
                                    printf("  \xA8\x51\x75\x82 desea hacer?\n\n 4. Listar unicamente usuarios y contrase\xA4\x61\x73\n 5. Listar unicamente informaci\xA2\x6E de clientes\n\n 8. Volver al men\xA3 anterior\n 0. Volver al men\xA3 de Administrador\n\n  ");
                                    fflush(stdin);
                                    scanf("%d",&subOpcion);
                                    break;
                            default:printf("\n Opcion invalida. Seleccione alguna de las opciones listadas\n\n  ");
                                    Sleep(1900);
                                    break;
                        }}while (subOpcion == 4 || subOpcion == 5);
                }
                subOpcion=-1;
                break;
            case 9:
                    login(archivoUsuarios,archivoPersonas);
                    break;
            default:
                printf("\n Opcion invalida. Seleccione alguna de las opciones listadas");
                //fflush(stdin);
                //getchar();
                Sleep(1400);
                break;

        }
    }
    return(retorno);
}


//  Carga

void cargaUsuarios(char nombre_archivo_usuarios[])
{
    char passlocal[11];
    char control='s';

    stUsuario a;
    stUsuario anterior; /// Para saber cuál fue el ultimo Id asignado
    FILE * archi;
    archi=fopen(nombre_archivo_usuarios,"a+b");

    while(control=='s')
    {
        system("cls");
        printf("\n\n   ______________________\n   | Modo Administrador |\n   ----------------------\n\n\n");
        printf(" Defina las credenciales del nuevo usuario \n");
        printf("\n Usuario: ");
        fflush(stdin);
        scanf("%s",a.usuario);

        while (buscaUsuario(a.usuario,nombre_archivo_usuarios) == 1 || strcmp(a.usuario,"admin") == 0 || strcasecmp(a.usuario,"salir") == 0)
        {
            printf("\n\n                                                                            [M\xA0x: 20 caracteres]");
            printf("\n El usuario %s ya existe o es inv\xA0\x6C\x69\x64\x6F\x2C por favor elija un nuevo usuario: ",a.usuario);
            fflush(stdin);
            scanf("%s",a.usuario);
        }

        printf("\n Contrase\xA4\x61: ");
        fflush(stdin);
        gets(passlocal);

        while (strlen(passlocal)!=10)
        {
            printf("\n Contrase\xA4\x61 inv\xA0\x6C\x69\x64\x61\x21 Esta debe contener 10 caracteres\n Password: ");
            fflush(stdin);
            gets(passlocal);
        }
        puts("\n----------------------------------\n");

        encriptaPass(passlocal,a.pass);

        a.eliminado=0;

        //          modificando..
        if (fseek(archi,sizeof(stUsuario)*(-1),SEEK_END) == 0)
        {
            fread(&anterior,sizeof(stPersona),1,archi);
            a.id=anterior.id+1;
            fseek(archi,1,SEEK_CUR); // qué onda esto??
        }
        else a.id=1; /// Nro que se le asigna al primer cliente

        //////////////////////
        printf(" El id asignado al cliente fue: %d\n\n",a.id);

        fwrite(&a,sizeof(stUsuario),1,archi);


        printf("Desea crear otro usuario? (s/n) ");
        fflush(stdin);
        scanf("%c", &control);
        system("cls");
    }
    fclose(archi);
}

int cargaPersonas(char nombre_archivo_personas[]) // retorna el id asignado al cliente
{
    char control='s';

    stPersona a;
    stPersona anterior; //para saber cual fue el ultimo id asignado
    FILE * archi;
    archi=fopen(nombre_archivo_personas,"a+b");

    while(control=='s')
    {
        system("cls");
        printf("\n\n   ______________________\n   | Modo Administrador |\n   ----------------------\n\n\n");

        printf(" Ingreso de datos sobre el cliente: \n");
        printf("\n Nombres: ");
        fflush(stdin);
        gets(a.nombres);

        printf("\n Apellido: ");
        fflush(stdin);
        gets(a.apellido);

        printf("\n Niveles de prioridad de cliente:   1 - Embarazada  |  2 - Jubilado  |  3 - Cliente com\xA3n\n \xA8\x51\x75\x82 tipo de cliente es? :  ");
        fflush(stdin);
        scanf("%d",&a.tipoCliente);

        printf("\n Medios de pago disponibles:   1 - Efectivo  |  2 - Cr\x82\x64ito  |  3 - Ambos \n Como abonara? :");
        fflush(stdin);
        scanf("%d",&a.medioPago);

        puts("\n----------------------------------\n");

        a.tiempoEspera=0;
        a.tiempoProcesado=0;
        a.eliminado=0;

        if (fseek(archi,sizeof(stPersona)*(-1),SEEK_END) == 0)
        {
            fread(&anterior,sizeof(stPersona),1,archi);
            a.id=anterior.id+1;
            fseek(archi,1,SEEK_CUR);
        }
        else a.id=1; /// Nro que se le asigna al primer cliente
        printf(" El id asignado al cliente fue: %d\n\n",a.id);

        fwrite(&a,sizeof(stPersona),1,archi);

        printf("  \xA8\x44\x64sea dar de alta a otro cliente? (s/n) ");
        fflush(stdin);
        scanf("%c", &control);
        system("cls");
    }
    fclose(archi);
    return(a.id);
}


// Muestra

void muestraUsuarios(char nombre_archivo[])
{
    FILE *archi;
    stUsuario a;
    archi=fopen(nombre_archivo, "rb");

    system("cls");
    printf("\n\n   ______________________\n   | Modo Administrador |\n   ----------------------\n\n\n");

    int i=0;
    int eliminados=0;

    if (archi!=NULL)
    {
        while(!feof(archi))
        {
            fread(&a,sizeof(stUsuario),1,archi);
            if(!feof(archi) && a.eliminado == 0)
            {
                printf("\n  Registro numero %d",i);
                puts("\n  ---------------------------------------");
                mostrarUsuario(a);
                puts("\n");
            }
            else if (a.eliminado == 1)
            {
                eliminados++;
            }
            i++;
        }
    }
    fclose(archi);
    printf("\n Usuarios Eliminados: %d\n\n  ",eliminados);
    fflush(stdin);
    getchar();
}
void mostrarUsuario(stUsuario a)
{
    int i;
    char passDesencriptadaLocal[11];

    decriptaPass(a.pass,passDesencriptadaLocal);

    printf("  Usuario: %s", a.usuario);
    printf("\n  Contrase\xA4\x61: %s",passDesencriptadaLocal);
}

void muestraPersonas(char nombre_archivo[])
{
    FILE *archi;
    stPersona a;
    archi=fopen(nombre_archivo, "rb");

    system("cls");
    printf("\n\n   ______________________\n   | Modo Administrador |\n   ----------------------\n\n\n");

    int i=0;
    int eliminados=0;

    if (archi!=NULL)
    {
        while(!feof(archi))
        {
            fread(&a,sizeof(stPersona),1,archi);
            if(!feof(archi) && a.eliminado == 0)
            {
                printf("\n  Registro numero %d",i);
                puts("\n  ---------------------------------------");
                mostrarPersona(a);
            }
            else if (a.eliminado == 1)
            {
                eliminados++;
            }
            i++;
        }
    }
    fclose(archi);
    printf("\n Personas Eliminados: %d\n\n  ",eliminados);
    fflush(stdin);
    getchar();
}
void mostrarPersona(stPersona a)
{
    printf("     Nombres: %s", a.nombres);
    printf("\n    Apellido: %s", a.apellido);
    printf("\n  Prioridad : %d", a.tipoCliente);
    printf("\n       Abona: %d\n\n ",a.medioPago);
}

void muestraAmbos(char nombre_archivo_usuarios[],char nombre_archivo_personas[],char criterio[])
{
    FILE *archiUsuario,*archiPersona;
    stUsuario a,usuarioAux;
    stPersona p,clienteAux;

    archiUsuario=fopen(nombre_archivo_usuarios, "rb");
    archiPersona=fopen(nombre_archivo_personas, "rb");

    system("cls");
    printf("\n\n   ______________________\n   | Modo Administrador |\n   ----------------------\n\n\n");


    if (strcmp(criterio,"porId") == 0)
    {
        int i=0;
        int eliminados=0;

        if (archiUsuario!=NULL && archiPersona!=NULL)
        {
            while(!feof(archiUsuario) && !feof(archiPersona))
            {
                fread(&a,sizeof(stUsuario),1,archiUsuario);
                fread(&p,sizeof(stPersona),1,archiPersona);

                if(!feof(archiUsuario)   && !feof(archiPersona) && a.eliminado == 0)
                {
                    printf("\n  Registro numero %d",i);
                    puts("\n  ---------------------------------------");
                    mostrarUsuario(a);
                    puts(" ");
                    mostrarPersona(p);
                }
                else if (a.eliminado == 1)
                {
                    eliminados++;
                }
                i++;
            }
            printf("\n Usuarios Eliminados: %d\n\n  ",eliminados);
        }
        else printf(" Todavia no fue agregado ning\xA3\x6E cliente\n Para agregar clientes seleccione la opci\xA2\x6E 1 en el men\xA3 de Administrador\n\n  ");

        fflush(stdin);
        getchar();

    }

    fclose(archiUsuario);
    fclose(archiPersona);




    /*  // ORDENADO COMO VIENE
    int i=0;
    int eliminados=0;

    if (archiUsuario!=NULL && archiPersona!=NULL)
    {
        while(!feof(archiUsuario) && !feof(archiPersona))
        {
            fread(&a,sizeof(stUsuario),1,archiUsuario);
            fread(&p,sizeof(stPersona),1,archiPersona);
            if(!feof(archiUsuario) && !feof(archiPersona) && a.eliminado == 0)
            {
                printf("\n  Registro numero %d",i);
                puts("\n  ---------------------------------------");
                mostrarUsuario(a);
                puts(" ");
                mostrarPersona(p);
            }
            else if (a.eliminado == 1)
            {
                eliminados++;
            }
            i++;
        }
            printf("\n Usuarios Eliminados: %d\n\n  ",eliminados);
        }
        else printf(" Todavia no fue agregado ning\xA3\x6E cliente\n Para agregar clientes seleccione la opci\xA2\x6E 1 en el men\xA3 de Administrador\n\n  ");

        fclose(archiUsuario);
        fclose(archiPersona);

        fflush(stdin);
        getchar();

    }
*/
}



//  Modificación

void modificaPersonaPorId (char nombre_archivo_personas[])
{ /* Esta funcion originalmente modificaba ambas estructuras, si se necesita modificar la estructura de usuarios buscar en la original, or just recode it you lazy fuck */

    FILE *archiPersona;
    stPersona p;

    archiPersona=fopen(nombre_archivo_personas, "rb+");

    system("cls");
    printf("\n\n   ______________________\n   | Modo Administrador |\n   ----------------------\n\n\n");

    int id;
    int existe=0,eliminado=0;
    int campo_a_modificar=-1;
    char alta;

    printf(" Ingrese el n\xA3mero de identificaci\xA2n de la persona a modificar: ");
    fflush(stdin);
    scanf("%d",&id);
    system("cls");
    printf("\n\n   ______________________\n   | Modo Administrador |\n   ----------------------\n\n\n");


    // Chequea que exista usuario para la id ingresada y muestra sus datos
    if (archiPersona!=NULL)
    {
        while(!feof(archiPersona) && existe == 0)
        {
            fread(&p,sizeof(stPersona),1,archiPersona);

            if(id == p.id && !feof(archiPersona))
            {
                mostrarPersona(p);
                existe++;
                if (p.eliminado == 1)
                    {
                        printf("\n Aviso: Este cliente se encuentra dado de baja\n  ");
                    }
            }
        }
    }

    if (existe == 0)
    {
        printf("\n No se encontro ningun cliente con n\xA3mero de identificaci\xA2n %d\n\n  ",id);
        fflush(stdin);
        getchar();
    }
    // Se modifican los datos del cliente
    else
    {
        while (campo_a_modificar!=0 && campo_a_modificar!='n')
        {   printf("\n \xA8\x51\x75\x82 campo desea modificar?\n\n 1. Id\n 2. Nombres\n 3. Apellido\n 4. Tipo de cliente\n 5. Medio de Pago\n\n 0. No modificar ningun campo\n\n  ");
            fflush(stdin);
            scanf("%d",&campo_a_modificar);

            char passlocal[11]; // para poder modificar la contraseña
            switch (campo_a_modificar)
            {
                case 0:
                        break;
                case 1:
                        printf("\n Nuevo n\xA3mero de identificaci\nA2n: ");
                        fflush(stdin);
                        scanf("%d",p.id);
                        while (buscaPersonaPorId(p.id,nombre_archivo_personas) == 1 || id ==0)
                        {
                            printf("\n\n El id #%d ya existe o es inv\xA0\x6C\x69\x64\x6F\x2C por favor elija un nuevo id: ",id);
                            fflush(stdin);
                            scanf("%d",p.id);
                        }
                        break;
                case 2:
                        printf("\n Nuevo Nombre: ");
                        fflush(stdin);
                        gets(p.nombres);
                        break;
                case 3:
                        printf("\n Nuevo Apellido: ");
                        fflush(stdin);
                        gets(p.apellido);
                        break;
                case 4:
                        printf("\n Nuevo Tipo de cliente: ");
                        fflush(stdin);
                        scanf("%d",p.tipoCliente);
                        break;
                case 5:
                        printf("\n Nuevo Medio de Pago: ");
                        fflush(stdin);
                        scanf("%d",p.medioPago);
                        break;
            }
            if (campo_a_modificar != 0)
            {
                fseek(archiPersona,sizeof(stPersona)*-1,SEEK_CUR);
                fwrite(&p,sizeof(stPersona),1,archiPersona);
                printf("\n\n El campo ha sido modificado satisfactoriamente"); /* monsanto approves */
            }
            while (campo_a_modificar != 0 && campo_a_modificar != 's' && campo_a_modificar!= 'n')
            {
                printf("\n\n Desea modificar algun otro campo?  s/n ");
                fflush(stdin);
                scanf("%c",&campo_a_modificar);
                if (campo_a_modificar != 's' && campo_a_modificar!= 'n')
                {
                    printf("\n\n Respuesta inv\xA0\x6C\x69\x64\x61\x21\n\n");
                    fflush(stdin);
                    getchar();
                }
            }

        }
    }
    fclose(archiPersona);
}

int eliminaUsuario(char nombre_archivo_usuarios[])
{
    FILE *archiUsuario;                                         /*        Devuelve:         */
    stUsuario a;                                                /*      0 si no elimina     */
    archiUsuario=fopen(nombre_archivo_usuarios, "rb+");         /*       1 si elimina       */

    system("cls");
    printf("\n\n   ______________________\n   | Modo Administrador |\n   ----------------------\n\n\n");

    int opcion = -1;
    int eliminado=0;
    int id_a_eliminar;
    char usuario_a_eliminar[20];

    while (opcion!=1 && opcion!=2 && opcion!=0) // Pregunta
    {
        printf("\n C\xA2mo desea indentificar al usuario a eliminar? \n\n 1. Usuario\n 2. Id\n\n 0. Volver al menu de Administrador\n\n  ");
        fflush(stdin);
        scanf("%d",&opcion);
    }
    if (opcion == 1) // Elimina por nombre Usuario
    {
        printf("\n Inserte el usuario a dar de baja: ");
        fflush(stdin);
        scanf("%s",usuario_a_eliminar);

        // Checkea que exista
        while (buscaUsuario(usuario_a_eliminar,nombre_archivo_usuarios) == 0)
        {
            printf("\n El usuario %s no existe      [ Tip: Si desea volver al men\xA3 ingrese \"salir\" ]\n\n Ingrese otro usuario a dar de baja: ",usuario_a_eliminar);
            fflush(stdin);
            scanf("%s",usuario_a_eliminar);
            if (strcmp(usuario_a_eliminar,"salir") == 0)
            {
                break;
            }
        }

        // Elimina por usuario
        if (archiUsuario!=NULL)
        {
            while(!feof(archiUsuario) && eliminado == 0)
            {
                fread(&a,sizeof(stUsuario),1,archiUsuario);
                if ((strcmp(usuario_a_eliminar,a.usuario) == 0) && (a.eliminado == 1))
                {
                    printf("\n El usuario %s ya hab\xA1\x61 sido dado de baja anteriormente\n ",a.usuario);
                    eliminado = 1;
                }
                else if (strcmp(usuario_a_eliminar,a.usuario) == 0)
                {
                    a.eliminado=1; // asigna un 1 al campo "eliminado"
                    eliminado=1; // retorno de la funcion, despues si puede eliminar en personas se pone en 1
                    fseek(archiUsuario,sizeof(stUsuario)*-1,SEEK_CUR);
                    fwrite(&a,sizeof(stUsuario),1,archiUsuario);
                    printf("\n EL usuario %s ha sido dado de baja satisfactoriamente\n\n  ",a.usuario);
                }
            }
            if (eliminado != 1)
                printf("\n No se encontr\xA2 ningun usuario bajo el nombre %s",usuario_a_eliminar);
        }
    }

    if (opcion == 2)  // Elimina por Id
    {
        printf("\n Inserte el #Id del usuario a dar de baja: ");
        fflush(stdin);
        scanf("%d",&id_a_eliminar);

        if (archiUsuario!=NULL && eliminado == 0)
        {
            while (!feof(archiUsuario) && eliminado == 0)
            {
                fread(&a,sizeof(stUsuario),1,archiUsuario);
                if (a.id == id_a_eliminar)
                {
                    a.eliminado = 1;
                    eliminado = 2; //corta el while, tmb es valor de retorno
                    fseek(archiUsuario,sizeof(stUsuario)*-1,SEEK_CUR);
                    fwrite(&a,sizeof(stUsuario),1,archiUsuario);
                    printf("\n El usuario %s fu\x82 dado de baja existosamente\n ",a.usuario);
                }
            }
            if (eliminado != 2)
                printf("\n No se encontr\xA2 ningun usuario con #Id = %d",id_a_eliminar);
        }
    }
    fclose(archiUsuario);
    return(eliminado);
}

int eliminaPersonas(char nombre_archivo_personas[])
{
    FILE *archiPersona;                                         /*          Devuelve:       */
    stPersona p;                                                /*      0 si no elimina     */
    archiPersona=fopen(nombre_archivo_personas, "rb+");         /*      1 si elimina        */

    system("cls");
    printf("\n\n   ______________________\n   | Modo Administrador |\n   ----------------------\n\n\n");

    int opcion = -1;
    int eliminado = 0;
    int id_a_eliminar;
    char cliente_a_eliminar[20];

    while (opcion!=1 && opcion!=2 && opcion!=0)
    {
        printf("\n C\xA2mo desea indentificar al cliente a eliminar? \n\n 1. Nombre\n 2. Id\n\n 0. Volver al menu de Administrador\n  ");
        fflush(stdin);
        scanf("%d",&opcion);
    }
    if (opcion == 1) // Elimina por nombre
    {   printf("\n\n Inserte nombre del cliente a dar de baja: ");
        fflush(stdin);
        scanf("%s",cliente_a_eliminar);

        // Checkea que exista
        while (buscaPersonaPorNombre(cliente_a_eliminar,nombre_archivo_personas) == 0)
        {
            printf("\n El cliente %s no existe      [ Tip: Si desea volver al men\xA3 ingrese \"salir\" ]\n\n Ingrese otro usuario a dar de baja: ",cliente_a_eliminar);
            fflush(stdin);
            scanf("%s",cliente_a_eliminar);
            if (strcmp(cliente_a_eliminar,"salir") == 0)
                break;
        }

        // Elimina en Personas por nombre
        if (archiPersona!=NULL)
        {
            while(!feof(archiPersona) && eliminado == 0)
            {
                fread(&p,sizeof(stPersona),1,archiPersona);
                if ((strcmp(cliente_a_eliminar,p.nombres) == 0) && (p.eliminado == 1))
                {
                    printf("\n El cliente %s ya hab\xA1\x61 sido dado de baja anteriormente\n ",p.nombres);
                    eliminado = 1;
                }
                else if (strcmp(cliente_a_eliminar,p.nombres) == 0)
                {
                    p.eliminado = 1; // asigna un 1 al campo "eliminado"
                    eliminado = 1; // retorno de la funcion, despues si puede eliminar en personas se pone en 1
                    fseek(archiPersona,sizeof(stPersona)*-1,SEEK_CUR);
                    fwrite(&p,sizeof(stPersona),1,archiPersona);
                    printf("\n EL usuario %s %s ha sido dado de baja satisfactoriamente\n\n  ",p.nombres,p.apellido);
                }
            }
            if (eliminado != 1)
                printf("\n No se encontr\xA2 ningun cliente bajo el nombre %s",cliente_a_eliminar);
        }
    }

    if (opcion == 2)  // Elimina en Personas por id
    {
        printf("\n Inserte el #Id del cliente a dar de baja: ");
        fflush(stdin);
        scanf("%d",&id_a_eliminar);

        if (archiPersona!=NULL) // eliminado==1 se fija que se haya eliminado el usuario mas arriba
        {
            while(!feof(archiPersona) && eliminado == 0)
            {
                fread(&p,sizeof(stPersona),1,archiPersona);
                if (p.id == id_a_eliminar)
                {
                    p.eliminado=1; // asigna un 1 al campo "eliminado"
                    eliminado=2; // corta el while (tmb es valor de retorno)
                    fseek(archiPersona,sizeof(stPersona)*-1,SEEK_CUR);
                    fwrite(&p,sizeof(stPersona),1,archiPersona);
                    printf("\n El cliente %s %s fu\x82 dado de baja exitosamente\n ",p.nombres,p.apellido);
                }
            }
            if (eliminado != 2)
                printf("\n No se encontr\xA2 ningun cliente con #Id = %d",id_a_eliminar);
        }
    }
    fclose(archiPersona);
    return eliminado;
}


void encriptaPass (char pass[11],int *passEnciptada[3][6])
{
    int i,j,k=0;
    int matrizAux[3][6];
    int matrizEncriptadora[3][3];
    matrizEncriptadora[0][0]=1;         /*   Visualmente   */
    matrizEncriptadora[0][1]=2;
    matrizEncriptadora[1][0]=1;         /*     / 1 2 \     */
    matrizEncriptadora[1][1]=3;         /*     \ 1 3 /     */


    // Vuelco pass[11] a matrizAux[2][5]
    for (j=0;j<5;j++)
    {
        for (i=0;i<2;i++)
        {
            matrizAux[i][j]=pass[k];
            k++;
        }
    }

    // Multiplico matrizEncriptadora*matrizAux
    for (j=0;j<5;j++)
    {
        for (i=0;i<2;i++)
        {
            passEnciptada[i][j]=matrizEncriptadora[i][0]*matrizAux[0][j]+matrizEncriptadora[i][1]*matrizAux[1][j];
        }
    }

}
void decriptaPass (int passEncriptada[3][6],char pass[11])
{
    int i,j,k=0;
    int matrizAux[3][6];
    int matrizDecriptadora[3][3];
    matrizDecriptadora[0][0]=3;         /*     Visualmente     */
    matrizDecriptadora[0][1]=-2;
    matrizDecriptadora[1][0]=-1;         /*      / 3 -2\        */
    matrizDecriptadora[1][1]=1;         /*      \-1 1 /        */

    // Multiplica por la inversa
    for (j=0;j<5;j++)
    {
        for (i=0;i<2;i++)
        {
            matrizAux[i][j]=matrizDecriptadora[i][0]*passEncriptada[0][j]+matrizDecriptadora[i][1]*passEncriptada[1][j];
        }
    }
    // Vuelco matrizAux[2][5] a pass[11]
    for (j=0;j<5;j++)
    {
        for (i=0;i<2;i++)
        {
            pass[k]=matrizAux[i][j];
            k++;
        }
    }
    pass[10]='\0';
}


void consultaUsuario(char archivoUsuarios[],char archivoPersonas[])
{
    int existe=0;
    char usuarioTeclado[20];
    FILE *archiUsuario, *archiPersona;
    stUsuario a;
    stPersona p;
    archiUsuario=fopen(archivoUsuarios, "rb");
    archiPersona=fopen(archivoPersonas, "rb");

    system("cls");
    printf("\n\n   ______________________\n   | Modo Administrador |\n   ----------------------\n\n\n");
    printf("Ingrese el usuario por el cual desea realizar la consulta: ");
    scanf("%s",usuarioTeclado);

    if (archiUsuario!=NULL)
    {
        while(!feof(archiUsuario))
        {
            fread(&a,sizeof(stUsuario),1,archiUsuario);
            fread(&p,sizeof(stPersona),1,archiPersona);

            //printf("strcmp vale: %d\n",strcmp(usuario_a_buscar,a.usuario));
            if (strcmp(usuarioTeclado,a.usuario) == 0)
            {
                existe=1;
                mostrarUsuario(a);
                puts(" ");
                mostrarPersona(p);

                if (a.eliminado == 1)
                   printf("\n\n Notese que el usuario %s se encuentra dado de baja",a.usuario);
            }
        }
        if (existe == 0)
            printf("  El usuario %s no existe",usuarioTeclado);
    }
    else printf("\n\n  El usuario no fue encontrado dado que todavia no fue cargado ningun usuario");

    fclose(archiUsuario);
    fclose(archiPersona);
}

int buscaUsuario (char usuario_a_buscar[],char archivoUsuarios[])
{
    int existe=0;                                   /*      Devuelve                */
    stUsuario a;                                    /*   0 si el usuario no existe  */
    FILE * archi;                                   /*   1 si el usuario existe     */
    archi=fopen(archivoUsuarios,"rb");

    if (archi!=NULL)
    {
        while(!feof(archi))
        {
            fread(&a,sizeof(stUsuario),1,archi);
          //  printf("strcmp vale: %d\n",strcmp(usuario_a_buscar,a.usuario));
            if (strcmp(usuario_a_buscar,a.usuario) == 0)
                existe=1;
        }
    }
    fclose(archi);
    return existe;
}
int buscaUsuarioPorId (int id_usuario_a_buscar, char archivoUsuarios[])
{
    int existe = 0;
    stUsuario a;
    FILE *archi;
    archi = fopen(archivoUsuarios,"rb");

    if (archi != NULL)
    {
        while (!feof(archi) && existe == 0)
        {
            fread(&a,sizeof(stUsuario),1,archi);
            if (id_usuario_a_buscar == a.id)
                existe = 1;
        }
    }
    fclose(archi);
    return existe;
}

int buscaPersonaPorNombre (char persona_a_buscar[],char archivoPersonas[])
{
    int existe=0;                                   /*      Devuelve                */
    stPersona a;                                    /*   0 si el usuario no existe  */
    FILE * archi;                                   /*   1 si el usuario existe     */
    archi=fopen(archivoPersonas,"rb");

    if (archi!=NULL)
    {
        while(!feof(archi))
        {
            fread(&a,sizeof(stPersona),1,archi);
          //  printf("strcmp vale: %d\n",strcmp(usuario_a_buscar,a.usuario));
            if (strcmp(persona_a_buscar,a.nombres) == 0)
                existe = 1;
        }
    }
    fclose(archi);
    return existe;
}
int buscaPersonaPorId (int id_persona_a_buscar[],char archivoPersonas[])
{
    int existe = 0;                                 /*      Devuelve:               */
    stPersona p;                                    /*   0 si el usuario no existe  */
    FILE * archi;                                   /*   1 si el usuario existe     */
    archi=fopen(archivoPersonas,"rb");

    if (archi!=NULL)
    {
        while(!feof(archi))
        {
            fread(&p,sizeof(stPersona),1,archi);
            if (id_persona_a_buscar == p.id)
                existe = 1;
        }
    }
    fclose(archi);
    return existe;
}
