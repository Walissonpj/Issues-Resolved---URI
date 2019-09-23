#include <bits/stdc++.h>
using namespace std ;
main()
{
	int t ;
	cin >> t ;
	while(t--)
	{
		 int n, e ;
		 cin >> n >> e ;
		 int qt[n+1]  ;
		 vector< vector<int> > adj(n + 1) ;
		 memset( qt, 0, sizeof(qt) ) ;

		 for( int j = 1 ; j <= e ; j++ )
		 {
			   int a, b ;
				cin >> a >> b ;
				adj[a].push_back(b) ;
				qt[b]++ ;
		}
		queue<int> q, aux ;
		bool vis[ n+1 ] ;
		memset( vis , false, sizeof( vis ) ) ;
		for( int i = 1 ; i <= n ; i++ )
		{
			 if( !qt[i] )
			 {
				  q.push( i ) ;
				  vis[i] = true ;
			 }
		}
		while( !q.empty() )
		{
			 int ans = q.front() ;
			 q.pop() ;
			 aux.push( ans ) ;
			 for( int i = 0 ; i < adj[ans].size() ; i++ )
			 {
				  if( qt[ adj[ans][i] ] )
						qt[ adj[ans][i] ]-- ;
				  if( !qt[ adj[ans][i] ]  && !vis[ adj[ans][i] ] )
				  {
						vis[ adj[ans][i] ] = true ;
						q.push( adj[ans][i] ) ;
				  }
			 }
		}
		if( aux.size() != n )
			cout << "SIM\n" ;
		else
			cout << "NAO\n" ;
	}
}
