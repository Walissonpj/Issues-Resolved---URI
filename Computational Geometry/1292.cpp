#include <bits/stdc++.h>
using namespace std;
int main(){
	double k = sin(108*M_PI/180)/sin(63*M_PI/180);
	double l;
	while( cin >> l)
		cout << fixed << setprecision(10) << k*l << endl;
	return 0;
}