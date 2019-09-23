#include<bits/stdc++.h>
using namespace std ;
int main()
{
	 double l ;
	 while( cin >> l )
	 {
		 double result = (8.0/5.0) * ((l * l  * sqrt(3)) / 4) ; 
		  cout << fixed << setprecision(2) << result << "\n";
	 }
	 return 0 ;
}
