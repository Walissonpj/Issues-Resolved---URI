#include <bits/stdc++.h>
using namespace std;
int dp[110];
vector<int>v;
int solve(int at, int op){
	if( op == at)
		return 0;
	
	if( dp[at] == -1){
		dp[at] = 0;
		dp[at] += solve( v[at], op) + 1;
	}
	return dp[at];
}
int main(){
	int n;
	cin >> n;
	v = vector<int>( n+1);
	for(int i = 1 ; i <= n; i++){
		cin >> v[i];
	}
	int ans = 1;
	vector<int>mmc(n+1);
	for( int i = 1 ; i <= n; i++){
		memset( dp, -1, sizeof(dp));
		mmc[i] = solve( v[i], i) + 1;
	}
	for( int i = 2; ; ){
		bool f = true;
		for( int j = 1 ; j <= n && f; j++){
			f &= (mmc[j] == 1);
		}
		if(f)
			break;
		bool f1 = false;
		for( int j = 1 ; j <= n; j++){
			if( mmc[j] != 1 && mmc[j] % i == 0){
				mmc[j] /= i;
				f1 = true;
			}
		}
		if(f1)
			ans *= i;
		else
			i++;
	}
	cout << ans << endl;
	return 0;
}