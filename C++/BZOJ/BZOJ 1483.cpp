#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int n,m,ans,last[1000010],pre[100010],sum[1000010],col[100010],st[1000010],bh[1000010];
void swap(int &a,int &b)
{
    int t=a;a=b;b=t;
}
void solve(int x,int y)
{
    int i;
    for(i=last[x];i;i=pre[i])
    {
        if(col[i+1]==y)  ans--;
        if(col[i-1]==y)  ans--;
    }
    for(i=last[x];i;i=pre[i])  col[i]=y;
    pre[st[x]]=last[y];last[y]=last[x];sum[y]+=sum[x];
    last[x]=0;st[x]=0;sum[x]=0;
}
int main()
{
    int i,x,y,k;
    scanf("%d%d",&n,&m);
    col[0]=-1000;col[n+1]=-1000;
    for(i=1;i<=1000000;i++)  bh[i]=i;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&col[i]);
        if(col[i]!=col[i-1])  ans++;
        if(last[col[i]]==0)  st[col[i]]=i;
        sum[col[i]]++;pre[i]=last[col[i]];last[col[i]]=i;
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d",&k);
        if(k==2)  printf("%d\n",ans);
        else
        {
            scanf("%d%d",&x,&y);
            if(x==y)  continue;
            if(sum[bh[x]]>sum[bh[y]])  swap(bh[x],bh[y]);
            x=bh[x];y=bh[y];
            if(sum[x]==0 || sum[y]==0)  continue;
            if(sum[x]>sum[y]) swap(x,y);
            solve(x,y);
        }
    }
    return 0;
}