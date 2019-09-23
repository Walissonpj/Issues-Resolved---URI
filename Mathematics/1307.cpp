#include <bits/stdc++.h>
using namespace std ;
main()
{
	int n ;
	cin >> n ;
	string a, b ;
	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b ;
		int x , y ;
		x = 0, y = 0 ;
		for(int j = a.size() - 1, cont = 0; j >= 0 ; j--, cont++)
			if(a[j] == '1')
				x += 1 << cont ;
		for(int j = b.size() - 1, cont = 0; j >= 0 ; j--, cont++)
			if(b[j] == '1')
				y += 1 << cont ;
		cout << "Pair #" << i + 1 << ": " ;
		int len = __gcd( x, y) ; 
		if( len > 1 )
			cout <<  "All you need is love!\n";
		else 
			cout << "Love is not all you need!\n" ;
	}
}