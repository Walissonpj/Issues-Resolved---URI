#include <iostream>
 
using namespace std;
 
int main() {
    int t; 
	cin >> t ;
    for(int i = 0 ; i < t ; i++)
    {
        int x, y, a, b, c  ;
        cin >> x >> y ;
        a = (9*x*x) + (y * y) ;
        b = (2*x*x) + (25*y*y) ;
        c = (-100*x) + (y*y*y) ;
		int ans = max(a, max(b, c)) ;
        if(a  == ans)
            cout << "Rafael ganhou\n";
        if(b == ans )
            cout << "Beto ganhou\n";
        if( c == ans )
            cout << "Carlos ganhou\n" ;
    }
    return 0;
}