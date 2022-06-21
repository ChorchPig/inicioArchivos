#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

int verificarArchivo(const char *fname){
    FILE *fp=fopen(fname, "r");
    if(fp!=NULL){
        fclose(fp);
        return 1;
    }
    return 0;
}

void guardarBackup(FILE *fp){
    long sz;
    fseek(fp, 0, SEEK_END);
    sz=ftell(fp);
    rewind(fp);
    void *memoria= malloc(sz);
    fread(memoria, sz, 1, fp);
    FILE *fcopy=fopen("archivos/backup.bin", "wb");
    fwrite(memoria, sz, 1, fcopy);
    fclose(fcopy);
    free(memoria);
}
