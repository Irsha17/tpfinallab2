#ifndef ARBOLESCLIENTES_H_INCLUDED
#define ARBOLESCLIENTES_H_INCLUDED

#include "cliente.h"
#include "consumo.h"


typedef struct_nodoArbol
{
    stCliente dato;
    nodoLista* consumos;
    struct_nodoArbol* izq;
    struct_nodoArbol* der;

}nodoArbol;



#endif // ARBOLESCLIENTES_H_INCLUDED
