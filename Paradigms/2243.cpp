#include <bits/stdc++.h>
using namespace std;
int main(){
	int n; cin >> n;
	vector<int>v(n+2);
	v[0] = v[n+1]= 0;
	for( int i = 1 ; i <= n; i++)
	    cin >> v[i];
	int i = 1;
	while( i <= n/2){
        if( v[i] > v[i-1])
            v[i] = v[i-1] + 1;
        int j = i;
        while( v[j-1] - v[j] > 1 && j >= 1){
            v[j-1] = v[j]+1;
            j--;
        }
	    i++;
	}
	i = n;
	while( i > 1){
            if( v[i] > v[i+1])
                v[i] = v[i+1] + 1;
            int j = i;
            while( v[j+1] - v[j] > 1 && j <= n){
                v[j+1] = v[j]+1;
                j++;
            }
	    i--;
	}
	cout << *max_element( v.begin() + 1, v.end() -1) << endl;
	return 0;
}