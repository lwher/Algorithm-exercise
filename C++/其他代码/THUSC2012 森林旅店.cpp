#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
struct point
{
    int zb[2],key;
}p[200010];
int n,Q,K,P,root,ls[200010],rs[200010];
int pmax[200010][2],pmin[200010][2];
long long ansd[5];
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
    for(i=0;i<2;i++) pmax[x][i]=p[x].zb[i],pmin[x][i]=p[x].zb[i];
    ls[x]=build(l,x-1,w^1);rs[x]=build(x+1,r,w^1);
    updata(x);
    return x;
}
void Ins(int &x,int w,int o)
{
    if(!x)
    {
        x=o;
        for(int i=0;i<2;i++) pmax[x][i]=p[o].zb[i],pmin[x][i]=p[o].zb[i];
        return; 
    }
    if(p[o].zb[w]<=p[x].zb[w]) Ins(ls[x],w^1,o);
    else  Ins(rs[x],w^1,o);
    updata(x);
}
inline long long sqr(long long x) {return x*x;}
inline long long dist(point a,point b)
{
     if(K==1) return abs(a.zb[0]-b.zb[0])+abs(a.zb[1]-b.zb[1]);
     else return sqr(a.zb[0]-b.zb[0])+sqr(a.zb[1]-b.zb[1]);
}
void query(int x,int w)
{
     if(x==0) return;
     int i,j;long long d,k;
     d=dist(p[x],p[0]);
     for(i=1;i<=P;i++) if(d<ansd[i]) break;
     for(j=P;j>i;j--) ansd[j]=ansd[j-1];
     ansd[i]=d;
     if(p[0].zb[w]<=p[x].zb[w])
     {
         query(ls[x],w^1);
         if(pmax[rs[x]][w^1]<p[0].zb[w^1]) 
         {
            if(K==1) d=p[0].zb[w^1]-pmax[rs[x]][w^1];
            else d=sqr(p[0].zb[w^1]-pmax[rs[x]][w^1]);
         } else
         if(pmin[rs[x]][w^1]>p[0].zb[w^1])
         {
            if(K==1) d=pmin[rs[x]][w^1]-p[0].zb[w^1];
            else d=sqr(pmin[rs[x]][w^1]-p[0].zb[w^1]);
         } 
         else d=0;
         if(K==1) k=pmin[rs[x]][w]-p[0].zb[w]; else k=sqr(pmin[rs[x]][w]-p[0].zb[w]);
         if(k+d<ansd[P]) query(rs[x],w^1);  
     }
     else
     {
         query(rs[x],w^1);
         if(pmax[ls[x]][w^1]<p[0].zb[w^1]) 
         {
            if(K==1) d=p[0].zb[w^1]-pmax[ls[x]][w^1];
            else d=sqr(p[0].zb[w^1]-pmax[ls[x]][w^1]);
         } else
         if(pmin[ls[x]][w^1]>p[0].zb[w^1])
         {
            if(K==1) d=pmin[ls[x]][w^1]-p[0].zb[w^1];
            else d=sqr(pmin[ls[x]][w^1]-p[0].zb[w^1]);
         } 
         else d=0;
         if(K==1) k=p[0].zb[w]-pmax[ls[x]][w]; else k=sqr(p[0].zb[w]-pmax[ls[x]][w]);
         if(k+d<ansd[P]) query(ls[x],w^1);  
     }
}
int main()
{
    int i,j,x,y;char s[3];
    for(i=0;i<2;i++) pmax[0][i]=-1e8,pmin[0][i]=1e8;
    scanf("%d%d%d%d",&n,&Q,&K,&P);    
    for(i=1;i<=n;i++) scanf("%d%d",&p[i].zb[0],&p[i].zb[1]);    
    root=build(1,n,0);        
    for(i=1;i<=Q;i++)
    {
        scanf("%s%d%d",s,&x,&y);
        if(s[0]=='A')
        {
            p[++n].zb[0]=x;p[n].zb[1]=y;
            Ins(root,0,n);
        }
        else
        {
            p[0].zb[0]=x;p[0].zb[1]=y;
            for(j=1;j<=P;j++) ansd[j]=1e20;
            query(root,0);
            for(j=1;j<P;j++) if(K==1) printf("%.4lf ",(double)ansd[j]); else printf("%.4lf ",sqrt(ansd[j]));
            if(K==1) printf("%.4lf\n",(double)ansd[P]); else printf("%.4lf\n",sqrt(ansd[P]));
        }
    }
    system("pause");
    return 0;
}
