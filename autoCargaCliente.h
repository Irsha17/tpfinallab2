#ifndef AUTOCARGACLIENTE_H_INCLUDED
#define AUTOCARGACLIENTE_H_INCLUDED

int nroCliente();
char* getDomicilio();
char* getNro();
char* getNombre();
char* getApellido();
char* getDni();
char* getEmail();
char* getMovil();
int csv2arreglo(int col, char archivo[], char n[][col], int dim);
int csv2arregloBis(int col, char archivo[], char n[][col], int dim);

#endif // AUTOCARGACLIENTE_H_INCLUDED
