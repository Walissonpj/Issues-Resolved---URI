#include<bits/stdc++.h>
#define VERTICES 60
using namespace std;
int pai[VERTICES]  ;  
int posto[VERTICES];

int getrep( int x ) 
{
	if ( pai[x] != x ) 
		pai[x] = getrep( pai[x] );
	return pai[x];
}

bool unio( int a, int b ) 
{
	a = getrep(a) ;
	b = getrep(b) ;
	if ( a == b ) 
		return false ;
	
	if ( posto[a] >= posto[b] ) 
	{
		pai[b] = a;
		if (posto[a] == posto[b]) posto[a]++;
	}
	else pai[a] = b ;
	return true ;
}

pair< int, pair<int, int> > arestas[210] ;
int m ;
int  kruskal() 
{
	int r = 0 ;
	sort(arestas, arestas + m);
	for ( int i = 0 ; i < m; i++ ) 
	{
		if ( unio( arestas[i].second.first, arestas[i].second.second ) ) 
			r += arestas[i].first ;
	}
	return r;
}
int main()
{
	int v  ;
	cin >> v >> m ;
	memset(posto, 0, sizeof(posto)) ;
	for(int i = 0 ; i < m ; i++)
	{
		int a, b, c ;
		pai[i] = i ;
		cin >> a >> b >> c ;
		arestas[i].first = c ;
		arestas[i].second.first = a  ;
		arestas[i].second.second = b ;
	}
	cout << kruskal() << '\n' ;
}