#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
struct sth
{
    int num,v,s; // a:数据值 b:权值 s:访问频度 
}p[71];
int n,K,f[71][71][71],sum[71];
inline bool cmp(sth a,sth b)
{
    return a.v<b.v;
}
inline bool comp(sth a,sth b)
{
    return a.num<b.num;
}
int main()
{
    int i,j,k,u,l,tmp;
    scanf("%d%d",&n,&K);
    for(i=1;i<=n;i++) scanf("%d",&p[i].num);
    for(i=1;i<=n;i++) scanf("%d",&p[i].v);
    for(i=1;i<=n;i++) scanf("%d",&p[i].s);    
    sort(p+1,p+1+n,cmp);
    for(i=1;i<=n;i++) p[i].v=i;
    sort(p+1,p+1+n,comp);
    for(i=1;i<=n;i++) sum[i]=sum[i-1]+p[i].s;
    for(l=1;l<=n;l++) for(i=1;i<=n;i++)
    {
        j=i+l-1;
        if(j>n) continue;
        for(k=0;k<=n;k++)
        {
           tmp=INF;
           for(u=i;u<=j;u++) 
           {
               if(p[u].v>=k) tmp=min(tmp,f[i][u-1][p[u].v]+f[u+1][j][p[u].v]);
               tmp=min(tmp,f[i][u-1][k]+f[u+1][j][k]+K);
           }
           f[i][j][k]=tmp+sum[j]-sum[i-1];
        }
    }
    cout<<f[1][n][0]<<endl;
    return 0;
}