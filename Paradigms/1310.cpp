#include<bits/stdc++.h>
using namespace std ;
int v[1000] ;
int n ;
int custo ;
int kadane()
{
	    int max_total;
		int max_atual;
		int xtemp;
		int i;
		max_atual = 0;
		max_total = -1;
		for(i=0;i<n;i++)
		{
			max_atual = max_atual + v[i] - custo;
			if(max_atual < 0) 
			{ 
				max_atual = 0 ;
			}
			if(max_atual > max_total)
			{
				max_total = max_atual;
			} 
		}
	return max_total ;
}
int main()
{
	 while( cin >> n )
	 {
		  cin >> custo ;
		  for( int i = 0 ; i < n ; i++ )
				cin >> v[i] ;
		  
		  cout << kadane() << '\n' ;
	 }
	 return 0 ;
}