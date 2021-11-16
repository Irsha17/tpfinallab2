#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Consumo.h"
#include <time.h>
#include "cliente.h"


///.....................................FUNCIONES PARA CARGAR CONSUMOS ......................................................
///...........................................................................................................................

// CARGA UN CONSUMO DE FORMA MANUAL.
void cargaUnConsumo(char archivo[])
{
    stFecha f;
    int id=ultimoId(archivo);
    stConsumo a;
    FILE *archi=fopen(archivo, "ab");
    char opcion=0;
    time_t tiempo;
    time(&tiempo);
    struct tm *fecha = localtime(&tiempo);
    int mesActual = fecha->tm_mon + 1;
    f.anio = fecha->tm_year+1900;
    f.dia = fecha->tm_mday;

    if(archi)
    {
        do
        {
            a.id=id+1;
            printf("ID: %d", a.id);
            printf("\nID cliente:" );
            scanf("%d", &a.idCliente);
            do
            {
                printf("Anio:");
                scanf("%d", &a.anio);
            }while(a.anio!=f.anio);

            do
            {
                printf("Mes:");
                scanf("%d", &a.mes);
            }while(a.mes>mesActual);
            do
            {
                printf("Dia:");
                scanf("%d", &a.dia);
            }while(a.dia>f.dia);

                printf("Baja:");
                scanf("%d", &a.baja);

            printf("Datos consumidos:");
            scanf("%d", &a.datosConsumidos);
            fwrite(&a, sizeof(stConsumo),1,archi);
            printf("\nESC para salir");
            fflush(stdin);
            opcion=getch();
            system("cls");
            id++;

        }
        while(opcion!=27);

        fclose(archi);
    }

}

//CARGA UNA DETERMINADA CANTIDAD DE CONSUMOS, DE FORMA ALEATORIA.
void cargaConsumosRandom(char archivo[], char archClientes[]){ // Carga automaticamente mil consumos random.
    stCliente c;
    stConsumo a;
    stFecha b;
    int i=ultimoId(archivo);
    FILE *parchiClientes = fopen(archClientes, "rb");
    FILE *pArchiConsumos = fopen(archivo, "ab");

    if(parchiClientes){
        if(pArchiConsumos){
            while(fread(&c, sizeof(stCliente), 1, parchiClientes)>0){
                for(int j=0 ; j<11 ; j++){
                    a.idCliente= c.id;
                    b = fechaAleatoria(); // cargamos fecha aleatoria en estructura auxiliar. Luego se copiara en la fecha de estructura de consumo.

                    a.anio = b.anio;
                    a.mes = b.mes;
                    a.dia = b.dia;
                    a.datosConsumidos = rand()%1000;
                    a.baja = rand()%2;
                    i++;

                    a.id = i;

                    fwrite(&a, sizeof(stConsumo), 1, pArchiConsumos);
                }
            }
        fclose(pArchiConsumos);
        }
    }
}

//BUSCA EL ULTIMO ID DE CONSUMO, DENTRO DE UN ARCHIVO, Y LO RETORNA.
int ultimoId(char archivo[]){

    FILE *pArchi = fopen(archivo, "rb");
    stConsumo a;
    int ultimoId=0;

    if(pArchi){
        fseek(pArchi, -1 * sizeof(stConsumo), SEEK_END);

        if(fread(&a, sizeof(stConsumo), 1, pArchi)>0){
            ultimoId = a.id;
        } fclose(pArchi);

    } return ultimoId;
}


// CARGA ESTRUCTURA FECHA DE FORMA ALEATORIA (FORMATEA LA FECHA ACTUAL PARA OBTENERLA) Y LA RETORNA.
stFecha fechaAleatoria(){
    stFecha f;   //TRABAJAMOS ESTRUCTURA FECHA
    int mesActual;
    time_t tiempo;   //NOS DEVUELVE EL TIEMPO
    time(&tiempo);
    struct tm *fecha = localtime(&tiempo); //Obtenemos fecha actual

    mesActual = fecha->tm_mon + 1; //Para el mes actual. Se le suma 1 porque el formato de meses que se obtiene es de 0(enero) a 11(diciembre)

    f.mes = 1 + rand() % mesActual; //Se obtiene mes aleatorio menor al mes actual. Sumamos 1 para evitar que nos de 0

    f.anio = fecha->tm_year+1900;//obtiene anio actual. Se le suma 1900, ya que originalmente se obtiene 121   ///(USAMOS FLECHA PORQUE ESTAMOS TRABAJANDO DIRECTAMENTE CON EL PUNTERO DE LA ESTRUCUTURA)

    if(f.mes == mesActual){ //en caso de que obtengamos aleatoriamente el mes actual, nos aseguramos que sea menor al dia actual.

        f.dia = 1 + (rand() % fecha->tm_mday);
    }else{
        switch(f.mes){

            case 4 || 6 || 9 || 11 : f.dia= 1 + (rand() % 30); // los meses 4, 6, 9 y 11 tienen 30 dias Sumamos 1 para evitar dia 0
            break;

            case 2 : f.dia = (rand() % 28); // El anio actual, febrero tuvo 28 dias.
            break;

            default: f.dia = 1+ (rand() % 31); // Para el resto de los meses se obtiene el modulo de dividir un numero aleatorio por 31.
        }
    }    return f;
}


///.....................................FUNCIONES PARA MOSTRAR CONSUMOS Y LIQUIDACIONES.......................................
///...........................................................................................................................


void muestraUnConsumo(stConsumo consumo){
    printf("\n Id.....................: %d", consumo.id);
    printf("\n Id de Cliente..........: %d", consumo.idCliente);
    printf("\n Fecha..................: %.2d/%.2d/%d", consumo.dia, consumo.mes, consumo.anio);
    printf("\n Datos Consumidos.......: %d Mb", consumo.datosConsumidos);
    printf("\n Baja...................: %s", (consumo.baja== 0)?"Activo":"Eliminado");
    printf("\n---------------------------------------------------");
}

void muestraUnaLiquidacion(stLiquidacion l){
    printf("\n--------------------------------------------------");
    printf("\n Nombre y Apellido......: %s %s",l.nombre, l.apellido);
    printf("\n Id de Cliente..........: %d", l.idCliente);
    printf("\n Periodo................: %d", l.periodo);
    printf("\n Datos Consumidos.......: %d Mb", l.datosConsumidos);
    printf("\n--------------------------------------------------\n");
}

// Recorre el archivo y muestra el archivo completo utilizando la siguiente funcion de mostrar un consumo.
void muestraArchivo(char archivo[]){

    FILE *pArchi = fopen(archivo, "rb");
    stConsumo a;

    if(pArchi){

        while(fread(&a, sizeof(stConsumo), 1, pArchi)>0){
            muestraUnConsumo(a);
        }
        fclose(pArchi);
    }
}


///.....................................FUNCIONES DE BUSQUEDA DE CONSUMOS Y MODIFICACION......................................
///...........................................................................................................................


//MUESTRA LOS CONSUMOS DE UN DETERMINADO CLIENTE QUE COINCIDE CON EL ID PASADO POR PARAMETRO.
void muestraConsumosPorCliente(char archivo[], int id){

    FILE *pArchi = fopen(archivo, "rb");
    stConsumo a;

    if(pArchi != NULL){
        while(fread(&a,sizeof(stConsumo),1,pArchi)>0){
            if(a.idCliente == id){
                muestraUnConsumo(a);
            }
        } fclose(pArchi);
    }
}

//MUESTRA LOS CONSUMOS QUE COINCIDEN CON UNA FECHA ESPECIFICA, PASADA POR PARAMETRO.
void buscarConsumosXFecha(char archivoConsumos[], int anio, int mes, int dia){

    stConsumo a;
    FILE *pArchi = fopen(archivoConsumos, "rb");

    if(pArchi){
        while(fread(&a, sizeof(stConsumo), 1, pArchi) > 0){
            if(a.anio == anio && a.mes == mes && a.dia == dia){
                muestraUnConsumo(a);
            }
        } fclose(pArchi);
    }
    printf("\n");
    system("pause");
    system("cls");
}

//MODIFICA EL ALTA O BAJA DE UN CONSUMO, BUSCADO POR FECHA PASADA POR PARAMETRO.
void modificarConsumoAltaBaja (char archivoConsumos[], int id){
    stConsumo a;
    FILE *pArchi = fopen(archivoConsumos, "r+b");
    char opcion;
    int flag = 0;
    if(pArchi){
        while(fread(&a, sizeof(stConsumo), 1, pArchi) > 0 && flag == 0){
            if(a.id == id){
                flag = 1;
                muestraUnConsumo(a);
                printf("\n El consumo se encuentra %s, \ndesea cambiar su estado? S/N : \n", (a.baja== 0)?"Activo":"Eliminado");
                fflush(stdin);
                opcion = getch();
                if(opcion == 83 || opcion == 115){
                    if(a.baja == 0){
                        a.baja = 1;
                    }else{
                        a.baja = 0;
                    }
                    fseek(pArchi, -1 * sizeof(stConsumo), 1);
                    fwrite(&a, sizeof(stConsumo), 1, pArchi);
                    fclose(pArchi);
                    printf("\n El consumo ha cambiado de estado\n");
                    muestraUnConsumo(a);
                    printf("\n");
                    system("pause");
                    system("cls");
                }

            }
        }
    }
}
