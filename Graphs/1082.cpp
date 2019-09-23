#include <bits/stdc++.h>
using namespace std;
 
int visitado[27];
int adj[27][27];
int cont = 1;
list <char >  l;
void dfs(int u, int n)
{
	for(int v = 0 ; v < n ; v++)
	{
		if(adj[u][v] && !visitado[v] )
		{
			visitado[v] = true;
			l.push_back('a' + v );
			dfs(v, n);
		}
	}
}

void conexo(int n)
{
	memset(visitado, 0, sizeof(visitado)); 
	for(int v = 0 ; v < n ; v++)
	{
		if(!visitado[v])
		{
			l.push_back( 'a' + v);
			visitado[v] = true;
			dfs(v, n);
			l.sort();
			for(list<char > :: iterator  k = l.begin() ; k != l.end() ; k++ )
			{
				cout << *k << "," ;
			}
			l.clear() ;
			cout << endl;
			cont++;
		}
	}
}

int main()
{
		int n , aux = 1;
		cin >> n ;
		while(n--)
		{
			int v, e ;
			cin >> v >> e ;
			memset(adj, 0, sizeof(adj));
			for(int i = 0 ; i < e ; i++)
			{
				char de, pa;
				cin >> de >> pa;
				adj[de - 'a'][pa - 'a'] = 1;
				adj[pa - 'a'][de - 'a'] = 1 ;
			}
			cout << "Case #" << aux++ << ":\n";
			cont = 0;
			conexo(v);
			cout << cont <<" connected components\n\n";
		}
	return 0 ;
} 