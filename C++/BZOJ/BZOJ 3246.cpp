#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,L,ans;
int sz,to[200010],pre[200010],v[200010],last[100010];
int d[100010],maxx[100010],cnt,far[100010],zj[100010],stack[100010],f[100010];
int zd,cd,sd;
bool mark[100010];
void Ins(int a,int b,int c)
{
     sz++;to[sz]=b;pre[sz]=last[a];v[sz]=c;last[a]=sz;
}
void dfs(int x,int fa)
{
     int i=last[x];
     if(d[x]>d[maxx[cnt]])  maxx[cnt]=x;
     mark[x]=1;
     while(i>0)
     {
         if(to[i]!=fa)
         {
             d[to[i]]=d[x]+v[i];
             dfs(to[i],x);
         }
         i=pre[i];
     }
}
void dfsfind(int x,int dep,int fa)
{
     int i;
     if(d[x]==zj[cnt])
     {
        for(i=1;i<=dep;i++)
        {
           f[i]=max(stack[i],zj[cnt]-stack[i]);
           far[cnt]=min(far[cnt],f[i]);
        }
     }
     i=last[x];
     while(i>0)
     {
        if(to[i]!=fa)
        {
            d[to[i]]=d[x]+v[i];
            stack[dep+1]=d[to[i]];
            dfsfind(to[i],dep+1,x);
        }
        i=pre[i];
     }
}
void checkmax(int x)
{
     if(zd<x)  {sd=cd;cd=zd;zd=x;}
     else 
     if(cd<x)  {sd=cd;cd=x;}
     else
     if(sd<x)  sd=x;
}
int main()
{
    int i,a,b,c;
    scanf("%d%d%d",&n,&m,&L);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        a++;b++;
        Ins(a,b,c);Ins(b,a,c);
    }
    for(i=1;i<=n;i++)
    if(!mark[i])
    {
        cnt++;maxx[cnt]=i;
        d[i]=0;dfs(i,0);
        d[maxx[cnt]]=0;dfs(maxx[cnt],0);
        zj[cnt]=d[maxx[cnt]];far[cnt]=zj[cnt];
        d[maxx[cnt]]=0;dfsfind(maxx[cnt],0,0);
    }
    ans=0;
    if(cnt==1)  ans=zj[cnt];
    else 
    if(cnt==2)
    {
        ans=max(zj[1],zj[2]);
        ans=max(ans,far[1]+far[2]+L);
    }
    else
    {
        zd=0;cd=0;sd=0;
        for(i=1;i<=cnt;i++)
        {
            ans=max(ans,zj[i]);
            checkmax(far[i]);
        }
        ans=max(ans,max(zd+cd+L,cd+sd+L*2));
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}
