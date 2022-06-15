#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

typedef struct{
    int cantChar;
    char *palabra;
} palabras;

int exist(const char*);
long flen(FILE *);
void mycopy(FILE *);

#endif //PROTOTIPOS_H_INCLUDED
