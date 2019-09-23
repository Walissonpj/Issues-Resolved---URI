#include<bits/stdc++.h>
#define ull unsigned long long 
using namespace std ;
int main()
{
	 ios::sync_with_stdio (false);
	 int n ;
	 scanf("%d", &n ) ;
	 while(n--)
	 {
	 	ull a, b, k ;
		scanf( "%llu%llu", &a, &b) ;
	 	k = a / b ;
	 	if( !k )
	 	{
		 	 printf( "2\n") ;
		  	 continue ;
	 	}
			 printf("%llu\n", (( (a % b)  && k > 0)? k + 1: k) ) ;
	 }
	 return 0 ;
}
