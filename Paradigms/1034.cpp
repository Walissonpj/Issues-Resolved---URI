#include <bits/stdc++.h>
#define inf 0x3F3F3F3F
using namespace std ;
int v[30] ;
main()
{
    int t ;
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    scanf("%d", &t) ;
    while( t-- )
    {
        int n, e ;
        scanf("%d %d", &n, &e) ;
        for( register int i = 1 ; i <= n ; i++ )
            scanf("%d", &v[i] ) ;
        int dp[ e + 1 ] ;
        memset( dp, inf, sizeof( dp ) ) ;
        dp[0] = 0 ;
        for( int i = 1 ; i <= n ; i++ )
        {
            for(int j = v[i] ; j <= e ; j++)
            {
                dp[j] = min( dp[ j - v[i] ] + 1 ,  dp[j] ) ;
            }
        }
        printf("%d\n", dp[e] ) ;
    }
}