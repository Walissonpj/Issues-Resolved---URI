#include <bits/stdc++.h>
using namespace std ;
int dp[101][601] ;
int n ;
vector< pair<int, int> > v ;
int solve( int at, int w)
{
	if( at == n )
		return 0 ;
	if( dp[at][w] != -1 )
		return dp[at][w] ;
	for(int i = 0 ; i * v[at].first <= w ; i++)
	{
		dp[at][w] = max( dp[at][w], solve( at + 1, w - (v[at].first * i) ) + (v[at].second * i) ) ;
	}
	return dp[at][w] ;
}
main()
{
	int t ;
	int cont = 1 ;
	while( cin >> n >> t && (n || t) )
	{
		memset( dp, -1, sizeof(dp) ) ;
		v = vector< pair<int, int> > (n) ;
		for ( int i = 0; i < n; ++i )
		{
			cin >> v[i].first >> v[i].second ;
		}
		cout << "Instancia " << cont++ << '\n' ;
		cout << solve( 0, t ) << "\n\n" ;
	}
}