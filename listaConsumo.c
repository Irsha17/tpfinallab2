#include <stdio.h>
#include <stdlib.h>
#include "listaConsumo.h"

///.....................................FUNCIONES DE LISTAS DE CONSUMOS.......................................................
///...........................................................................................................................


//INICIA LISTA DE CONSUMOS
nodoLista* inicLista(){
    return NULL;
}

//CREA NODO LISTA
nodoLista* crearNodoLista(stConsumo consumo){
    nodoLista* nuevo = (nodoLista*)malloc(sizeof(nodoLista));
    nuevo->dato = consumo;
    nuevo->sig = NULL;
    return nuevo;
}

//AGREGA NODO LISTA AL PRINCIPIO DE LA MISMA
nodoLista* agregarAlPrincipio(nodoLista* lista, nodoLista* nuevo){
    nuevo->sig = lista;
    return nuevo;
}

//AGREGAR EN ORDEN SEGUN FECHA

nodoLista* agregarEnOrdenPorFecha(nodoLista* lista, nodoLista* nuevoNodo){
    if(!lista){
        lista=nuevoNodo;
    }else{
        if(nuevoNodo->dato.mes < lista->dato.mes){
            lista = agregarAlPrincipio(lista, nuevoNodo);
        }
        else if(nuevoNodo->dato.mes == lista->dato.mes && nuevoNodo->dato.dia < lista->dato.dia){
            lista = agregarAlPrincipio(lista, nuevoNodo);
        }
        else{
            nodoLista* ante = lista;
            nodoLista* seg = lista->sig;
            while(seg != NULL && nuevoNodo->dato.mes >= seg->dato.mes){
                ante = seg;
                seg = seg->sig;
            }
            ante->sig = nuevoNodo;
            nuevoNodo->sig = seg;
        }
    }

    return lista;
}

//MUESTRA LISTA
void mostrarLista(nodoLista* lista){
    nodoLista* seg = lista;
    while(seg){
        muestraNodo(seg);
        seg = seg->sig;
    }
}

//MUESTRA UN NODO
void muestraNodo(nodoLista* nodo){
    muestraUnConsumo(nodo->dato);
}


//BORRA TODA UNA LISTA
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


//SUMA LOS DATOS CONSUMIDOS, DURANTE CIERTO PERIODO PASADO POR PARAMETRO.
int datosConsumidosPorPeriodo(nodoLista* lista, int periodo){
    nodoLista* seg = lista;
    int datos = 0;
    while(seg){
        if(seg->dato.baja == 0 && (periodo == seg->dato.anio || periodo == seg->dato.mes)){
            datos = datos + seg->dato.datosConsumidos;
        }
        seg = seg->sig;

    }
    return datos;
}

