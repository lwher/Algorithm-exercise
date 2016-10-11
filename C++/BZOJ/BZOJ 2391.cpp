#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
struct point
{
    int x,y,bh,v;
}p[2010];
int n,m,sum,root,Sum[2010],ls[2010],rs[2010],rnd[2010];
int stack[110],f[2010][2010],pw[2010];
inline int chaji(point a,point b)
{
    return a.x*b.y-a.y*b.x;
}
inline point jian(point a,point b)
{
    point c;
    c.x=a.x-b.x;c.y=a.y-b.y;
    return c;
}
inline int turnto(point a,point b,point c) //>0 a to b ÏòÓÒ to c 
{
    return chaji(jian(c,a),jian(b,a));
}
inline int dist(point a,point b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
} 
inline bool comp(point a,point b)
{
    if(turnto(p[0],a,b)>0) return 1;
    if(turnto(p[0],a,b)==0 && dist(p[0],a)<dist(p[0],b)) return 1;
    return 0;
}
inline void updata(int x)
{
    Sum[x]=Sum[ls[x]]+Sum[rs[x]]+p[x].v;
}
inline void rturn(int &t)
{
    int k=ls[t];
    ls[t]=rs[k];rs[k]=t;
    updata(t);updata(k);
    t=k;
}
inline void lturn(int &t)
{
    int k=rs[t];
    rs[t]=ls[k];ls[k]=t;
    updata(t);updata(k);
    t=k;
}
void Ins(int &x,int y,int z)
{
    if(!x)
    {
        x=y;ls[x]=0;rs[x]=0;Sum[x]=p[x].v;rnd[x]=rand();
        return;
    }
    Sum[x]+=p[y].v;
    if(turnto(p[z],p[x],p[y])>0) 
    {
        Ins(ls[x],y,z);
        if(rnd[ls[x]]<rnd[x]) rturn(x);
    }
    else
    {
        sum+=Sum[ls[x]]+p[x].v;Ins(rs[x],y,z);
        if(rnd[rs[x]]<rnd[x]) lturn(x);
    }
}
void build()
{
    int i,j;
    for(i=1;i<=n;i++) pw[p[i].bh]=i;
    for(i=1;i<=n;i++)
    {
        root=0;
        for(j=i+1;j<=n;j++)
        {
            sum=0;Ins(root,j,i);
            f[i][j]=f[j][i]=sum;
        }
    }
}
void solve()
{
     int i,s,x,y,ans=0;
     scanf("%d",&s);
     for(i=1;i<=s;i++)
     {
        scanf("%d",&stack[i]);
        stack[i]=pw[stack[i]];
     }
     stack[s+1]=stack[1];
     for(i=1;i<=s;i++) 
     {
         x=stack[i];y=stack[i+1];
         if(turnto(p[0],p[x],p[y])>0) ans+=f[x][y];
         else ans-=f[x][y];
     }
     if(ans<0) ans=-ans;
     printf("%d\n",ans);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) {scanf("%d%d",&p[i].x,&p[i].y);p[i].bh=i;p[i].v=0;}
    for(int i=n+1;i<=n+m;i++) {scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].v);p[i].bh=i;}
    n+=m;
    p[0].x=-10003;p[0].y=-10003;
    sort(p+1,p+1+n,comp);
    build();
    scanf("%d",&m);
    for(int i=1;i<=m;i++) 
    solve();
    system("pause");
    return 0;
}
