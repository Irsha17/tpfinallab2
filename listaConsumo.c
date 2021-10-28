#include <stdio.h>
#include <stdlib.h>
#include "listaConsumo.h"

nodoLista* inicLista(){
    return NULL;
}

nodoLista* crearNodoLista(stConsumo consumo){
    nodoLista* nuevo = (nodoLista*)malloc(sizeof(nodoLista));
    nuevo->dato = consumo;
    nuevo->sig = NULL;
    return nuevo;
}

nodoLista* agregarAlPrincipio(nodoLista* lista, nodoLista* nuevo){
    nuevo->sig = lista;
    return nuevo;
}

void mostrarLista(nodoLista* lista){
    nodoLista* seg = lista;
    while(seg){
        muestraUnNodo(seg);
        seg = seg->siguiente;
    }
}

void muestraNodo(nodoLista* nodo){
    muestraUnConsumo(nodoLista->dato);
}
