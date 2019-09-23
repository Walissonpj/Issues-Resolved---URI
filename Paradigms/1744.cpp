#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std ;
int main()
{
	 ull a, b ;
	 cin >> a >> b ;
	 string  s ;
	 cin >> s ;
	 ull len = s.size(),  tam = 0, tot = 0 ;
	 for(int i = len - 1 ; i > tam ; i-- )
	 {
		  if( s[i] == 'B' )
		  {
				for( ;  i > tam && s[ tam ] == 'B' ; tam++ );
				if(i == tam)
					 break ;
				swap(s[i], s[tam]) ;
				ull x = ( i - tam ) * (a -b) ;
				tot += min( x, a ) ;
		  }
	 }
	 cout << tot << '\n' ;
	return 0 ;
}