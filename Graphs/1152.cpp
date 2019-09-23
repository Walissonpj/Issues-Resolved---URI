#include <bits/stdc++.h>
#define F first 
#define S second 
using namespace std;
vector<int> pai, posto;
int n, m;
vector<pair< int, pair<int, int> > > gh;
int find( int x){
	if( pai[x] != x)
		pai[x] = find(pai[x]);
	return pai[x];
}
bool unio( int a, int b){
	a = find(a);
	b = find(b);
	if( a == b)
		return false;
	if( posto[a] >= posto[b]){
		pai[b] = a;
		if( posto[a] == posto[b])
			posto[a]++;
	}else{
		pai[a] = b;
	}
	return true;
}
void kruskal(){
	sort(gh.begin(), gh.end());
	long long res = 0;
	for( int i = 0 ; i < m; i++)
		if( !unio(gh[i].S.F, gh[i].S.S))
			res += gh[i].F;
	cout << res << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	while( cin >> n >> m && (n && m)){
		pai = vector<int>(n);
		posto = vector<int>(n, 0);
		gh = vector<pair<int, pair<int, int> > >(m);
		for( int i = 0; i < n; i++)
			pai[i] = i;
		for( int i = 0 ; i < m; i++){
			cin >> gh[i].S.F >> gh[i].S.S >> gh[i].F;
		}
		kruskal();
	}
	return 0;
}
