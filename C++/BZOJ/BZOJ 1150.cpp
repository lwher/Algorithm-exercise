#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
struct sth {int v,bh;}h[200010];
int n,m,tt,st,sz,ans,num[100010];
int next[100010],pre[100010],w[100010];
inline void swap(sth &a,sth &b){sth t=a;a=b;b=t;}
void read(int &x)
{
     char ch=getchar();
     while(!(ch>='0' && ch<='9'))  ch=getchar();
     x=0;
     while(ch>='0' && ch<='9')  {x=x*10+(ch-'0');ch=getchar();}
}
void uppush(int x)
{
    while(h[x].v<h[x/2].v)
    {
        w[h[x/2].bh]=x;
        swap(h[x],h[x/2]);
        x=x>>1;
    }
    w[h[x].bh]=x;
}
void Ins(int v,int bh) 
{
    sz++;h[sz].v=v;h[sz].bh=bh;
    w[bh]=sz;
    uppush(sz);
}
void downpush(int x)
{
    int to;
    while((x<<1)<=sz)
    {
        to=(x<<1);
        if(to<sz && h[to].v>h[to+1].v)  to++;
        if(h[x].v>h[to].v)
        {
            w[h[to].bh]=x;
            swap(h[to],h[x]);
            x=to;
        }
        else break;  
    }
    w[h[x].bh]=x;
}
inline void del(int x){h[x].v=INF;downpush(x);}
void init()
{
    int i;h[0].v=-1;
    read(n);read(m);//scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)  read(num[i]);//scanf("%d",&num[i]);
    for(i=2;i<=n;i++)  Ins(num[i]-num[i-1],i-1);
    for(i=1;i<n;i++)  {pre[i]=i-1;next[i]=i+1;}
    pre[1]=-1;next[n-1]=-1;
}
void solve()
{
    int i,a,b;sth k;
    for(i=1;i<=m;i++)
    {
        k=h[1];
        if(pre[k.bh]==-1)
        {
            ans+=k.v;
            del(1);del(w[next[k.bh]]);
            pre[next[next[k.bh]]]=-1;
        }  else
        if(next[k.bh]==-1)
        {
            ans+=k.v;
            del(1);del(w[pre[k.bh]]);
            next[pre[pre[k.bh]]]=-1;
        }  else
        {
            ans+=k.v;
            a=next[k.bh];b=pre[k.bh];
            pre[k.bh]=pre[b];next[pre[b]]=k.bh;
            next[k.bh]=next[a];pre[next[a]]=k.bh;
            h[1].v=h[w[a]].v+h[w[b]].v-h[1].v;
            downpush(1);
            del(w[a]);del(w[b]);
        }
    }
    printf("%d\n",ans);
}
int main()
{
    init();
    solve();
    system("pause");
    return 0;
}
