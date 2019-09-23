#include <bits/stdc++.h>
#define pi 3.1415926535897
using namespace std ;
int main()
{
     double a, b, c ;
     while( cin >> a >> b >> c )
     {
          double p, r ;
          p = (a + b + c)/2.0 ;
          double AC, AR, ACM ;
          AR = sqrt( p*(p - a)*(p-b)*(p-c) ) ;
          ACM = ((AR/p) *(AR/p)) * pi ;
          AC = ((a*b*c) /(4*AR)*(a*b*c) /(4*AR)) * pi ;
          cout << fixed << setprecision(4) << AC - AR << ' ' << AR - ACM << ' ' << ACM << '\n' ;
     }
     return 0 ;
}