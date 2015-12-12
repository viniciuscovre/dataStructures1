#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int pilha[MAX];
int topo1 = 0;
int topo2 = 99;

void menu();
char verifica_vazia(); //1
char verifica_cheia(); //2
void push(int x); //3
void pop(); //4

int main()
{   menu();

    printf("\n\n");
    system("pause");
    return 0;
}

void menu()
{   int opt;
    int x;
    printf("\n1. Verifica se vazia");
    printf("\n2. Verifica se cheia");
    printf("\n3. PUSH");
    printf("\n4. POP");
    printf("\n5. Imprimir");
    printf("\n6. Sair");
    printf("\n\n OPCAO: ");
    scanf("%d", &opt);
    fflush(stdin);
    switch(opt)
    {   case 1: if (verifica_vazia() == 'v')
                {
                    printf("\n\nPILHA Vazia!");
                    getch();
                }
                else
                {
                    printf("\n\nPILHA NAO Vazia!");
                    getch();
                }
                system("cls");
                menu();
        case 2: if (verifica_cheia() == 'v')
                {
                    printf("\n\nPILHA cheia!");
                    getch();
                }
                else
                {
                    printf("\n\nPILHA NAO cheia!");
                    getch();
                }
                system("cls");
                menu();
        case 3: if (verifica_cheia() == 'v')
                {   printf("Lista Cheia! impossivel inserir!");
                    getch();
                    system("cls");
                    menu();
                }
                printf("\n\n Digite um valor para inserir: ");
                scanf("%d", &x);
                fflush(stdin);
                push(x);
                getch();
                system("cls");
                menu();
        case 4: pop();
                menu();
        case 5: for (int i=0; i<MAX; i++)
                   printf(" %d ", pilha[i]);
                getch();
                system("cls");
                menu();
        case 6: break;
    }
}

char verifica_vazia()
{   if(topo1 == 0 && topo2 == 99)
        return 'v';
    else
        return 'f';
}

char verifica_cheia()
{   if (topo2-topo1 == 1)
        return 'v';
    else
        return 'f';
}

void push(int x)
{   pilha[topo1] = x;
    topo1++;
    pilha[topo2] = x;
    topo2++;
}

void pop()
{   topo1--;
    topo2--;
}
