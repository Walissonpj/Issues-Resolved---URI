#include<bits/stdc++.h>
#define pi 3.141592654
using namespace std ;
int main()
{
	 double a, b, c ;
	 while(cin >> a >> b >> c)
	 {
		  double h, ca, altura ;
		  h = c / sin((a * pi/180));
		  ca = h * cos((a * pi/180)) ;
		  altura =( (b + ca) / ca) * c ;
		  cout << fixed << setprecision(2) << 5.0 * altura << '\n' ; 
	 }
	 return 0 ;
}
