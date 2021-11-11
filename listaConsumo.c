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
        muestraNodo(seg);
        seg = seg->sig;
    }
}

void muestraNodo(nodoLista* nodo){
    muestraUnConsumo(nodo->dato);
}

nodoLista* borrarLista(nodoLista* lista){
    nodoLista* proximo=NULL;
    nodoLista* seg=NULL;

    seg = lista;
    while(seg){
        proximo = seg->sig;
        free(seg);
        seg=proximo;
    }
    return seg;
}



int datosConsumidosPorPeriodo(nodoLista* lista, int periodo){
    nodoLista* seg = lista;
    int datos = 0;
    while(seg){
        if(periodo == seg->dato.anio || periodo == seg->dato.mes){
            datos = datos + seg->dato.datosConsumidos;
        }
        seg = seg->sig;

    }
    return datos;
}
