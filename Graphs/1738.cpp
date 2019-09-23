#include <bits/stdc++.h>
using namespace std ;
main()
{
	int t ;
	ios_base::sync_with_stdio(false) ;
	while( scanf("%d", &t) && t )
	{
		int mat[t+1][t+1] ;
		int a, b ;
		char x[500] ;
		memset( mat, 0, sizeof(mat) ) ;
		while( scanf("%d%d", &a, &b) && ( a || b ) )
		{
			scanf( "%s", x ) ;
			int len = strlen(x) ;
			for(register int i = 0 ; i < len ; i++)
			{
				mat[a][b] |= 1 << (x[i] - 'a') ;
			}
		}
		for(register int k = 1 ; k <= t; k++)
		{
			for(register int i = 1 ; i <= t ; i++)
			{
				for(register int j = 1 ; j <= t ; j++)
				{
					mat[i][j] |= ( mat[i][k] & mat[k][j] ) ;
				}
			}
		}
		
		while( scanf("%d%d", &a, &b) && (a || b) )
		{
			if( mat[a][b] )
			{
				for( register int i = 0 ; i < 26 ; i++)
				{
					if( mat[a][b] & (1 << i) )
					{
						printf("%c", ( 'a' + i) )  ;
					}
				}
				printf("\n") ;
			}
			else
				printf("-\n") ;
		}
		printf("\n") ;
	}
}