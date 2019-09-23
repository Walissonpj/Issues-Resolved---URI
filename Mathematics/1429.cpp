#include <bits/stdc++.h>
using namespace std ;
int v[7] ;
int main(){
	int n ;
	v[0] = 1 ;
	for( int i = 1 ; i <= 8 ; i++)
		v[i] = i * v[i-1] ;
	while( cin >> n && n){
		int sz = log10(n) + 1 ;
		int tot = 0 ;
		int d = pow(10, sz) ;
		while(sz){
			d/= 10 ;
			int k = (n/d) ; 
			tot +=  k * v[sz]  ;
			n= n%d;
			sz-- ;
		}
		cout << tot << endl ;
	}
	return 0 ;
}