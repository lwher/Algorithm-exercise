#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int n,m,ans;
int sz,to[2000010],pre[2000010],last[10010];
void Ins(int a,int b)
{
     sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
bool vis[10010];
int col[10010],p[10010],out[10010],hash[10010];
int main()
{
    int i,j,k,a,b,maxx;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
        Ins(a,b);Ins(b,a);
    }    
    for(i=n;i>=1;i--)
    {
        maxx=-1;
        for(j=1;j<=n;j++)
        if(!vis[j] && out[j]>maxx)  
        {k=j;maxx=out[j];}
        vis[k]=1;p[i]=k;
        j=last[k];
        while(j>0)
        {
           if(!vis[to[j]])  out[to[j]]++;
           j=pre[j];
        }
    }
    for(i=n;i>=1;i--)
    {
        k=p[i];j=last[k];
        while(j>0)
        {
           if(col[to[j]])   hash[col[to[j]]]=i;
           j=pre[j];
        }
        j=1;  while(hash[j]==i)  j++;
        col[k]=j;
        if(j>ans)  ans=j;
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}
