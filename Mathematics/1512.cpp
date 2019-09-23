#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, a, b;
	while( cin >> n >> a >> b && (n && a && b)){
		int cont = n/a + n/b;
		int gcd = __gcd(a, b);
		int lcm = a * (b/gcd);
		if( lcm > n)
			cout << cont << endl;
		else{
			cont -= n/lcm;
			cout << cont << endl;
		}
	}
	return 0;
}