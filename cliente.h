#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct {
	int id; /// campo �nico y autoincremental
	int nroCliente;
	char nombre[30];
	char apellido[30];
	char dni[10];
	char email[30];
	char domicilio[45];
	char m�vil[12];
	int baja; /// 0 si est� activo - 1 si est� eliminado
} stCliente;

void muestraUnCliente(stCliente cliente){
    printf("\n ID")
}

#endif // CLIENTE_H_INCLUDED
