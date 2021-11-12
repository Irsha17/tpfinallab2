#ifndef CONSUMO_H_INCLUDED
#define CONSUMO_H_INCLUDED

typedef struct{ //Estructura de los consumos
    int id; // campo único y autoincremental
    int idCliente;
    int anio;
    int mes; // 1 a 12
    int dia; // 1 a … dependiendo del mes
    int datosConsumidos; // expresados en mb.
    int baja; // 0 si está activo - 1 si está eliminado
}stConsumo;

typedef struct{
    int anio;
    int mes;
    int dia;
}stFecha;

typedef struct{
    int idCliente;
    char nombre[30];
	char apellido[30];
    int periodo;
    int datosConsumidos;
}stLiquidacion;
                                                                                              ///
void cargaUnConsumo(char archivo[]);                                                          ///
void cargaConsumosRandom(char archivo[], char archClientes[]);                                ///
void muestraUnConsumo(stConsumo a);                                                           ///
void muestraUnaLiquidacion(stLiquidacion l);                                                  ///
void muestraArchivo(char archivo[]);                                                          ///
int ultimoId(char archivo[]);                                                                 ///
void muestraConsumosPorCliente(char archivo[], int id);                                       ///
void buscarConsumosXFecha(char archivoConsumos[], int anio, int mes, int dia);                ///
void modificarConsumoAltaBaja (char archivoConsumos[], int anio, int mes, int dia);           ///
stFecha fechaAleatoria();                                                                     ///



void cargaUnConsumo(char archivo[]);                                                          ///
void altaConsumos(char archivo[]);                                                            ///
void muestraUnConsumo(stConsumo a);                                                           ///
void muestraArchivo(char archivo[]);                                                          ///
int ultimoId(char archivo[]);                                                                 ///
void muestraConsumosPorCliente(char archivo[], int id);                                       ///
void buscarConsumosXFecha(char archivoConsumos[], int anio, int mes, int dia);                ///
void modificarConsumoAltaBaja (char archivoConsumos[], int anio, int mes, int dia);           ///


#endif // CONSUMO_H_INCLUDED
