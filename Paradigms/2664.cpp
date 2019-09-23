#include <bits/stdc++.h>
using namespace std;
int dp[51][100005];
int t, m, n, vis;
const int MOD = 1000000007;
long long inf;
long long solve(int idx, int at) {
	if(at < m || at > n) return 0;
	if(idx == t-1) return 1;

	if(dp[idx][at] != inf) return dp[idx][at];
	dp[idx][at] = (solve(idx+1, at+1)%MOD + solve(idx+1, at-1)%MOD)%MOD;
	return dp[idx][at];
}

int main() {
	cin >> t >> m >> n;
	long long ans = 0L;
	memset(dp, -1, sizeof(dp));
	inf = dp[0][0];
	vis = 1;
	for(long long i = m; i <= n; i++) {
		ans = (ans + solve(0, i))%MOD;
		vis++;
	}
	cout << ans << '\n';
	return 0;
}
