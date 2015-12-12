#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
const int TAM = 10;

struct LISTA
{   int info;
    struct LISTA *prox;
};
typedef struct LISTA LISTA;

void organiza(LISTA **L);
void imprimir(LISTA **L);

int main()
{   LISTA *L;
    L = (LISTA *) malloc(sizeof(LISTA));
    L->info = 0;
    L = NULL;
    organiza(&L);
    imprimir(&L);
    
    printf("\n\n");
    system("pause");
    return 0;    
}

void organiza(LISTA **L)
{   LISTA *p;
    int i = 1;
    p = *L;
    while (i<TAM)
    {   p = (LISTA *)malloc(sizeof(LISTA));
        p->info = i;
        p = p->prox;
        i++;
    }
    p = NULL;
    printf("LISTA INICIAL:\n\n\n");
}

void imprimir(LISTA **L)
{   LISTA *aux;
    for(aux = *L; aux!=NULL; aux = aux->prox)
       printf(" %d  ", aux->info);
}

