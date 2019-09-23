#include <bits/stdc++.h>
using namespace std ;
int n, time_s, s, e;
typedef vector<int> vi ;
vi visit, dfs, ar ;
stack<int> filhos ;
vector< vi > ADJ ;
vector<bool> ta_na_pilha ;
int aux  ;
void tarjan( int u )
{
    dfs[u] = visit[u] = time_s++ ;
    filhos.push(u) ;
    ta_na_pilha[u] = 1 ;
    for( int i = 0 ; i < ADJ[u].size(); i++ )
    {
       if( visit[ADJ[u][i]] == -1 )
       {
          tarjan( ADJ[ u ][ i ] ) ;
          dfs[u] = min( dfs[ u ] , dfs[ ADJ[ u ][ i ] ] ) ;
       }
       else if( ta_na_pilha[ ADJ[u][i] ] )
       {
          dfs[u] = min( dfs[u], dfs[ ADJ[u][i] ] ) ;
       }
    } 
    if( dfs[u] == visit[u] )
    {
            int ans;
            while( ans != u )
            {
                    ans = filhos.top() ;
                    filhos.pop() ;
                    ta_na_pilha[ ans ] = 0 ;
                    ar[ ans ] = aux ;
            }
            aux++ ;
    }
}
main()
{
	while( cin >> n && n)
	{
                cin >> e ;
		ADJ = vector< vi >( n + 1 ) ;
                visit = vi( n + 1, -1 ) ;
                dfs = vi( n + 1, 0 ) ;
                time_s = 1 ;
                ar = vi( n+1, 0 ) ;
                aux = 0 ;
                ta_na_pilha = vector<bool>(n+1, 0) ;
		for(int i = 0 ; i < e ; i++ )
		{
			int x, y ;
			cin >> x >> y ;
                        ADJ[x].push_back( y ) ;
		}
		for(int i = 1 ; i <= n ; i++)
                        if( visit[i] == -1 )
                                tarjan( i );
                visit = vi(n + 1, 0 ) ;
		for(int i = 1 ; i <= n  ; i ++ )
                {
                        for(int j = 0 ; j < ADJ[i].size() ; j++)
                        {
                                if( ar[i] != ar[ ADJ[i][j] ] )
                                        visit[ ar[i] ] = 1 ;
                        }
                }
                for( int i = 1, j = 0 ; i <= n ; i++ )
                {
                        if( !visit[ ar[i] ] )
                        {
                                if(j)
                                        cout << ' ' ;
                                j = 1 ;
                                cout << i ;
                        }
                }
                cout << endl ;
	}
}
