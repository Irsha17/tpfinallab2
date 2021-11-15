#ifndef LISTA_CONSUMO_H_INCLUDED
#define LISTA_CONSUMO_H_INCLUDED

#include "consumo.h"



typedef struct _nodoLista
{
    stConsumo dato;
    struct _nodoLista* sig;

}nodoLista;

nodoLista* inicLista();
nodoLista* crearNodoLista(stConsumo consumo);
nodoLista* agregarAlPrincipio(nodoLista* lista, nodoLista* nuevo);
void mostrarLista(nodoLista* lista);
void muestraNodo(nodoLista* nodo);

#endif // LISTA_CONSUMO_H_INCLUDED



