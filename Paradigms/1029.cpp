#include <bits/stdc++.h>
using namespace std ;
long long v[41], cal[41] ;
void fib()
{
	v[0] = 0 ;
	v[1] = 1 ;
	for( int i = 2 ; i <= 40 ; i++ )
	{
		v[i] = v[ i-1 ] + v[ i-2 ] ;
		//cout << v[i] << " -> "  << i << endl ;
	}
	cal[0] = cal[1] = 0 ;
	for( int i = 2 ; i <= 40 ; i++ )
	{
		cal[i] = cal[i-1] + cal[i - 2] + 1 ;
	}
}
main()
{
	int t ;
	cin >> t ;
	fib() ;
	while(t--)
	{
		int a ;
		cin >> a ;
		cout << "fib(" << a << ") = " << 2 * cal[a] << " calls = " << v[a] << '\n' ;
	}
}