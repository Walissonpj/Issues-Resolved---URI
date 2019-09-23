#include<bits/stdc++.h>
using namespace std ;
int main()
{
	 int r1, x1, y1, r2, x2, y2 ;
	 while(cin >> r1 >> x1 >> y1 >> r2 >> x2 >> y2)
	 {
		  if(r1 < r2)
		  {
				cout << "MORTO\n"; 
				continue;
		  }
		  double dist = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
		  if(dist + r2 > r1)
				cout << "MORTO\n" ;
			else
				 cout << "RICO\n" ;
	 }
	 return 0 ;
}
