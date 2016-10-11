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
       int  x,y,id;
}dian[10010];
int n,k,sz;
int c[2010],bh[2010],fa[10010];
struct xxx
{
       int a,b,v;
}lu[100010];
int lowbit(int x)
{
    return x & (-x);
}
inline bool comp(sth a,sth b)
{
       if(a.x==b.x)  return a.y<b.y; return a.x<b.x;
}
inline bool cmp(xxx a,xxx b)
{
      return a.v<b.v;
}
void Ins(int a,int b,int c)
{
     sz++;lu[sz].a=a;lu[sz].b=b;lu[sz].v=c;
}
void query(int val,int w,int cid)
{
     int id=-1,minx=INF;
     val+=1000;
     for(int i=val;i<2010;i+=lowbit(i))
     {
         if(c[i]<minx)
         {
             minx=c[i];
             id=bh[i];
         }
     }
     if(id!=-1)  Ins(id,cid,minx-w);
}
void updata(int val,int w,int cid)
{
     val+=1000;
     for(int i=val;i>0;i-=lowbit(i))
     {
             if(w<c[i])
             {
                 c[i]=w;
                 bh[i]=cid;
             }
     }
}
void go()
{
     int i;
     sort(dian+1,dian+1+n,comp);
     for(i=0;i<2010;i++)  c[i]=INF;
     for(i=n;i>=1;i--)
     {
         query(dian[i].y-dian[i].x,dian[i].x+dian[i].y,dian[i].id);
         updata(dian[i].y-dian[i].x,dian[i].x+dian[i].y,dian[i].id);
     }
}
void swap(int &a,int &b)
{
     int t=a;a=b;b=t;
}
int getfa(int x)
{
    if(fa[x]==0) return x;
    else return fa[x]=getfa(fa[x]);   
}
int solve()
{
    int i,x,y;
    if(k==n)  return 0;
    go();
    for(i=1;i<=n;i++)  swap(dian[i].x,dian[i].y);
    go();
    for(i=1;i<=n;i++)  dian[i].y=-dian[i].y;
    go();
    for(i=1;i<=n;i++)  swap(dian[i].x,dian[i].y);
    go();
    sort(lu+1,lu+1+sz,cmp);
    for(i=1;i<=sz;i++)
    {
       x=getfa(lu[i].a);y=getfa(lu[i].b);
       if(x!=y)
       {
           n--;fa[x]=y;
           if(n==k)  return lu[i].v;
       }
    }
    return -1;
}
int main()
{
    int i;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&dian[i].x,&dian[i].y);
        dian[i].id=i;
    }
    printf("%d\n",solve());
    system("pause");
    return 0;
}
