#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include "prototipos.h"

int exist(const char *fname){
    FILE *fp=fopen(fname, "r");
    if(fp!=NULL){
        fclose(fp);
        return 1;
    }
    return 0;
}

long flen(FILE *fp){
    long longitud;
    fseek(fp, 0, 2);
    longitud=ftell(fp);
    return longitud;
}

void mycopy(FILE *fp){
    long int sz=0; //va a marcar el tamaño del archivo
    void *memoria=NULL; //va a almacenar los contenidos del archivo
    FILE *fcopy=fopen("archivos/backup.txt", "wt");
    fseek(fp, 0L, SEEK_END);
    sz = ftell(fp);
    rewind(fp);
    memoria = malloc(sz);
    if(!memoria){
        perror("No se puede reservar memoria.\n");
        exit(2);
    }
    fread(memoria, sz, 1, fp);
    fwrite(memoria, sz, 1, fcopy);
    free(memoria);
    fclose(fcopy);
}
