
#ifndef ARQ_H
#define ARQ_H

#endif

#import <string.h>
#import <stdio.h>
#import <stdlib.h>

char nomeArq[] = ("inventario.txt");

FILE* leArq(){

    FILE* f;
    f = fopen(nomeArq, "a");

    if(f!=NULL){
        return f;
    }

    printf("\nErro ao ler arquivo");
    return NULL;

}

void escreveArq(FILE* f, char string[]){
    fprintf(f, "\n%s",string);
}

void excluiArq(){

    printf("Retorno ao excluir arquivo: %d\n", remove(nomeArq));
}

void fechaArq(FILE* f){
    if(f!=NULL){
        fclose(f);
        printf("\nArquivo fechado com sucesso.\n");
    }
}


