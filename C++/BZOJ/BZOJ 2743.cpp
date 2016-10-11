#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
struct sth
{
    int l,r,bh;
}xw[1000010];
int n,c,q,ans[1000010];
int last[1000010],pre[1000010],t[1000010];
int read()
{
    char ch=getchar();
    while(!(ch>='0' && ch<='9'))  ch=getchar();
    int x=0;
    while(ch>='0' && ch<='9')  {x=x*10+(ch-'0');ch=getchar();}
    return x;
}
void add(int x,int k)
{
     for(int i=x;i<=n;i+=(i & (-i)))  t[i]+=k; 
}
int ask(int x)
{
    int tmp=0;
    for(int i=x;i;i-=(i & (-i)))  tmp+=t[i];
    return tmp;
}
inline bool comp(sth a,sth b)
{
    return a.r<b.r;
}
int main()
{
    int i,x;
    n=read();c=read();q=read();//scanf("%d%d%d",&n,&c,&q);
    for(i=1;i<=n;i++)  
    {
       x=read();//scanf("%d",&x);
       pre[i]=last[x];last[x]=i;
    }
    for(i=1;i<=q;i++)  
    {
       xw[i].l=read();xw[i].r=read();//scanf("%d%d",&xw[i].l,&xw[i].r);
       xw[i].bh=i;
    }
    sort(xw+1,xw+1+q,comp);    
    int now=1;
    for(i=1;i<=n;i++)
    {
        add(pre[pre[i]]+1,1);add(pre[i]+1,-1);
        while(now<=q && xw[now].r==i)
        {
           ans[xw[now].bh]=ask(xw[now].l);
           now++;
        }
    }
    for(i=1;i<=q;i++)  printf("%d\n",ans[i]);
    return 0;
}