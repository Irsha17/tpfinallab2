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
nodoArbol* crearNodoArbolCliente(stCliente cliente, stConsumo consumo);
#endif // ARBOLESCLIENTES_H_INCLUDED
