#include <bits/stdc++.h>
using namespace std ;
int main(){
	int n ;
	cin >> n ;
	while(n--){
		double qt, v ;
		cin >> qt >> v ;
		double r, R, h, new_v = v/qt ;
		cin >> r >> R >> h ;
		double l, ri ;
		l = 0.;
		ri = h ;
		bool f = false ;
		double new_h = 0.0 ;
		double V;
		double mid = h ;
		while( true ){
			V =  (M_PI * (r*r + r*R + R*R)) / 3.0 ;
			if(fabs( (mid * V) - new_v) < 10e-6){
				new_h += mid ;
				break ;
			}
			if( mid*V > new_v ){
				R = (R + r)/2.0 ;
				mid /= 2.0 ;
			}
			else{
				new_v -= mid*V ;
				new_h += mid ;
				R += (R - r) ;
				r = (R+r)/2.0 ;
			}
		}
		if( !f )
			cout << fixed << setprecision(2) << new_h << endl ;
	}
	return 0 ;
}