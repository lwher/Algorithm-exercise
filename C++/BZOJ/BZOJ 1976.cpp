#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define INF 0x7fffffff
#define inf 100000000
using namespace std;
int n,s,t,kind[50][50][50],ans;
char ch[50];
int sz=1,to[3000010],pre[3000010],v[3000010],last[65000],cur[65000];
int dui[65000],h[65000],gap[65000];
int dx[6]={1,-1,0,0,0,0};
int dy[6]={0,0,1,-1,0,0};
int dz[6]={0,0,0,0,1,-1};
void Ins(int a,int b,int c)
{
     sz++;to[sz]=b;v[sz]=c;pre[sz]=last[a];last[a]=sz;
     sz++;to[sz]=a;v[sz]=0;pre[sz]=last[b];last[b]=sz;
}
void bfs()
{
     memset(h,-1,sizeof(h));
     int tou=1,wei=1,now,i;
     dui[1]=t;h[t]=1;gap[1]=1;
     while(tou<=wei)
     {
         now=dui[tou];tou++;
         for(i=last[now];i;i=pre[i])
         if(h[to[i]]==-1)
         {
              h[to[i]]=h[now]+1;
              gap[h[to[i]]]++;
              dui[++wei]=to[i];
         }
     }
}
int dfs(int x,int F)
{
    if(x==t) return F;
    int used=0,w,i;
    for(i=cur[x];i;i=pre[i])
    if(v[i]>0 && h[x]-1==h[to[i]])
    {
        w=min(v[i],F-used);
        w=dfs(to[i],w);
        v[i]-=w; 
        if(v[i]>0)  cur[x]=i;
        v[i^1]+=w;
        used+=w; 
        if(F==used)  return F;
    }
    gap[h[x]]--;
    if(!gap[h[x]])  h[s]=t+2;
    gap[++h[x]]++;
    cur[x]=last[x];
    return used;
}
int sap()
{
    int tmp=0;
    for(int i=1;i<=t;i++)   cur[i]=last[i];
    bfs();
    while(h[s]<t+2)  tmp+=dfs(s,INF);
    return tmp;
}
int P(int x,int y,int z)
{
    return (x-1)*n*n+(y-1)*n+z;
}
void init()
{
     int i,j,k,l,nx,ny,nz;
     scanf("%d",&n);
     s=n*n*n+1;t=s+1;
     for(i=1;i<=n;i++)
     {
         for(j=1;j<=n;j++)
         {
             scanf("%s",ch+1);
             for(k=1;k<=n;k++)
             {
                 if(ch[k]=='?')   kind[i][j][k]=0;
                 if(ch[k]=='P')   kind[i][j][k]=1;
                 if(ch[k]=='N')   kind[i][j][k]=-1;
             }
         }
     }
     for(i=1;i<=n;i++)  for(j=1;j<=n;j++)  for(k=1;k<=n;k++)
     {
          for(l=0;l<6;l++)
          {
              nx=i+dx[l];ny=j+dy[l];nz=k+dz[l];
              if(nx<1 || ny<1 || nz<1 || nx>n || ny>n || nz>n)  continue;
              Ins(P(i,j,k),P(nx,ny,nz),1);
              ans++;
          }
          if(kind[i][j][k]!=0)
          {
              if(kind[i][j][k]==1)  
              {
                 if((i+j+k) & 1) Ins(s,P(i,j,k),inf);
                 else  Ins(P(i,j,k),t,inf);
              }
              else  
              {
                 if((i+j+k) & 1) Ins(P(i,j,k),t,inf);
                 else  Ins(s,P(i,j,k),inf);
              }
          }
     }
}
int main()
{
    init();
    ans>>=1;
    printf("%d\n",ans-sap());
    system("pause");
    return 0;
}
