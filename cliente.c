#include "cliente.h"

void muestraUnCliente(stCliente cliente){
    printf("ID Cliente:           |%d \n",cliente.id);
    printf("Numero Cliente:       |%d \n",cliente.nroCliente);
    printf("Nombre y Apellido:    |%s %s\n",cliente.nombre, cliente.apellido);
    printf("DNI:                  |%d \n",cliente.dni);
    printf("Correo Electronico:   |%s \n",cliente.email);
    printf("Domicilio:            |%s",cliente.domicilio);
    printf("Celular:              |%s \n",cliente.movil);
    printf("Estado:               |%d \n", (cliente.baja== 0)?"Activo":"Eliminado");

    printf("-------------------------------------------------------------------\n");
}
