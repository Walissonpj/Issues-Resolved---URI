#include <bits/stdc++.h>
#include <string>
using namespace std ;
int main()
{
    int t ; cin >> t;
    while(t--)
    {
        int a, b ;
        cin >> a >> b ;
        cout << __gcd(a, b) << '\n' ;
    }
    return 0 ;
}
