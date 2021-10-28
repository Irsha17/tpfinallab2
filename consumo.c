#include "consumo.h"

void muestraUnConsumo(stConsumo consumo){
    printf("\n Id.....................: %d", consumo.id);
    printf("\n Id de Cliente..........: %d", consumo.idCliente);
    printf("\n Fecha..................: %.2d/%.2d/%d", consumo.dia, consumo.mes, consumo.anio);
    printf("\n Datos Consumidos.......: %d Mb", consumo.datosConsumidos);
    printf("\n Baja...................: %d", (consumo.baja== 0)?"Activo":"Eliminado");
    printf("\n---------------------------------------------------");
}
