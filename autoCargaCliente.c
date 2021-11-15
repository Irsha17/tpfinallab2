#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "autoCargaCliente.h"

///.....................................FUNCIONES DE AUTOCARGA DE CLIENTES....................................................
///...........................................................................................................................


int getNroCliente(){
    int nro = rand()%100;
    return nro;
}


char *getDomicilio(){
    char *calle = (char*)malloc(sizeof(char)*30);
    char calles[1001][30];
    int v=0;
    char altura[6];

    v = csv2arreglo(30, "mocks/calles.csv", calles, 1001);

    strcpy(calle, calles[rand()%v]);
    strcpy(altura, getNro());
    strcat(calle," ");
    strcat(calle,altura);
    return calle;
}

char *getNro(){
    char *nro = (char*)malloc(sizeof(char)*7);

    itoa(rand()%10000, nro, 10);

    return nro;
}

char *getNombre(){
    char *nombre = (char*)malloc(sizeof(char)*30);
    char nombres[1001][30];
    int v=0;

    v = csv2arregloBis(30, "mocks/nombres.csv", nombres, 1001);

    strcpy(nombre, nombres[rand()%v]);

    return nombre;
}

char *getApellido(){
    char *apellido = (char*)malloc(sizeof(char)*30);
    char apellidos[1001][30];
    int v=0;

    v = csv2arregloBis(30, "mocks/apellidos.csv", apellidos, 1001);

    strcpy(apellido, apellidos[rand()%v]);

    return apellido;
}

char* getDni(){
    char *nro = (char*)malloc(sizeof(char)*10);
    long nroRand = rand()%40000000 + 20000000;
    itoa(nroRand, nro, 10);
    return nro;
}
char* getEmail(){
    char *email = (char*)malloc(sizeof(char)*30);
    char emails[1001][30];
    int v=0;

    v = csv2arregloBis(30, "mocks/email.csv", emails, 1001);

    strcpy(email, emails[rand()%v]);

    return email;
}

char* getMovil(){
    char *nro = (char*)malloc(sizeof(char)*15);
    char celulares[1001][30];
    int v=0;

    v = csv2arregloBis(30, "mocks/celulares.csv", celulares, 1001);

    strcpy(nro, celulares[rand()%v]);

    return nro;
}

int csv2arreglo(int col, char archivo[], char n[][col], int dim){
    FILE* archi = fopen(archivo, "r");
    int i=0;
    if(archi){
        while(fgets(n[i], col, archi)){
            n[i][strlen(n[i])-1] = '\0';
            i++;
        }
        fclose(archi);
    }
    return i;
}

int csv2arregloBis(int col, char archivo[], char n[][col], int dim){
    FILE* archi = fopen(archivo, "r");
    int i=0;
    if(archi){
        while((fscanf(archi, "%s",n[i])==1) && (i<dim)){
            i++;
        }
        fclose(archi);
    }
    return i;
}
