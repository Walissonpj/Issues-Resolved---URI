#include <bits/stdc++.h>
using namespace std ;
int bit[100005] ;
int n ;
 
inline int solve(int id)
{
    register int sum = 0 ;
    while( id )
    {
        sum += bit[id] ;
        id -= (id & (-id) ) ;
    }
    return sum ;
}
inline void up( int id )
{
    while( id <= n)
    {
        bit[id] ++;
        id += (id & (-id) ) ;
    }
}
 
int main()
{
    while( cin >> n )
    {
        vector<pair< string, int > > v( n ) ;
        memset( bit, 0, sizeof(bit) ) ;
        for (register  int i = 0 ; i < n ; ++i )
        {
            cin >> v[i].first ;
            v[i].second = n - i ;
        }
        long long  cont = 0LL ;
        sort( v.begin(), v.end() ) ;
        for( register int i = 0 ; i < n ; i++)
        {
            cont += solve( v[i].second ) ;
            up( v[i].second ) ;
        }
        cout << cont << endl ;
    }
    return 0 ;
}