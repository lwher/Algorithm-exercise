#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,top,s[50][50],num[50][50],pipei[1610],col[1610],ans[2010];
int sz,to[30010],pre[30010],last[1610];
bool vis[1610],mark[1610],ok[2010];
char map[50][50];
void Ins(int a,int b)
{
    sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
bool find(int x)
{
    for(int i=last[x];i;i=pre[i])
    if(!vis[to[i]] && !mark[to[i]])
    {
        vis[to[i]]=1;
        if(!pipei[to[i]] || find(pipei[to[i]]))
        {
            pipei[x]=to[i];pipei[to[i]]=x;
            return 1;
        }
    }
    return 0;
}
int main()
{
    int i,j,k,qx,qy,x0,y0;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) 
    {
        scanf("%s",map[i]+1);
        for(j=1;j<=m;j++) 
        {
            if(map[i][j]=='.') qx=i,qy=j;
            if(map[i][j]=='X' || map[i][j]=='.') s[i][j]=1;
            else s[i][j]=0;
        }  
    }
    for(i=1;i<=n;i++) for(j=1;j<=m;j++) 
    {
        if((abs(i-qx)+abs(j-qy)+s[i][j]) & 1) 
        {
            num[i][j]=++top;
            if((i+j)&1) col[top]=1; else col[top]=0;
        }
    }
    for(i=1;i<=n;i++) for(j=1;j<=m;j++)
    {
        if(num[i][j] && num[i+1][j])
        {
            Ins(num[i][j],num[i+1][j]);
            Ins(num[i+1][j],num[i][j]);
        }
        if(num[i][j] && num[i][j+1])
        {
            Ins(num[i][j],num[i][j+1]);
            Ins(num[i][j+1],num[i][j]);
        }
    }
    for(i=1;i<=top;i++) if(col[i]==0) 
    {
        memset(vis,0,sizeof(vis));
        find(i);
    }
    x0=qx;y0=qy;
    scanf("%d",&k);
    for(i=1;i<=2*k;i++)
    {
        mark[j=num[x0][y0]]=1;
        if(pipei[j])
        {
            memset(vis,0,sizeof(vis));
            pipei[pipei[j]]=0;
            if(!find(pipei[j])) ok[i]=1;
        }
        scanf("%d%d",&x0,&y0);
    }
    for(i=1;i<=k;i++) if(ok[i*2-1] && ok[i*2]) ans[++ans[0]]=i;
    printf("%d\n",ans[0]);
    for(i=1;i<=ans[0];i++) printf("%d\n",ans[i]);
    return 0;
}