#include<bits/stdc++.h>
#define int long long
using namespace std ; 

main()
{
	double a1, a2, at, d ;
	while( cin >> a1 >> a2 >> at >> d )
	{
		if( a1 == 0 && a2 == 0 && at == 0 && d == 0)
			break ;
		a1 = ceil( a1 / d) ;
		a2 = ceil( a2 / d) ;
		double a = a1 + a2 ;
		double p  = at / 6.0 ;
		double q = 1.0 - p ;
		if(at == 3.0)
		{
			cout << fixed << setprecision(1) << ( 1.0 - a2 / a ) * 100.0 << '\n' ;
		}
		else
		{
			cout << fixed << setprecision(1) << 100.0 * (( 1 - pow( (q / p), a1)) / (1 - pow( (q / p), a))) << '\n' ;
		}
	}
	return 0 ;
}