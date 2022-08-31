#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include "prototipos.h"

int main(){
    setlocale(LC_ALL, "spanish");
    existeArchivo("archivos/registro.txt");
    FILE *fp=fopen("archivos/registro.txt", "r");
    char *cabecera=(char *)malloc(primeraLinea*sizeof(char));
    verificarMemoria(cabecera, 1);
    char *tiempo[horasTotales];
    for(int i=0; i<horasTotales; i++){
        tiempo[i]=(char *)malloc(horaStr*sizeof(char));
        verificarMemoria(tiempo[i], 2);
    }
    float *temp=(float *)malloc(horasTotales*sizeof(float));
    verificarMemoria(temp, 3);

    fscanf(fp, "%[^\n]", cabecera);
    for(int i=0; i<horasTotales; i++){
        fscanf(fp, " %s", tiempo[i]);
        fscanf(fp, "%f", &temp[i]);
    }
    fclose(fp);


    printf("%s\n", cabecera);
    for(int i=0; i<horasTotales; i++){
        printf("%s\t", tiempo[i]);
        printf("%.2f\n", temp[i]);
    }
    float promedio=0.0;
    int maxTempIndex=0, minTempIndex=0;
    promedio=calcularPromedio(temp);
    maxTempIndex=obtenerTempMax(temp);
    minTempIndex=obtenerTempMin(temp);
    printf("Temperatura promedio: %.2f°C\n", promedio);
    printf("Temperatura mínima: %.2f°C, registrada a las %s\n", temp[minTempIndex], tiempo[minTempIndex]);
    printf("Temperatura máxima: %.2f°C, registrada a las %s\n", temp[maxTempIndex], tiempo[maxTempIndex]);

    free(cabecera);
    free(temp);
    for(int i=0; i<horasTotales; i++){
        free(tiempo[i]);
    }
    return 0;
}
