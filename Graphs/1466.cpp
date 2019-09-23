#include <bits/stdc++.h>
using namespace std ;
typedef struct no{
	int d ;
	struct no *l, *r ;
}no;

void insert(int x, no **arv){
	if( (*arv) ==  NULL)
	{
		(*arv) = (no *)malloc( sizeof(no) ) ;
		(*arv)->l = NULL ;
		(*arv)->r = NULL ;
		(*arv)->d = x ;
		return ;
	}
	if( x > (*arv)->d )
		insert( x, &(*arv)->r ) ;
	else
		insert( x, &(*arv)->l ) ;
}


typedef struct queu{
	 no *dado ;
	 struct queu *prox ;
}queu;
int qinit(queu **q){
	(*q) = NULL ;
}
void qpush(queu **q, no *valor){
	 if( (*q) == NULL )
	 {
	 	*q = (queu *)malloc(sizeof(queu)) ;
	 	if( !(*q) )
	 	{
		  return ;
	 	}
	 	(*q)->dado = valor ;
	 	(*q)->prox = NULL  ;
		return             ;
	 }
	 qpush( &(*q)->prox, valor ) ;
}
void qpop( queu **p ){
	if((*p) == NULL)
		return ;
	 queu *aux = ( *p ) ;
	 (*p) = (*p)->prox ;
	 free(aux) ;
}
no *front( queu **p ){
	 return (*p)->dado ;
}




main()
{
	int t ;
	cin >> t ;
	int ans = 1 ;
	while(t--)
	{
		int n ; cin >> n ;
		no *arv = NULL ;
		for (int i = 0; i < n; ++i)
		{
			int x ; cin >> x ;
			insert(x, &arv) ;
		}
		queu *q = NULL ;
		qpush( &q, arv ) ;
		cout << "Case " << ans++ << ":\n" ;
		bool sna = 0 ;
		while( q != NULL )
		{
			no *aux = front( &q ) ;
			qpop( &q) ;
			if(sna)
				cout << ' ' ;
			sna = 1 ;
			cout << aux->d ;
			if( aux->l  != NULL )
				qpush( &q, aux->l ) ;
			if( aux->r  != NULL )
				qpush( &q, aux->r ) ;
		}
		cout << "\n\n" ;
	}
}