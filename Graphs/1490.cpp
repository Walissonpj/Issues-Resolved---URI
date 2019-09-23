#include <bits/stdc++.h>
using namespace std;
vector<vector<int> >bpGraph;
bool bpm(int u, bool seen[], int matchR[])
{
    for (int v = 0; v < bpGraph[u].size(); v++)
    {
		int ve = bpGraph[u][v];
        if (!seen[ve])
        {
            seen[ve] = true;

            if (matchR[ve] < 0 || bpm( matchR[ve], seen, matchR))
            {
                matchR[ve] = u;
                return true;
            }
        }
    }
    return false;
}

int maxBPM(int N)
{
    int matchR[N];   
    memset(matchR, -1, sizeof(matchR));
    int result = 0; 
    for (int u = 0; u < N; u++)
    {
        bool seen[bpGraph.size()+1];
        memset( seen, 0, sizeof(seen));
        if ( bpm( u, seen, matchR))
            result++;
    }
    return result;
}



int main(){
	int n;
	ios_base::sync_with_stdio(false);
	while(cin >> n){
		char mp[n][n];
		int id[n][n];
		for( int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++)
				cin >> mp[i][j];
		}
		bpGraph = vector<vector<int> >(n*n);
		int l = 0;
		for( int i = 0; i < n; i++){
			for( int j = 0 ; j < n; j++){
				if( mp[i][j] == 'X'){
					l++;
					continue;
				}
				id[i][j] = l;
			}
			l++;
		}
		int c = 0;
		//cout << "*********************\n";
		for( int i = 0; i < n; i++){
			for( int j = 0 ; j < n; j++){
				if( mp[j][i] == 'X'){
					c++;
					continue;
				}
			//	cout << c << ' ' << j << endl;
				bpGraph[c].push_back(id[j][i]);
				//g[id[j][i]].push_back(c);
			}
			c++;
		}
		cout << maxBPM(n*n)<< endl;
	}
	return 0;
}
