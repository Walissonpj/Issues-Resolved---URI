#include <bits/stdc++.h>
using namespace std ;
main()
{
	int  t ; cin >> t ;
	map< char, map<char, int> > m ;
	m['R']['G'] = 2 ;
	m['R']['B'] = 1 ;
	m['G']['B'] = 2 ;
	m['G']['R'] = 1 ;
	m['B']['R'] = 2 ;
	m['B']['G'] = 1 ;
	map< char, int> x ;
	while( t-- )
	{
		int n ;
		x['G'] = x['B'] = x['R'] = 0 ;
		cin >> n ;
		while( n-- )
		{
			char a, b ;
			cin >> a >> b ;
			x[a] += m[a][b] ;
		}
		if( x['G'] == x['B'] && x['B'] == x['R'] )
		{
			cout << "trempate\n" ;
		}
		else if( x['G'] > x['R'] && x['G'] > x['B'] )
		{
			cout << "green\n" ;
		}
		else if( x['R'] > x['G'] && x['R'] > x['B'] )
		{
			cout << "red\n" ;
		}
		else if( x['B'] > x['G'] && x['B'] > x['R'] )
		{
			cout << "blue\n" ;
		}
		else
			cout <<"empate\n"  ;
	}
}