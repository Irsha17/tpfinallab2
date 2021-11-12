#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "string.h"
#include "autoCargaCliente.h"

///.....................................FUNCIONES PARA CARGAR CLIENTES A UN ARCHIVO...........................................
///...........................................................................................................................


//FUNCION PARA CARGAR UN CLIENTE DE FORMA MANUAL
void cargarCliente(char archivo[]){// RECIBE COMO PARAMETRO EL ARCHIVO DONDE SE GUARDA EL CLIENTE
    FILE * archi;//puntero al archivo
    stCliente cliente;//creamos el nombre de la estrutura para cargar los datos
    int i=0;
    int validacion=0;
    int pos=0;

    char control= 115;

    archi = fopen(archivo,"ab");//abrimos el archivo en modo ab para agregar un dato al ultimo elemento de nuestro archivo

    printf("\t\t\t--CARGAR DATOS DEL CLIENTE--\n\n");

    if (archi != NULL){
        while (control == 115){

            cliente.id = contarIdCliente(archi)+i;
            printf("\nID del Cliente: %d",cliente.id);

            printf("\nIngrese el Numero de Cliente: ");
            scanf("%d", &cliente.nroCliente);

            do{
                validacion = validacionNroCliente(archivo,cliente.nroCliente);
                if(validacion==1){
                    printf("\nEl Numero de Cliente ya fue registrado ");
                    printf("\nIngrese el Numero de Cliente: ");
                    fflush(stdin);
                    scanf("%d", &cliente.nroCliente);
                }
            } while(validacion==1);

            printf("\nIngrese Nombre del Cliente: ");
            fflush(stdin);
            gets(&cliente.nombre);

            printf("\nIngrese Apellido del Cliente: ");
            fflush(stdin);
            gets(&cliente.apellido);

            printf("\nIngrese el dni del Cliente: ");
            fflush(stdin);
            gets(&cliente.dni);
            validacion = validacionClienteDni(archivo,cliente.dni);

            while(validacion==1){
                printf("\nEl dni ingresado ya fue registrado ");
                printf("\nIngrese el dni del Cliente: ");
                fflush(stdin);
                gets(&cliente.dni);
                validacion = validacionClienteDni(archivo,cliente.dni);
            }

            printf("\nIngrese el e-mail del Cliente: ");
            fflush(stdin);
            scanf("%s",&cliente.email);
            validacion = validacionEmail(archivo,50,cliente.email);

            while(validacion==1){
                printf("\nEl e-mail ingresado ya fue registrado ");
                printf("\nIngrese el e-mail del Cliente: ");
                fflush(stdin);
                scanf("%s", &cliente.email);
                validacion = validacionEmail(archivo,50,cliente.email);
            }


            printf("\nIngrese el numero de movil del Cliente: ");
            printf("\n<El numero de area sin el 0, el resto sin el 15> ");
            fflush(stdin);
            scanf("%s", cliente.movil);

            printf("\nIngrese el domicilio del Cliente: ");
            fflush(stdin);
            fgets(cliente.domicilio, 45, stdin);

            printf("\nEstado del Cliente (0 = Activo / 1 = Eliminado): ");
            scanf("%d",&cliente.baja);

            fwrite(&cliente,sizeof(stCliente),1,archi);

            printf("\n¿Desea cargar otro Cliente?:(S/N) ");
            fflush(stdin);
            control = getch();
            i++;
        }
        fclose(archi);//cerramos el archivo para guardarlo en memoria
    }
    system("pause\n");
    system("cls");
}


//FUNCION PARA CARGAR UNA DETERMINADA CANTIDAD DE CLIENTES DE FORMA ALEATORIA Y AGREGARLOS A UN ARCHIVO
void cargaClienteRandom(char arch[]){
    FILE *parchi = fopen(arch, "ab");
    stCliente e;

    for(int i=0 ; i<51 ; i++){
        e = cargaUnClienteRand(parchi, i);
        fwrite(&e,sizeof(stCliente),1,parchi);
    }
    fclose(parchi);

}
//CARA UN CLIENTE DE FORMA ALEATORIA. RETORNA EL CLIENTE
stCliente cargaUnClienteRand(FILE *fp, int i){
    stCliente e;
    int validacion = 0;
    e.id = ultimoId(fp)+i;
    e.nroCliente = getNroCliente();
    do{
        validacion = validacionNroCliente(fp,e.nroCliente);
        if(validacion==1){
            e.nroCliente = getNroCliente();
        }
    } while(validacion==1);

    strcpy(e.dni, getDni());
    validacion = validacionClienteDni(fp, e.dni);
    while(validacion==1){
            strcpy(e.dni, getDni());
            validacion = validacionClienteDni(fp, e.dni);
    }

    strcpy(e.nombre, getNombre());
    strcpy(e.apellido, getApellido());
    strcpy(e.domicilio, getDomicilio());
    strcpy(e.email, getEmail());
    strcpy(e.movil, getMovil());
    e.baja = rand()%2;

    return e;
}

///....................................FUNCIONES DE VALIDACION DE DATOS DEL CLIENTE...........................................
///.................................... evita ingresar un cliente con datos repetidos..........................................


//VALIDA SI EL NUMERO DE CLIENTE PASADO POR PARAMETRO, EXISTE DENTRO DE UN ARCHIVO. EN CASO VERDADERO, RETORNA 1.
int validacionNroCliente (char archivo[],int nroCliente){
    stCliente aux;
    int existe = 0;
    FILE * archi;

    archi=fopen(archivo, "rb");//Abrimos el archivo en modo lectura

    if(archi!=NULL){
        fread(&aux, sizeof(stCliente),1, archi);
        while(!feof(archi)){
            if (nroCliente == aux.nroCliente){
                existe = 1;
            }
            fread(&aux, sizeof(stCliente), 1, archi);//Avanza hasta llegar al final del archivo
        }  fclose(archi);
    }  return existe;
}

//VALIDA SI EL NUMERO DE DNI PASADO POR PARAMETRO, EXISTE DENTRO DE UN ARCHIVO. EN CASO VERDADERO, RETORNA 1.
int validacionClienteDni(char archivo[],char dni[]){
    FILE * archi;
    stCliente aux;
    int existe = 0;

    archi=fopen(archivo, "rb");//Abrimos el archivo en modo lectura
    fread(&aux, sizeof(stCliente),1, archi);

    if(archi!=NULL){
        while(!feof(archi)){
            if (strcmp(dni, aux.dni)==0){
                existe = 1;
            }
            fread(&aux, sizeof(stCliente), 1, archi);//Avanza hasta llegar al final del archivo
        }  fclose(archi);
    }  return existe;
}


////VALIDA SI EL EMAIL PASADO POR PARAMETRO, EXISTE DENTRO DE UN ARCHIVO. EN CASO VERDADERO, RETORNA 1.
int validacionEmail(char archivo[],int dim,char email[][dim]){
    FILE * archi;
    stCliente aux;
    int existe = 0;

    archi=fopen(archivo, "rb");//Abrimos el archivo en modo lectura
    fread(&aux, sizeof(stCliente),1, archi);

    if(archi!=NULL){
        while(!feof(archi)){
            if (strcmpi(aux.email,email)==0){
                existe = 1;
            }
            fread(&aux, sizeof(stCliente), 1, archi);//Avanza hasta llegar al final del archivo
        }  fclose(archi);
    }  return existe;
}


///.....................................FUNCIONES PARA MOSTRAR CLIENTES ......................................................
///...........................................................................................................................


//FUNCION PARA MOSTRAR TODOS LOS CLIENTES CARGADOS EN UN ARCHIVO
void mostrarArchClientes(char archivo[]){//RECIBE COMO PARAMETRO EL ARCHIVO QUE QUEREMOS MOSTRAR

    FILE * archi;
    stCliente cliente;

    archi=fopen(archivo, "rb");//Abrimos el archivo en modo lectura

    if(archi!=NULL){
        printf("-------------------------------------------------------------------\n");
        printf("                     Contenido del archivo                         \n");
        printf("-------------------------------------------------------------------\n");

        printf("----------------------Informacion Cliente--------------------------\n");

        while(fread(&cliente, sizeof(stCliente), 1, archi)>0){//Mientras que no llegue al final del archivos enviamos todos los datos cargados a la funcion monstrar

            muestraUnCliente(cliente);//funcion para mostrar los clientes
        } fclose(archi);
    }
    system("pause\n");
    system("cls");
}


//FUNCION PARA IMPRIMIR POR PANTALLA UN CLIENTE
void muestraUnCliente(stCliente cliente){
    printf("-------------------------------------------------------------------\n");
    printf("ID Cliente:           |%d \n",cliente.id);
    printf("Numero Cliente:       |%d \n",cliente.nroCliente);
    printf("Nombre y Apellido:    |%s %s\n",cliente.nombre, cliente.apellido);
    printf("DNI:                  |%s \n",cliente.dni);
    printf("Correo Electronico:   |%s \n",cliente.email);
    printf("Domicilio:            |%s \n",cliente.domicilio);
    printf("Celular:              |%s \n",cliente.movil);
    printf("Estado:               |%s \n", (cliente.baja== 0)?"Activo":"Eliminado");

    printf("-------------------------------------------------------------------\n");
}


//FUNCION PARA MOSTRAR UN SOLO CLIENTE EN CASO DE QUE COINCIDA CON ID PASADO POR PARAMETRO
void mostrarClienteArch(int dato){//RECIBE COMO PARAMETRO LA ESTRUCTURA Y EL DATO PARA SEÑALAR CUAL CLIENTE SE DESEA MOSTRAR
    FILE *archi;
    archi=fopen("Clientes.dat", "rb");//Abrimos el archivo en modo lectura
    stCliente cliente;
    if(archi){
        while(fread(&cliente, sizeof(stCliente), 1, archi)>0){
            if (dato == cliente.id){//Si hay igualdad muestra por pantalla los datos de cliente buscado
                muestraUnCliente(cliente);
            }
        }
    }
    system("pause\n");
    system("cls");
}


///.....................................FUNCIONES PARA CONSULTA Y MODIFICACION DE CLIENTES ...................................
///...........................................................................................................................


//BUSCA UN CLIENTE POR ID PASADO POR PARAMETRO, UNA VEZ ENCONTRADO, LO MUESTRA.
void consultaIdCliente(char archivo[], int nro){
    stCliente a;
    FILE *archi=fopen(archivo, "rb");

    if(archi){
        while(fread(&a, sizeof(stCliente),1,archi)>0){
            if(a.id==nro){
                muestraUnCliente(a);
            }
        } fclose(archi);
    }
}


//FUNCION PARA MODIFICAR DATOS DEL CLIENTE
void modificarCliente(char archivo[]){//RECIBE COMO EL ARCHIVO DE LOS CLIENTES

    FILE *archi;
    stCliente aux;
    int id=0;
    int existe=0;
    int pos=0;

    archi=fopen(archivo,"r+b");//Abrimos el archivo en modo lectura y en modo sobreescribir

    if (archi!=NULL){//Si el archivo no esta cerrado
        printf("Ingrese el ID del Cliente que desea modificar\n");//Ingresamos el id para buscar el cliente que se desea modificar
        scanf("%d", &id);
        mostrarClienteArch(id);

        fread(&aux, sizeof(stCliente),1, archi);//enviamos los datos cargados

        while(!feof(archi)){//mientras que el indicador no llegue al final del archivo hacemos

            if(id == aux.id){//Buscamos igualdad en el id solicitado y luego modificamos los datos

                printf("\nIngrese el Numero de Cliente: ");
                scanf("%d", &aux.nroCliente);

                printf("Ingrese el Nombre del cliente: ");
                fflush(stdin);
                gets(aux.nombre);

                printf("Ingrese el Apellido del cliente: ");
                fflush(stdin);
                gets(aux.apellido);

                printf("Ingrese el dni del cliente: ");
                fflush(stdin);
                gets(aux.dni);

                printf("Ingrese el email del cliente : ");
                fflush(stdin);
                scanf("%s",aux.email);


                printf("Ingrese movil del cliente: ");
                fflush(stdin);
                scanf("%s",aux.movil);

                printf("Ingrese el domicilio del cliente: ");
                fflush(stdin);
                fgets(aux.domicilio, 45, stdin);

                pos=ftell(archi)-sizeof(stCliente);// nos indica donde se encuentra el indicador

                fseek(archi,pos,SEEK_SET);//nos desplazamos a la posicion del cliente desde el comienzo del archivo

                fwrite(&aux, sizeof(stCliente), 1, archi);//retornamos los nuevos datos cargados

                printf("Se modifico el Cliente \n");
                existe=1;// validamos que el cliente existe
                break;
            }
            fread(&aux, sizeof(stCliente), 1, archi);
        }

        if (existe==0){
            printf("No existe el cliente \n");//si la variable es igual a 0 es que no existe el cliente buscado
        }
        fclose(archi);//cerramos archivo
    }
    system("pause\n");
    system("cls");
}

//FUNCION PARA DAR DE BAJA AL CLIENTE
void bajaCliente(char archivo[]){//RECIBE POR PARAMETRO NUESTRO ARCHIVO DE CLIENTES
    FILE *archi;
    stCliente aux;
    int id=0;
    int existe=0;
    int pos=0;

    archi=fopen(archivo,"r+b");//Abrimos el archivo en modo lectura y escritura
    fread(&aux, sizeof(stCliente),1, archi);

    if (archi!=NULL){

        printf( "Dar de ALTA/BAJA a un cliente\n");
        printf("Ingrese el ID del Cliente que desea modificar\n");
        scanf("%d", &id);

        mostrarClienteArch(id);

        while(!feof(archi)){//Cuando se encuentra al cliente modificamos su estado de ALTA a BAJA o de la forma contraria

            if (id == aux.id){
                printf("Estado del cliente (ALTA / BAJA):");
                scanf("%s",aux.baja);

                pos=ftell(archi)-sizeof(stCliente);// posicion del indicador(la posicion del indicador menos un bloque de memoria).

                fseek(archi,pos,SEEK_SET);//mueve el indicador desde el comienzo hasta la posicion pos.

                fwrite(&aux, sizeof(stCliente), 1, archi);

                printf("Se modifico el Cliente \n");
                existe = 1;
                break;
            }
            fread(&aux, sizeof(stCliente), 1, archi);
        }

        if (existe == 0){
            printf("No existe el cliente \n");
        }
        fclose(archi);
    }
    system("pause\n");
    system("cls");
}


///.....................................FUNCION PARA CONTAR CLIENTES EN UN ARCHIVO............................................
///...........................................................................................................................

int contarIdCliente(char archivo[]){ //recorre el archivo para calcular cantidad de clientes ya cargados

    FILE *archiclientes;
    stCliente cliente;
    int i=0;
    int pos=0;

    archiclientes=fopen("Clientes.dat","rb");

    if (archiclientes!=NULL){
        fread(&cliente, sizeof(stCliente),1, archiclientes);

        while(!feof(archiclientes)){
            fread(&cliente, sizeof(stCliente), 1, archiclientes);//Avanza hasta llegar al final del archivo
            pos++;

            if(pos=(feof(archiclientes)-1)){//cuando pos = a la ultima posicion del archivo
                i = cliente.id+1;//Igualamos i al valor contenido de id + 1
            }
        }
        fclose(archiclientes);
    }
    return i;
}



///...............................FUNCION PARA PASAR CLIENTES DE UN ARCHIVO, A UN ARREGLO.....................................
///...........................................................................................................................

//PASA CLIENTES A UN ARREGLO, RETORNA LOS VALIDOS.
int file2ArrayClientes(stCliente arreglo[], int dim){
    FILE *parchic = fopen("Clientes.dat","rb");
    stCliente c;
    int v = 0;
    if(parchic != NULL){
        while(fread(&c, sizeof(stCliente), 1, parchic)>0){
            arreglo[v] = c;
            v++;
        }
    }
    fclose(parchic);
    return v;
}
