#include<bits/stdc++.h>
using namespace std;
main()
{
        int n, p ;
        cin >> n >> p ;
        map< string, int > m ;
        int cont = 1 ;
        vector<vector<int> > v(n) ;
        m["Rerisson"] = 0 ;
        for(int i = 0 ; i < n ; i++)
        {
                string a, b ;
                cin >> a >> b ;
                if( !m.count(a) )
                        m[a] = cont, cont++ ;
                if( !m.count(b) )
                 m[b] = cont, cont++ ;
                v[ m[a] ].push_back( m[b] );
                v[m[b]].push_back( m[a]) ;
        }
        queue< pair<int, int> >q ;
        q.push( make_pair( 0, 0) ) ;
        int vis[n] ;
        int conti = 0 ;
        memset(vis, 0 , sizeof(vis) ) ;
        while( !q.empty() )
        {
                int ans = q.front().first ;
                int aux = q.front().second ;
                q.pop() ;
                if( aux == p )
                {
                        continue ;
                }
                for(int i = 0 ; i < v[ans].size() ; i++)
                {
                        if( !vis[ v[ans][i] ] && v[ans][i]  )
                        {
                                vis[v[ans][i]] = 1 ;
                                conti++;
                                q.push( make_pair( v[ans][i], aux + 1) ) ;
                        }
                }
        }
        cout << conti << '\n';
        for( map<string, int>:: iterator is = m.begin() ; is != m.end(); is++ )
        {
                if( vis[is->second] )
                {
                        cout << is->first << endl ;
                }
        }
}