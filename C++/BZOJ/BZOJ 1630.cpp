#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
#define mod 1000000
#define MAXt 1005
#define MAXn 105
#define rep(i,j,k) for( i = j ; i <= k ; ++i )
int S,T,A,B,end,ans,f[2][MAXt*MAXn],cnt[MAXt],pre[MAXt*MAXn];
inline void plu ( int &a , int b )
{
        a += b ;
        if( a > mod ) a -= mod ;        
}
int main()
{
        int i,j,a;
        scanf("%d%d%d%d",&T,&A,&S,&B);
        rep(i,1,A)
        {
                scanf("%d",&a);
                ++cnt[a]        ;
        }
        rep(i,0,cnt[1]) 
                f[1][i] = 1 ;
        end = cnt[1] ;
        rep(i,2,T) 
        {
                memset(f[i&1],0,sizeof(f[0]));
                pre[0] = 1 ;
                end += cnt[i] ; 
                rep(j,1,end)
                        pre[j] = ( pre[j-1] + f[(i-1)&1][j] ) % mod ;
                rep(j,1,end)
                {
                        f[i&1][j] = ( f[(i-1)&1][j] + pre[j-1] ) % mod ;
                        if( j - cnt[i] > 0 ) 
                                f[i&1][j] = ( f[i&1][j] - pre[j-cnt[i]-1] ) % mod ;
                }
        }
        rep(i,S,B)
                plu(ans,f[T&1][i]);
        ans %= mod;
        if( ans < 0 ) ans += mod ;
        printf("%d\n",ans);
        system("pause");
        return 0;
}
  
