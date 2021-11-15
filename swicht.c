#include "swicht.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include "gotoxy.h"
#include "menu.h"
#include "windows.h"
#include "arbolesclientes.h"
#include "autoCargaCliente.h"
#include "Lista_Consumo.h"
#include "cliente.h"
#include "consumo.h"

const char ARCH_CONSUMOS[]="consumos.dat";
const char Archivo_Cliente[]="Clientes.dat";

void consola()
{
    menu_integrantes();

    int id=0;
    int id_consumo_cliente=0;

    int opcion = 0;
    int opcion1 = 0;
    int opcion2 = 0;
    int opcion3 = 0;
    int seleccion = 0;

    int anioConsumo=0;
    int mesConsumo=0;
    int diaConsumo=0;

    nodoArbol* cliente;
    int clienteEliminar;

    stCliente arrayClientes[50];
    int validosClientes = 0;
    nodoArbol* arbolClientes = inicArbolClientes();

    int idC;
    int periodo;
    stLiquidacion liquidacion;

    do
    {
        menu();
        system("pause");
        system("cls");
        fflush(stdin);
        opcion = getch();

        switch(opcion)
        {
        /// MENU CLIENTES, CONSUMOS, ADMINISTRAR ARBOL
        case 49:
            system("cls");
            menu1();
            system("pause");
            system("cls");
            fflush(stdin);
            opcion1 = getch();

            switch(opcion1)
            {
            /// SUB-MENU REGISTRAR CLIENTE
            case 49:
                system("cls");
                menuCliente();
                fflush(stdin);
                opcion1 = getch();

                switch(opcion1)
                {
                /// CLIENTES - CARGA MANUAL
                case 49:
                    system("cls");
                    cargarCliente(Archivo_Cliente);
                    break;
                /// CLIENTES - CARGA RANDOM
                case 50:
                    system("cls");
                    cargaClienteRandom(Archivo_Cliente);
                    break;
                }
                break;
            ///SUB-MENU MODIFICAR CLIENTE
            case 50:
                //system("cls");
                menu2();
                fflush(stdin);
                seleccion = getch();

                switch(seleccion)
                {
                /// CAMBIAR DATOS CLIENTE
                case 49:
                    system("cls");
                    modificarCliente(Archivo_Cliente);   //CAMBIAR DATOS CLIENTE
                    break;
                    break;
                /// ALTA - BAJA CLIENTE
                case 50:
                    system("cls");
                    bajaCliente(Archivo_Cliente);     //ALTA / BAJA CLIENTE
                    break;
                }
                break;

            /// MOSTRAR TODOS LOS CLIENTES
            case 51:
                system("cls");
                mostrarArchClientes(Archivo_Cliente);   //MOSTRAR CLIENTES
                break;

            ///MOSTRAR UN CLIENTE
            case 52:
                system("cls");
                printf("\n Ingrese un Id: ");
                scanf("%d", &id);
                consultaIdCliente("Clientes.dat", id);  // MOSTRAR UN CLIENTE X ID
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
        case 50:                                             //***CONSUMOS***
            system("cls");
            menu3();
            fflush(stdin);
            opcion2 = getch();

            switch(opcion2)
            {
            ///ALTA BAJA CONSUMO
            case 49:
                system("cls");
                printf("\nIngrese el anio: ");
                scanf("%d",&anioConsumo);
                printf("\nIngrese el mes: ");
                scanf("%d",&mesConsumo);
                printf("\nIngrese el dia: ");
                scanf("%d",&diaConsumo);
                modificarConsumoAltaBaja (ARCH_CONSUMOS, anioConsumo, mesConsumo, diaConsumo);    //ALTA /BAJA DE UN CONSUMO X.
                break;

            ///CONSUMOS DE UN CLIENTE
            case 50:
                system("cls");
                printf("Ingrese ID: ");
                scanf("%d",&id_consumo_cliente);
                muestraConsumosPorCliente(ARCH_CONSUMOS,id_consumo_cliente);      //CONSUMOS DE UN CLIENTE X.
                break;

            ///VER LISTADO DE CONSUMOS
            case 51:
                system("cls");
                muestraArchivo(ARCH_CONSUMOS);    //VER LISTADO DE CONSUMOS.
                break;

            ///BUSCAR CONSUMO POR FECHA
            case 52:
                system ("cls");
                printf("\nIngrese el anio: ");
                scanf("%d",&anioConsumo);
                printf("\nIngrese el mes: ");
                scanf("%d",&mesConsumo);
                printf("\nIngrese el dia: ");
                scanf("%d",&diaConsumo);
                buscarConsumosXFecha(ARCH_CONSUMOS, anioConsumo, mesConsumo, diaConsumo); // BUSCA CONSUMOS POR FECHA
                break;

            ///CARGA RANDOM DE CONSUMOS
            case 53:
                system ("cls");
                cargaConsumosRandom(ARCH_CONSUMOS, Archivo_Cliente);                   //INICIA LA CARGA DE 30 consumos x cliente
                printf("\nSe cargaron correctamente los consumos aleatorios \n");
                system("pause");
                system("cls");
                break;

            ///CARGAR UN CONSUMO
            case 54:
                system("cls");
                cargaUnConsumo(ARCH_CONSUMOS);                                          //CARGA UN SOLO CONSUMO SOLICITANDO ID
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
        case 51:                                                                           // CARGAR ARBOL DESDE ARCHIVOS
            system("cls");
            menu4();
            fflush(stdin);
            opcion3 = getch();

            switch(opcion3)
            {
            ///CARGAR ARBOL DESDE ARCHIVOS
            case 49:
                system("cls");
                if(!ARCH_CONSUMOS || !"Consumos.dat")
                {
                    printf("\n ***** PRIMERO DEBE CARGAR LOS ARCHIVOS *****");
                }
                else
                {
                    validosClientes = file2ArrayClientes(arrayClientes, 50);
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
                if(arbolClientes == NULL)
                {
                    printf("\n\n\n\n\n ****** PRIMERO DEBE CARGAR EL ARBOL ******\n\n\n\n\n\n");
                    system("pause");
                    system("cls");
                    break;
                }
                printf("\n********* ATENCION USTED ESTA POR LIQUIDAR LOS CONSUMOS DE UN CLIENTE *********\n");
                printf("\n INGRESE EL idCliente QUE DESEA LIQUIDAR: ");
                scanf("%d", &idC);
                cliente = buscaNodoArbolClientePorId(arbolClientes, idC);
                if(cliente == NULL)
                {
                    do
                    {
                        printf("\n EL CLIENTE NO EXISTE! Ingrese id valido: ");
                        scanf("%d", &idC);
                        cliente = buscaNodoArbolClientePorId(arbolClientes, idC);
                    }
                    while(cliente == NULL);
                }
                printf("\n INGRESE EL MES O ANIO QUE DESEA LIQUIDAR: ");
                scanf("%d", &periodo);
                if(periodo>12 && periodo<2021)
                {
                    do
                    {
                        printf("\n EL PERIODO NO EXISTE! Ingrese MES O ANIO valido: ");
                        scanf("%d", &periodo);
                    }
                    while(periodo>12 && periodo<2021);
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
                if(arbolClientes == NULL)
                {
                    printf("\n\n\n\n\n ****** PRIMERO DEBE CARGAR EL ARBOL ******\n\n\n\n\n\n");
                    system("pause");
                    system("cls");
                    break;
                }
                printf("\n Ingrese el id del cliente que desea eliminar: ");
                scanf("%d", &clienteEliminar);
                arbolClientes = eliminaNodoArbol(arbolClientes, clienteEliminar);
                system("pause");
                system("cls");

            ///MOSTRAR ARBOL
            case 52:
                system("cls");
                if(arbolClientes == NULL)
                {
                    printf("\n\n\n\n\n ****** PRIMERO DEBE CARGAR EL ARBOL ******\n\n\n\n\n\n");
                    system("pause");
                    system("cls");
                    break;
                }
                system("cls");
                printf("\n ***** SE MUESTRA ARBOL DE CLIENTES CON SUS CONSUMOS ***** \n");
                enOrdenClientes(arbolClientes);
                system("pause");
                system("cls");
            }
        case 48:                                               //SALIR DEL SISTEMA
            system("cls");

            break;
        }
    }
    while(opcion!=48);
    system("pause\n");
    system("pause\n");

    return 0;
}

