#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include "prototipos.h"

int main(){
    setlocale(LC_ALL, "spanish");
    int existe=exist("archivos/archivoPrueba.txt");
    long longitud;
    if(!existe){
        perror("No existe el archivo.\n");
        exit(1);
    }
    FILE *fp=fopen("archivos/archivoPrueba.txt", "r");
    longitud=flen(fp);
    printf("%li", longitud);
    mycopy(fp);
    fclose(fp);
    return 0;
}
