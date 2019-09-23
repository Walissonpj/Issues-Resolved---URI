#include<bits/stdc++.h>
using namespace std ;
int main()
{
	 int t, ans = 1 ;
	 cin >> t ;
	 while(t--)
	 {
		  int n ;
		  cin >> n ;
		  int v[ n ] ;
		  for( int i = 0 ; i < n ; i++ )
				cin >> v[i] ;
		  sort( v, v + n ) ;
		  cout << "Case " << ans++ << ": " << v[ ( n / 2 ) ] << '\n' ;
	 }
	 return 0 ; 
}
