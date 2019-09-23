#include<bits/stdc++.h>
using namespace std ;

main()
{
	int t ;
	cin >> t ;
	while(t--)
	{
		int n ;
		cin >> n ;
		int x, y, a, b, m, pos = 1 ;
		cin >>  x >> y >> a >> b ;
		m = (x-a)*(x-a) + (y-b) * (y-b) ;
		for(int i = 1 ; i< n ; i++)
		{
			cin >> a >> b ;
			int ans = (x-a)*(x-a) + (y-b) * (y-b) ;
			if( m > ans)
			{
				m = ans ;
				pos = i + 1 ;
			}
		}
		cout << pos << '\n' ;
	}
}
