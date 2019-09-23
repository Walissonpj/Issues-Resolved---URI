#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
	cin >> n;
	vector<pair<int, int> >v(n);
	for(int i = 0 ; i < n ; i++){
		cin >> v[i].first >> v[i].second;
	}
	sort( v.begin(), v.end());
	int ans = 0;
	for( int i = 0; i < n ; i++){
		stack<int> up, dow;
		int y1 = v[i].second;
		for( int j = 0; j < i ; j++){
			int y2 = v[j].second;
			if( y1 <= y2){
				while( !up.empty() && up.top() > y2)
					up.pop();
				up.push( y2 );
			}  else{
				while( !dow.empty() && dow.top() < y2)
					dow.pop();
				dow.push(y2);
			}
		}
		ans += (dow.size() + up.size());
	}
	cout << ans << endl;
	return 0;
}