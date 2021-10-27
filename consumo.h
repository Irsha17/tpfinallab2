#ifndef CONSUMO_H_INCLUDED
#define CONSUMO_H_INCLUDED

#include "cliente.h"


typedef struct
{
    int id; ///campo unico y autoincremental//
    int idCliente;
    int anio;
    int mes;/// 1 al 12//
    int dia; /// 1 a ... dependiendo del mes //
    int datosConsumidos; /// expresados en mb//
    int baja;/// 0 si esta activo - 1 si esta elimunado//

}stConsumo;


#endif // CONSUMO_H_INCLUDED
