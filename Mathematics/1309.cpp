#include<bits/stdc++.h>
using namespace std ;
main()
{
	string s ;
	while(cin >> s)
	{
		string c, ans = "" ;
		cin >> c ;
		if(c.size() == 1)
			c = "0" + c ;
		int len = s.size() ;
		cout << '$' ;
		for(int i = len -1, cont = 0 ; i >= 0 ; i--, cont++)
		{
			if(cont == 3)
				ans += ',', cont = 0 ;
			ans += s[i] ;
		}
		reverse(ans.begin(), ans.end()) ;
		cout << ans;
		cout << '.'<< c << '\n';
	}
}
