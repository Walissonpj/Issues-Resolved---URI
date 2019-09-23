#include <bits/stdc++.h>
using namespace std ;
vector<int> posto, pai ;
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
main()
{
	int t ;
	cin >> t ;
	while(t--)
	{
		int n ; cin >> n ;
		posto = vector<int> ( n, 0 ) ;
		pai = vector<int> ( n ) ;
		vector<pair< int, int> > v(n) ;
		for ( int i = 0; i < n ; i++ )
			pai[i] = i ;
		for (int i = 0; i < n; ++i)
		{
			cin >> v[i].first >> v[i].second ;
		}
		int maos = (n*n) - n ;
		pair< int , pair<int, int> > ans[ maos ] ;
		int x = 0 ;
		for ( int i = 0; i < n; ++i )
		{
			for (int j = i + 1; j < n ; ++j )
			{
				ans[x].first = ( v[i].first - v[j].first)*(v[i].first - v[j].first) + ( v[i].second - v[j].second)*(v[i].second - v[j].second) ;
				ans[x].second.first = i ;
				ans[x].second.second = j ; 
				x++ ;
			}
		}
		sort( ans, ans + maos ) ;
		double tot = 0.0 ;
		for(int i = 0 ; i < maos ; i++)
		{
			if( unio(ans[i].second.first, ans[i].second.second) )
				tot += sqrt( ans[i].first )/100 ;
		}
		cout << fixed << setprecision(2) << tot << '\n' ;
	}
}