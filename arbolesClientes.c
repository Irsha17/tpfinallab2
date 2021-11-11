#include "arbolesclientes.h"


nodoArbol* inicArbolClientes(){
    return NULL;
}

nodoArbol* crearNodoArbolClientes(stCliente cliente, nodoLista* consumo){
    nodoArbolPersona* nuevo = (nodoArbolPersona*)malloc(sizeof(nodoArbolPersona));
    nuevo->dato = dato;
    nuevo->izq = NULL;
    nuevo->der = NULL;

    return nuevo;
}
