#include <bits/stdc++.h>
using namespace std ;
main()
{
    string a, b ;
    while( cin >> a >> b && (a != "0" || b != "0") )
    {
        int ans = 0 ;
        int x = a.size() , y = b.size() ;
        int cont = 0 ;
        if( x >= y )
        {
            for( int i = x - 1, j = y - 1 ; i >= 0 ; i--)
            {
                if( j > -1 )
                {
                    int d = a[i] - '0', e = b[j] - '0' ;
                    if( ans + d + e <= 9 )
                        ans = 0 ;
                    else
                        ans = (ans + d + e) / 10 , cont++ ;
                    j-- ;
                }
                else
                {
                    int d = a[i] - '0' ;
                    if( ans + d <= 9 )
                        ans = 0 ;
                    else
                        ans = (ans + d)  / 10, cont++ ;
                }
            }
        }
        else
        {
          for( int i = x - 1, j = y - 1 ; j >= 0 ; j--)
            {
                if( i > -1 )
                {
                    int d = a[i] - '0', e = b[j] - '0' ;
                    if( ans + d + e <= 9 )
                        ans = 0 ;
                    else
                        ans = ( ans + d + e ) / 10 , cont++ ;
                    i-- ;
                }
                else
                {
                    int e = b[j] - '0' ;
                    if( ans + e <= 9 )
                        ans = 0 ;
                    else
                        ans = (ans + e) / 10 , cont++  ;
                }
            }
        }
        if(cont)
            cout << cont << " carry operation" << ((cont == 1)? (".\n"): "s.\n") ;
        else
            cout << "No carry operation.\n" ;
    }
}