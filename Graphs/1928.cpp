#include <bits/stdc++.h>
using namespace std ;
int nivel[ 50005 ], pai[50005] ;
int ancestral[ 50005 ][ 17 ] ;
vector< vector<int> > v ;
vector< pair<int, int> > pos( 25005 ) ;
void dfs( int u )
{
	for( int i = 0 ; i < v[u].size() ; i++ )
	{
		if( !nivel[ v[u][i] ] )
		{
			nivel[ v[u][i] ]  = nivel[u] + 1 ;
			pai[ v[u][i] ] = u ;
			dfs( v[u][i] ) ;
		}
	}
}

int lca(int a, int b)
{
	if(nivel[a] < nivel[b])
		swap( a, b ) ;
	for(int i = 16 ; i >= 0 ; i--)
		if( nivel[a] - (1 << i) >= nivel[b] )
			a = ancestral[a][i] ;
	if( a == b )
		return b ;
	for ( int i = 16 ; i >= 0 ; i-- )
	{
		if( ancestral[a][i] != -1 && ancestral[a][i] != ancestral[b][i] )
			a = ancestral[a][i], b = ancestral[b][i] ;
	}
	return ancestral[a][0] ;
}


main()
{
	int n ;
	cin >> n ;
	memset( ancestral, -1, sizeof( ancestral ) ) ;
	v = vector< vector<int> > ( n + 1 ) ;
	for ( int i = 1 ; i <= n ; ++i )
	{
		int x ;
		cin >> x ;
		if( !pos[x].first )
			pos[x].first = i ;
		else
			pos[x].second = i ;
	}
	for ( int i = 1; i < n ; ++i )
	{
		int a, b ;
		cin >> a >> b ;
		v[ a ].push_back( b ) ;
		v[ b ].push_back( a ) ;
	}
	nivel[ 1 ] = 1 ;
	pai[ 1 ] = 0 ;
	dfs( 1 )     ;
	for (int i = 1 ; i <= n ; ++i)
		ancestral[i][0] = pai[i] ;

	for (int j = 1 ; j < 17 ; j++)
		for (int i = 1 ; i <= n ; ++i)
			if( ancestral[i][j-1] != -1 )
				ancestral[i][j] = ancestral[ancestral[i][j-1]][j-1] ;
	int sum = 0 ;
	for (int i = 1; i <= n / 2 ; ++i)
	{
		int a = pos[i].first, b = pos[i].second ;
		int ans = lca( a, b ) ;
		sum += abs( nivel[a] - nivel[ans]) + abs( nivel[b] - nivel[ans] ) ;
	}
	cout << sum << endl ;
}