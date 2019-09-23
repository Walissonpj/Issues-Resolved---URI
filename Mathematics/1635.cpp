#include <bits/stdc++.h>
using namespace std ;
bool compar(string s, double ans, string sinal ){
	istringstream ss(s) ;
	double aux ;
	double e = 0.000001 ;
	ss >> aux ;
	double x = ans - aux ;
	if( sinal == "=")
		return (( x < e)&& (x > -e)) ;
	if( sinal == "<" )
		return (x < -e);
	if( sinal == "<=" )
		return (x < e) ;
	if( sinal == ">" )
		return (x > e) ;
	if( sinal == ">=" )
		return (x > -e) ;
}
int main(){
	int a, b ;
	cin >> a >> b ;
	map<string, double> m ;
	for( int i = 0 ; i < a ; i++)
	{
		string s ;
		double c ;
		cin >> s; cin >>  c ;
		m[s] = c ;
	}
	cin.ignore() ;
	for( int i = 1 ; i <= b ; i++){
		string s, r, sinal;
		getline(cin, s) ;
		double ans = 0.0 ;
		istringstream ss(s) ;
		while( ss >> r ){
			if( m.count(r) ){
				ans += m[r] ;
			}
			if( r == "=" || r == "<" || r == "<=" || r == ">" || r == ">="){
				sinal = r ;
				break ;
			}
		}
		ss >> r ;
		bool f = compar( r, ans, sinal) ;
		cout << "Guess #" << i << " was " << (( f == true ) ? "correct.\n" : "incorrect.\n") ;
	}
	return 0 ;
}