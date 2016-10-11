#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int n,p,tt,top;
int t[200010];
int sz,to[200010],last[100010],pre[200010];
int sum[200010],bh[200010],ft[100010],sd[100010],z[100010];
bool mark[100010];
void Ins(int a,int b)
{
     sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
void dfs()
{
     memset(mark,0,sizeof(mark));
     top=1;z[1]=p;
     int x,i,g;
     while(top>0)
     {
         x=z[top];i=last[x];
         if(!mark[x])  {tt++;ft[x]=tt;bh[tt]=x;mark[x]=1;}
         if(i>0){
             g=to[i];
             if(!mark[g]) {top++;z[top]=g;}
             last[x]=pre[i];
         }
         else{
             top--;tt++;sd[x]=tt;bh[tt]=x;
         }
     }
}
void add(int x)
{
     while(x<=n)
     {
          t[x]++;
          x+=x & (-x);
     }
}
int ask(int x)
{
    int now=0;
    while(x>0)
    {
         now+=t[x];
         x-=x & (-x);
    }
    return now;
}
void init()
{
     int i,a,b;
     memset(t,0,sizeof(t));
     sz=0;tt=0;
     memset(last,0,sizeof(last));
     memset(sum,0,sizeof(sum));
     for(i=1;i<n;i++)
     {
         scanf("%d%d",&a,&b);
         Ins(a,b);Ins(b,a);
     }
     dfs();n*=2;
}
void solve()
{
     int i;
     for(i=1;i<=n;i++)
     {
        sum[i]=ask(bh[i]-1);
        add(bh[i]);
     }
     n/=2;
     for(i=1;i<n;i++)
     {
        printf("%d ",(sum[sd[i]]-sum[ft[i]])/2);
     }
     printf("%d\n",(sum[sd[n]]-sum[ft[n]])/2);
     
}
int main()
{
    while(scanf("%d%d",&n,&p))
    {
        if(n==0 && p==0)  break;
        init();
        solve();
    }
    system("pause");
    return 0;
}
