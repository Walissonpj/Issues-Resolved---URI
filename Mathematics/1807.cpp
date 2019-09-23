#include <bits/stdc++.h>
#define ld long double
#define ll long long
using namespace std ;
ll pow_fast( ll a, ll b, ll d){
	ll ans = 1;
	while( b ){
		if( (b & 1LL) ){
			ld x = (long long)(((ld)ans * (ld)a) / (ld)d) ;
			ans = (long long)((ld)ans*(ld)a - ((ld)d * x )) ;
			b-- ;
		}
		long double x = (ll)(((ld)a * (ld)a) / (ld)d) ;
		a = (ll)( ((ld)a*(ld)a) - ((ld)d * x ) ) ;
		b /= 2LL ;
	}
	return ans ;
}
int main(){
	ll n, ans ;
	cin >> n ;
	ll d = (1LL << 31LL) - 1LL ;
	cout << pow_fast(3LL, n, d) << endl ;
	return 0 ;
}