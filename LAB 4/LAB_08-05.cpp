#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
const int TAM = 10;

struct NO
{	
	int info;
	struct NO *esq, *dir;
};
typedef struct NO NO;

void insere(NO **atual, int elem);
void imprimir(NO *r, int c);
void conta_nos(NO *raiz, int *cont);
int soma_info(NO *raiz, int *soma);
void menor_valor(NO *raiz, int *menor);
void antecessor(NO **aux, NO **atual);
void retira(NO **atual, int menor);
void limpar(NO **raiz);

int main()
{	
	printf("********** ARVORES **********\n\n\n");
	NO *raiz = NULL, *dado;
	unsigned int info;
	int cont = 1, soma = 0, menor = 1000;
	printf("Insira ao menos 10 numeros (0 para sair)\n\n");
	do
	{	printf("Digite um numero: ");
		scanf("%d", &info);
		fflush(stdin);
		if (info)
		{
			insere(&raiz, info);
			cont ++;
		}
	}while(info || cont <= 10); //para quando cont >10 e o usuario digitar 0
	imprimir(raiz,0);
	
	cont = 0;
	conta_nos(raiz, &cont);
	soma_info(raiz, &soma);
	printf("\n\nTotal de nos: %d", cont);
	printf("\nSoma dos nos: %d", soma);
	getch();
	system("cls");
	
	menor_valor(raiz, &menor);
	retira(&raiz, menor);
	printf("\n\nMenor valor retirado!\n\n");
	imprimir(raiz, 0);
	
	limpar(&raiz);
	printf("\n\nLimpando a arvore...");
	getch();
	printf("\n\nArvore removida com sucesso!");
	printf("\n\n");
	system("pause");
	return 0;
}

void insere(NO **atual, int elem)
{
	if(*atual == NULL) //para a raiz
	{	*atual = (NO *) malloc(sizeof(NO));
		if(!(*atual)) //se nao for possivel alocar memoria para "atual"
		{	printf("Sem memória! Saindo...");
			getch();
			exit(0);
		}
		else
		{	
			(*atual)->info = elem;
			(*atual)->esq = NULL;
			(*atual)->dir = NULL;
			return;
		}
	}
	else //escolhe a subarvore
	{	if(elem < (*atual)->info)
			insere(&(*atual)->esq, elem);
		else
			insere(&(*atual)->dir, elem);
	}
}

void imprimir(NO *r, int c)
{
	int i;
	if(!r) //se nao tem raiz (se a arvore esta vazia)
		return;
	imprimir(r->dir, c+1);
	for(i=0; i<c; ++i)
		printf(" ");
	printf(" %d \n\n", r->info);
	imprimir(r->esq, c+1);
}

void conta_nos(NO *raiz, int *cont)
{
	if(raiz) //if raiz != 0 
	{	(*cont)++;
	  	conta_nos(raiz->esq, &(*cont));
	  	conta_nos(raiz->dir, &(*cont));	
	}
	else
		return;
}

int soma_info(NO *raiz, int *soma)
{
	if(raiz)
	{
	  	(*soma) = (*soma) + raiz->info;
	  	soma_info(raiz->esq, &(*soma));
	  	soma_info(raiz->dir, &(*soma));
	}
}
void menor_valor(NO *raiz, int *menor)
{
	if(raiz)
	{
	  if(raiz->info < (*menor))
	    (*menor) = raiz->info;
	  menor_valor(raiz->esq, &(*menor));
	  menor_valor(raiz->dir, &(*menor));
	}
	else
		return;
}

void antecessor(NO **aux, NO **atual)
{
	if((*atual)->dir)
	  	antecessor(aux, &(*atual)->dir);
	else
	{
	  	(*aux)->info = (*atual)->info;
	  	*aux = *atual;
	  	*atual = (*atual)->esq;
	}
}

void retira(NO **atual, int menor)
{
	NO *aux;
	if(menor < (*atual)->info)
		retira(&(*atual)->esq, menor);
		else if(menor > (*atual)->info)
			retira(&(*atual)->dir, menor);
	else
	{
	  	aux = *atual;
	  	if((*atual)->dir == NULL)
	  	  	*atual = aux->esq;
	  		else if((*atual)->esq == NULL)
		    	*atual = aux->dir;
		else
			antecessor(&aux, &(*atual)->esq);
			free(aux);  
	}
}

void limpar(NO **raiz)	
{
	if(*raiz)
	{
		limpar(&(*raiz)->esq);
		limpar(&(*raiz)->dir);
		free(*raiz);
	}
}
