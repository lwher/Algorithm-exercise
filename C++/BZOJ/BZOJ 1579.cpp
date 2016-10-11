#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
struct sth
{
    int ft,sd,v;
}heap[500010];
int n,m,K;
int sz,to[100010],pre[100010],v[100010],last[10010];
int w[10010][21],hsz,d[10010][21];
bool mark[10010][21];
void Ins(int a,int b,int c)
{
    sz++;to[sz]=b;pre[sz]=last[a];v[sz]=c;last[a]=sz;
}
void swap(sth &a,sth &b)
{
    sth t=a;a=b;b=t;
}
void upput(int x)
{
    while(heap[x].v<heap[x/2].v)
    {
        if(x==1) break;
        swap(heap[x],heap[x/2]);
        w[heap[x].ft][heap[x].sd]=x;
        x/=2;
    }
    w[heap[x].ft][heap[x].sd]=x;
}
void downput(int x)
{
    while(x+x<=hsz)
    {
        if(heap[x+x].v<heap[x].v && (x+x+1>hsz || heap[x+x].v<heap[x+x+1].v))  
        {
            swap(heap[x],heap[x+x]);
            w[heap[x].ft][heap[x].sd]=x;
            x=x+x;
        }else
        if(x+x+1<=hsz && heap[x+x+1].v<heap[x].v)
        {
            swap(heap[x],heap[x+x+1]);
            w[heap[x].ft][heap[x].sd]=x;
            x=x+x+1;
        }
        else break;
    }
    w[heap[x].ft][heap[x].sd]=x;
}
void charu(int ft,int sd,int v)
{
    hsz++;w[ft][sd]=hsz;
    heap[hsz].ft=ft;heap[hsz].sd=sd;heap[hsz].v=v;
    upput(hsz);
}
int main()
{
    int i,j,a,b,c,now,nk,tmp,k;
    scanf("%d%d%d",&n,&m,&K);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        Ins(a,b,c);Ins(b,a,c);
    }
    memset(d,127,sizeof(d));
    d[1][0]=0;
    charu(1,0,0);   
    n*=(K+1);
    for(i=1;i<n;i++)
    {
        now=heap[1].ft;nk=heap[1].sd;tmp=heap[1].v;
        mark[now][nk]=1;
        heap[1].v=INF;
        downput(1);
        for(j=last[now];j;j=pre[j])
        {
            if(!mark[to[j]][nk] && d[to[j]][nk]>d[now][nk]+v[j])
            {
                d[to[j]][nk]=d[now][nk]+v[j];
                if(w[to[j]][nk]==0)  charu(to[j],nk,d[to[j]][nk]);
                else {k=w[to[j]][nk];heap[k].v=d[to[j]][nk];upput(k);k=w[to[j]][nk];downput(k);}
            }
            if(nk<K && !mark[to[j]][nk+1] && d[to[j]][nk+1]>d[now][nk])
            {
                d[to[j]][nk+1]=d[now][nk];
                if(w[to[j]][nk+1]==0)  charu(to[j],nk+1,d[to[j]][nk+1]);
                else {k=w[to[j]][nk+1];heap[k].v=d[to[j]][nk+1];upput(k);k=w[to[j]][nk+1];downput(k);}
            }
        }
    }
    n/=(K+1);
    int ans=INF;
    for(i=0;i<=K;i++) ans=min(ans,d[n][i]);
    printf("%d\n",ans);
    return 0;
}