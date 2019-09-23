#include <bits/stdc++.h>
using namespace std ;
#define inf 0x3F3F3F3F
vector< vector< pair<int, int> > > v ;
int solve( int fim )
{
    priority_queue< pair< pair<int, int>, int> , vector< pair < pair<int, int>, int> >, greater< pair <pair<int, int>, int > > > q ;
    q.push( make_pair( make_pair( 0 , 1), 0 ) ) ;
    vector<int> par( fim + 1, inf ), impar( fim + 1, inf ) ;
    par[1] = impar[1] = 0 ;
    while( !q.empty() )
    {
        int at = q.top().first.second ;
        int var = q.top().first.first ;
        int d = q.top().second ;
        q.pop() ;
        for( int i = 0 ; i < v[at].size() ; i++ )
        {
            int prox = v[ at ][ i ].first ;
            if( d & 1 )
            {
                if( par[ prox ] > impar[at] + v[at][i].second )
                {
                    par[prox] = impar[at] + v[at][i].second ;
                    q.push( make_pair( make_pair( par[prox] , prox ) , d + 1 ) ) ;
                }
            }
            else
            {
                 if( impar[ prox ] > par[at] + v[at][i].second )
                {
                    impar[prox] = par[at] + v[at][i].second ;
                    q.push( make_pair( make_pair( impar[prox] , prox ) , d + 1 ) ) ;
                }
            }
        }
    }
    return par[fim] ;
}
int main()
{
    int n, e ;
    cin >> n >> e ;
    v = vector< vector< pair<int, int> > > ( n + 1 ) ;
    for (int i = 0 ; i < e ; ++i )
    {
        int a, b, c ;
        cin >> a >> b >> c ;
        v[a].push_back( make_pair( b, c) ) ;
        v[b].push_back( make_pair( a, c) ) ;
    }
    int ans = solve( n ) ;
    if( ans == inf )
        cout << "-1\n" ;
    else
        cout << ans << endl ;
    return 0 ;
}