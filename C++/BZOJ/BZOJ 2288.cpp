#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
struct sth
{
    int v,bh,absv;
}h[300010];
int n,m,tt,st,sz,shu[100010],ans,tot;
int num[100010],top;
int next[100010],pre[100010],w[100010];
void swap(sth &a,sth &b)
{
    sth t=a;a=b;b=t;
}
void uppush(int x)
{
    while(h[x].absv<h[x/2].absv)
    {
        w[h[x/2].bh]=x;
        swap(h[x],h[x/2]);
        x=x>>1;
    }
    w[h[x].bh]=x;
}
void Ins(int v,int bh) 
{
    sz++;h[sz].v=v;h[sz].bh=bh;h[sz].absv=abs(v);
    w[bh]=sz;
    uppush(sz);
}
void downpush(int x)
{
    int to;
    while((x<<1)<=sz)
    {
        to=(x<<1);
        if(to<sz && h[to].absv>h[to+1].absv)  to++;
        if(h[x].absv>h[to].absv)
        {
            w[h[to].bh]=x;
            swap(h[to],h[x]);
            x=to;
        }
        else break;  
    }
    w[h[x].bh]=x;
}
void del(int x)
{
    h[x].absv=INF;downpush(x);
}
void init()
{
    int i;h[0].absv=-1;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)  
    {
        scanf("%d",&shu[++tt]);
        if(shu[tt]==0) tt--;
    }
    num[++top]=shu[1];
    for(i=2;i<=tt;i++)
    {
        if((shu[i]>0 && shu[i-1]>0) || (shu[i-1]<0 && shu[i]<0))  num[top]+=shu[i];
        else  num[++top]=shu[i]; 
    }
    for(i=1;i<=top;i++)  if(num[i]>0)  {ans+=num[i];tot++;}
    if(num[top]<0)  top--;
    if(num[1]<0)  st=2; else st=1;
    for(i=st;i<=top;i++)  {next[i]=i+1;pre[i]=i-1;}
    pre[st]=-1;next[top]=-1;
}
void solve()
{
    int i,a,b,wei;sth k;
    for(i=st;i<=top;i++)  Ins(num[i],i);
    while(tot>m)
    {
        k=h[1];
        if(pre[k.bh]==-1)
        {
            if(k.v>0)  {ans-=k.v;del(1);}
            else  {del(1);tot++;}
            pre[next[k.bh]]=-1;
        }  else
        if(next[k.bh]==-1)
        {
            if(k.v>0)  {ans-=k.v;del(1);}
            else  {del(1);tot++;}
            next[pre[k.bh]]=-1;
        }  else
        {
            ans-=k.absv;
            a=next[k.bh];b=pre[k.bh];
            pre[k.bh]=pre[b];next[pre[b]]=k.bh;
            next[k.bh]=next[a];pre[next[a]]=k.bh;
            h[1].absv=h[w[a]].absv+h[w[b]].absv-h[1].absv;
            h[1].v+=h[w[a]].v+h[w[b]].v;
            downpush(1);
            del(w[a]);del(w[b]);
        }
        tot--;
    }
    printf("%d\n",ans);
}
int main()
{
    init();
    solve();
    return 0;
}