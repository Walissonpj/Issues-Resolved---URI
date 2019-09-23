#include <bits/stdc++.h>
using namespace std ;

void bfs(int ini, int fim)
{
			map< int, bool >  vis;
			queue < pair<int , int > > f ;
			int dis = 0 ;
			if( ini == fim )
			{
				cout << "0\n" ;
				return;
			}
			f.push(make_pair(0, ini)) ;
			vis[ ini ] = true ;
			while(1)
			{
				int soma = 0 ;
				dis = f.front().first ;
				int aux = f.front().second ;
				f.pop();
				if(!vis[aux + 1])
				{
					vis[aux + 1] = true ;
					f.push(make_pair(dis + 1, aux + 1 )) ;
				}
				if( aux == fim )
				{
					break ;
				}
				int i = ((aux == 0)? 1: (log10(aux) + 1));
				while(i--)
				{
					soma += (aux % 10) * pow(10, i);
					aux = aux / 10 ;
				}
				if(!vis[soma])
				{
					vis[soma] = true ;
					f.push(make_pair(dis + 1, soma)) ;
				}
			}
			cout << dis << "\n";
}	

int main()
{
	int n ;
	cin >> n ;
	while( n-- )
	{
		int a , b ;
		cin  >> a >> b ;
		bfs(a, b);
	}
	return 0 ;
}