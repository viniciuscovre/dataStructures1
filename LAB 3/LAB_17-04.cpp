/*Construir uma função em C que recebe como parâmetro duas filas não vazias (Fila1 e Fila2) 
contendo números inteiros ordenados (com no máximo 20 elementos), e monta uma terceira 
fila (Fila3), circular, com os elementos de Fila1 e Fila2. Fila3 deverá ter seus elementos
 inseridos de forma ordenada. Não utilizar estrutura auxiliar.
Obs.: para resolver será necessário criar programas que inicializem adequadamente as estruturas utilizadas.*/
#include <stdio.h>
#include <conio.h>
#define TAM 20
#define VN 9999

void inserirfc(int filac[], int* fim, int inicio, int max, int x);
int eliminarfc(int filac[], int* inicio, int fim);
void inicializarLista(int filac[], int* fim, int inicio, int v);
void unir(int f1[], int f1fim, int* f1inicio, int f2[], int f2fim, int* f2inicio, int f3[], int* f3fim, int f3inicio);

int main() 
{
    int f1[TAM + 1], f2[TAM + 1], f3[TAM*2 + 1];
    int f1inicio = 0, f1fim = 0;
    int f2inicio = 0, f2fim = 0;
    int f3inicio = 0, f3fim = 0;
    //inicializacao adequada
    inicializarLista(f1, &f1fim, f1inicio, 1); //inicia a f1 com elementos impares
    printf("\n");
    inicializarLista(f2, &f2fim, f2inicio, 2); //inicia a f2 com elementos pares
	printf("\n");
	
    unir(f1, f1fim, &f1inicio, f2, f2fim, &f2inicio, f3, &f3fim, f3inicio);

    getch();
}

void inicializarLista(int filac[], int* fim, int inicio, int v)
{
    for (int i = v; i <= TAM; i = i + 2) 
        inserirfc(filac, fim, inicio, TAM, i);
}

void inserirfc(int filac[], int* fim, int inicio, int max, int x) 
{
    if ((*fim + 1) % max == inicio) 
	{
        printf("%d erro", *fim);
        printf("overflow");
    }
        
    else 
	{
        printf("%d ", x);
        *fim = (*fim + 1) % TAM;
        filac[*fim] = x;
    }
}

int eliminarfc(int filac[], int* inicio, int fim) 
{
    int v;
    if (*inicio == fim)
        return VN;
        
    else {
        *inicio = (*inicio + 1) % TAM;
        v = filac[*inicio];
        return v;
    }
}

void unir(int f1[], int f1fim, int* f1inicio, int f2[], int f2fim, int* f2inicio, int f3[], int* f3fim, int f3inicio) 
{
    int ef1 = VN;
    int ef2 = VN;
    
    ef1 = eliminarfc(f1, f1inicio, f1fim); //ef1 = 1
    ef2 = eliminarfc(f2, f2inicio, f2fim); //ef2 = 2

    do 
	{
        if (ef1 < ef2) 
		{
            inserirfc(f3, f3fim, f3inicio, TAM*2, ef1);//insere em f3 o elemento atual de ef1
            ef1 = eliminarfc(f1, f1inicio, f1fim);//elimina o elemento de f1 para ser comparado posteriormente
        } 
		else 
		{
            inserirfc(f3, f3fim, f3inicio, TAM*2, ef2);//insere em f3 o elemento atual de f2
            ef2 = eliminarfc(f2, f2inicio, f2fim);//elimina o elemento de f2 para ser comparado posteriormente
        }
        
    } while (ef1 != VN || ef2 != VN);
        
}
