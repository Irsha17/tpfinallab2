#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "switch.h"
#include "cliente.h"
#include "consumo.h"
#include "listaConsumo.h"
#include "arbolesclientes.h"
#include "menu.h"
#include "gotoxy.h"
#include "windows.h"

const char ARCH_CONSUMOS[]="consumos.dat";
const char Archivo_Cliente[]="Clientes.dat";

void consola(){

    int id=0;
    int id_consumo_cliente=0;

    int opcion;
    int opcion1;
    int seleccion = 0;

    int idConsumo;
    int anioConsumo;
    int mesConsumo;
    int diaConsumo;

    nodoArbol* cliente;
    int clienteEliminar;

    int dim = contarIdCliente(Archivo_Cliente)+1;
    stCliente arrayClientes[dim];
    int validosClientes = 0;
    int cantidad;
    nodoArbol* arbolClientes = inicArbolClientes();
    nodoArbol* rta = NULL;

    int idC;
    int periodo;
    stLiquidacion liquidacion;

    do{
        menu();
        fflush(stdin);
        opcion1 = getch();

        switch(opcion1){
            /// MENU CLIENTES, CONSUMOS, ADMINISTRAR ARBOL
            case 49:
                system("cls");
                menu1();
                fflush(stdin);
                opcion = getch();

            switch(opcion){
                /// SUB-MENU REGISTRAR CLIENTE
                case 49:
                    system("cls");
                    menuCliente();
                    fflush(stdin);
                    opcion = getch();

                    switch(opcion){
                        /// CLIENTES - CARGA MANUAL
                        case 49:
                            system("cls");
                            cargarCliente(Archivo_Cliente);
                        break;
                        /// CLIENTES - CARGA RANDOM
                        case 50:
                            system("cls");
                            printf("\n Ingrese cantidad de clientes que desea cargar: ");
                            scanf("%d", &cantidad);
                            cargaClienteRandom(Archivo_Cliente, cantidad);
                            printf("\n Carga de clientes exitosa\n");
                            system("pause");
                            system("cls");
                        break;
                    }
                break;
                ///SUB-MENU MODIFICAR CLIENTE
                case 50:
                    system("cls");
                    menu2();
                    fflush(stdin);
                    seleccion = getch();

                switch(seleccion){
                    /// CAMBIAR DATOS CLIENTE
                    case 49:
                        system("cls");
                        modificarCliente(Archivo_Cliente);
                    break;
                break;
                    /// ALTA - BAJA CLIENTE
                    case 50:
                        system("cls");
                        printf("\n Ingrese el id del cliente que quiere dar de baja o alta: ");
                        scanf("%d", &idC);
                        bajaCliente(Archivo_Cliente, idC);
                    break;
                }
                break;

                /// MOSTRAR TODOS LOS CLIENTES
                case 51:
                    system("cls");
                    mostrarArchClientes(Archivo_Cliente);
                break;

                ///MOSTRAR UN CLIENTE
                case 52:
                    system("cls");
                    printf("\n Ingrese un Id: ");
                    scanf("%d", &id);
                    consultaIdCliente("Clientes.dat", id);
                    system("pause");
                    system("cls");
                break;

                ///VOLVER AL MENU ANTERIOR
                case 48:
                    system("cls");
                    printf("\nFINALIZAR EL PROGRAMA\n");
                break;
            }
            break;

            ///MENU CONSUMOS
            case 50:
                system("cls");
                menu3();
                fflush(stdin);
                opcion = getch();

            switch(opcion){
                ///ALTA BAJA CONSUMO
                case 49:
                    system("cls");
                    printf("\nIngrese id de consumo: ");
                    scanf("%d",&idConsumo);
                    modificarConsumoAltaBaja (ARCH_CONSUMOS, idConsumo);
                break;

                ///CONSUMOS DE UN CLIENTE
                case 50:
                    system("cls");
                    printf("Ingrese ID: ");
                    scanf("%d",&id_consumo_cliente);
                    muestraConsumosPorCliente(ARCH_CONSUMOS,id_consumo_cliente);
                    printf("\n");
                    system("pause");
                    system("cls");
                break;

                ///VER LISTADO DE CONSUMOS
                case 51:
                    system("cls");
                    muestraArchivo(ARCH_CONSUMOS);
                    printf("\n");
                    system("pause");
                    system("cls");
                break;

                ///BUSCAR CONSUMO POR FECHA
                case 52:
                    system ("cls");
                    do{
                        printf("\nIngrese el mes (1 - 12): ");
                        scanf("%d",&mesConsumo);
                    }while(mesConsumo<1 || mesConsumo>12);
                    do{
                        printf("\nIngrese el dia: ");
                        scanf("%d",&diaConsumo);
                    }while(diaConsumo<1 || diaConsumo>31);
                    buscarConsumosXFecha(ARCH_CONSUMOS, 2021, mesConsumo, diaConsumo);
                break;

                ///CARGA RANDOM DE CONSUMOS
                case 53:
                    system ("cls");
                    cargaConsumosRandom(ARCH_CONSUMOS, Archivo_Cliente);
                    printf("\nSe cargaron correctamente los consumos aleatorios \n");
                    system("pause");
                    system("cls");
                break;

                ///CARGAR UN CONSUMO
                case 54:
                      system("cls");
                      cargaUnConsumo(ARCH_CONSUMOS);
                      system("pause");
                      system("cls");

                ///VOLVER AL MENU ANTERIOR
                case 48:
                    system("cls");
                    printf("\nFINALIZAR EL PROGRAMA\n");
                break;
            }
            break;

            /// ADMINISTRAR ARBOL
            case 51:
                system("cls");
                menu4();
                fflush(stdin);
                opcion = getch();

            switch(opcion){
                ///CARGAR ARBOL DESDE ARCHIVOS
                case 49:
                    system("cls");
                    if(!ARCH_CONSUMOS || !"Consumos.dat"){
                        printf("\n ***** PRIMERO DEBE CARGAR LOS ARCHIVOS *****");
                    }else{
                        validosClientes = file2ArrayClientes(arrayClientes);
                        arbolClientes = arrayClientes2Arbol(arrayClientes, validosClientes);
                        arbolClientes = cargarArbolConListas(arbolClientes, ARCH_CONSUMOS);
                        printf("\n ***** EL ARBOL HA SIDO CARGADO CORRECTAMENTE *****\n");
                    }
                    system("pause");
                    system("cls");
                break;

                ///LIQUIDAR CONSUMOS DE UN CLIENTE
                case 50:
                    system("cls");
                    if(arbolClientes == NULL){
                        printf("\n\n\n\n\n ****** PRIMERO DEBE CARGAR EL ARBOL ******\n\n\n\n\n\n");
                        system("pause");
                        system("cls");
                        break;
                    }
                    printf("\n********* ATENCION USTED ESTA POR LIQUIDAR LOS CONSUMOS DE UN CLIENTE *********\n");
                    printf("\n INGRESE EL idCliente QUE DESEA LIQUIDAR: ");
                    scanf("%d", &idC);
                    cliente = buscaNodoArbolClientePorId(arbolClientes, idC);
                    if(cliente == NULL){
                        do{
                            printf("\n EL CLIENTE NO EXISTE! Ingrese id valido: ");
                            scanf("%d", &idC);
                            cliente = buscaNodoArbolClientePorId(arbolClientes, idC);
                        }while(cliente == NULL);
                    }
                    printf("\n INGRESE EL MES O ANIO QUE DESEA LIQUIDAR: ");
                    scanf("%d", &periodo);
                    while(periodo>12 && periodo<2021 || periodo <= 0 || periodo>2021){
                        printf("\n EL PERIODO NO EXISTE! Ingrese MES O ANIO valido: ");
                        scanf("%d", &periodo);
                    }
                    liquidacion = liquidarPeriodo(cliente, periodo);
                    system("pause");
                    system("cls");
                    printf("\n ******** SE MUESTRA LIQUIDACION ******** \n");
                    muestraUnaLiquidacion(liquidacion);
                    system("pause");
                    system("cls");
                break;

                ///ELIMINAR CLIENTE DEL ARBOL
                case 51:
                    system("cls");
                    menu5();
                    fflush(stdin);
                    opcion = getch();

                    switch(opcion){
                        /// ELIMINAR - CLIENTE
                        case 49:
                            system("cls");
                            if(arbolClientes == NULL){
                                printf("\n\n\n\n\n ****** PRIMERO DEBE CARGAR EL ARBOL ******\n\n\n\n\n\n");
                                system("pause");
                                system("cls");
                            break;
                            }
                            printf("\n Ingrese el id del cliente que desea eliminar: ");
                            scanf("%d", &clienteEliminar);
                            rta = buscaNodoArbolClientePorId(arbolClientes, clienteEliminar);
                            while(rta == NULL){
                                printf("\nEl cliente %d, no se encuentra en nuestra base de datos. Ingrese otro id: ");
                                scanf("%d", &clienteEliminar);
                                rta = buscaNodoArbolClientePorId(arbolClientes, clienteEliminar);
                            }
                            arbolClientes = eliminaNodoArbol(arbolClientes, clienteEliminar);
                            system("pause");
                            system("cls");
                        break;

                        /// ELIMINAR - ARBOL
                        case 50:
                            system("cls");
                            if(arbolClientes == NULL){
                                printf("\n\n\n\n\n ****** EL ARBOL NO EXISTE ******\n\n\n\n\n\n");
                                system("pause");
                                system("cls");
                            break;
                            }else{
                                arbolClientes = eliminarArbol(arbolClientes);
                                printf("\n ******** EL ARBOL HA SIDO ELIMINADO CORRECTAMENTE ******** \n");
                                system("pause");
                                system("cls");
                            }
                            break;
                    }
                break;

                ///MOSTRAR ARBOL
                case 52:
                    system("cls");
                    if(arbolClientes == NULL){
                        printf("\n\n\n\n\n ****** PRIMERO DEBE CARGAR EL ARBOL ******\n\n\n\n\n\n");
                        system("pause");
                        system("cls");
                        break;
                    }
                    system("cls");
                    menu5();
                    fflush(stdin);
                    opcion = getch();

                    switch(opcion){
                        ///MOSTRAR UN CLIENTE DEL ARBOL
                        case 49:
                            system("cls");
                            printf("\n Ingrese el id del cliente que desea mostrar: ");
                            scanf("%d", &idC);
                            rta = buscaNodoArbolClientePorId(arbolClientes, idC);
                            while(rta == NULL){
                                printf("\nEL cliente %d, no se encuentra en nuestra base de datos, ingrese otro id: ");
                                scanf("%d", &idC);
                                rta = buscaNodoArbolClientePorId(arbolClientes, idC);
                            }
                            muestraNodoArbolClientes(rta);
                            printf("\n");
                            system("pause");
                            break;
                        ///MODO DE MOSTRAR ARBOL
                        case 50:
                            system("cls");
                            printf("\n De que forma desea ver el arbol? : 1- Pre-orden / 2- En orden / 3- Post-orden : ");
                            opcion = getch();
                            switch(opcion){
                                case 49:
                                    preOrdenClientes(arbolClientes);
                                    system("pause");
                                    system("cls");
                                    break;
                                case 50:
                                    enOrdenClientes(arbolClientes);
                                    system("pause");
                                    system("cls");
                                    break;
                                case 51:
                                    postOrdenClientes(arbolClientes);
                                    system("pause");
                                    system("cls");
                                    break;
                            }
                    }
            }
            case 48:                                               //SALIR DEL SISTEMA
                system("cls");
                printf("\n Finalizando programa... \n");

            break;
        }
    }
    while(opcion1!=48);


}
