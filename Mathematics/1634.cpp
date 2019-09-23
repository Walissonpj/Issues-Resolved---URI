#include <bits/stdc++.h>
using namespace std ;
int main(){
	int n, m ;
	while(cin >> n >> m && (n || m) ){
		int mi[n][m] ;
		int v[m] ;
		memset( v, 0, sizeof(v)) ;
		for( int i = 0 ; i < n ; i++)
			for( int j = 0 ; j < m ; j++){
				cin >> mi[i][j] ;
				v[j] += mi[i][j] ;
			}
		int k = m-1 ;
		while( k >= 0 && !v[k] ) k-- ;
		for( int i = 0 ; i < n ; i++){
			int a = mi[i][k] ;
			int b = v[k] ;
			int j = min( a, b) ;
			int c = __gcd( a, b) ;
			a /= c, b /= c ;
			cout << a << " / " << ((a == 0)? 1 : b) << endl ;
		}
	}
	return 0 ;
}
