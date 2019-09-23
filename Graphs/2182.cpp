#include <bits/stdc++.h>
using namespace std;
vector<int>pai;
vector<pair<int, int> > posto;
int find( int x ) {
	if ( pai[x] != x ) 
		pai[x] = find( pai[x] );
	return pai[x];
}

void unio(int a, int b, int c){
  a = find(a);
  b = find(b);
  if(a == b){
	  posto[a].first += c;
	  posto[a].second++;
	  return;
  }
  if( a < b)
	  swap( a, b);
  pai[b] = a;
  posto[a].first += posto[b].first + c;
  posto[a].second += posto[b].second + 1;
  posto[b] = make_pair( 0, 0);
}
int main()
{
	int n, m;
	cin >> n >> m;
	posto = vector< pair<int, int> >( n+1);
	pai = vector<int>( n+1);
	for(int i = 0 ; i <= n ; i++){
	    pai[i] = i;
		posto[i] = make_pair( 0, 0);
	}
	for(int i = 0 ; i < m; i++){
	  int a, b, c;
	  cin >> a >> b >> c;
	  unio( a, b, c);
	}
	pair< double, int> ma = make_pair( 1000000000., 0);
	for( int i = 1;	i <= n ; i++){
		double ans;
		int x = find(i);
		if( posto[x].second == 0)
			ans = 0.0;
		else
			ans = (double)posto[x].first/((double)posto[x].second);
		ma = min( ma, make_pair( ans, -x));
	}
	cout << -ma.second << endl;
	return 0;
}