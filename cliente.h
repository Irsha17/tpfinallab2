#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include "consumo.h"

typedef struct {
	int id; /// campo único y autoincremental
	int nroCliente;
	char nombre[30];
	char apellido[30];
	char dni[10];
	char email[30];
	char domicilio[45];
	char movil[12];
	int baja; /// 0 si está activo - 1 si está eliminado
} stCliente;

void cargarCliente(char archivo[]);
int idClientes(char archivo[]);
int contarIdCliente(char archivo[]);
int validacionNroCliente (char archivo[],int nroCliente);
int validacionClienteDni(char archivo[],char dni[]);
int validacionEmail(char archivo[],int dim,char email[][dim]);
void consultaIdCliente(char archivo[], int nro);
void mostrarArchClientes(char archivo[]);
void muestraUnCliente(stCliente cliente);
void modificarCliente(char archivo[]);
void bajaCliente(char archivo[], int id);
void cargaClienteRandom(char arch[], int cantidad);
stCliente cargaUnClienteRand(FILE *fp, int i);
int file2ArrayClientes(stCliente arreglo[]);

#endif // CLIENTE_H_INCLUDED
