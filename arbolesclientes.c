#include <stdio.h>
#include <stdlib.h>
#include "arbolesclientes.h"

nodoArbol* inicArbolClientes(){
    return NULL;
}

nodoArbol* crearNodoArbolCliente(stCliente cliente, nodoLista* consumo){
    nodoArbol* nuevo = (nodoArbol*)malloc(sizeof(nodoArbol));
    nuevo->dato = cliente;
    nuevo->consumos = consumo;
    nuevo->izq = NULL;
    nuevo->der = NULL;

    return nuevo;
}

nodoArbol* agregarArbolClientes(nodoArbol* arbol, nodoArbol* nuevo){
    if(arbol==NULL){
        arbol = nuevo;
    }else{
        if(nuevo->dato.id < arbol->dato.id){
            arbol->izq = agregarArbolClientes(arbol->izq, nuevo);
        }else{
            if(nuevo->dato.id > arbol->dato.id){
                arbol->der = agregarArbolClientes(arbol->der, nuevo);
            }
        }
    }

    return arbol;
}

nodoArbol* buscaNodoArbolClientePorId(nodoArbol* arbol, int id){
    nodoArbol* respuesta = NULL;
    if(arbol){
        if(arbol->dato.id == id){
            respuesta = arbol;
        }else{
            respuesta = buscaNodoArbolClientePorId(arbol->izq, id);
            if(respuesta == NULL){
                respuesta = buscaNodoArbolClientePorId(arbol->der, id);
            }
        }
    }

    return respuesta;
}

nodoArbol* arch2Arbol(nodoArbol* arbol, char archConsumos[], char archClientes[]){
    FILE *parchiConsumos = fopen(archConsumos, "rb");
    FILE *parchiClientes = fopen(archClientes, "rb");
    stConsumo cons;
    stCliente client;
    nodoArbol* aux = NULL;
    if(parchiConsumos){
        while(fread(&cons, sizeof(stConsumo), 1, parchiConsumos)>0){
            if(parchiClientes){
                rewind(parchiClientes);
                while(fread(&client, sizeof(stCliente), 1, parchiClientes)>0){
                    if(cons.idCliente == client.id){
                        aux = buscaNodoArbolClientePorId(arbol, client.id);
                        if(aux == NULL){
                            nodoArbol* nuevo= crearNodoArbolCliente(client, crearNodoLista(cons));
                            arbol = agregarArbolClientes(arbol, nuevo);
                        }else{
                            aux->consumos = agregarAlPrincipio(aux->consumos, crearNodoLista(cons));
                        }

                    }
                }
            }
        }
        fclose(parchiClientes);
        fclose(parchiConsumos);
    }
    return arbol;

}

void enOrdenClientes(nodoArbol* arbol){
    if(arbol){
        enOrdenClientes(arbol->izq);
        muestraNodoArbolClientes(arbol);
        enOrdenClientes(arbol->der);
    }
}

void muestraNodoArbolClientes(nodoArbol* nodo){
    if(nodo->dato.id){
    printf("\n Cliente \n");
    muestraUnCliente(nodo->dato);
    printf("\n\n Consumos\n");
    mostrarLista(nodo->consumos);
    printf("\n\n *********************************************************************** \n");
    }
}

nodoArbol * arbolMasDerecha(nodoArbol * arbol){
    nodoArbol * seg = arbol;
    while(seg->der) {
        seg = seg->der;
    }
    return seg;
}

nodoArbol * arbolMasIzquierdo(nodoArbol * arbol){
    nodoArbol * seg = arbol;
    while(seg->izq) {
        seg = seg->izq;
    }
    return seg;
}

int esHoja(nodoArbol * arbol) {
    int rta = 0;
    if(arbol) {
        if(!arbol->izq && !arbol->der){
            rta = 1;
        }
    }
    return rta;
}

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
nodoArbol* eliminaNodoArbol(nodoArbol* arbol, int id){

    nodoArbol* aux = arbol;
    if(aux) {
        if(id==aux->dato.id) {

            if(aux->izq) {
                nodoArbol* masIzq = arbolMasDerecha(aux->izq);
                aux->dato = masIzq->dato;
                aux->izq = eliminaNodoArbol(aux->izq, id);
            } else if (aux->der) {
                nodoArbol* masDer = arbolMasIzquierdo(aux->der);
                aux->dato = masDer->dato;
                aux->der = eliminaNodoArbol(aux->der, id);
            } else if (esHoja(aux)) {
                aux->consumos=borrarLista(aux->consumos);
                free(aux);
            }
        } else {
            aux->izq = eliminaNodoArbol(aux->izq, id);
            if(!aux->izq) {
                aux->der = eliminaNodoArbol(aux->der, id);
            }
        }
    }
    return arbol;
}
