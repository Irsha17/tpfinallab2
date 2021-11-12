#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbolesclientes.h"
#include "cliente.h"
#include "consumo.h"


///............................FUNCIONES PARA INICIAR ARBOL, CREAR NODOS, AGREGARLOS Y BUSCARLOS..............................
///...........................................................................................................................


//INICIA ARBOL
nodoArbol* inicArbolClientes(){
    return NULL;
}

//CREA NODO ARBOL, CON SU ESTRUCTURA CLIENTE Y SE LE INICIALIZA UNA LISTA DE CONSUMOS
nodoArbol* crearNodoArbolCliente(stCliente cliente){
    nodoArbol* nuevo = (nodoArbol*)malloc(sizeof(nodoArbol));
    nuevo->dato = cliente;
    nuevo->consumos = inicLista();
    nuevo->izq = NULL;
    nuevo->der = NULL;

    return nuevo;
}

//AGREGA UN NODO AL ARBOL, DE FORMA ORDENADA. MENORES POR LA IZQUIERDA, MAYORES POR LA DERECHA.
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

//BUSCA EN EL ARBOL, EL CLIENTE QUE COINCIDA CON EL ID PASADO POR PARAMETRO. LUEGO LO RETORNA
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



///.....................................FUNCIONES PARA CARGAR ARBOL DESDE ARCHIVOS............................................
///...........................................................................................................................


//SE RECORRE EL ARCHIVO DE CONSUMOS Y SE AGREGA CADA CONSUMO A SU CLIENTE CORRESPONDIENTE, SEGUN EL ID QUE LOS RELACIONA.
nodoArbol* cargarArbolConListas(nodoArbol* arbol, char archConsumos[]){
    FILE *parchiConsumos = fopen(archConsumos, "rb");
    stConsumo cons;
    nodoArbol* aux = NULL;
    int i = 0;
    if(parchiConsumos){
        while(fread(&cons, sizeof(stConsumo), 1, parchiConsumos)>0){
            aux = buscaNodoArbolClientePorId(arbol, cons.idCliente);
            aux->consumos = agregarAlPrincipio(aux->consumos, crearNodoLista(cons));
        }

    }
    fclose(parchiConsumos);

    return arbol;

}

//SE DIVIDE EL ARREGLO DE CLIENTES CON EL FIN DE QUE, AL PASAR CADA CLIENTE AL ARBOL, ESTE QUEDE BALANCEADO.
nodoArbol* arrayClientes2Arbol(stCliente arrayCliente[],int validos){
    nodoArbol* arbol = NULL;
    int i, mitad=(validos-1)/2;
    for(i=mitad; i>=0; i--){
        if( (i%2)!=0 ){
            arbol=agregarArbolClientes(arbol, crearNodoArbolCliente(arrayCliente[i]));
        }
    }
    for(i=mitad; i>=0; i--){
        if( (i%2)==0 ){
            arbol=agregarArbolClientes(arbol, crearNodoArbolCliente(arrayCliente[i]));
        }
    }
    //PARTE DERECHA
    for(i=mitad+1; i<validos; i++){
        if( (i%2)!=0 ){
            arbol=agregarArbolClientes(arbol, crearNodoArbolCliente(arrayCliente[i]));
        }
    }
    for(i=mitad+1; i<validos; i++){
        if( (i%2)==0 ){
            arbol=agregarArbolClientes(arbol, crearNodoArbolCliente(arrayCliente[i]));
        }
    }
    return arbol;
}


///.....................................FUNCIONES MOSTRAR UN ARBOL DE LISTAS..................................................
///...........................................................................................................................

//MUESTRA ARBOL INORDER
void enOrdenClientes(nodoArbol* arbol){
    if(arbol){
        enOrdenClientes(arbol->izq);
        muestraNodoArbolClientes(arbol);
        enOrdenClientes(arbol->der);
    }
}

//MUESTRA NODO ARBOL CON SU ESTRUCTURA CLIENTE Y SU RESPECTIVA LISTA DE CONSUMOS
void muestraNodoArbolClientes(nodoArbol* nodo){
    if(nodo->dato.id){
    printf("\n Cliente \n");
    muestraUnCliente(nodo->dato);
    printf("\n\n Consumos\n");
    mostrarLista(nodo->consumos);
    printf("\n\n *********************************************************************** \n");
    }
}


///.....................................FUNCIONES PARA ELIMINAR NODO DEL ARBOL................................................
///...........................................................................................................................

//ELIMINA UN NODO DEL ARBOL
nodoArbol* eliminaNodoArbol(nodoArbol* aux, int id){

    if(aux) {
        if(id==aux->dato.id) {

            if(aux->izq) {
                nodoArbol* masDer = arbolMasDerecha(aux->izq);
                aux->dato = masDer->dato;
                aux->consumos = masDer->consumos;
                aux->izq = eliminaNodoArbol(aux->izq, masDer->dato.id);
            } else if (aux->der) {
                nodoArbol* masIzq = arbolMasIzquierdo(aux->der);
                aux->dato = masIzq->dato;
                aux->der = eliminaNodoArbol(aux->der, masIzq->dato.id);
            } else if (esHoja(aux)) {
                aux->consumos=borrarLista(aux->consumos);
                free(aux);
                aux = NULL;
            }
        }else{
            if(id > aux->dato.id){
                aux->der = eliminaNodoArbol(aux->der, id);
            }else{
                aux->izq = eliminaNodoArbol(aux->izq, id);
            }
        }
    }
    return aux;
}



//RETORNA EL NODO ARBOL QUE SE ENCUENTRA MAS A LA DERECHA
nodoArbol * arbolMasDerecha(nodoArbol * arbol){
    nodoArbol * seg = arbol;
    while(seg->der) {
        seg = seg->der;
    }
    return seg;
}

//RETORNA EL NODO ARBOL QUE SE ENCUENTRA MAS A LA IZQUIERDA
nodoArbol * arbolMasIzquierdo(nodoArbol * arbol){
    nodoArbol * seg = arbol;
    while(seg->izq) {
        seg = seg->izq;
    }
    return seg;
}

//RETORNA 1 EN CASO DE QUE EL NODO ARBOL SEA HOJA, ES DECIR, QUE NO TIENE HIJOS
int esHoja(nodoArbol * arbol) {
    int rta = 0;
    if(arbol) {
        if(!arbol->izq && !arbol->der){
            rta = 1;
        }
    }
    return rta;
}


///.....................................FUNCION DE LIQUIDACION DE CONSUMOS....................................................
///...........................................................................................................................


//RECIBE EL NODO DEL CLIENTE Y EL PERIODO AL QUE SE LE DESEA REALIZAR LA LIQUIDACION DE SUS CONSUMOS.
stLiquidacion liquidarPeriodo(nodoArbol* cliente, int periodo){
    stLiquidacion liquidacion;
    if(cliente){
        strcpy(liquidacion.nombre, cliente->dato.nombre); //LOS DATOS SON ALMACENADOS EN UNA ESTRUCTURA LIQUIDACION
        strcpy(liquidacion.apellido, cliente->dato.apellido);
        liquidacion.idCliente = cliente->dato.id;
        liquidacion.periodo = periodo;
        liquidacion.datosConsumidos = datosConsumidosPorPeriodo(cliente->consumos, periodo);//SE LLAMA A LA FUNCION QUE SE ENCARGA DE SUMAR LOS DATOS CONSUMIDOS SEGUN PERIODO.
    }
    return liquidacion;
}
