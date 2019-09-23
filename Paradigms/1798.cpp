#include<bits/stdc++.h>
#define int long long
using namespace std ;
int dp[1001][2001], up[1001][2001], vis;
int v[1005], x[1005] ;
int mochila(int at, int w)
{
     if(at == 0)
          return 0 ;
     int &ans = dp[at][w] ;
     if(up[at][w] == vis)
          return ans ;
     up[at][w] = vis ;
     ans = -100000 ;
     if( v[at]  <= w )
     {
		 int y = w / v[at] ;
          ans = max(ans, mochila( at-1, w - v[at]) + x[at] ) ;
		  for(int i = 1 ; i <= y; i++)
		  {
          		ans = max( ans, mochila(at-1, w - (i*v[at]) ) + (i*x[at]) ) ;
		  }
          ans = max(ans, mochila(at-1, w)) ;
     }
	 else
		 ans = mochila(at-1, w) ;
     return  ans ;
}
main()
{
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;
     int n, t ;
     cin >> n >> t ;
     vis = 1 ;
     for(int i = 1 ; i <= n ; i++)
          cin >> v[i] >> x[i] ;
     cout << mochila( n, t ) << '\n';
}
