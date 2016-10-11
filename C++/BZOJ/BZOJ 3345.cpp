#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define INF 0x7fffffff
using namespace std;
int n,m,map[510][510],w[510];
int minc,ans=0x7fffffff;
bool mark[510],vis[510];
void prime(int &s,int &t)
{
     int i,j,k,nmax;
     memset(w,0,sizeof(w));
     memset(vis,0,sizeof(vis));
     for(i=0;i<n;i++)
     {
         nmax=-INF;k=-1;
         for(j=1;j<=n;j++)
         if(!vis[j] && !mark[j] && w[j]>nmax)
         {
             nmax=w[j];k=j;
         }
         if(k==-1)  break;
         vis[k]=1;
         s=t;t=k;
         for(j=1;j<=n;j++)
         {
             if(!vis[j] && !mark[j] && map[k][j])
             {
                 w[j]+=map[k][j];
             }
         }
     }
     minc=w[t];
}
int main()
{
    int i,j,a,b,c,s,t;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
    {
       scanf("%d%d%d",&a,&b,&c);
       map[a][b]+=c;map[b][a]+=c;
    }    
    for(i=1;i<n;i++)
    {
        s=-1;t=-1;
        prime(s,t);
        if(minc<ans)  ans=minc;
        mark[t]=1;
        for(j=1;j<=n;j++)
        {
            map[s][j]+=map[t][j];
            map[j][s]+=map[j][t];
        }
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}
