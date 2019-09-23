#include<bits/stdc++.h>
using namespace std ;
int cont ;
map<int, map<int, int> > m ;
bool vis[10000] ;
void dfs(int u, int n)
{
	cont ++ ;
	vis[u] = true ;
	for(int v = 0 ; v < n ; v++)
	{
		if(m[u][v] && !vis[v] )
		{
			vis[v] = true;
			dfs(v, n);
		}
	}
}
int main()
{
	int t ;
	cin >> t ;
	while(t--)
	{
		 memset(vis, 0, sizeof(vis)) ;
		 cont = 0 ;
		 int raiz ;
		 cin >> raiz ;
		 int v, e ;
		 cin >> v >> e ;
		 for(int i = 0 ; i < e ; i++)
		 {
			  int a, b ;
			  cin >> a >> b ;
			  m[a][b] = 1 ;
			  m[b][a] = 1 ;
		 }
		 dfs( raiz, v ) ;
		 cout << 2 * (cont- 1) << '\n' ;
		 m.clear() ;
	}
}
