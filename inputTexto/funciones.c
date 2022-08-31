#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include "prototipos.h"

int existe(void const *fname){
    FILE *fp=fopen(fname, "r");
    if(!fp){
        perror("Archivo inexistente. ");
        exit(1);
    }
    return 0;
}

void verificarMemoria(void *ptr, int llamado){
    if(!ptr){
        perror("No se puede reservar memoria. ");
        printf("Error ocurrido en el llamado %i", llamado);
        exit(1);
    }
}
