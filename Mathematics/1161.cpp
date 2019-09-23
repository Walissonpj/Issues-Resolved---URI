#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std ;
 ull fat(int a)
{
	 ull  cont = 1 ;
	 for(int i = 1 ; i <= a ; i++ )
		  cont *= i ;
		return cont ;
}
int main()
{
	 int a, b ;
	 while(cin >> a >> b)
	 {
		  cout << fat(a) + fat(b) << '\n' ;
	 }
	 return 0 ;
}
