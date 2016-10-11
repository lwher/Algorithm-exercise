#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
int n,link[310],lx[310],ly[310],w[310][310],slack[310];
bool visx[310],visy[310];
bool find(int x)
{
     visx[x]=1;
     for(int i=1;i<=n;i++)
     {
         if(visy[i]) continue;
         int t=lx[x]+ly[i]-w[x][i];
         if(t==0)
         {
            visy[i]=1;
            if(link[i]==-1 || find(link[i]))
            {
                link[i]=x;
                return 1;
            }
         }
         else if(slack[i]>t) slack[i]=t;
     }
     return 0;
}
void KM()
{
     int i,j;
     memset(link,-1,sizeof(link));
     for(i=1;i<=n;i++) 
     {
         lx[i]=-INF;ly[i]=0;
         for(j=1;j<=n;j++)  if(w[i][j]>lx[i]) lx[i]=w[i][j];
     }
     for(i=1;i<=n;i++)
     {
         for(j=1;j<=n;j++)  slack[j]=INF;
         while(1)
         {
            memset(visx,0,sizeof(visx));
            memset(visy,0,sizeof(visy));
            if(find(i)) break;
            int d=INF;
            for(j=1;j<=n;j++)  if(!visy[j] && slack[j]<d)  d=slack[j];
            for(j=1;j<=n;j++)
            {
                if(visx[j])  lx[j]-=d;
                if(visy[j])  ly[j]+=d;
                slack[j]=INF;
            }
         }
     }
     int res=0;
     for(i=1;i<=n;i++)  res+=w[link[i]][i];
     printf("%d\n",res);
}
int main()
{
    int i,j;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++) for(j=1;j<=n;j++) scanf("%d",&w[i][j]);        
        KM();
    }
    system("pause");
    return 0;
}
