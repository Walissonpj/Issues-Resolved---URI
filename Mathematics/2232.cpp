#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	long long m[32];
	m[0] = 0LL;
	for( long long i = 1LL ; i < 32LL ; i++){
		m[i] = ((1LL <<i) + m[i-1]);
	}
	cin >> t;
	while(t--){
		int a;
		cin >>a;
		cout << m[a]/2LL << endl;
	}
	return 0;
}