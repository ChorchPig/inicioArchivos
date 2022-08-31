#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include "prototipos.h"

void existeArchivo(void const *fname){
    FILE *fp=fopen(fname, "r");
    if(!fp){
        perror("Archivo inexistente. ");
        exit(1);
    }
    fclose(fp);
}

void verificarMemoria(void *ptr, int llamado){
    if(!ptr){
        perror("No se puede reservar memoria. ");
        printf("Error ocurrido en el llamado %i", llamado);
        exit(2);
    }
}

float calcularPromedio(float *temp){
    float promedio;
    for(int i=0; i<horasTotales; i++){
        promedio+=temp[i];
    }
    promedio/=horasTotales;
    return promedio;
}

int obtenerTempMin(float *temp){
    int minTempIndex=0;
    float minTemp=999.999;
    for(int i=0; i<horasTotales; i++){
        if(temp[i]<minTemp){
            minTemp=temp[i];
            minTempIndex=i;
        }
    }
    return minTempIndex;
}

int obtenerTempMax(float *temp){
    int maxTempIndex=0;
    float maxTemp=-999.999;
    for(int i=0; i<horasTotales; i++){
        if(temp[i]>maxTemp){
            maxTemp=temp[i];
            maxTempIndex=i;
        }
    }
    return maxTempIndex;
}
