#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t ;
	while(t--)
	{
		string a, b ;
		cin >> a >> b ;
		if( a.size() >= b.size() )
		{
			int j = a.size()-1, i = b.size()-1 ;
			for( ; i >= 0 ; i--, j--)
			{
				if(a[j] != b[i])
					break ;
			}
			if( i < 0)
				cout << "encaixa\n" ;
			else
				cout << "nao encaixa\n" ; 
		}
		else
			cout << "nao encaixa\n" ;
	}
	return 0;
}