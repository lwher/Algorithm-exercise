#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
const int maxn=1000,maxm=100000,INF=1<<30;
int X[4]={-1,0,1,0},Y[4]={0,-1,0,1};
int tot,n,S,T,V[maxm],G[maxm],N[maxm],F[maxn],lay[maxn],cur[maxn],Q[maxn+100];
int c(int a,int b) {return (a-1)*n+b; }
void add(int a,int b,int c)
{
    ++tot;V[tot]=b;G[tot]=c;N[tot]=F[a];F[a]=tot;
    ++tot;V[tot]=a;G[tot]=0;N[tot]=F[b];F[b]=tot;
}
void bfs(int n)
{
    int hd=0,tl=1,p,u;
    memset(lay,127,sizeof(lay));
    Q[1]=T;lay[T]=0;
    while (hd!=tl)
    {
        u=Q[++hd];
        for (p=F[u];p;p=N[p])
          if (G[p^1]>0&&lay[V[p]]>=n)
          {
              lay[V[p]]=lay[u]+1;
              Q[++tl]=V[p];
              cur[V[p]]=p^1;
          }
    }
}
int dfs(int u,int f)
{
    if (u==T) return f;
    int l=f,tmp;
    for (int &p=cur[u];p;p=N[p])
      if (G[p]>0&&lay[u]==lay[V[p]]+1)
      {
          tmp=dfs(V[p],l< G[p]?l:G[p]);
          G[p]-=tmp;G[p^1]+=tmp;l-=tmp;
          if (l==0) return f;
      }
    return f-l;
}
int dinic(int n)
{
    int ret=0,i;
    bfs(n);
    while (lay[S]< n)
    {
        for (i=1;i<=T;i++) cur[i]=F[i];
        ret+=dfs(S,INF);
        bfs(n);
    }
    return ret;
}
int main()
{
    int i,j,k,t,tx,ty,ans=0;tot=1;
    scanf("%d",&n);
    S=n*n+1;T=S+1;
    for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
      {
          scanf("%d",&t);
          if ((i+j)%2) add(S,c(i,j),t);
          else add(c(i,j),T,t);
          ans+=t;
      }
    for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
        if ((i+j)%2)
          for (k=0;k<4;k++)
          {
            tx=i+X[k];ty=j+Y[k];
            if (tx>0&&ty>0&&tx<=n&&ty<=n) add(c(i,j),c(tx,ty),INF);
          }
    ans-=dinic(n*n+2);
    printf("%d\n",ans);
    system("pause");
    return 0;
}
