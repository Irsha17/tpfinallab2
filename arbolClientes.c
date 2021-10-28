#include <stdio.h>
#include <stdlib.h>
#include "arbolesclientes.h"

nodoArbol* inicArbolClientes(){
    return NULL;
}

nodoArbol* crearNodoArbolCliente(stCliente cliente, nodoLista* consumo){
    nodoArbol* nuevo = (nodoArbol*)malloc(sizeof(nodoArbol));
    nuevo->dato = cliente;
    nuevo->consumos = consumo;
    nuevo->izq = NULL;
    nuevo->der = NULL;

    return nuevo;
}
