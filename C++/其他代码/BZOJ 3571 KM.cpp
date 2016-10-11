#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct point
{
    int x,y;
};
int n,A[71][71],B[71][71],ans,Link[71];
long long w[71][71],lx[71],ly[71],slack[71];;
bool visx[71],visy[71];
void init()
{
     int i,j;
     scanf("%d",&n);
     for(i=1;i<=n;i++) for(j=1;j<=n;j++) scanf("%d",&A[i][j]);
     for(i=1;i<=n;i++) for(j=1;j<=n;j++) scanf("%d",&B[i][j]);
}
bool find(int x)
{
     visx[x]=1;
     for(int y=1;y<=n;y++)
     {
         if(visy[y])  continue;
         long long t=lx[x]+ly[y]-w[x][y];
         if(t==0)
         {
             visy[y]=1;
             if(Link[y]==0 || find(Link[y]))
             {
                Link[y]=x;
                return 1;
             }
         }
         else if(t<slack[y]) slack[y]=t;
     }
     return 0;
}
point KM()
{
    memset(Link,0,sizeof(Link));
    int x,i,j;
    for(x=1;x<=n;x++)
    {
        lx[x]=-1e30;ly[x]=0;
        for(i=1;i<=n;i++) if(w[x][i]>lx[x]) lx[x]=w[x][i];
    }
    for(x=1;x<=n;x++)
    {
        for(i=1;i<=n;i++) slack[i]=1e30;
        while(1)
        {
            memset(visx,0,sizeof(visx));
            memset(visy,0,sizeof(visy));
            if(find(x))  break;
            long long d=1e30;
            for(i=1;i<=n;i++)  if(!visy[i] && slack[i]<d) d=slack[i];  
            for(i=1;i<=n;i++)
            {
                if(visx[i]) lx[i]-=d;
                if(visy[i]) ly[i]+=d;
                slack[i]=1e30;
            }
        }
    }
    point now;
    now.x=now.y=0;
    for(i=1;i<=n;i++)  
    {
        now.x+=A[Link[i]][i];
        now.y+=B[Link[i]][i];
    }  
    if(now.x*now.y<ans)  ans=now.x*now.y;
    return now;
}
void work(point l,point r)
{
    long long a=r.y-l.y,b=l.x-r.x,c=-(a*l.x+b*l.y);
    for(int i=1;i<=n;i++)  for(int j=1;j<=n;j++)  w[i][j]=a*A[i][j]+b*B[i][j];
    point mid=KM();
    if(a*mid.x+b*mid.y+c<=0) return;
    work(l,mid);work(mid,r);
}
void solve()
{
     int i,j;point l,r;ans=1<<30;     
     for(i=1;i<=n;i++)  for(j=1;j<=n;j++)  w[i][j]=-A[i][j];
     l=KM();
     for(i=1;i<=n;i++)  for(j=1;j<=n;j++)  w[i][j]=-B[i][j];
     r=KM();
     work(l,r);
     printf("%d\n",ans);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        init();
        solve();
    }
    return 0;
}