#include <bits/stdc++.h>
using namespace std;
int main(){
	int l, c, r1, r2;
	while( cin >> l >> c >> r1 >> r2 && l && c && r1 && r2){
		int r = r1 + r2;
		if( l< c)
			swap(l,c);
		if(r1 < r2)
			swap(r1, r2);
		int ans = (l - r)*(l-r) + (c - r)*(c-r);
		if( c >= 2*r1 && ans >= r*r)
			cout << "S\n";
		else
			cout << "N\n";
	}
	return 0;
}