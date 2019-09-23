#include <bits/stdc++.h>
using namespace std ;
int main(){
	int n ;
	cin >> n ;
	while(n--){
		long long k, ans, t ;
		string s ;
		cin >> k >> s;
		ans = k ;
		t = s.size() ;
		for( long long i = 1LL ; i * t < k; i++ ){
			ans = ans * (k - i*t) ;
		}
		cout << ans << endl ;
	}
	return 0 ;
}