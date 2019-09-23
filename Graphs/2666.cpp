#include <bits/stdc++.h>
using namespace std;

int n, l;

vector<int> price(n);
vector< vector< pair<int, int> > > caminho;
vector<int> vis;

pair<int, int> dfs(int idx) {
	int peso = price[idx];
	int distancia = 0;

	vis[idx] = 1;
	for(int i = 0; i < caminho[idx].size(); i++) {
		if(!vis[caminho[idx][i].first]) {
			pair<int, int> aux = dfs(caminho[idx][i].first);
			int k = aux.second/l + (aux.second%l != 0);
			
			peso += aux.second;
			distancia += 2*k*caminho[idx][i].second + aux.first;
		}
	}

	return make_pair(distancia, peso);
}

int main() {
	cin >> n >> l;
	
	price = vector<int>(n);	
	caminho = vector< vector< pair<int, int> > > (n);
	vis = vector<int>(n);

	for(int i = 0; i < n; i++)
		vis[i] = 0;
	
	for(int i = 0; i < n; i++)
		cin >> price[i];

	for(int i = 0; i < n-1; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		caminho[a-1].push_back(make_pair(b-1,c));
		caminho[b-1].push_back(make_pair(a-1,c));
	}

	cout << dfs(0).first << '\n';

	return 0;
}
