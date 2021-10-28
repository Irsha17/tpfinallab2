#ifndef ARBOLESCLIENTES_H_INCLUDED
#define ARBOLESCLIENTES_H_INCLUDED


typedef struct _nodoArbol
{
    stCliente dato;
    nodoLista* consumos;
    struct_nodoArbol* izq;
    struct_nodoArbol* der;

} nodoArbol;



#endif // ARBOLESCLIENTES_H_INCLUDED
