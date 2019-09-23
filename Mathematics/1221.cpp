#include <bits/stdc++.h>
#include <string>
using namespace std ;
int main()
{
    int t ; cin >> t;
    while(t--)
    {
        int a ;
        cin >> a ;
        bool ok = true ;
        int ans = sqrt(a) ;
        for(int i = 2 ; i <= ans ; i++ )
        {
            if( !(a % i) )
            {
                ok = false ;
                break ;
            }
        }
        if(ok)
            cout << "Prime\n" ;
        else
            cout << "Not Prime\n" ;
    }
    return 0 ;
}
