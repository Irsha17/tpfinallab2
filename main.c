#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "consumo.h"
#include "listaConsumo.h"
#include "arbolesclientes.h"

int main()
{
    printf("Trabajo Final LABORATORIO 2\n");

    nodoArbol* arbolClientes = inicArbolClientes();

    arbolClientes = arch2Arbol(arbolClientes, "consumos.dat", "Clientes.dat");


    enOrdenClientes(arbolClientes);

    printf("\n");
    return 0;
}
