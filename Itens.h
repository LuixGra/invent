#import "Arq.h"

#ifndef ITENS_H
#define ITENS_H
#endif // ITENS_H

int id = 0;

typedef struct item{
    char nome[30];
    int quantidade;
    float preco;
    struct item* prox;
    int id;
}Item;


Item* criaItem(){
    Item* p = (Item*)malloc(sizeof(Item));
    p->prox = NULL;
    p->id = id;

    printf("\nQual o nome do item?\n");
    scanf("%s",p->nome);
    printf("\nQuantos itens?\n");
    scanf("%d",&p->quantidade);
    printf("\nPreco\n");
    scanf("%f",&p->preco);

    id++;

    return p;
}

Item* addItem(Item* lista){
    if(lista==NULL){
        Item* p = criaItem();
        lista = p;
        return lista;

    }
    else{
        Item* aux = lista;
        while(lista->prox!=NULL){
            lista = lista->prox;
        }
        Item* p = criaItem();
        lista->prox = p;
        lista = aux;
        return lista;

    }
}

int achaItem(Item* lista){
    printf("\nDigite o ID do item:\n");
    int n = 0;
    scanf("%d",&n);
    Item* aux = lista;

    int nm = 0;

    if(lista->id==n){
        return nm;
    }
    else{
        while(lista->prox!=NULL){
            lista = lista->prox;
            nm++;
            if(lista->id==n){
                return nm;
            }
        }
    }

}


Item* removeItem(Item* lista){
    if(lista!=NULL){
        int n = achaItem(lista);
        Item* comeco = lista;
        if(n==0){
            Item* aux = lista;
            lista = lista->prox;
            free(aux);
            return lista;
        }
        for(int i = 0; i < n-1; i++){
            lista = lista->prox;

        }
        Item* aux = lista;
        lista = lista->prox;
        Item* auxx = lista->prox;
        free(lista);
        lista = aux;
        lista->prox = auxx;
        lista = comeco;
        return lista;
    }
    else{

        printf("\nLista vazia.\n");
    }

}

void imprimeItem(Item* lista){
    printf("\n%d||%d||%s||%f\n",lista->id, lista->quantidade, lista->nome, lista->preco);
}

void imprimeLista(Item* lista){
    if(lista==NULL){
        printf("\nLista vazia.\n");
    }
    else{
        Item* aux = lista;
        while(lista->prox!=NULL){
            imprimeItem(lista);
            lista = lista->prox;
        }
        imprimeItem(lista);
        lista = aux;

    }

}

void editarItem(Item* lista){
    if(lista!=NULL){
        int n = achaItem(lista);
        Item* aux = lista;
        int quant;

        for(int i = 0; i<n; i++){
            lista = lista->prox;
        }

        printf("\nQual a nova quantia total do item?\n");
        scanf("%d",&quant);

        lista->quantidade = quant;

        lista = aux;
    }
    else{
        printf("\nLista vazia.\n");
    }

}

