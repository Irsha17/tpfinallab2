#ifndef LISTACONSUMO_H_INCLUDED
#define LISTACONSUMO_H_INCLUDED
#include "consumo.h"

typedef struct _nodoLista{
	stConsumo dato;
	struct _nodoLista* sig;
}nodoLista;

nodoLista* inicLista();
nodoLista* crearNodoLista(stConsumo consumo);
nodoLista* agregarAlPrincipio(nodoLista* lista, nodoLista* nuevo);
void mostrarLista(nodoLista* lista);
void muestraNodo(nodoLista* nodo);
nodoLista* borrarLista(nodoLista* lista);
int datosConsumidosPorPeriodo(nodoLista* lista, int periodo);


#endif // LISTACONSUMO_H_INCLUDED
