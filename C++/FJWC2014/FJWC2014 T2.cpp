#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define mod 10007
using namespace std;
int n,size[210],F[210],root,maxx,ans;
int sz,to[510],pre[510],last[210];
int f[210][210],g[2][210][210],ve[210];
bool map[210][210];
void Ins(int a,int b)
{
     sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
void dfs(int x,int fa)
{
     int i;
     size[x]=1;F[x]=0;
     for(i=1;i<=n;i++)
     {
         if(map[x][i] && i!=fa)
         {
              dfs(i,x);
              F[x]=max(F[x],size[i]);
              size[x]+=size[i];
         }
     }
     F[x]=max(F[x],n-size[x]);
}
void dp(int x,int fa)
{
     size[x]=1;
     int i=last[x],j,k;
     f[x][0]=1;f[x][1]=1;
     while(i>0)
     {
         if(to[i]!=fa)
         {
             dp(to[i],x);
             size[x]+=size[to[i]];
             for(j=size[x];j>=1;j--)  for(k=size[to[i]];k>=1;k--)
             {
                 if(j-k>=1)  f[x][j]=(f[x][j]+(f[to[i]][k]*f[x][j-k])%mod)%mod;
             }
         }
         i=pre[i];
     }
}
inline bool comp(int a,int b)
{
     return size[a]<size[b];
}
int main()
{
    int i,j,k,p,l,dd=0,T,a,b,q;
    scanf("%d",&T);
    while(T--)
    {
        memset(map,0,sizeof(map));
        scanf("%d",&n);
        for(i=1;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            map[a][b]=1;map[b][a]=1;
        }
        if(n<=2)  {printf("Case %d: 1\n",++dd);continue;}
        dfs(1,0);
        root=-1;F[n+1]=-1;maxx=0x7fffffff;
        for(i=1;i<=n;i++)  maxx=min(maxx,F[i]);
        memset(last,0,sizeof(last));sz=0;
        for(i=1;i<=n;i++)
        {
             for(j=1;j<=n;j++)
             {
                 if(i!=j && map[i][j])
                 {
                      if(F[i]==maxx && F[j]==maxx)
                      {
                           root=n+1;
                           Ins(root,i);
                      }
                      else  Ins(i,j);
                 }
             }
             if(root==-1 || F[root]>F[i]) root=i;
        }
        if(root==n+1)  {++n;ans=-1;}  else ans=0;
        memset(f,0,sizeof(f));
        dp(root,0);
        int m=0;
        i=last[root];
        while(i>0)
        {
            ve[++m]=to[i];i=pre[i];
        }
        sort(ve+1,ve+1+m,comp);
        memset(g,0,sizeof(g));
        for(i=1;i<=200;i++)  {g[0][i][0]=1;g[0][i][1]=1;}
        int sum=0,now,q=0;
        for(i=1;i<=m;i++)
        {
            now=ve[i];memset(g[q^1],0,sizeof(g[q^1]));
            for(j=1;j<=size[now];j++)
            {
                 if(i==1)  p=j;  else p=min(j,size[ve[i-1]]);
                 for(k=0;k<=j;k++)  for(l=0;l<=sum;l++)
                 g[q^1][j][k+l]=(g[q^1][j][k+l]+(g[q][p][l]*f[now][k])%mod)%mod;
            }
            sum+=size[now];q^=1;
            
        }
        ans++;
        for(i=1;i<=size[ve[m]];i++)
        for(j=i*2;j<=sum;j++)
        ans=(ans+g[q][i][j]-g[q][i-1][j])%mod;
        if(ans<0)  ans+=mod;
        printf("Case %d: %d\n",++dd,ans);
    }
    system("pause");
    return 0;
}
