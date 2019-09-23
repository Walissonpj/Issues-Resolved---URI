#include <bits/stdc++.h>
using namespace std ;
main()
{
	double L ;
	while( cin >> L && L != 0)
	{
		double x = (L - 3.0  ) / L ;
		cout << fixed << setprecision(6) << x << endl ;  
	}
}