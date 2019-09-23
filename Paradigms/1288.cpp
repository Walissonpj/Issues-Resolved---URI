#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while( t--){
		int w, n, x ;
		cin >> n ;
		vector<int> peso(n), qt(n) ;
		
		for(int i = 0 ; i < n; i++)
			cin >> qt[i] >> peso[i];
		cin >> w >> x;
		int dp[2][w+1];
		for(int i = 0 ; i <= n ; i++){
			for(int j = 0 ; j <= w; j++){
				if( i == 0 || j == 0){
					dp[i%2][j] = 0 ;
					continue;
				}
				dp[i%2][j] = dp[(i-1)%2][j];
				if( peso[i-1] <= j)
					dp[i%2][j] = max( dp[i%2][j], dp[(i-1)%2][j - peso[i-1]] + qt[i-1]);	
			}
		}
		if( dp[n%2][w] >= x )
				cout << "Missao completada com sucesso\n" ;
		  else
				cout << "Falha na missao\n";
	}
	return 0;
}