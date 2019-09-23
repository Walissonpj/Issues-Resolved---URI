#include <bits/stdc++.h>
using namespace std ;
int v[41] ;
int solve( int id ){
	if( id == 1 || id == 0 )
		return 1 ;
	if( v[id] )
		return v[id] ;
	return solve( id - 1) + solve( id - 2) ;
}
int main(){
	int n ;
	v[1] = 1 ;
	v[2] = 2 ;
	for( int i = 3 ; i <= 40 ; i++){
		v[i] = solve(i);
	}
	while( cin >> n && n){
		cout << v[n] << endl ;
	}
	return 0 ;
}