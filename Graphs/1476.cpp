#include <bits/stdc++.h>
#define MAXL    20
#define MAXN 50500
#define INF 100000000
using namespace std;

int n, m, k;
vector< pair< int,pair<int, int> > >aresta;
vector<int>pai, posto;
vector<vector<pair<int, int> > >gf;
// LCA
int nivel[MAXN];
int ancestral[MAXN][MAXL];
int men[MAXN][MAXL];
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
bool kruskal(){
	sort( aresta.begin(), aresta.end());
	for( int i = m-1 ; i >= 0 ; i--){
		int a = aresta[i].second.first;
		int b = aresta[i].second.second;
		if( unio( a, b) ){
			gf[a].push_back( make_pair(b, aresta[i].first));
			gf[b].push_back( make_pair(a, aresta[i].first));
		}
	}
}


void dfs(int u){
    
    for(int i = 0;i < (int)gf[u].size();i++){
        int v = gf[u][i].first;
        
        if(nivel[v] == -1){
            pai[v] = u;
			men[v][0] = gf[u][i].second;

            nivel[v] = nivel[u]+1;
            
            dfs(v);
        }
    }
    
}

int LCA(int u, int v){
    
    if(nivel[u] < nivel[v]) swap(u, v);
    
    for(int i = MAXL-1;i >= 0;i--)
        if(nivel[u] - (1<<i) >= nivel[v])
            u = ancestral[u][i];
    
    if(u == v) return u;
    
    for(int i = MAXL-1;i >= 0;i--)
        if(ancestral[u][i] != -1 && ancestral[u][i] != ancestral[v][i]){
            u = ancestral[u][i];
            v = ancestral[v][i];
        }
            
    return pai[u];
}

int main(){

	while(cin >> n >> m >> k){
		aresta = vector< pair< int,pair<int, int> > >(m);
		pai = vector<int>(n+1);
		posto = vector<int>(n+1, 0);
		gf = vector<vector<pair<int, int> > >(n+1);
		for(int i = 0 ; i <= n ; i++)
			pai[i] = i;
		for( int i = 0 ; i < m ; i++){
			int a, b, c;
			cin >> a >> b >> c;
			aresta[i] = make_pair( c, make_pair(a, b));
		}
		kruskal();
		
		for(int i = 0;i <= n;i++) pai[i] = nivel[i] = -1;
		for(int i = 0;i < MAXN;i++)
		for(int j = 0;j < MAXL;j++)
			ancestral[i][j] = -1, men[i][j] = INF;
		
		nivel[1] = 0;
		dfs(1);
		
		for(int i = 1;i <= n;i++) ancestral[i][0] = pai[i];
		
		
		
		for(int j = 1;j < MAXL;j++)
		for(int i = 1;i <=   n;i++)
			if(ancestral[i][j-1] != -1)
				ancestral[i][j] = ancestral[ ancestral[i][j-1] ][j-1];
		
		for(int j = 1;j < MAXL;j++)
		for(int i = 1;i <=   n;i++)
			if(ancestral[i][j-1] != -1)
				men[i][j] = min(men[i][j-1], men[ ancestral[i][j-1] ][j-1]);
		
		
		while(k--){
			int a, b;
			cin >> a >> b;
			int u = LCA(a, b);
			int menor = INF;
			for(int i = MAXL-1;i >= 0;i--)
				if(nivel[a] - (1<<i) >= nivel[u])
					menor = min(menor, men[a][i]), a = ancestral[a][i];
			
			for(int i = MAXL-1;i >= 0;i--)
				if(nivel[b] - (1<<i) >= nivel[u])
					menor = min(menor, men[b][i]), b = ancestral[b][i];
			
			cout << menor << endl;				
			
		}
	}
	return 0;
}
