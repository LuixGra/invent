#import "Itens.h"

int main(){

    Item* lista = NULL;

    int select = 1;
    while(select!=0){

        printf("\nDigite sua operação:\n1.Ver lista.\n2. Adcionar item.\n3. Editar item.(quantidade)\n4. Remover item.\n0. Encerrar\n");
        scanf("%d",&select);
        switch(select){
        case 1:
            imprimeLista(lista);
            break;

        case 2:
            lista = addItem(lista);
            break;


        case 3:
            editarItem(lista);
            break;

        case 4:
            lista = removeItem(lista);
            break;
        }

    }

    return 0;
}
