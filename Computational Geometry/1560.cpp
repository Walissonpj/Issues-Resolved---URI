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

bool inside_convex_poly(pt p, pt a, pt b, pt c){
	int left = 0, right = 0, side;
	side = side_sign(p, a, b);
	right += (side < 0);
	left += (side > 0);
	side = side_sign(p, b, c);
	right += (side < 0);
	left += (side > 0);
	side = side_sign(p, c, a);
	right += (side < 0);
	left += (side > 0);
	return !(left && right);
}

int main ()
{
	int n, m;
	ios_base::sync_with_stdio(false);
	while( cin >> n >> m){
		vector<pt>p(n), b(m);
		for( int i = 0 ; i < n ; i++)
			cin >> p[i].x >> p[i].y;
		for( int i = 0 ; i < m ; i++)
			cin >> b[i].x >> b[i].y;
		long long ans = 0;
		for( int i = 0 ; i < n ; i++){
			for( int j = i+1 ; j < n ; j++)
				for( int k = j+1; k < n; k++){
					int cont = 0;
					int min_x = min(p[i].x, min( p[j].x, p[k].x));
					int min_y = min(p[i].y, min( p[j].y, p[k].y));
					int max_x = max(p[i].x, max( p[j].x, p[k].x));
					int max_y = max(p[i].y, max( p[j].y, p[k].y));
					for( int u = 0 ; u < m ; u++){
						if(b[u].x < min_x || b[u].x > max_x || b[u].y < min_y || b[u].y > max_y)
							continue;
						cont += inside_convex_poly( b[u], p[i], p[j], p[k]);
					}
					ans += cont*cont;
				}
		}
		cout << ans << '\n';
	}
	return 0;
}