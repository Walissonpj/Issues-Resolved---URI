#include <bits/stdc++.h>
using namespace std ;
main()
{
	int r, l, h, cont = 1;
	while( cin >> r && r)
	{
		cin >> l >> h ;
		cout << "Pizza " << cont++ ;
		double a = sqrt( l*l + h*h ) ;
		double ans = r * 2.0 ;
		if( a - ans <= 0.0 )
			cout << " fits on the table.\n" ;
		else
			cout << " does not fit on the table.\n" ;
	}
}