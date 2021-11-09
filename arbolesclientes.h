#ifndef ARBOLESCLIENTES_H_INCLUDED
#define ARBOLESCLIENTES_H_INCLUDED
#include "cliente.h"
#include "listaConsumo.h"

<<<<<<< Updated upstream
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
=======
#include "cliente.h"
#include "Lista_Consumo.h"


typedef struct _nodoArbol{
	stCliente dato;
	nodoLista* consumos;
	struct _nodoArbol* izq;
	struct _nodoArbol* der;
}nodoArbol;
>>>>>>> Stashed changes

/// Agregar nodo arbol///

<<<<<<< Updated upstream
=======
nodoArbol* inicArbolClientes();
nodoArbol* crearNodoArbolCliente(stCliente cliente, nodoLista* consumo);
nodoArbol* buscaNodoArbolClientePorId(nodoArbol* arbol, int id);
void muestraNodoArbolClientes(nodoArbol* nodo);
void enOrdenClientes(nodoArbol* arbol);


nodoArbol * arbolMasDerecha(nodoArbol * arbol);
nodoArbol * arbolMasIzquierdo(nodoArbol * arbol);
int esHoja(nodoArbol * arbol);
nodoLista* eliminaPrimerNodo(nodoLista* lista);
nodoArbol * eliminaNodoArbol(nodoArbol* arbol, int id);
nodoLista* borrarLista(nodoLista* lista);

>>>>>>> Stashed changes
nodoArbol * arbolMasDerecha(nodoArbol * arbol);
nodoArbol * arbolMasIzquierdo(nodoArbol * arbol);
int esHoja(nodoArbol * arbol);
nodoLista* eliminaPrimerNodo(nodoLista* lista);
nodoArbol * eliminaNodoArbol(nodoArbol* arbol, int id);
nodoLista* borrarLista(nodoLista* lista);

#endif // ARBOLESCLIENTES_H_INCLUDED
