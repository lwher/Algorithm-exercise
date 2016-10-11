#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int n,sz,m,tt;
int to[100010],pre[100010],last[100010];
int ft[100010],sd[100010],t[600010];
bool mark[600010];
void Ins(int a,int b)
{
     sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
void build()
{
     int i,fa;
     for(i=2;i<=n;i++)
     {
        scanf("%d",&fa);Ins(fa,i);
     }
}
void dfs(int x)
{
     int i=last[x];
     tt++;ft[x]=tt;
     while(i>0)
     {
         dfs(to[i]);
         i=pre[i];
     }
     tt++;sd[x]=tt;
}
void downgo(int l,int r,int k)
{
     int mid=(l+r)>>1;
     mark[k]^=1;mark[k<<1]^=1;mark[k+k+1]^=1;
     t[k<<1]=mid-l+1-t[k<<1];
     t[k+k+1]=r-mid-t[k+1+k];
}
void change(int l,int r,int k,int zuo,int you)
{
     if(l==r)  {t[k]^=1;return;}
     if(l>=zuo && r<=you)  {mark[k]^=1;t[k]=r-l+1-t[k];return;}
     int mid=(l+r)>>1;
     if(mark[k]) downgo(l,r,k);
     if(zuo<=mid)change(l,mid,k+k,zuo,you);
     if(you>mid) change(mid+1,r,k+k+1,zuo,you);
     t[k]=t[k+k]+t[k+k+1];
}
int ask(int l,int r,int k,int zuo,int you)
{
    int mid=(l+r)>>1,a=0,b=0;
    if(l>=zuo && r<=you)   return t[k];
    if(mark[k])  downgo(l,r,k);
    if(zuo<=mid)  a=ask(l,mid,k+k,zuo,you);
    if(you>mid)   b=ask(mid+1,r,k+k+1,zuo,you);
    return a+b;
}
void solve()
{
     int i,x;
     char ch[2];
     n*=2;
     for(i=1;i<=m;i++)
     {
        scanf("%s%d",ch,&x);
        if(ch[0]=='o')  change(1,n,1,ft[x],sd[x]);
        else
        printf("%d\n",ask(1,n,1,ft[x],sd[x])/2);
     }
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
         sz=0;tt=0;
         memset(last,0,sizeof(last));
         memset(t,0,sizeof(t));
         memset(ft,0,sizeof(ft));
         memset(sd,0,sizeof(sd));
         memset(mark,0,sizeof(mark));
         build();
         dfs(1);
         solve();
         cout<<endl;
    }
    system("pause");
    return 0;
}
