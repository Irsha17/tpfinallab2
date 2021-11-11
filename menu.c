#include "menu.h"

void menu(){

    printf("|------------------------------------------------------------------------|\n");
    printf("|                             UTN MOVIL                                  |\n");
    printf("|------------------------------------------------------------------------|\n");
    printf("|-----------------BIENVENIDO A LA APLICACION UTN MOVIL-------------------|\n");
    printf("|-----NUESTRA EMPRESA SE CARACTERIZA POR LA MEJOR ATENCION AL CLIENTE----|\n");
    printf("|------------FISCALIZAMOS SUS CONSUMOS PARA SU TRANQUILIDAD--------------|\n");
    printf("|------------------------------------------------------------------------|\n");

    printf("\n");
    system("pause\n");
    system("cls");
    printf("\n");

    printf("|---------------------------¿Que desea realizar?-------------------------|\n");
    printf("|------------------------------------------------------------------------|\n");
    printf("|     -------------------------              ------------------------    |\n");
    printf("|     |                       |              |                      |    |\n");
    printf("|     |       CLIENTES        |              |       CONSUMOS       |    |\n");
    printf("|     |                       |              |                      |    |\n");
    printf("|     -------------------------              ------------------------    |\n");
    printf("|           (PRESIONE 1)                           (PRESIONE 2)          |\n");
    printf("|     -------------------------              ------------------------    |\n");
    printf("|     |                       |              |                      |    |\n");
    printf("|     |   ADMINISTRAR ARBOL   |              |   SALIR DEL SISTEMA  |    |\n");
    printf("|     |                       |              |                      |    |\n");
    printf("|     -------------------------              ------------------------    |\n");
    printf("|           (PRESIONE 3)                           (PRESIONE 0)          |\n");
    printf("|------------------------------------------------------------------------|\n");
}

void menu1(){

    printf("|--------------------------¿Que desea realizar?--------------------------|\n");
    printf("|------------------------------------------------------------------------|\n");
    printf("|     ------------------------              ------------------------     |\n");
    printf("|     |                      |              |                      |     |\n");
    printf("|     |   REGISTRAR CLIENTE  |              |  MODIFICAR CLIENTE   |     |\n");
    printf("|     |                      |              |                      |     |\n");
    printf("|     ------------------------              ------------------------     |\n");
    printf("|          (PRESIONE 1)                           (PRESIONE 2)           |\n");
    printf("|     ------------------------              ------------------------     |\n");
    printf("|     |                      |              |                      |     |\n");
    printf("|     |     MOSTRAR TODOS    |              |      MOSTRAR UN      |     |\n");
    printf("|     |      LOS CLIENTES    |              |       CLIENTE        |     |\n");
    printf("|     |                      |              |                      |     |\n");
    printf("|     ------------------------              ------------------------     |\n");
    printf("|          (PRESIONE 3)                           (PRESIONE 4)           |\n");
    printf("|                        ------------------------                        |\n");
    printf("|                        |                      |                        |\n");
    printf("|                        |    VOLVER AL MENU    |                        |\n");
    printf("|                        |       ANTERIOR       |                        |\n");
    printf("|                        |                      |                        |\n");
    printf("|                        ------------------------                        |\n");
    printf("|                             (PRESIONE 0)                               |\n");
    printf("|------------------------------------------------------------------------|\n");
}

void menuCliente(){

    printf("|---------------------------¿Que desea realizar?-------------------------|\n");
    printf("|------------------------------------------------------------------------|\n");
    printf("|     -------------------------              ------------------------    |\n");
    printf("|     |                       |              |                      |    |\n");
    printf("|     |      CARGA MANUAL     |              |     CARGA RANDOM     |    |\n");
    printf("|     |                       |              |                      |    |\n");
    printf("|     -------------------------              ------------------------    |\n");
    printf("|           (PRESIONE 1)                           (PRESIONE 2)          |\n");
    printf("|------------------------------------------------------------------------|\n");
}

void menu2(){

    printf("|---------------------------¿Que desea realizar?-------------------------|\n");
    printf("|------------------------------------------------------------------------|\n");
    printf("|     -------------------------              ------------------------    |\n");
    printf("|     |                       |              |                      |    |\n");
    printf("|     | CAMBIAR DATOS CLIENTE |              |  ALTA / BAJA CLIENTE |    |\n");
    printf("|     |                       |              |                      |    |\n");
    printf("|     -------------------------              ------------------------    |\n");
    printf("|           (PRESIONE 1)                           (PRESIONE 2)          |\n");
    printf("|------------------------------------------------------------------------|\n");
}

void menu3(){

    printf("|---------------------------¿Que desea realizar?-------------------------|\n");
    printf("|------------------------------------------------------------------------|\n");
    printf("|     --------------------------             -------------------------   |\n");
    printf("|     |                        |             |                       |   |\n");
    printf("|     |       ALTA / BAJA      |             |      CONSUMOS DE      |   |\n");
    printf("|     |         CONSUMO        |             |      UN  CLIENTE      |   |\n");
    printf("|     |                        |             |                       |   |\n");
    printf("|     --------------------------             -------------------------   |\n");
    printf("|           (PRESIONE 1)                           (PRESIONE 2)          |\n");
    printf("|     ------------------------              ------------------------     |\n");
    printf("|     |                      |              |                      |     |\n");
    printf("|     |      VER LISTADO     |              |    BUSCAR CONSUMO    |     |\n");
    printf("|     |      DE CONSUMOS     |              |       POR FECHA      |     |\n");
    printf("|     |                      |              |                      |     |\n");
    printf("|     ------------------------              ------------------------     |\n");
    printf("|          (PRESIONE 3)                           (PRESIONE 4)           |\n");
    printf("|     ------------------------              ------------------------     |\n");
    printf("|     |                      |              |                      |     |\n");
    printf("|     |     CARGA  RANDOM    |              |      CARGAR UN       |     |\n");
    printf("|     |      DE CONSUMOS     |              |       CONSUMO        |     |\n");
    printf("|     |                      |              |                      |     |\n");
    printf("|     ------------------------              ------------------------     |\n");
    printf("|          (PRESIONE 5)                           (PRESIONE 6)           |\n");
    printf("|                                                                        |\n");
    printf("|                           ----------------                             |\n");
    printf("|                           |              |                             |\n");
    printf("|                           |   VOLVER AL  |                             |\n");
    printf("|                           | MENU ANTERIOR|                             |\n");
    printf("|                           |              |                             |\n");
    printf("|                           ----------------                             |\n");
    printf("|                             (PRESIONE 0)                               |\n");
    printf("|------------------------------------------------------------------------|\n");
}

void menu4(){

    printf("|---------------------------¿Que desea realizar?-------------------------|\n");
    printf("|------------------------------------------------------------------------|\n");
    printf("|     -------------------------              ------------------------    |\n");
    printf("|     |                       |              |                      |    |\n");
    printf("|     |     CARGAR ARBOL      |              |  LIQUIDAR CONSUMOS   |    |\n");
    printf("|     |    DESDE ARCHIVOS     |              |    POR PERIODO       |    |\n");
    printf("|     -------------------------              ------------------------    |\n");
    printf("|           (PRESIONE 1)                           (PRESIONE 2)          |\n");
    printf("|     -------------------------              ------------------------    |\n");
    printf("|     |                       |              |                      |    |\n");
    printf("|     |  ELIMINAR UN CLIENTE  |              |     MOSTRAR ARBOL    |    |\n");
    printf("|     |                       |              |                      |    |\n");
    printf("|     -------------------------              ------------------------    |\n");
    printf("|           (PRESIONE 3)                           (PRESIONE 4)          |\n");
    printf("|                                                                        |\n");
    printf("|                           ----------------                             |\n");
    printf("|                           |              |                             |\n");
    printf("|                           |   VOLVER AL  |                             |\n");
    printf("|                           | MENU ANTERIOR|                             |\n");
    printf("|                           |              |                             |\n");
    printf("|                           ----------------                             |\n");
    printf("|                             (PRESIONE 0)                               |\n");
    printf("|------------------------------------------------------------------------|\n");

}
