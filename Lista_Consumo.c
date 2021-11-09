
#include <stdio.h>
#include <stdlib.h>
#include "lista_Consumo.h"

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
        muestraNodo(seg);
        seg = seg->sig;
    }
}

void muestraNodo(nodoLista* nodo){
    muestraUnConsumo(nodo->dato);
}
