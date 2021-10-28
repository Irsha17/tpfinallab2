#ifndef ARBOLESCLIENTES_H_INCLUDED
#define ARBOLESCLIENTES_H_INCLUDED
#include "cliente.h"
#include "listaConsumo.h"

typedef struct _nodoArbol{
	stCliente dato;
	nodoLista* consumos;
	struct _nodoArbol* izq;
	struct _nodoArbol* der;
}nodoArbol;

nodoArbol* inicArbolClientes();
nodoArbol* crearNodoArbolCliente(stCliente cliente, nodoLista* consumo);
nodoArbol* buscaNodoArbolClientePorId(nodoArbol* arbol, int id);
void muestraNodoArbolClientes(nodoArbol* nodo);
void enOrdenClientes(nodoArbol* arbol);
#endif // ARBOLESCLIENTES_H_INCLUDED
