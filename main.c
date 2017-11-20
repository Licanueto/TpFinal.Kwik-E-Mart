#include <stdio.h>
#include <stdlib.h>
#include <string.h>         // Cada vez se use código del primer
#include <windows.h>        // cuatrimestre hay que reemplazar
#include "libTpFinal.h"     // cliente por persona (las personas siguen
                            // siendo los clientes del la empresa)

//   Para Modo Administrador: Usuario:admin
//                            Contraseña: admin


void main()
{
    system("color F1");

    char archivoUsuarios[]={"usuarios.dat"};
    char archivoPersonas[]={"personas.dat"};

    login(archivoUsuarios,archivoPersonas);

//  prubaEncriptacion();

//  testBusqueda();

//  cargaPersonas(archivoUsuarios);
}




void cargaUsuariosTest (char nombre_archivo[]) //
{
    char passlocal[11];
    char control='s';

    stUsuario a;
    FILE * archi;
    archi=fopen(nombre_archivo,"a+b");

    while(control=='s')
    {
        printf("Carga de Usuarios: \n");
        printf("\n User: ");
        fflush(stdin);
        scanf("%s",a.usuario);

        printf("\n Contrase\xA4\x61: ");
        fflush(stdin);
        gets(passlocal);
//        scanf("%s",&passlocal);

        encriptaPass(passlocal,a.pass);

        fwrite(&a,sizeof(stUsuario),1,archi); // Here lays all the crap

        printf("hasta aca llega?");

        printf("Desea crear otro usuario? si/no ");
        fflush(stdin);
        scanf("%c", &control);
        system("cls");
    }
    fclose(archi);
}

void prubaEncriptacion() //fn de prueba [encriptacion]
{
    char pass[11]={'h','o','l','a','m','u','n','d','o','s'};
    char passNueva[11];
    int passEncriptada[3][6];
    int i,j;

    printf("\n Pass sin encriptar: %s",pass);


    //Encripta y muestra
    printf("\n\n.. encripta..\n ");

    encriptaPass(pass,&passEncriptada);

    printf("\n passEncriptada: ");
    for (j=0;j<5;j++)
    {
        for (i=0;i<2;i++)
        {
            printf("%d ",passEncriptada[i][j]);
        }
    }
    printf("\n\n passEncriptada en su formato real: \n ");
    for (i=0;i<2;i++)
    {
        for (j=0;j<5;j++)
        {
            printf("%d ",passEncriptada[i][j]);
        }
        printf("\n ");
    }

    //Decripta y muestra
    printf("\n.. decripta..\n ");

    decriptaPass(passEncriptada,passNueva);

    printf("\n Pass desencriptada: ");
    for(i=0;i<10;i++)
    {
        printf("%c",passNueva[i]);
    }
    printf("\n Pass desencriptada leida como string: %s",passNueva);
    passNueva[10]='\0';
    printf("\n Pass desencriptada leida como string (null terminated): %s",passNueva);

    puts("\n\n\n\n");
}


int cargaPersonasAutomaticamente (char nombre_archivo_personas[]) // retorna el id asignado al cliente
{
    FILE * archi;
    archi=fopen(nombre_archivo_personas,"w+b");


    stPersona a;
    a.id=1;
    strcpy(a.apellido,"Aligieri");
    strcpy(a.nombres,"Alejandra");
    a.tipoCliente = 1;
    a.medioPago = 1;
    a.tiempoEspera=0;
    a.tiempoProcesado=0;
    a.eliminado=0;
    fwrite(&a,sizeof(stPersona),1,archi);

    a.id=1;
    strcpy(a.apellido,"Brites");
    strcpy(a.nombres,"Bartolo");
    a.tipoCliente = 2;
    a.medioPago = 2;
    a.tiempoEspera=0;
    a.tiempoProcesado=0;
    a.eliminado=0;
    fwrite(&a,sizeof(stPersona),1,archi);

    a.id=1;
    strcpy(a.apellido,"Caleno");
    strcpy(a.nombres,"Carlos");
    a.tipoCliente = 1;
    a.medioPago = 1;
    a.tiempoEspera=0;
    a.tiempoProcesado=0;
    a.eliminado=0;
    fwrite(&a,sizeof(stPersona),1,archi);

    a.id=1;
    strcpy(a.apellido,"D'Lorean");
    strcpy(a.nombres,"Dante");
    a.tipoCliente = 1;
    a.medioPago = 1;
    a.tiempoEspera=0;
    a.tiempoProcesado=0;
    a.eliminado=0;
    fwrite(&a,sizeof(stPersona),1,archi);

    a.id=1;
    strcpy(a.apellido,"Ez");
    strcpy(a.nombres,"Esteban");
    a.tipoCliente = 1;
    a.medioPago = 1;
    a.tiempoEspera=0;
    a.tiempoProcesado=0;
    a.eliminado=0;
    fwrite(&a,sizeof(stPersona),1,archi);

    a.id=1;
    strcpy(a.apellido,"Fernandez");
    strcpy(a.nombres,"Fernanda");
    a.tipoCliente = 1;
    a.medioPago = 1;
    a.tiempoEspera=0;
    a.tiempoProcesado=0;
    a.eliminado=0;
    fwrite(&a,sizeof(stPersona),1,archi);

    a.id=1;
    strcpy(a.apellido,"Juarez");
    strcpy(a.nombres,"Alejandra");
    a.tipoCliente = 1;
    a.medioPago = 1;
    a.tiempoEspera=0;
    a.tiempoProcesado=0;
    a.eliminado=0;
    fwrite(&a,sizeof(stPersona),1,archi);

    a.id=1;
    strcpy(a.apellido,"Juarez");
    strcpy(a.nombres,"Alejandra");
    a.tipoCliente = 1;
    a.medioPago = 1;
    a.tiempoEspera=0;
    a.tiempoProcesado=0;
    a.eliminado=0;
    fwrite(&a,sizeof(stPersona),1,archi);

    a.id=1;
    strcpy(a.apellido,"Juarez");
    strcpy(a.nombres,"Alejandra");
    a.tipoCliente = 1;
    a.medioPago = 1;
    a.tiempoEspera=0;
    a.tiempoProcesado=0;
    a.eliminado=0;
    fwrite(&a,sizeof(stPersona),1,archi);

    a.id=1;
    strcpy(a.apellido,"Juarez");
    strcpy(a.nombres,"Alejandra");
    a.tipoCliente = 1;
    a.medioPago = 1;
    a.tiempoEspera=0;
    a.tiempoProcesado=0;
    a.eliminado=0;
    fwrite(&a,sizeof(stPersona),1,archi);

    a.id=1;
    strcpy(a.apellido,"Juarez");
    strcpy(a.nombres,"Alejandra");
    a.tipoCliente = 1;
    a.medioPago = 1;
    a.tiempoEspera=0;
    a.tiempoProcesado=0;
    a.eliminado=0;
    fwrite(&a,sizeof(stPersona),1,archi);

    a.id=1;
    strcpy(a.apellido,"Juarez");
    strcpy(a.nombres,"Alejandra");
    a.tipoCliente = 1;
    a.medioPago = 1;
    a.tiempoEspera=0;
    a.tiempoProcesado=0;
    a.eliminado=0;
    fwrite(&a,sizeof(stPersona),1,archi);

    a.id=1;
    strcpy(a.apellido,"Juarez");
    strcpy(a.nombres,"Alejandra");
    a.tipoCliente = 1;
    a.medioPago = 1;
    a.tiempoEspera=0;
    a.tiempoProcesado=0;
    a.eliminado=0;
    fwrite(&a,sizeof(stPersona),1,archi);

    a.id=1;
    strcpy(a.apellido,"Juarez");
    strcpy(a.nombres,"Alejandra");
    a.tipoCliente = 1;
    a.medioPago = 1;
    a.tiempoEspera=0;
    a.tiempoProcesado=0;
    a.eliminado=0;
    fwrite(&a,sizeof(stPersona),1,archi);

    a.id=1;
    strcpy(a.apellido,"Juarez");
    strcpy(a.nombres,"Alejandra");
    a.tipoCliente = 1;
    a.medioPago = 1;
    a.tiempoEspera=0;
    a.tiempoProcesado=0;
    a.eliminado=0;
    fwrite(&a,sizeof(stPersona),1,archi);

    a.id=1;
    strcpy(a.apellido,"Juarez");
    strcpy(a.nombres,"Alejandra");
    a.tipoCliente = 1;
    a.medioPago = 1;
    a.tiempoEspera=0;
    a.tiempoProcesado=0;
    a.eliminado=0;
    fwrite(&a,sizeof(stPersona),1,archi);

    a.id=1;
    strcpy(a.apellido,"Juarez");
    strcpy(a.nombres,"Alejandra");
    a.tipoCliente = 1;
    a.medioPago = 1;
    a.tiempoEspera=0;
    a.tiempoProcesado=0;
    a.eliminado=0;
    fwrite(&a,sizeof(stPersona),1,archi);

    a.id=1;
    strcpy(a.apellido,"Juarez");
    strcpy(a.nombres,"Alejandra");
    a.tipoCliente = 1;
    a.medioPago = 1;
    a.tiempoEspera=0;
    a.tiempoProcesado=0;
    a.eliminado=0;
    fwrite(&a,sizeof(stPersona),1,archi);

    a.id=1;
    strcpy(a.apellido,"Juarez");
    strcpy(a.nombres,"Alejandra");
    a.tipoCliente = 1;
    a.medioPago = 1;
    a.tiempoEspera=0;
    a.tiempoProcesado=0;
    a.eliminado=0;
    fwrite(&a,sizeof(stPersona),1,archi);

    a.id=1;
    strcpy(a.apellido,"Juarez");
    strcpy(a.nombres,"Alejandra");
    a.tipoCliente = 1;
    a.medioPago = 1;
    a.tiempoEspera=0;
    a.tiempoProcesado=0;
    a.eliminado=0;
    fwrite(&a,sizeof(stPersona),1,archi);

    a.id=1;
    strcpy(a.apellido,"Juarez");
    strcpy(a.nombres,"Alejandra");
    a.tipoCliente = 1;
    a.medioPago = 1;
    a.tiempoEspera=0;
    a.tiempoProcesado=0;
    a.eliminado=0;
    fwrite(&a,sizeof(stPersona),1,archi);

    a.id=1;
    strcpy(a.apellido,"Juarez");
    strcpy(a.nombres,"Alejandra");
    a.tipoCliente = 1;
    a.medioPago = 1;
    a.tiempoEspera=0;
    a.tiempoProcesado=0;
    a.eliminado=0;
    fwrite(&a,sizeof(stPersona),1,archi);

    a.id=1;
    strcpy(a.apellido,"Juarez");
    strcpy(a.nombres,"Alejandra");
    a.tipoCliente = 1;
    a.medioPago = 1;
    a.tiempoEspera=0;
    a.tiempoProcesado=0;
    a.eliminado=0;
    fwrite(&a,sizeof(stPersona),1,archi);

    a.id=1;
    strcpy(a.apellido,"Juarez");
    strcpy(a.nombres,"Alejandra");
    a.tipoCliente = 1;
    a.medioPago = 1;
    a.tiempoEspera=0;
    a.tiempoProcesado=0;
    a.eliminado=0;
    fwrite(&a,sizeof(stPersona),1,archi);

    a.id=1;
    strcpy(a.apellido,"Juarez");
    strcpy(a.nombres,"Alejandra");
    a.tipoCliente = 1;
    a.medioPago = 1;
    a.tiempoEspera=0;
    a.tiempoProcesado=0;
    a.eliminado=0;
    fwrite(&a,sizeof(stPersona),1,archi);

    a.id=1;
    strcpy(a.apellido,"Juarez");
    strcpy(a.nombres,"Alejandra");
    a.tipoCliente = 1;
    a.medioPago = 1;
    a.tiempoEspera=0;
    a.tiempoProcesado=0;
    a.eliminado=0;
    fwrite(&a,sizeof(stPersona),1,archi);

    a.id=1;
    strcpy(a.apellido,"Juarez");
    strcpy(a.nombres,"Alejandra");
    a.tipoCliente = 1;
    a.medioPago = 1;
    a.tiempoEspera=0;
    a.tiempoProcesado=0;
    a.eliminado=0;
    fwrite(&a,sizeof(stPersona),1,archi);

    a.id=1;
    strcpy(a.apellido,"Juarez");
    strcpy(a.nombres,"Alejandra");
    a.tipoCliente = 1;
    a.medioPago = 1;
    a.tiempoEspera=0;
    a.tiempoProcesado=0;
    a.eliminado=0;
    fwrite(&a,sizeof(stPersona),1,archi);

    a.id=1;
    strcpy(a.apellido,"Juarez");
    strcpy(a.nombres,"Alejandra");
    a.tipoCliente = 1;
    a.medioPago = 1;
    a.tiempoEspera=0;
    a.tiempoProcesado=0;
    a.eliminado=0;
    fwrite(&a,sizeof(stPersona),1,archi);

    a.id=1;
    strcpy(a.apellido,"Juarez");
    strcpy(a.nombres,"Alejandra");
    a.tipoCliente = 1;
    a.medioPago = 1;
    a.tiempoEspera=0;
    a.tiempoProcesado=0;
    a.eliminado=0;
    fwrite(&a,sizeof(stPersona),1,archi);


    fclose(archi);
}
























