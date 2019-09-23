#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

typedef struct No{
	int dado;
	struct No *es;
	struct No *di;
}No;


void insereNo(No **leaf, int d)
{
	if((*leaf) == NULL) 
	{
		(*leaf) = (No *) malloc(sizeof(No));
		if((*leaf) == NULL) 
		{
			puts("Erro na alocacao");
		}
		else
		{
			(*leaf)->di = NULL;
			(*leaf)->es = NULL;
			(*leaf)->dado = d ;
			return;
		}
	}

	if ( d < (*leaf)->dado )
	{
		insereNo(&(*leaf)->es, d);
		return;
	}
	insereNo(&(*leaf)->di, d);
}





void pesquisaPosOrdem(No *raiz)
{
    if(raiz == NULL)
        return;
    pesquisaPosOrdem(raiz->es);
    pesquisaPosOrdem(raiz->di);
    printf(" %d",raiz->dado);
}
 
void pesquisaPreOrdem(No *raiz)
{
    if(raiz == NULL)
        return;
    printf(" %d",raiz->dado);
    pesquisaPreOrdem(raiz->es);
    pesquisaPreOrdem(raiz->di);
}
void pesquisainordem(No *raiz)
{
  if(raiz == NULL)
    return;
    pesquisainordem(raiz->es);
    printf(" %d",raiz->dado);
    pesquisainordem(raiz->di);
}
int main()
{
	
	int n , cont = 1;
	scanf("%d", &n);
	bool flag = true ;
	while(n--)
	{
	  flag = false ;
	  int y;
	  scanf("%d", &y) ;
	  int i = 0 ;
	  No *raiz ;
	  raiz = NULL;
	  for( ; i < y ; i++)
	  {
	    int x ;
	    scanf("%d", &x);
	    insereNo(&raiz, x);
	  }
	  printf("Case %d:\n", cont);
	  printf("Pre.:");
	  pesquisaPreOrdem(raiz);
	  printf("\n");
	  printf("In..:");
	  pesquisainordem(raiz);
	  printf("\n");
	  printf("Post:");
	  pesquisaPosOrdem(raiz);
	  printf("\n\n");
	  cont++;
	  free(raiz);
	}
	return 0 ;
}
