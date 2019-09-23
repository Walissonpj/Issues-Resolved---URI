#include<bits/stdc++.h>
using namespace std ;
main()
{
	int t ;
	while(cin >> t && t)
	{
		int sum = 0 ;
		for(int i = 0 ; i <= t  ; i++)
			sum += i*i ;
		cout << sum << '\n' ;
	}
}
