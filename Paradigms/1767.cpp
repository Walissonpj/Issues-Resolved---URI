#include <bits/stdc++.h>
using namespace std ;
int dp[103][53] ;
int n ;
vector< pair<int, int> > v ;
int solve( int at, int w )
{
	if( at == n )
	{
		return  0 ;
	}
	int &ans = dp[ at ][ w ] ;
	if( ans != -1 )
	{
		return ans ;
	}
	if( v[at].second <= w )
	{
		ans = solve( at + 1, w ) ;
		ans = max( ans, solve( at + 1, w - v[at].second ) + v[at].first ) ;
	}
	else
		ans = solve( at + 1, w ) ;
	return ans ;
}
int main()
{
	int t ;
	cin >> t ;
	while(t--)
	{
		memset( dp, -1, sizeof(dp) ) ;
		cin >> n ;
		v = vector<pair<int, int> > ( n ) ;
		for ( int i = 0 ; i < n ; ++i )
		{
			cin >> v[i].first >> v[i].second ;
		}
		int ans = solve( 0, 50 ) ;
		cout << ans << " brinquedos\n" ;
		int cont = 50, x = 1, flag = 0 ;
		for ( int i = 0 ; i < n ; i++ )
		{
			if( dp[i + 1][cont] != dp[i][cont]  && cont >= v[i].second )
				cont -= v[i].second, flag = 1 ;
			else
				x++ ;
		}
		cout << "Peso: " << 50 - cont << " kg\n" ;
		if( !flag )
		{
			cout << "sobra(m) " << n << " pacote(s)\n\n" ;
		}
		else
			cout << "sobra(m) " << x - 1 << " pacote(s)\n\n" ;
	}
	return 0;
}
