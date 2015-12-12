#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
const int MAX = 20;

void iniciaF1(int fila1[], int *i1, int *f1, int tam1);
void iniciaF2(int fila2[], int *i2, int *f2, int tam1, int tam2);
void comparar(int fila1[], int fila2[], int *i1, int *f1, int *i2, int *f2);

int main()
{   int fila1[MAX], fila2[MAX];
    int i1 = -1, f1 = -1, tam1;
    int i2 = -1, f2 = -1, tam2;
    printf("\n Tamanho da Fila 1: ");
    scanf("%d", &tam1);
    fflush(stdin);
    while(tam1 > 20)
    {   printf("\n Tamanho invalido! Digite novamente: ");
        scanf("%d", &tam1);
        fflush(stdin);
    }
    system("cls");
    tam2 = MAX - tam1;
    iniciaF1(fila1, &i1, &f1, tam1);
    iniciaF2(fila2, &i2, &f2, tam1, tam2);
    comparar(fila1, fila2, &i1, &f1, &i2, &f2);
    
    printf("\n\n");
    system("pause");
    return 0;
}

void iniciaF1(int fila1[], int *i1, int *f1, int tam1)
{   printf("Preenchendo as filas...\n\n");
    printf("\n FILA 1:\n\n");
    for (int i=0, j=0; i<tam1; i++, j=j+2)
    {   fila1[i] = j+1;
        printf(" %d ", fila1[i]);
    }
    *i1 = 0;
    *f1 = tam1-1;
}

void iniciaF2(int fila2[], int *i2, int *f2, int tam1, int tam2)
{   printf("\n\n FILA 2:\n\n");
    for (int i=0, j=0; i<tam2; i++, j=j+2)
    {   fila2[i] = j;
        printf(" %d ", fila2[i]);
    }
    *i2 = 0;
    *f2 = tam2-1;
}

void comparar(int fila1[], int fila2[], int *i1, int *f1, int *i2, int *f2)
{   int fila3[(MAX*2)+1];
    int i3 = 0, f3 = 0;
    printf("\n\n FILA 3: \n\n");
    while(*i1!=*f1 || *i2!=*f2)
    {   if(fila1[*i1] <= fila2[*i2])
        {   f3 = (f3+1)%(MAX*2);
            printf(" %d ", fila1[*i1]);
            fila3[f3] = fila1[*i1];
            (*i1)++;
            
            f3 = (f3+1)%(MAX*2);
            fila3[f3] = fila2[*i2];
            (*i2)++;
        }
        else
        {   f3 = (f3+1)%(MAX*2);
            printf(" %d ", fila1[*i2]);
            fila3[f3] = fila2[*i1];
            (*i1)++;
            
            f3 = (f3+1)%(MAX*2);
            fila3[f3] = fila1[*i2];
            (*i2)++;
        }
    }
    while(*i1 == *f1 && *i2 == *f2)
    {   f3 = (f3+1)%(MAX*2);
        fila3[f3] = fila2[*i2];
        (*i2)++;
    }
    while(*i2 == *f2 && *i1== *f1)
    {   f3 = (f3+1)%(MAX*2);
        fila3[f3] = fila1[*i1];
        (*i1)++;
    }
}


