//wCw', na qual w contém a sequência de a's e b's, ou w é vazia, e w' é o reverso de w
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int tam = 255;

int bemFormada(char s[]);
int pop(char p[], int *topo, char cmp);
void push(char p[], int *topo, char aux);

int main()
{	char s[255];
	printf("Digite uma sequencia do tipo wCw': ");
	gets(s);
	fflush(stdin);
	
	if (bemFormada(s) == 1)
		printf("\n\nSequencia correta, bem formada!\n\n");
	else
		printf("\n\nSequencia incorreta, mal formada!\n\n");
	
	system("pause");
	return 0;
}

int bemFormada(char s[])
{	char *pilha; 
	int topo = -1;
   	pilha = (char*)malloc(tam * sizeof (char));
   	int ret;
   	
   	int i = 0;
	while(1) //empilhamos tudo o que vem antes do C
	{	if(s[i]=='c' || s[i]=='C')
		{	i++;
			break;
		}
		
		else if(s[i] == 'a' || s[i] == 'b')
			push(pilha, &topo, s[i]);
			
			else //se ele digitar algo diferente de a, b ou c
				return 0;
			
		i++;
	}
	
	for(i; i<strlen(s); i++) //vamos trabalhar com a outra metade, apos o C
	{	switch(s[i])
		{	
			case 'a':	ret = pop(pilha, &topo, 'a');
						if (!ret) //if ret == 0
							return ret;
						break;
						
			case 'b':	ret = pop(pilha, &topo, 'b');
						if (!ret)
							return ret;
						break;
						
			default: return 0; //se ele digitar algo diferente de a ou b, depois do C
		}
	}
	return (topo == -1);
}

void push(char p[], int *topo, char aux)
{	(*topo)++;
    p[*topo] = aux;
}

int pop(char p[], int *topo, char cmp)
{	if (*topo == -1)
    	return 0;

    else if(p[*topo] == cmp)
	{	(*topo)--;
        return 1;
	}
	
	else
		return 0;
}
