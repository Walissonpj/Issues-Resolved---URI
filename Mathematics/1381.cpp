#include <bits/stdc++.h>
#define ll long long
using namespace std ;
ll xi ;
ll gcd(ll a, ll b)
{
	ll x[] = {1, 0};
	ll y[] = {0, 1};
	while( (a%b) )
	{
		ll q = a / b ;
		ll temp = a ;
		a = b ;
		b = temp % b ;
		ll X = x[0] - (x[1] * q) ;
		ll Y = y[0] - (y[1] * q) ;
		x[0] = x[1] ;
		x[1] = X ;
		y[0] = y[1] ;
		y[1] = Y ;
	}
  xi = x[1] ;
	return b ;
}
int main(){
	ll n, c ;
	ll mod = 1300031 ;
	vector<ll>f(3*mod+1) ;
	int t ;
	cin >> t ;
	f[0] = 1LL ;
	for( ll i = 1 ; i <= 3*mod ; i++)
		f[i] = (f[i-1] * i) % mod ;

	while( t--){
		cin >> n >> c ;
		ll ans = f[c + n - 1 ] ;
		ll sna = gcd( (ll)((f[c] * f[n-1]) % mod), mod ) ;
		if( sna != 1)
			cout << "0\n" ;
		else
    {
			cout << (( ((mod+xi)%mod) * ans) % mod) << endl ;
    }
	}
	return 0 ;
}