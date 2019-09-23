#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1111;

int n, m, from, to, weight, nxt[N], dp[N][N];
vector < pair < pair <int, int>, pair <int, int> > > v;

int main() {
 
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &m);
        for (int j = 0; j < m; j++) {
            scanf("%d %d %d", &from, &to, &weight);
            v.push_back({make_pair(from, to), make_pair(weight, 1 << i)});
        }
    }
    
    sort(v.begin(), v.end());
    
    for (int i = 0; i < v.size(); i++) {
        nxt[i] = v.size();
        for (int j = i + 1; j < v.size(); j++) {
            if (v[j].first.first >= v[i].first.second) {
                nxt[i] = j;
                break;
            }
        }
    }
    
    for (int i = 0; i <= v.size(); i++) {
        for (int mask = 0; mask < (1 << n); mask++) {
            dp[i][mask] = -1;
        }
    }
    
    dp[0][0] = 0;

    for (int i = 0; i < v.size(); i++) {
        for (int mask = 0; mask < (1 << n); mask++) {
            if (dp[i][mask] == -1) continue;
            dp[i + 1][mask] = max(dp[i + 1][mask], dp[i][mask]);
            dp[nxt[i]][mask | v[i].second.second] = max(dp[nxt[i]][mask | v[i].second.second], dp[i][mask] + v[i].second.first);
        }
    }
   
    printf("%d\n", dp[v.size()][(1 << n) - 1]);
   
    return 0;
    
}
