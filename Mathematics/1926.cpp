#include<bits/stdc++.h>
using namespace std;
  
const unsigned MXX = 1000000, MAX_S = sqrt(MXX/60);
unsigned w[16] = {1, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 49, 53, 59};
unsigned short composite[MXX];
vector<int> primes;
bool isp[1000005];
void sieve() {
    unsigned mod[16][16], di[16][16], num;
    for(int i = 0; i < 16; i++)
        for(int j = 0; j < 16; j++) {
            di[i][j] = (w[i]*w[j])/60;
            mod[i][j] = lower_bound(w, w + 16, (w[i]*w[j])%60) - w;
        }
  
    primes.push_back(2);
    primes.push_back(3);
    primes.push_back(5);
    isp[2] = 1;
    isp[3] = 1;
    isp[5] = 1;
    bool ok = 0;
    memset(composite, 0, sizeof composite);
    for(unsigned i = 0; i < MXX; i++)
        for(int j = (i==0); j < 16; j++) {
            if(composite[i] & (1<<j)) continue;
            num = 60*i + w[j];
            if(num > 1000000)
            {
                ok = 1 ;
                break;
            }
  
            primes.push_back( num );
            isp[num]= 1;
            if(!ok)
            {
                if(i > MAX_S) 
                        continue;
                for(unsigned k = i, done = false; !done; k++)
                        for(int l = (k==0); l < 16 && !done; l++) {
                                unsigned mult = k*num + i*w[l] + di[j][l];
                                if(mult >= MXX) 
                                        done = true ;
                                else
                                        composite[mult] |= 1<<mod[j][l] ;
                        }
                }
        }
}
int v[1000005];
void init()
{
    v[2] = 0 ;
    v[3] = 1 ;
    for(int i = 4; i <= 1000000; i++)
    {
        v[i] = v[i-1] ;
        if( isp[i] && ( isp[i+2]||isp[i-2] ) )
            v[i]++;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ;
    sieve();
    init();
    int n;
    scanf("%d", &n) ;
    for(int i = 0; i < n; i++)
    {
        int a,b;
        scanf("%d%d", &a, &b) ;
        int ma = max(a,b) ;
        int mi = min(a,b) ;
        printf("%d\n", v[ma]-v[mi - 1] ) ;
    }
    return 0 ;
}