#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int t[1000000];
int n,m,sz,tt;
int to[200010],pre[200010],last[100010];
bool mark[100010];
int ft[100010],sd[100010];
void Ins(int a,int b)
{
     sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
     sz++;to[sz]=a;pre[sz]=last[b];last[b]=sz;
}
void dfs(int x)
{
     int i;
     mark[x]=1;
     i=last[x];
     tt++;
     ft[x]=tt;
     while(i>0)
     {
         if(!mark[to[i]])  dfs(to[i]);
         i=pre[i];
     }
     tt++;
     sd[x]=tt;
}
void change(int l,int r,int k,int x)
{
     if(l==r) {t[k]^=1;return;}
     int mid=(l+r)>>1;
     if(x<=mid)  change(l,mid,k+k,x);
     else        change(mid+1,r,k+k+1,x);
     t[k]=t[k+k]+t[k+k+1];
}
int ask(int l,int r,int k,int zuo,int you)
{
    if(l>=zuo && r<=you)  return t[k];
    int mid=(l+r)>>1,aa=0,bb=0;
    if(zuo<=mid)   aa=ask(l,mid,k+k,zuo,you);
    if(you>mid)    bb=ask(mid+1,r,k+k+1,zuo,you);
    return aa+bb;
}
void solve()
{
     int i,a,b,xx;
     char ch[2];
     scanf("%d",&n);
     for(i=1;i<=n-1;i++)
     {scanf("%d%d",&a,&b);Ins(a,b);}
     dfs(1);
     n*=2;
     for(i=1;i<=n;i++)  change(1,n,1,i);
     scanf("%d",&m);
     for(i=1;i<=m;i++)
     {
          scanf("%s",ch);
          scanf("%d",&xx);
          if(ch[0]=='C')
          {change(1,n,1,ft[xx]);change(1,n,1,sd[xx]);}
          else
          {printf("%d\n",ask(1,n,1,ft[xx],sd[xx])/2);}
     }
     
}
int main()
{
    solve();
    system("pause");
    return 0;
}
