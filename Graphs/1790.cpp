#include<bits/stdc++.h>
using namespace std ;
int n, time_s, visit[ 1255 ], qt ;
vector< vector<int> > ADJ ;  
int dfs( int u, int pai )
{  
	int menor = visit[u] = time_s++ ;
	for( int i = 0 ; i < ADJ[u].size() ; i++ )
	{
		if( !visit[ ADJ[ u ][ i ] ] )
		{
			int m = dfs( ADJ[u][i], u ) ;
			menor = min( menor, m ) ;
			if( visit[ u ] < m )
			{
				qt++ ;
			}
		}
		else if( ADJ[u][i] != pai )
		{
			menor = min( menor, visit[ ADJ[u][i] ] ) ;
		}
	}
	return menor ;
}
int main()
{
	ios_base::sync_with_stdio( false ) ;
	 int v, e ;
	 while( cin >> v >> e )
	 {
	 	time_s = 1 ;
		ADJ = vector<vector<int > > (v) ;
		memset(visit, 0, sizeof( visit )) ;
	 	qt  = 0 ;
	 	for( int i = 0 ; i < e ; i++ )
	 	{
		 	int a, b ;
		 	cin >> a >> b ;
		 	ADJ[a-1].push_back(b-1) ;
		 	ADJ[b-1].push_back(a-1) ;
	 	}
	 	dfs( 0, 0 ) ;
	 	cout << qt << '\n' ;
	 }
	 return 0 ;
}
