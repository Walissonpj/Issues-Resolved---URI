#include<bits/stdc++.h>
using namespace std;
main()
{
	int t ;
	cin >> t ;
	while(t--)
	{
		int n ;
		cin >> n ;
		double v[n] ;
		double sum = 0.0 ;
		for(int i = 0 ; i < n ; i++)
		{
			cin >> v[i] ;
			sum += v[i] ;
		}
		double media = sum / (double)n ;
		int ans = 0 ;
		for(int i = 0 ; i < n ; i++)
		{
			if(v[i] > media)
			{
				ans++ ;
			}
		}
		double aux = 100.0*((double)ans / (double)n) ;
		cout << fixed << setprecision(3) << aux << "%\n" ;
	}
}