#include <bits/stdc++.h>
using namespace std;

int d[1010], sum[1010];

int main(){
	for( int i = 1; i <= 1001; i++)
		for( int j = i; j <= 1001; j += i)
			d[j] ++;
	
	for( int i = 1; i <= 1001; i++)
		sum[i] += sum[i-1] + !(d[i]&1);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << sum[n] << '\n';
	}
	return 0;
}
