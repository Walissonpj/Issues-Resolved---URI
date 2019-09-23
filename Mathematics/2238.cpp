#include <bits/stdc++.h>
using namespace std;
int main(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int ma = c+1;
	for( int i = 1; i*i <= c; i++){
		if( c % i == 0 ){
			int ans = i;
			if( (ans % a) == 0 && (ans% b) != 0 && (d % ans) != 0 )
				ma = min( ma, ans);
			ans = c/i;
			if( (ans % a) == 0 && (ans% b) != 0 && (d % ans) != 0 )
				ma = min( ma, ans);
		}
	}
	if( ma > c)
		cout << -1 << endl;
	else
		cout << ma << endl;
	return 0;
}