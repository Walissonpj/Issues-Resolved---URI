#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	while( cin >> n && n){
		int w;
		cin >> w;
		vector<int> peso(n), qt(n);
		
		for(int i = 0 ; i < n; i++)
			cin >> qt[i] >> peso[i];
	
		int dp[n+1][w+1];
		for(int i = 0 ; i <= n ; i++)
			dp[i][0] = 0;
		
		for(int i = 0 ; i <= w; i++)
			dp[0][i] = 0 ;
		
		for(int i = 1 ; i <= n ; i++)
			for(int j = 1 ; j <= w; j++){
				if( peso[i-1] <= j)
					dp[i][j] = max( dp[i-1][j], dp[i-1][j - peso[i-1]] + qt[i-1]);
				else
					dp[i][j] = dp[i-1][j];
			}
		cout << dp[n][w] << " min.\n";
	}
	return 0;
}