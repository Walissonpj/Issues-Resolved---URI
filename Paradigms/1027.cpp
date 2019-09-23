#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	while(cin >> n){
		vector<pair<int, int> >v(n);
		vector< vector<pair<int, bool> > >dis(n);
		for(int i=0; i <n; i++)
			cin >> v[i].first >> v[i].second;
		sort(v.begin(), v.end());
		int mat[2][n];
		for(int i = 0 ; i < n; i++){
			for(int j = i+1 ; j < n; j++){
				if( v[i].first != v[j].first){
					int ans = v[i].second - v[j].second;
					if( abs(ans) == 2)
						dis[i].push_back( make_pair( j, ans > 0));
				}
			}
		}
		queue< pair<int, int> > q;
		for( int i = 0 ; i < n; i++){
			q.push( make_pair(i, 0));
			q.push( make_pair(i, 1));
			mat[0][i] = 1;
			mat[1][i] = 1;
		}
		while( !q.empty()){
		//		cout << "ok ************** \n";
			int ans = q.front().first;
			int op = q.front().second;
			q.pop();
			for( int i = 0 ; i < dis[ans].size() ; i++){
				int pos = dis[ans][i].first;
				int sinal = dis[ans][i].second;
				if( (op^1) != sinal && mat[op^1][pos] < mat[op][ans] + 1){
					mat[op^1][pos] = mat[op][ans] + 1;
					q.push( make_pair( pos, sinal)) ;
				}
			}
		}
		int ans = 0 ;
		for(int i = 0 ; i < n ; i++){
			for(int j = 0; j < 2; j++)
				ans = max( ans, mat[j][i]);
		}
		cout << ans << endl ;
	}
	return 0 ;
}