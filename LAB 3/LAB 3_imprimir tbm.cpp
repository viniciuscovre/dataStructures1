/*Construir uma função em C que recebe como parâmetro duas filas não vazias (Fila1 e Fila2) contendo números 
inteiros ordenados (com no máximo 20 elementos), e monta uma terceira fila (Fila3), dinamica, com os elementos 
de Fila1 e Fila2. Fila3 deverá ter seus elementos inseridos de forma ordenada. Não utilizar estrutura auxiliar.
Obs.: para resolver será necessário criar programas que inicializem adequadamente as estruturas utilizadas.*/
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 20

struct FILA
{
	int info;
	struct FILA *prox;
};
typedef struct FILA FILA;

void inicializa(FILA **fila1, FILA **inicio1, FILA **fim1, FILA **fila2, FILA **inicio2, FILA **fim2);
void inserir(FILA **fila, FILA **inicio, FILA **fim, int item);
int remover(FILA **fila, FILA **inicio, FILA **fim);
void unir(FILA **fila1, FILA **inicio1, FILA **fim1, FILA **fila2, FILA **inicio2, FILA **fim2, FILA **fila3, FILA **inicio3, FILA **fim3);
void exibir(FILA **fila, FILA **inicio, FILA **fim);

int main()
{
	FILA *fila1, *inicio1 = NULL, *fim1 = NULL;
	FILA *fila2, *inicio2 = NULL, *fim2 = NULL;
	inicializa(&fila1, &inicio1, &fim1, &fila2, &inicio2, &fim2);
	exibir(&fila1, &inicio1, &fim1);
	printf("\n\n");
	exibir(&fila2, &inicio2, &fim2);
	printf("\n\n");
	FILA *fila3, *inicio3 = NULL, *fim3 = NULL;
	unir(&fila1, &inicio1, &fim1, &fila2, &inicio2, &fim2, &fila3, &inicio3, &fim3);
	exibir(&fila3, &inicio3, &fim3);
	getch();
	return 0;
}

void inicializa(FILA **fila1, FILA **inicio1, FILA **fim1, FILA **fila2, FILA **inicio2, FILA **fim2)
{
	for (int i=1; i<=MAX; i=i+2)
	{
		inserir(fila1, inicio1, fim1, i);
		inserir(fila2, inicio2, fim2, i+1);
	}
}

void inserir(FILA **fila, FILA **inicio, FILA **fim, int item)
{
	FILA *aux = (FILA*) malloc (sizeof(FILA));
	aux->info = item;
	aux->prox = NULL;
	
	if((*fim) == NULL)
		*inicio = aux;
	else
		(*fim)->prox = aux;
	
	*fim = aux;
}

int remover(FILA **fila, FILA **inicio, FILA **fim)
{
	if ((*inicio) == NULL) //se a fila esta vazia
		return -999;
		
	int ret;
	FILA *aux = *inicio;
	
	ret = aux->info;
	(*inicio) = (*inicio)->prox;
	if ((*inicio) == NULL) //se removeu o ultimo no da fila
		*fim = NULL;
	free(aux);
	aux = *inicio;
	return ret;
}

void unir(FILA **fila1, FILA **inicio1, FILA **fim1, FILA **fila2, FILA **inicio2, FILA **fim2, FILA **fila3, FILA **inicio3, FILA **fim3)
{
	int v;
	for(int i=0; i<MAX/2; i++)
	{
		v = remover(fila1, inicio1, fim1);
		inserir(fila3, inicio3, fim3, v);
		//printf(" %d ", v);
		v = remover(fila2, inicio2, fim2);
		inserir(fila3, inicio3, fim3, v);
		//printf(" %d ", v);
	}
}

void exibir(FILA **fila, FILA **inicio, FILA **fim)
{
     FILA *fim_aux;
	 int v;
     fim_aux = *fim;
     while (1) 
	 {
		if ((*inicio)->info == fim_aux->info)
        	break;
        v = remover(fila, inicio, fim);
    	printf(" %d ", v);
        inserir(fila, inicio, fim, v);
     }
}
