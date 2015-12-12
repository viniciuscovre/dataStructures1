#include <stdio.h>
#include <conio.h>
#define MAX 100

//o programa tem que digitar até receber o caractere '$'

char receber() 
{
    char r;
    scanf("%c", &r);
    
    return r;
}

void push(char pilha[], int *topo, char x) 
{
    if (*topo == MAX - 1) 
    {
        printf("Overflow");
        return;  
    } 
    else 
    {
        (*topo)++;
        pilha[*topo] = x;
    }
}

void pop(char pilha[], int *topo, char x) 
{
    if ((*topo) == -1) 
    {
        printf("Underflow");
        return;    
    } 
    
    else if (x == pilha[*topo]) 
    {
        (*topo)--;
    }
}

int main() {
    char pilha[MAX];
    int topo = -1;
    int C = 0;
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
    {
        printf("Certo");  
    } 
    else 
    {
        printf("Errado");
    }

    getch();
    return 0;
}
