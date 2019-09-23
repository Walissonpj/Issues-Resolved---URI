#include <bits/stdc++.h>
using namespace std ;
vector<int> v ;
int a, b ;
long long dp[10005][105], us[10005][105], vis ;
long long solve( int at, int cont )
{
	if( at == a && cont )
		return 0LL ;
	if( at == a && !cont )
		return 1LL ;
	if( !cont )
		return 1LL ;
	long long &ans = dp[at][cont] ;
	long long &u = us[at][cont] ;
	if( u == vis )
		return ans ;
	u = vis ;
	ans = 0LL ;
	for( int i = at + 1 ;  i < a ; i++ )
	{
		if( v[ at ] < v[ i ] )
			ans += solve( i, cont - 1 ) ;
	}
	return ans ;
}
main()
{
	vis = 1LL ;
	while( cin >> a >> b && ( a || b ) )
	{
		v = vector<int> ( a ) ;
		for ( int i = 0 ; i < a ; ++i )
		{
			cin >> v[i] ;
		}
		long long ans = 0;
		for( int i = 0; i < a; i++ ){
	    	ans += solve( i, b-1 );
		}
		cout << ans << '\n';
		vis++ ;
	}
}