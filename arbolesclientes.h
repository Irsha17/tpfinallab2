#ifndef ARBOLESCLIENTES_H_INCLUDED
#define ARBOLESCLIENTES_H_INCLUDED

typedef struct _nodoArbol{
	stCliente dato;
	nodoLista* consumos;
	struct _nodoArbol* izq;
	struct _nodoArbol* der;
}nodoArbol;


#endif // ARBOLESCLIENTES_H_INCLUDED
