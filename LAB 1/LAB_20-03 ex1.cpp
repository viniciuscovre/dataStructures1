#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct LISTA
{   int info, prox;
};

typedef LISTA LISTA;
LISTA L[MAX];
int dispo;

void organiza();
int leiaVi();
int leiaVf(int Vi);
void remove(int Vi, int Vf);
void libera(int i);
void exibir();

int main()
{   organiza();
    exibir();
    int Vi = leiaVi();
    int Vf = leiaVf(Vi);
    remove(Vi, Vf);
    exibir();

    printf("\n\n");
    system("pause");
    return 0;
}

void organiza()
{   for(int i=0; i<MAX-1; i++)
        L[i].prox = i+1;
    L[MAX-1].prox = -1;
    
    for(int i=0; i<MAX; i++)
        L[i].info = i;
        
    printf("LISTA INICIAL:\n\n\n");
}

int leiaVi()
{   int Vi;
    printf("\n\nDigite o valor inicial (Vi): ");
    scanf("%d", &Vi);
    fflush(stdin);
    return Vi;
}

int leiaVf(int Vi)
{   int Vf;
    printf("Digite o valor final (Vf): ");
    scanf("%d", &Vf);
    fflush(stdin);
    
    while(Vf <= Vi)
    {   printf("\nO valor final tem que ser maior do que o valor inicial!");
        printf("\nDigite novamente o valor final: ");
        scanf("%d", &Vf);
        fflush(stdin);
    }

    return Vf;
}

void remove(int Vi, int Vf)
{   int ant;
    for (int i = 0; i < MAX; i++)
    {   
        if(L[i].info == Vi)
        {   dispo = Vi;
            ant = i-1;
        }
        
        if(L[i].info == Vf)
        {   L[ant].prox = L[i].prox;
            L[i].prox = -1;
        }
    }
    system("cls");
    printf("\nNova lista com Vetores removidos:\n\n\n");
}

void libera(int i)
{   L[i].prox = dispo;
    dispo = i;
}

void exibir()
{   /*for(int i=0; i<MAX; i++)
        printf(" %d  ", L[i]);*/
        
    int aux = 0;
    do
    {   printf("%d ", L[aux].info);
        aux = L[aux].prox;
    }while (aux != -1);
}
