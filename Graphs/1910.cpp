#include <bits/stdc++.h>
using namespace std ;
#define inf 0x3F3F3F3F
//#define int long long
#define REP(i,n)	for(int i=0;i<n;i++)
#define RE(i,j,n)	for(int i=j;i<n;i++)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define sz(s) (int) s.size()
#define st(v) sort( v.begin(), v.end())
#define str(v) sort( v.rbegin(), v.rend())

int lim = 100000 ;
int o, d, k ;
bool vis[300001] ;
int solve(){

	queue< pair< int, int> > q ;
	vis[o] = vis[0] = true ;
	q.push( make_pair( o, 0) ) ;
	int dis, at ;
	int ma = max( o, d ) ;
	while( !q.empty() ){
		
		at = q.front().f ;
		dis = q.front().s ;
		q.pop() ;

		if( at == d )
			return dis ;

		if( !vis[at-1] ){
			q.push( make_pair( at-1, dis+1) ), vis[at-1] = true ;
		}
		
		if( at + 1 <= lim && !vis[at+1] ){
			q.push( make_pair( at+1, dis+1) ), vis[at+1] = true ;
		}
		
		if( at*2 <= lim && !vis[at*2] ){
			q.push( make_pair( at*2, dis + 1) ), vis[at*2] = true ;
		}
		
		if( at*3 <= lim && !vis[at*3] ){
			q.push( make_pair( at*3, dis + 1) ), vis[at*3] = true ;
		}

		if( !(at & 1) && !vis[at/2] ){
			q.push( make_pair( at/2, dis + 1) ), vis[at/2] = true ;
		}
	}
	return -1 ;
}
int main(){
	while( cin >> o >> d >> k && ( o || d || k) ){
		memset( vis, false, sizeof( vis) ) ;
		for( int i = 0 ; i < k ; i++)
		{
			int a; cin >> a ;
			vis[a] = true ;
		}
		cout << solve() << endl ;
	}
	return 0 ;
}