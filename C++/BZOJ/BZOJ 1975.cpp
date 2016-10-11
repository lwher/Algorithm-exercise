#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define INF 1e10
using namespace std;
struct sth {double d;int bh;}hp[2000010];
int n,m,tot,sum,A[200010],B[200010],dui[5010];
int sz,to[200010],pre[200010],last[5010];
double limt,v[200010],quan[200010],d[5010];
bool mark[5010];
void Ins(int a,int b,double c)
{
    sz++;to[sz]=b;v[sz]=c;pre[sz]=last[a];last[a]=sz;
}
void init()
{
    int i;hp[0].d=-INF;
    scanf("%d%d%lf",&n,&m,&limt);
    for(i=1;i<=m;i++)  
    {
        scanf("%d%d%lf",&A[i],&B[i],&quan[i]);
        Ins(B[i],A[i],quan[i]);
    }
}
void spfa()
{
    int i,now,tou=0,wei=1;
    for(i=1;i<=n;i++) d[i]=INF;      
    dui[1]=n;d[n]=0;mark[n]=1;
    while(tou!=wei)
    {
        tou++;if(tou>5000) tou=0;
        now=dui[tou];
        for(i=last[now];i;i=pre[i])
        {
            if(d[to[i]]>d[now]+v[i])
            {
                d[to[i]]=d[now]+v[i];
                if(!mark[to[i]])  
                {
                    mark[to[i]]=1;
                    wei++;if(wei>5000) wei=0;
                    dui[wei]=to[i];
                }
            }
        }
        mark[now]=0;
    }
}
void swap(sth &a,sth &b) {sth t=a;a=b;b=t;}
void upput(int x)
{
    while(hp[x].d<hp[x>>1].d)
    {
        swap(hp[x>>1],hp[x]);
        x=(x>>1);
    }
}
void downput(int x)
{
    while((x<<1)<=tot)
    {
        int p=(x<<1);
        if((p+1)<=tot && hp[p].d>hp[p+1].d)  p++;
        if(hp[p].d<hp[x].d)  {swap(hp[p],hp[x]);x=p;}
        else break;
    }
}
void Ins_heap(double x,int bh)
{
    if(x>limt) return;
    tot++;hp[tot].d=x;hp[tot].bh=bh;
    upput(tot);
}
void del(int x)
{
    if(tot==1) {tot--;return;}
    swap(hp[x],hp[tot]);
    tot--;
    downput(x);upput(x);
}
void A_star()
{ 
    Ins_heap(d[1],1);int a;double b;
    while(tot>0)
    {
        if(hp[1].d>limt)  break;
        a=hp[1].bh;b=hp[1].d;del(1);
        if(a==n)  {sum++;limt-=b;}  else
        for(int i=last[a];i;i=pre[i]) Ins_heap(b-d[a]+v[i]+d[to[i]],to[i]);
    }
}
void solve()
{   
    init();spfa();
    sz=0;memset(last,0,sizeof(last));
    for(int i=1;i<=m;i++)  Ins(A[i],B[i],quan[i]);   
    A_star();
    printf("%d\n",sum);
}
int main()
{
    solve();
    return 0;
}