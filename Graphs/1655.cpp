#include<bits/stdc++.h>
using namespace std ;
int main()
{
	 int n, m ;
	 while(cin >> n && n)
	 {
		  cin >> m ;
		  double grafo[n + 1][n + 1] ;
		  memset(grafo, 0.0, sizeof(grafo) ) ;
		  for(int i = 0 ; i < m ; i++)
		  {
				int a, b, c ;
				cin >> a >> b >> c ;
				grafo[a][b] = grafo[b][a] = (c * 1.0) / 100;
		  }
		  for(int k = 1 ; k <= n ; k++)
				for(int i = 1 ; i <= n ; i++)
					 for(int j = 1 ; j <= n ; j++)
						  grafo[i][j] = max( grafo[i][k] * grafo[k][j], grafo[i][j] ) ;
		 cout << fixed << setprecision(6) << (grafo[1][n] * 100.0) << " percent\n";
	}
	 return 0 ;
}