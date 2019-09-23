#include <bits/stdc++.h>
using namespace std;
int maior_numero_com_digitos_de(int x){
	int ans = 0;
	vector<int>v;
	while(x){
		v.push_back(x%10);
		x/= 10;
	}
	while(v.size() < 4){
		v.push_back(0);
	}
	sort( v.rbegin(), v.rend());
	for( int i = 0; i < v.size(); i++){
		ans *= 10;
		ans += v[i];
	}
	return ans;
}
int menor_numero_com_digitos_de(int x){
	int ans = 0;
	vector<int>v;
	while(x){
		v.push_back(x%10);
		x/= 10;
	}
	sort( v.begin(), v.end());
	for( int i = 0; i < v.size(); i++){
		ans *= 10;
		ans += v[i];
	}
	return ans;
}
int krapekar(int X) {
   int cnt = 0;
   map<int, bool>m;
   while (X != 6174) {
	   if( !m[X])
		   m[X] = true;
	   else
		   return -1;
       int maior = maior_numero_com_digitos_de(X);
       int menor = menor_numero_com_digitos_de(X);
       X = maior - menor;
       cnt = cnt + 1;

   }
   return cnt;
}


int main(){
	int t;
	cin >> t;
	for( int i = 1; i <= t; i++){
		int a;
		cin >> a;
		cout << "Caso #" << i << ": ";
		cout << krapekar(a) << endl;
	}
	return 0;
}