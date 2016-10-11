#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int n,m,s;
int sz,to[300010],pre[300010],v[300010],last[100010];
long long d[100010];
int cs[100010],dui[1000010];
bool mark[100010];
void Ins(int a,int b,int c)
{
    sz++;to[sz]=b;pre[sz]=last[a];v[sz]=c;last[a]=sz;
}
int next(int x)
{
    x++; if(x==1000000)  x=0;  return x;
}
bool spfa()
{
    int tou=0,wei=1,now,i;
    dui[1]=s;mark[s]=1;d[s]=1;cs[s]=1;
    while(tou!=wei)
    {
        tou=next(tou);now=dui[tou];
        i=last[now];
        while(i>0)
        {
            if(d[now]+v[i]>d[to[i]])
            {
                d[to[i]]=d[now]+v[i];
                cs[to[i]]++; if(cs[to[i]]==n) return 0;
                if(!mark[to[i]])
                {
                    mark[to[i]]=1;wei=next(wei);dui[wei]=to[i];
                }
            }
            i=pre[i];
        }
        mark[now]=0;
    }
    return 1;
}
void solve()
{
    int i,a,b,k,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&k,&a,&b);
        if(k==1)  {Ins(a,b,0);Ins(b,a,0);}
        if(k==2)  {Ins(a,b,1);if(a==b)  {printf("-1\n");return;}}
        if(k==3)  {Ins(b,a,0);}
        if(k==4)  {Ins(b,a,1);if(a==b)  {printf("-1\n");return;}}  
        if(k==5)  {Ins(a,b,0);}
    }
    s=n+1;
    for(i=n;i>=1;i--)  Ins(s,i,0);
    if(!spfa())  {printf("-1\n");return;}
    long long ans=0;
    for(i=1;i<=n;i++)  ans+=d[i];
    cout<<ans<<endl;
}
int main()
{
    solve();
    //system("pause");
    return 0;
}