#include "menu.h"



void menu()
{

    gotoxy(100,7);
    lineaHSup();
    printf("                                  UTN MOVIL%c                                   \n",169);

    printf("                     BIENVENIDO A LA APLICACION UTN MOVIL\n                    \n");

    printf("            NOS CARACTERIZAMOS POR LA MEJOR ATENCION AL CLIENTE            \n");

    printf("               FISCALIZAMOS SUS CONSUMOS PARA SU TRANQUILIDAD                  \n");

    lineaHInf();

    system("pause");
    system("cls");


    printf("\n\n\n");
    gotoxy(5,5);
    printf("\n  %c %cQue desea realizar?                 \n",254,168);
    lineaHSup();
    printf("\t%c\t       CLIENTES         %c        CONSUMOS            %c",186,186,186);
    printf("\n\t%c                               %c                            %c",186,186,186);
    printf("\n\t%c\t       (PRESIONE 1)     %c        (PRESIONE 2)        %c",186,186,186);
    lineaHMedio();
    printf("\t%c\t     ADMINISTRAR ARBOL  %c        SALIR DEL SISTEMA   %c",186,186,186);
    printf("\n\t%c                               %c                            %c",186,186,186);
    printf("\n\t%c\t        (PRESIONE 3)    %c          (PRESIONE 0)      %c",186,186);
    lineaHInf();
}

void menu1()
{

    printf("\n\n\n");
    gotoxy(7,5);
    printf("\n  %c %cQue desea realizar?                 \n",254,168);
    lineaHSup();
    printf("\t%c    REGISTRAR CLIENTE          %c      MODIFICAR CLIENTE     %c",186,186,186);
    printf("\n\t%c                               %c                            %c",186,186,186);
    printf("\n\t%c      (PRESIONE 1)             %c        (PRESIONE 2)        %c",186,186,186);
    lineaHMedio();
    printf("\t%c   MOSTRAR TODOS LOS CLIENTES  %c        MOSTRAR UN CLIENTE  %c",186,186,186);
    printf("\n\t%c                               %c                            %c",186,186,186);
    printf("\n\t%c\t        (PRESIONE 3)    %c          (PRESIONE 4)      %c",186,186);
    printf("\n\t%c                               %c                            %c",186,186,186);
    lineaHMedio();
    printf("\n\t%c                                                            %c",186,186);
    printf("\n\t%c                 VOLVER AL MENU ANTERIOR                    %c",186,186);
    printf("\n\t%c                                                            %c",186,186);
    printf("\n\t%c                      (PRESIONE 0)                          %c",186,186);
    printf("\n\t%c                                                            %c",186,186);
    lineaHInf();
}



void menuCliente()
{

    system("cls");
    gotoxy(5, 5);
    lineaHSup();
    printf("\t%c\t[ 1 ] - Carga un cliente  MANUAL                     %c",186,186);
    lineaHMedio();
    printf("\t%c\t[ 2 ] - Carga un cliente  RANDOM                     %c",186,186);
    lineaHInf();

}

void menu2()
{
    system("cls");
    gotoxy(5, 5);
    lineaHSup();
    printf("\t%c\t[ 1 ] - CAMBIAR datos cliente                        %c",186,186);
    lineaHMedio();
    printf("\t%c\t[ 2 ] - ALTA / BAJA cliente                          %c",186,186);
    lineaHInf();
}

void menu3()
{
    lineaHSup();
    printf("\t%c\t\t1) [ 1 ] ALTA / BAJA  Consumo.               %c",186,186);
    lineaHMedio();
    printf("\t%c\t\t2) [ 2 ] Consumos de UN CLIENTE.             %c",186,186);
    lineaHMedio();
    printf("\t%c\t\t3) [ 3 ] Ver LISTADO de consumos .           %c",186,186);
    lineaHMedio();
    printf("\t%c\t\t4) [ 4 ] BUSCAR consumo por FECHA.           %c",186,186);
    lineaHMedio();
    printf("\t%c\t\t5) [ 5 ] Carga RANDOM de Consumos.           %c",186,186);
    lineaHMedio();
    printf("\t%c\t\t5) [ 6 ] Cargar UN Consumo.                  %c",186,186);
    lineaHMedio();
    printf("\t%c\t\t5) [ < 0 > ] VOLVER AL MENU ANTERIOR...      %c",186,186);
    lineaHInf();
}

void menu4()
{

    lineaHSup();
    printf("\t%c\t\t1) [ 1 ] CARGAR arbol desde Archivo.         %c",186,186);
    lineaHMedio();
    printf("\t%c\t\t2) [ 2 ] LIQUIDAR consumos por Periodo.      %c",186,186);
    lineaHMedio();
    printf("\t%c\t\t3) [ 3 ] ELIMINAR Un Cliente.                %c",186,186);
    lineaHMedio();
    printf("\t%c\t\t4) [ 4 ] MOSTRAR Arbol.                      %c",186,186);
    lineaHMedio();

    printf("\t%c\t\t5) [ < 0 > ] VOLVER AL MENU ANTERIOR...      %c",186,186);
    lineaHInf();
}



/*************************
 * \brief LINEA SUPERIOR
 * \return VOID
 *************************/

void lineaHSup ()
{
    int i;

    printf("\n\t%c", 201);
    for (i = 15; i < 75; i++)
    {
        printf("%c", 205);
    }
    printf("%c\n",187);
}

/*************************
 * \brief LINEA MEDIO
 * \return VOID
 *************************/

void lineaHMedio ()
{
    int i;

    printf("\n\t%c", 186);
    for (i = 15; i < 75; i++)
    {
        printf("%c", 205);
    }
    printf("%c\n",186);
}

/*************************
 * \brief LINEA INFERIOR
 * \return VOID
 *************************/

void lineaHInf ()
{
    int i;

    printf("\n\t%c", 200);
    for (i = 15; i < 75; i++)
    {
        printf("%c", 205);
    }
    printf("%c\n",188);
}

/*************************
 * \brief LINEA SEPARADORA
 * \return VOID
 *************************/

void lineaHSep ()
{
    int i;

    printf("\n\t%c",186);
    for (i = 16; i < 76; i++)
    {
        printf("%c", 196);
    }
    printf("%c",186);
}

/********************************
 * \brief LINEA MOSTRAR MEDIO
 * \return VOID
 ********************************/

void lineaMostrarHMedio ()
{
    int i;

    printf("\n");
    for (i = 15; i < 69; i++)
    {
        printf("%c", 205);
    }
    printf("\n");
}

/********************************
 * \brief LINEA MOSTRAR SEPARADORA
 * \return VOID
 ********************************/

void lineaMostrarHSep ()
{
    int i;

    printf("\n");
    for (i = 16; i < 70; i++)
    {
        printf("%c", 196);
    }
}


void lineaVertical()
{

    printf("\n\t%c", 186);

}

void menu_integrantes()
{
    gotoxy(400,25);
    printf("\n         --------------------------------------------------------------------------\n");
    printf("\t                   TRABAJO PRACTICO FINAL - LABORATORIO 2 -  2021                  \n");
    printf("\n\t                                 >>> INTEGRANTES  <<<\n");
    printf("\n\t                           **************************\n");
    printf("\n\t                           *   LOPEZ, Ciro          *\n");
    printf("\n\t                           *                        *\n");
    printf("\n\t                           *   EULLOQUE, Rodrigo    *\n");
    printf("\n\t                           *                        *\n");
    printf("\n\t                           *   ROBLES, Fernando     *\n");
    printf("\n\t                           *                        *\n");
    printf("\n\t                           **************************\n");
    printf("\n          TECNICATURA UNIVERSITARIA EN PROGRAMACION           UTN MAR DEL PLATA\n");
    printf("\n        ----------------------------------------------------------------------------\n\n");

    system("pause");
    system("cls");
}
