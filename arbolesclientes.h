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
nodoArbol* crearNodoArbolCliente(stCliente cliente);
nodoArbol* buscaNodoArbolClientePorId(nodoArbol* arbol, int id);
void muestraNodoArbolClientes(nodoArbol* nodo);
void enOrdenClientes(nodoArbol* arbol);
nodoArbol* cargarArbolConListas(nodoArbol* arbol, char archConsumos[]);
nodoArbol* arrayClientes2Arbol(stCliente arrayCliente[],int validos);
nodoArbol* insertarPorID(nodoArbol* arbol, stCliente cliente);
stLiquidacion liquidarPeriodo(nodoArbol* cliente, int periodo);
nodoArbol* eliminaNodoArbol(nodoArbol* aux, int id);
nodoArbol * arbolMasDerecha(nodoArbol * arbol);
nodoArbol * arbolMasIzquierdo(nodoArbol * arbol);
int esHoja(nodoArbol * arbol);
#endif // ARBOLESCLIENTES_H_INCLUDED
