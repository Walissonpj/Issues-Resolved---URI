#include <bits/stdc++.h>
#define inf 0x3F3F3F3F
using namespace std;
vector< vector<int> >g;
int ini, fim, queijo, a, b;
int dj(){
	priority_queue<pair<int, int> >p;
	p.push( make_pair(0, queijo));
	int dis[a+10];
	memset(dis, inf, sizeof(dis));
	dis[queijo] = 0;
	while( !p.empty()){
		int d = -p.top().first;
		int at = p.top().second;
		p.pop();
		for(register int i = 0 ; i < g[at].size(); i++){
			int pos = g[at][i];
			if( dis[pos] > dis[at]+1){
				dis[pos] = dis[at]+1;
				p.push( make_pair(-dis[pos], pos));
			}
		}
	}
	return dis[ini] + dis[fim];
}
int main(){
    ios_base::sync_with_stdio(false);
	cin >> a >> b;
	g = vector<vector<int> >(a+10);
	map<string, int>m;
	int cont = 1;
	for(register int i = 0 ; i < b; i++){
		string x, y;
		cin >> x >> y;
		if( !m.count(x))
			m[x] = cont++;
		if( !m.count(y))
			m[y] = cont++;
		if( x == "*")
			queijo = m[x];
		if( y == "*")
			queijo = m[y];
		if( x == "Entrada")
			ini = m[x];
		if( x == "Saida")
			fim = m[x];
		if( y == "Entrada")
			ini = m[y];
		if( y == "Saida")
			fim = m[y];
		g[m[x]].push_back(m[y]);
		g[m[y]].push_back(m[x]);
	}
	cout << dj() << endl;
	return 0;
}
