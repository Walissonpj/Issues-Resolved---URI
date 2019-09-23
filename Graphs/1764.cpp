#include<bits/stdc++.h>
#define VERTICES 40001
using namespace std;
vector<int> posto, pai ;
vector<pair< int, pair<int, int> > >  arestas ;
int m ;
int find( int x ) 
{
	if ( pai[x] != x ) 
		pai[x] = find( pai[x] );
	return pai[x];
}

bool unio( int a, int b ) 
{
	a = find(a) ;
	b = find(b) ;
	if ( a == b ) 
		return false ;
	
	if ( posto[a] >= posto[b] ) 
	{
		pai[b] = a ;
		if (posto[a] == posto[b]) 
			posto[a]++ ;
	}
	else 
		pai[a] = b ;
	return true ;
}
int  kruskal() 
{
	int p = 0 ;
	sort( arestas.begin() , arestas.end() ) ;
	for ( int i = 0 ; i < m; i++ ) 
	{
		if ( unio( arestas[i].second.first, arestas[i].second.second ) ) 
			p += arestas[i].first ;
	}
	return p ;
}
int main()
{
	int v  ;
	while( cin >> v >> m, v != 0 && m != 0 )
	{
		posto = vector<int> (v, 0 ) ;
		pai = vector<int> (v) ;
		arestas = vector<pair< int, pair<int, int> > > (m) ;
		for ( int i = 0; i < v ; i++ )
			pai[i] = i ;
		for(int i = 0 ; i < m ; i++)
		{
			int a, b, c ;
			cin >> a >> b >> c ;
			arestas[i].first = c ;
			arestas[i].second.first = a  ;
			arestas[i].second.second = b ;
		}
		cout << kruskal() << '\n' ;
	}
}