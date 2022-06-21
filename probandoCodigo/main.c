#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "prototipos.h"

int main(){
    setlocale(LC_ALL, "spanish");
    int existe=verificarArchivo("archivos/archivoPrueba.bin");
    if(!existe){
        perror("Archivo inexistente. ");
        exit(1);
    }
    int *contenido=(int *) malloc(sizeof(int)*2);
    if(!contenido){
        perror("No se puede reservar memoria. ");
        exit(2);
    }
    FILE *fp=fopen("archivos/archivoPrueba.bin", "rb");
    fread(contenido, sizeof(int), 2, fp);
    fclose(fp);
    for(int i=0; i<2; i++){
        printf("%c ", contenido[i]);
    }
    free(contenido);
    return 0;
}
