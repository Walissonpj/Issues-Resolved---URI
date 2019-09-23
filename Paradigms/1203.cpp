#include<bits/stdc++.h>
using namespace std ;
int r , k ;
int dp[102] ;
int v[105], ok[5000] ;
int main()
{
	 while(cin >> r >> k)
	 {
		  int a , b ;
		  memset(v, 0, sizeof(v) ) ;
		  memset(dp, -1, sizeof(dp) ) ;
		  memset(ok, 0, sizeof(ok)) ;
		  for( int i = 0 ; i < k ; i++ )
		  {
				cin >> a >> b ;
				v[a]++ ;
				v[b]++ ;
		  }
		  ok[0] = 1 ;
		  for(int i = 1 ; i <= r ; ++i)
		  {
				for(int j = k ; j >= v[i]; j--)
				{
					 if( ok[j - (v[i]) ] == 1 )
						  ok[j] = 1 ;
				}
		  }

		  if( ok[k] )
			  cout << "S\n" ;
		  else
			  cout << "N\n" ;
	 }
	 return 0 ;
}