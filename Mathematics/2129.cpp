#include <bits/stdc++.h>
int fato[] = { 1, 1, 2, 6, 4, 2, 2, 4, 2, 8, 8};
using namespace std;
long long fat( int n){
	if( n <= 10){
		return fato[n];
	}
	int ans = 6;
	if( (n/10)&1)
		ans = 4;
	return ans * fat(n%10) * fat(n/5);
}
int main(){
	int n, a=1;
	while( cin >> n ){
		cout << "Instancia " << a++ << endl; 
		cout << fat(n)%10 << endl << endl;
	}
	return 0;
}