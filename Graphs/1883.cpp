#include <bits/stdc++.h>
#define inf 0x3F3F3F3F
using namespace std ;
int n, ra, iz, m ;
int cont ;
char mapa[1000][1000] ;
int x[] = {1,-1, 0, 0} ;
int y[] = {0, 0, 1,-1} ;
int temp[1000][1000], ts[1000][1000] ;
 
void inunda()
{
    queue< pair<int, int> > q ;
    for( int i = 0 ; i < m ; i++ )
    {
        for( int j = 0 ; j < n ; j++ )
        {
            if( mapa[i][j] == 'F' )
            {
                q.push( make_pair( i*n + j, 0) ) ;
                temp[i][j] = 0 ;
            }
            temp[i][j] = inf ;
        }
    }
    while( !q.empty() )
    {
        pair<int , int > ans  = q.front() ;
        q.pop() ;
        for(int k = 0 ; k < 4 ; k++)
        {
            int i = ans.first/n , j = ans.first % n ;
            i += x[k] ;
            j += y[k] ;
            if( (i >= 0 && i < m && j >= 0 && j < n) && ( temp[i][j] > ans.second + 1 ) )
            {
                q.push(make_pair(i*n+ j, ans.second+1));
                temp[i][j] = ans.second + 1 ;
            }
        }
    }
}
 
int go()
{
    queue< pair< int, int> > q ;
    q.push(make_pair( ra * n + iz, 0));
    ts[ra][iz] = 0;
        while( !q.empty() )
        { 
            pair<int , int > ans  = q.front() ;
            int tempo = ts[ans.first][ans.second] ;
            q.pop() ;
            for( int k = 0 ; k < 4 ; k++ )
            {
                int i = ans.first/n , j = ans.first%n ;
                i += x[k] ;
                j += y[k] ;
                if( i >= 0 && i < m && j >= 0 && j < n )
                {
                    if( mapa[i][j] == '.' && temp[i][j] > ans.second + 1 && ts[i][j] > ans.second + 1 )
                    {
                        ts[i][j] = ans.second + 1;
                        q.push(make_pair(i*n + j, ans.second + 1) );
                    }
                    else
                    {
                        if( mapa[i][j] == 'E' && temp[i][j] > ans.second + 1 && ts[i][j] > ans.second + 1 )
                        {
                                return ans.second + 1 ;
                        }
                    }
                }
            }
        }
        return 0 ;
}
 
int main()
{
    ios::sync_with_stdio (false) ;
    int t ;
    cin >> t ;
    while( t-- )
    {
        cin >> m >> n ;
        for( int i = 0 ; i < m ; i++ )
        {
            for( int j = 0 ; j < n ; j++ )
            {
                cin >> mapa[i][j] ;
                ts[i][j] = inf ;
                if( mapa[i][j] == 'S' )
                    ra = i, iz = j ;
            }
        }
        inunda() ;
        int a = go() ;
        if( a > 0 )

            cout << "Y" << '\n' ;
        else
            cout << "N\n" ;
    }
    return 0 ;
}