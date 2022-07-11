#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "prototipos.h"

int main(){
    setlocale(LC_ALL, "spanish");
    unsigned int cantHoras;
    printf("Cantidad de horas registradas: ");
    scanf("%u", &cantHoras);
    float *temp=(float *)malloc(sizeof(float)*cantHoras);
    verificarMemoria(temp, 1);
    for(int i=0; i<cantHoras; i++){
        printf("%i temperatura registrada: ", i+1);
        scanf("%f", &temp[i]);
        printf("\n");
    }
    FILE *fp=fopen("archivos/registro.bin", "wb");
    char *str="Temp,Hora,";
    int longitud=strlen(str);
    fwrite(str, sizeof(char), longitud, fp);
    fwrite(temp, sizeof(float), cantHoras, fp);
    fclose(fp);
    free(temp);
    return 0;
}
