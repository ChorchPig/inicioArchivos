#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

void existeArchivo(void const *);
void verificarMemoria(void *, int);
float calcularPromedio(float *);
int obtenerTempMin(float *);
int obtenerTempMax(float *);

enum {
    primeraLinea=10, horaStr=6, horasTotales=24
};

#endif // PROTOTIPOS_H_INCLUDED
