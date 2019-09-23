#include<bits/stdc++.h>
#define INF 100000000
using namespace std;
int dp[2000][2];
vector<int>v;
int N, C, T1, T2;
int solve( int id, int op, int FIM){
	if( id >= FIM)
		return 0;
	if( dp[id][op] != -1)
		return dp[id][op];
	int pos = (int)(upper_bound( v.begin(), v.end(), v[id] + T1) - v.begin());
	int pos1 = (int)(upper_bound( v.begin(), v.end(), v[id] + T2) - v.begin());
	if( pos <=  FIM && v[id] + T1 == v[pos]) pos++;
	if( pos1 <= FIM && v[id] + T2 == v[pos1]) pos1++;
	dp[id][op] = solve( pos, 0, FIM) + T1;
	dp[id][op] = min( dp[id][op], solve( pos1, 1, FIM) + T2);
	return dp[id][op];
}

int main(){
	while( scanf("%d %d %d %d", &N, &C, &T1, &T2) != EOF){
		v = vector<int>(2*N+1);
		for(int i = 0 ; i < N ; i++){
			scanf("%d", &v[i]);
			v[i+N] = C + v[i];
		}
		int ans = INF;
		for( int i = 0; i < N; i++){
			memset( dp, -1, sizeof(dp));
			ans = min( ans, solve( i, 0, N+i));
		}
		printf( "%d\n", ans);
	}
	return 0;
}