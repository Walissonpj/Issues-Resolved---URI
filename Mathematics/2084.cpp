#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int sum = 0 ;
	int ans = 0, aux = 0;
	for( int i = 0 ; i < n ; i++){
		int a ;
		cin >> a;
		sum += a;
		if( ans < a){
			if( aux < ans)
				aux = ans;
			ans = a;
		}
		else if( aux < a)
			aux = a;
	}
	int pc = (0.45 * (double)sum);
	int pc1 = (0.40 * (double)sum);
	int dez = (0.10 * (double)sum);
	//cout << pc << ' ' << pc1 << ' ' << dez << endl;
	if( (ans >= pc) || (ans >= pc1 && (ans - aux) >= dez))
		cout << "1\n";
	else
		cout << "2\n";
	return 0 ;
}