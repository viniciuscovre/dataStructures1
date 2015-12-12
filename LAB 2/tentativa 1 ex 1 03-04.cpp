#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

void push(char *pilha, int *topo, char x);
void pop(char *pilha, int *topo, char x);
char receber();

//o programa tem que digitar até receber o caractere '$'

int main()
{   char pilha[MAX];
    int topo = -1, C = 0;
    char x;

    while (x != '$') 
    {
        x = receber();
        
        if (x == 'C') 
        {
            C = 1;
            continue;
        }
        
        switch (C) 
        {
            case 0:
                push(pilha, &topo, x);
                break;
                
            case 1:
                pop(pilha, &topo, x);
                break;
        }
    }

    if (topo == -1) 
        printf("Certo");
    else
        printf("Errado");
        
    printf("\n\n");
    system("pause");
    return 0;
}

void push(char pilha[], int *topo, char x)
{   if (*topo == MAX - 1) 
    {
        printf("Overflow");
        return;
    }
    
    (*topo)++;
    pilha[*topo] = x;
}

void pop(char *pilha, int *topo, char x)
{   
    if ((*topo) == -1)
    {
        printf("Underflow");
        return;
    }
    else if (x == pilha[*topo])
        (*topo)--;
}

char receber() 
{
    char r;
    scanf("%c", &r);
    
    return r;
}
