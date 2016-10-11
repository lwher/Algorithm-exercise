#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define INF 100000000
using namespace std;
struct point
{
    int zb[2],key,id;
}p[1000010];
struct sth
{
    int x,y,t,id;
}cz[500010];
int n,m,ans,root,pmax[1000010][2],pmin[1000010][2],ls[1000010],rs[1000010],fa[1000010],pw[1000010];
bool mark[1000010];
inline bool comp(point a,point b)
{
    return a.key<b.key;
}
inline void updata(int x)
{
    for(int i=0;i<2;i++)
    {
        if(pmax[ls[x]][i]>pmax[x][i]) pmax[x][i]=pmax[ls[x]][i];
        if(pmax[rs[x]][i]>pmax[x][i]) pmax[x][i]=pmax[rs[x]][i];
        if(pmin[ls[x]][i]<pmin[x][i]) pmin[x][i]=pmin[ls[x]][i];
        if(pmin[rs[x]][i]<pmin[x][i]) pmin[x][i]=pmin[rs[x]][i];
    }
}
int build(int l,int r,int w)
{
    if(l>r) return 0;
    int i,x=(l+r)>>1;
    for(i=l;i<=r;i++) p[i].key=p[i].zb[w];
    sort(p+l,p+r+1,comp);
    for(i=0;i<2;i++) if(!mark[p[x].id]) pmax[x][i]=p[x].zb[i],pmin[x][i]=p[x].zb[i];
    else pmax[x][i]=-INF,pmin[x][i]=INF;
    ls[x]=build(l,x-1,w^1);rs[x]=build(x+1,r,w^1);
    if(ls[x]) fa[ls[x]]=x; if(rs[x]) fa[rs[x]]=x;
    updata(x);pw[p[x].id]=x;
    return x;
}
void query(int x,int w)
{
     if(x==0) return;
     int i,d=0;
     if(!mark[p[x].id])
     {
        for(i=0;i<2;i++) d+=abs(p[0].zb[i]-p[x].zb[i]);
        if(d<ans) ans=d;
     }
     if(p[0].zb[w]<=p[x].zb[w]) 
     {
         query(ls[x],w^1);
         if(pmin[rs[x]][w^1]>p[0].zb[w^1]) d=pmin[rs[x]][w^1]-p[0].zb[w^1]; else
         if(pmax[rs[x]][w^1]<p[0].zb[w^1]) d=p[0].zb[w^1]-pmax[rs[x]][w^1]; else
         d=0;
         if(pmin[rs[x]][w]-p[0].zb[w]+d<ans) query(rs[x],w^1);
     }
     else
     {
         query(rs[x],w^1);
         if(pmin[ls[x]][w^1]>p[0].zb[w^1]) d=pmin[ls[x]][w^1]-p[0].zb[w^1]; else
         if(pmax[ls[x]][w^1]<p[0].zb[w^1]) d=p[0].zb[w^1]-pmax[ls[x]][w^1]; else
         d=0;
         if(p[0].zb[w]-pmax[ls[x]][w]+d<ans) query(ls[x],w^1);
     }
}
int main()
{
    int i,j,k;
    for(i=0;i<2;i++) pmin[0][i]=INF,pmax[0][i]=-INF;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) {scanf("%d%d",&p[i].zb[0],&p[i].zb[1]);p[i].id=i;}
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&cz[i].t,&cz[i].x,&cz[i].y);
        if(cz[i].t==1) 
        {
            cz[i].id=++n;mark[n]=1;
            p[n].zb[0]=cz[i].x;p[n].zb[1]=cz[i].y;p[n].id=n;
        } 
    }
    root=build(1,n,0);    
    for(i=1;i<=m;i++)
    {
        if(cz[i].t==1)
        {
            k=pw[cz[i].id];mark[cz[i].id]=0;
            for(j=0;j<2;j++) 
            {
                if(p[k].zb[j]<pmin[k][j]) pmin[k][j]=p[k].zb[j];
                if(p[k].zb[j]>pmax[k][j]) pmax[k][j]=p[k].zb[j];
            }
            for(j=fa[k];j;j=fa[j]) updata(j);
        }
        else
        {
            ans=INF;
            p[0].zb[0]=cz[i].x;p[0].zb[1]=cz[i].y;
            query(root,0);
            printf("%d\n",ans);
        }
    }
    system("pause");
    return 0;
}
