#include <bits/stdc++.h>
#define int long long
using namespace std;

main(){
	int n;
	cin >> n;
	while(n--){
		unsigned long long x, i;
		cin >> x;
		i = (-1 + sqrt(1 + 4 * 2 * x))/2;
		cout << i << endl; 
	}
}
