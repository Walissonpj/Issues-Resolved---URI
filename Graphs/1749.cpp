#include <bits/stdc++.h>
#define unsigned long long long long
using namespace std;

long long dist(long long a, long long b, long long x, long long y){
	return (a-x)*(a-x) + (b-y)*(b-y);
}

int main(){
	int n;
	cin >> n;
	vector<pair<long long, long long> > v(n);
	map< long long, map<long long, int> > m;
	for( int i = 0 ; i < n; i++){
		cin >> v[i].first >> v[i].second;
		m[v[i].first][v[i].second] = i;
	}
	
	vector<vector<int> > g(n);
	for( int i = 0 ; i < n; i++){
		for( long long j = v[i].first - 5; j <= v[i].first + 5; j++){
			for( long long k = v[i].second-5;  k <= v[i].second + 5; k++){
				if( m[j].count(k)){
					int x = m[j][k];
					if( x == i)
						continue;
					if( dist(v[i].first, v[i].second, v[x].first, v[x].second) <= 25){
						g[i].push_back(x);
						g[x].push_back(i);
					}
				}
			}
		}
	}
	vector<int>cor(n, -1);
	int resp1 = 0, resp2=0;
	for( int i = 0 ; i < n; i++){
		if( cor[i] == -1 && g[i].size()){
			queue<int> q;
			cor[i] = 0;
			q.push(i);
			while(!q.empty()){
				int x = q.front();
				q.pop();
				for( int j = 0; j < g[x].size(); j++){
					if( cor[g[x][j]] == -1){
						cor[g[x][j]] = 1 - cor[x];
						q.push(g[x][j]);
					}
				}
			}
		}
		if( cor[i] == 1)
			resp1++;
		if( cor[i] == 0)
			resp2++;
	}
	cout << min(resp2, resp1) << endl;
	return 0;
}
