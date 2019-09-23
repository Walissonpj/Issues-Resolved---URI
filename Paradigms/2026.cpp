#include <bits/stdc++.h>
using namespace std;
int main(){
        int t;
        cin >> t;
        for( int q = 1; q <= t; q++){
                int p, w;
                cin >> p >> w;
                int dp[p+1][w+1];
                vector<pair<int, int> >v(p);
                for( int i = 0 ; i < p ; i++)
                        cin >> v[i].first >> v[i].second;
                for( int i = 0; i <= p; i++){
                        for( int j = 0; j <= w; j++){
                                if( i == 0 || j == 0)
                                        dp[i][j] = 0 ;
                                else if( j >= v[i-1].second)
                                        dp[i][j] = max( dp[i-1][j-v[i-1].second] + v[i-1].first, dp[i-1][j]);
                                else
                                        dp[i][j] = dp[i-1][j];
                        }
                }
                cout << "Galho " << q << ":\n";
                cout << "Numero total de enfeites: " << dp[p][w] << "\n\n";
        }
        return 0;
}