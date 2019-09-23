#include<bits/stdc++.h>
using namespace std ;
int main()
{
	 int t ;
	 cin >> t ;
	 while(t--)
	 {
		  double a ;
		  cin >> a ;
		  int cont = 0 ;
		  while( a > 1.0 )
		  {
				a /= 2.0 ;
				cont++ ;
		  }
		  cout << cont << " dias\n";
	 }
	 return 0 ;
}