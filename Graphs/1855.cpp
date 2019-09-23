#include <bits/stdc++.h>
using namespace std ;
main()
{
	int a, b ;
	cin >> b >> a ;
	char m[a][b] ;


	for (int i = 0; i < a; ++i)
	{
		for (int j = 0; j < b; ++j)
		{
			cin >> m[i][j] ;
		}
	}

	if( m[0][0] == '.')
		cout << "!\n" ;
	else
	{
		map< int, map<int, bool> > vis ;
		vis[0][0] = 1 ;
		queue< pair<int, int> > q ;
		int d[] = {0,0,1,0,-1} ;
		int e[] = {0,1,0,-1,0} ;

		map<char, int> w ;
		w['>'] = 1 ;
		w['v'] = 2 ;
		w['<'] = 3 ;
		w['^'] = 4 ;

		int at = w[ m[0][0] ] ;
		q.push( make_pair( d[ at ] , e[ at ] ) ) ;
		while( !q.empty() )
		{
			int x = q.front().first  ;
			int y = q.front().second ;
			q.pop() ;
			if( x < 0 || x >= a || y >= b || y < 0 || vis[x][y] )
			{
				cout << "!\n" ;
				break ;
			}
			else
			{
				if(m[x][y] == '*')
				{
					cout << "*\n" ;
					break ;
				}
				else
				{
					if( w[ m[x][y] ])
					{
						at = w[ m[x][y] ] ;
						vis[x][y] = true ;
 					}
					q.push(make_pair( x + d[at], y + e[at] ) ) ;
				}
			}
		}
	}
}