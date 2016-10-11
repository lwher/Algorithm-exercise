#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define eps 1e-6
using namespace std;
int n,m,s,t,dv[110],A[1010],B[1010];
int sz=1,to[5010],pre[5010],last[110];
int h[110],gap[110],dui[110],ans[110];
double v[5010];
bool mark[110];
inline void Ins(int a,int b,double c)
{
    sz++;to[sz]=b;v[sz]=c;pre[sz]=last[a];last[a]=sz;
    sz++;to[sz]=a;v[sz]=0;pre[sz]=last[b];last[b]=sz;
}
void bfs()
{
     memset(h,-1,sizeof(h));
     memset(gap,0,sizeof(gap));
     int tou=1,wei=1,i,now;
     dui[1]=t;h[t]=1;gap[1]=1;
     while(tou<=wei)
     {
         now=dui[tou];tou++;
         for(i=last[now];i;i=pre[i])
         if(h[to[i]]==-1)
         {
             h[to[i]]=h[now]+1;
             gap[h[to[i]]]++;
             dui[++wei]=to[i];
         }
     }
}
double dfs(int x,double F)
{
    if(x==t) return F;
    double used=0,w;
    for(int i=last[x];i;i=pre[i])
    if(v[i]>eps && h[x]-1==h[to[i]])
    {
        w=min(F-used,v[i]);
        w=dfs(to[i],w);
        v[i]-=w;v[i^1]+=w;used+=w;
        if(fabs(F-used)<eps) return F;
    }
    gap[h[x]]--;
    if(!gap[h[x]]) h[s]=t+2;
    gap[++h[x]]++;
    return used;
}
double SAP()
{
    double tmp=0;
    bfs();
    while(h[s]<t+2) tmp+=dfs(s,1e20);
    return tmp;
}
void build(double g)
{
    memset(last,0,sizeof(last));
    sz=1;s=n+1;t=s+1;
    for(int i=1;i<=n;i++)
    {
        Ins(s,i,m);
        Ins(i,t,m+2*g-dv[i]);
    }
    for(int i=1;i<=m;i++) {Ins(A[i],B[i],1);Ins(B[i],A[i],1);}
}
void dfs(int x)
{
    mark[x]=1;
    if(x!=s) ans[++ans[0]]=x;
    for(int i=last[x];i;i=pre[i]) 
       if(v[i]>eps && !mark[to[i]]) dfs(to[i]);
}
int main()
{
    int i,j,a,b;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
        dv[a]++;dv[b]++;
        A[i]=a;B[i]=b;
    }    
    if(m==0) printf("1\n1\n");
    else
    {        
        double l=1.0/n,r=m,mid,k;
        while(r-l>(1e-6))
        {
            mid=(l+r)*0.5;
            build(mid);
            k=SAP();
            k=((double)n*m-k)*0.5;
            if(k>eps) l=mid; 
            else r=mid;
        }
        build(l);SAP();
        dfs(s);
        sort(ans+1,ans+1+ans[0]);
        printf("%d\n",ans[0]);
        for(i=1;i<=ans[0];i++) printf("%d\n",ans[i]);
    }
    return 0;
}