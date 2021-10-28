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

nodoArbol* agregarArbolClientes(nodoArbol* arbol, nodoArbol* nuevo){
    if(arbol==NULL){
        arbol = nuevo;
    }else{
        if(nuevo->dato.id < arbol->dato.id){
            arbol->izq = agregarArbolClientes(arbol->izq, nuevo);
        }else{
            if(nuevo->dato.id > arbol->dato.id){
                arbol->der = agregarArbolClientes(arbol->der, nuevo);
            }
        }
    }

    return arbol;
}
