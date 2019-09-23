#include<bits/stdc++.h>
using namespace std ;
int p1[105], p2[105], p3[105] ;
int vis ;
int dp[105][105][105], up[105][105][105] ;
int solve(int a, int b, int c)
{
	 if( a == 0 && b == 0 && c == 0 )
		  return 1 ;
	 int &ans = dp[a][b][c] ;
	 int &u = up[a][b][c] ;
	 if( u == vis )
		  return ans ;
	 u = vis ;
	 ans = 0 ;
	 if( a && !( p1[a] % 3 ) ) ans = max( ans, solve(a-1, b, c)) ;
	 if( b && !( p2[b] % 3 ) ) ans = max( ans, solve(a, b-1, c)) ;
	 if( c && !( p3[c] % 3 ) ) ans = max( ans, solve(a, b, c-1)) ;
	 if( a && b && !( (p1[a] + p2[b])%3) ) ans = max( ans, solve(a-1, b-1, c)) ;
	 if( a && c && !( (p1[a] + p3[c])%3 ) ) ans = max( ans, solve(a-1, b, c-1)) ;
	 if( b && c && !((p2[b] + p3[c])%3) )   ans = max( ans, solve(a, b-1, c-1)) ;
	 if( a && b && c && !((p1[a] + p2[b] + p3[c])% 3) ) ans = max( ans, solve( a-1, b-1, c-1) ) ;
	 return ans ;
}

int main()
{
	 int n ;
	 vis = 1 ;
	 while( cin >> n && n )
	 {
		  for( int i = 1 ; i <= n ; i++ )
		  {
				cin >> p1[i] >> p2[i] >> p3[i] ;
		  }
		  int ans  = solve( n, n, n ) ;
		  cout << ans << "\n" ;
		  vis++ ;
	 }
	 return 0 ;
}