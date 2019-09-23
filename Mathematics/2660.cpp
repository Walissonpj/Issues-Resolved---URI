#include<bits/stdc++.h>
using namespace std;
int main(){
	unsigned long long n, l, lcm;
	cin >> n >> l;
	for( int i = 0 ; i < n; i++){
		unsigned long long a; cin >> a;
		if(i==0) lcm = a;
		else lcm = (lcm*a)/__gcd(lcm, a);
	}
	unsigned long long x = lcm, res=1LL;
	for( unsigned long long i = 1LL; i <= 1000000LL; i++){
		unsigned long long ans = (lcm*i)/__gcd(lcm, i);
		if( ans > x && ans <= l){
			x = ans, res = i;
		}
	}
	cout << res << endl;
	return 0;
}
