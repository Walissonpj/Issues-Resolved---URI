#include <bits/stdc++.h>
using namespace std ;
map<string, int> cor ;
int inv[5] ;
vector<pair<int, pair<int, int> > > v ;
int n, vis ;
int dp[1005][5][1002], up[1005][5][1002] ;
struct cmp
{
	bool operator()( const pair<int, pair<int, int> >& a, const pair<int, pair<int, int> >b)
	{
		if( a.second.second > b.second.second)
			return true ;
		else return false ;
	}
};
int solve( int at, int ant, int tam )
{
	if( at == n )
		return 0 ;
	if( up[at][ant][tam] == vis)
		return dp[at][ant][tam] ;
	up[at][ant][tam] = vis ;
	dp[at][ant][tam] = 0 ;
	if( inv[ v[at].first ] != ant  && v[at].second.second < tam )
		dp[at][ant][tam] = max( dp[at][ant][tam], solve( at + 1, v[at].first, v[at].second.second ) + v[at].second.first ) ;
	dp[at][ant][tam] = max( dp[at][ant][tam], solve( at + 1, ant, tam ) ) ;
	return dp[at][ant][tam] ;
 }
main()
{
	vis = 1 ;
	ios_base::sync_with_stdio(false) ;
	cor["VERMELHO"] = 1 ;
	cor["LARANJA"] = 2 ;
	cor["AZUL"] = 3 ;
	cor["VERDE"] = 4 ;
	inv[1] = 2 ;
	inv[2] = 3 ;
	inv[3] = 4 ;
	inv[4] = 1 ;
	while( cin >> n && n )
	{
		v = vector<pair<int, pair<int, int> > > (n) ;
		for ( register int i = 0; i < n; ++i)
		{
			string a ;
			cin >> v[i].second.first >> v[i].second.second >> a ;
			v[i].first = cor[a] ;
		}
		sort( v.begin(), v.end(), cmp() ) ;
		cout << solve( 0, 0, 1001 ) << " centimetro(s)\n" ;
		vis++ ;
	}
}