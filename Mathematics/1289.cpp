#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while( t--){
        int n;
        double p;
        int k;
        cin >> n >> p >> k;
        double ans = 0;
        for( int i = 0 ; i < 5000; i++){
            ans += p*pow(1.-p, n*i + k-1);
        }
        cout << fixed << setprecision(4) << ans << endl;
    }

    return 0;
}