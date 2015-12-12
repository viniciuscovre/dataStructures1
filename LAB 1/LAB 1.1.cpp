#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct
{	int info, prox;
}LISTA;

LISTA L[MAX];
int dispo;

void inicializa();
void imprimir();
int lerVi();
int lerVf(int Vi);
void nova_lista(int Vi, int Vf);

int main()
{	inicializa();
	imprimir();
	int Vi = lerVi();
	int Vf = lerVf(Vi);
	nova_lista(Vi, Vf);
	printf("\n\n");
	system("pause");
	return 0;
}

void inicializa()
{	for(int i=0; i<MAX; i++) //vai de 0 até 8(<MAX) mas o ultimo elemento tem q apontar para -1
	{	L[i].info = i+1; //preenche o vetor com inteiros 1, 2, ..., 10
		L[i].prox = i+1;
	}
	L[MAX-1].prox = -1; //atualiza o ultimo elemnto que apontava para 10, para apontar para -1

	printf("\n LISTA INICIAL:\n\n");
}

void imprimir()
{	int aux = 0;
    do
    {   printf("%d ", L[aux].info);
        aux = L[aux].prox;
    }while (aux != -1);
}

int lerVi()
{	int Vi;
	printf("\n\n    Digite o Valor Inicial (Vi): ");
	scanf("%d", &Vi);
	fflush(stdin);
	return Vi;
}

int lerVf(int Vi)
{	int Vf;
	printf("\n    Digite o Valor Final (Vf): ");
	scanf("%d", &Vf);
	fflush(stdin);
	while (Vf <= Vi)
	{	printf("\n Valor Final Invalido! Digite novamente: ");
		scanf("%d", &Vi);
		fflush(stdin);
	}
	return Vf;
}

void nova_lista(int Vi, int Vf)
{	int ant;
	for(int i=0; i<MAX-1; i++)
	{	if(L[i].info == Vi)
		{	dispo = i;
			ant = i-1;
		}
		
		if(L[i].info == Vf)
		{	L[ant].prox = L[i].prox;
			L[i].prox = -1;
		}
		
	}
	printf("\n\n\n NOVA LISTA:\n\n");
	imprimir();
}
