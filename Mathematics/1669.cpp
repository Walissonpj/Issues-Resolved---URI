#include<bits/stdc++.h>
using namespace std ;
int main()
{
	 int t ;
	 cin >> t ;
	 while(t--)
	 {
		  	unsigned long long ans ;
			cin >> ans ;
		  	ans = ( 1LL << ans )- 1 ;
		  	ans = (ans - 1) / 12000LL ;
		  	cout <<  ans << " kg\n" ; 
	 }
	 return 0 ;
}
