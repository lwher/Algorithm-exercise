#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct sth
{
       int x,y,z;
}d[1010];
bool map[1010][1010],vis[1010];
int pipei[1010];
inline bool comp(sth a,sth b)
{
       return a.x<b.x;
}
int n,now,ans=1;
int f[1010];
bool find(int x)
{
     int i;
     for(i=1;i<=n;i++)
     if(map[x][i] && !vis[i])
     {
          vis[i]=1;
          if(pipei[i]==0 || find(pipei[i]))
          {
             pipei[i]=x;
             return 1;
          }
     }
     return 0;
}
int main()
{
    int i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    scanf("%d%d%d",&d[i].x,&d[i].y,&d[i].z);
    sort(d+1,d+1+n,comp);
    for(i=1;i<=n;i++)
    {
      f[i]=1;
      for(j=1;j<i;j++)
      {
         if(d[j].x<d[i].x && d[j].y<d[i].y && d[j].z<d[i].z)
         {
             if(f[j]+1>f[i])
             f[i]=f[j]+1;
             if(f[i]>ans)   ans=f[i];
             map[i][j]=1;
         }
      }
    }
    for(i=1;i<=n;i++)
    {
      memset(vis,0,sizeof(vis));
      if(find(i))
      {now++;}
    }
    cout<<ans<<endl;
    cout<<n-now<<endl;
    system("pause");
    return 0;
}
