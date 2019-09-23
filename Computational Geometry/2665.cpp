#include <bits/stdc++.h>
using namespace std;
 
const double pi = acos(-1.0);
const double EPS = 1e-9;
const double INF = 1e50;
 
struct pt;
 
int cmp(double a, double b = 0.0){
    if(fabs(a-b) < EPS) return 0;
    return a > b ? 1 : -1;
}
 
struct pt{
    int x, y;
    pt( int x = 0, int y = 0) : x(x), y(y) {}
    pt operator - (pt p){ return pt(x - p.x, y - p.y); }
};
 
double dist(pt a, pt b){ return hypot(a.x - b.x, a.y - b.y); }
double cross(pt a, pt b){ return a.x*b.y - a.y*b.x; }
double signed_area(pt a, pt b, pt c){ return cross((a-c),(b-c))/2.0; }
int side_sign(pt a, pt b, pt c){ return cmp(signed_area(a, b, c)); }
 
 
vector<pt>poly(3);
bool inside_convex_poly(pt p){
    int left = 0, right = 0, side;
    for(int i = 0; i < poly.size(); i++){
        side = side_sign(p, poly[i], poly[(i+1)%poly.size()]);
        if(side < 0) right++;
        if(side > 0) left++;
    }
    return !(left && right);
}
vector<pt>p;
int N, a, b, var;
int dp[101][101];
struct comp{
    bool operator()( const pt &a, const pt &b){
        if( a.y < b.y) return true;
        return false;
    } 
};
int dfs( int x, int j, int n){
    if(n == 0) return 0;
    int &ans= dp[x][j];
    if( ans != var ) return ans;
    ans = 0;
    for( int i = 0 ; i < n; i++){
        if( i == j) continue;
        poly[2] = p[j];
        if( inside_convex_poly( p[i])){
            dp[x][j] = max(dp[x][j], dfs(j, i, n-1)+1);
        }
    }
    return ans;
}
int main(){
    cin >> N >> a >> b;
    p = vector<pt>(N);
    for( int i = 0 ; i < N; i++){
        cin >> p[i].x >> p[i].y;
    }
    sort(p.begin(), p.end(), comp());
    int ans = 0;
    poly[0] = pt(a, 0);
    poly[1] = pt(b, 0);
    memset(dp, -1, sizeof(dp));
    var = dp[0][0];
    for( int i = 0 ; i < N; i++){
        ans = max(dfs(0,i, N)+1, ans);
    }
    cout << ans << endl;
    return 0;
}