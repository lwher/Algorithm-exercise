#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define MAXn 10005
#define MAXm 10005
struct queue
{
        int x,y;        
}q[MAXm];
int f[MAXn],n,I,H,m,cnt;
inline bool cmp ( queue a , queue b )
{
        return ( a.x < b.x ) || ( a.x == b.x && a.y < b.y ) ;
}
int main()
{
        int i,a,b,j;
        scanf("%d%d%d%d",&n,&I,&H,&m);
        for( i = 1 ; i <= m ; ++i )
        {
                scanf("%d%d",&q[i].x,&q[i].y);
                if( q[i].x > q[i].y ) swap(q[i].x,q[i].y);
        }               
        sort(q+1,q+1+m,cmp);
        for( i = 1 ; i <= m ; )
        {
                -- f[q[i].x+1] ; ++f[q[i].y];
                for( j = i ; q[j].x == q[i].x && q[j].y == q[i].y && i <= m ; ++i ) ;
        }
        for( i = 1 ; i <= n ; ++i )
        {
                cnt += f[i];
                printf("%d\n",cnt + H); 
        }
        system("pause");
        return 0;
}
 
