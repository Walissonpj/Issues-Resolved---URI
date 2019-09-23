#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	while(cin >> n){
		long long dp[n+2];
		memset( dp, 0LL, sizeof(dp));
		vector<long long> v(n);
		for(int i = 0 ; i < n ; i++){
			cin >> v[i];
		}
		if( n == 2){
			cout << max( v[0], v[1]) << endl;
			continue;
		}
		for( int i = 0; i < n-2; i++){
			dp[i] = max( v[i+1], min( v[i], v[i+2]));
		}
		int l = n-3;
		long long count = 3;
		bool f = true;
		while( l ){
			for(int i = 0 ; i < l; i++){
				if( f )
					dp[i] = max( dp[i] + v[i + count], dp[i + 1] + v[i]);
				else
					dp[i] = min( dp[i], dp[i+1]);
			}
			f = !f;
			count ++;
			l--;
		}
		cout << dp[0] << endl ;
	}
	return 0;
}