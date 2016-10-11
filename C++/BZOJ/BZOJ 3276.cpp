#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
struct sth
{
    int w,x,y,p,rk;
    long long r,d;
    bool mark;
}ct[250010],stack[250010];
int X,Y,P,n,tot,top;
int sz,w[5000010],pre[5000010],last[250010];
long long R;
inline bool comp(sth a,sth b) {return a.w<b.w;}
inline bool cmp(sth a,sth b) {return a.d>b.d;}
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(!(ch>='0' && ch<='9')) {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0' && ch<='9') {x=x*10+(ch-'0');ch=getchar();}
    return x*f;
}
void Ins(int W,int bh)
{
     sz++;w[sz]=bh;pre[sz]=last[W];last[W]=sz;
}
void add(int x)
{
     for(int i=ct[x].rk;i<=tot;i+=(i & (-i))) Ins(i,x);
}
void solve(int x,long long RR)
{
     if(x==0) return;
     for(int j=x;j;j-=(j & (-j)))
     while(last[j]!=0 && ct[w[last[j]]].d<=RR) 
     {
         if(!ct[w[last[j]]].mark) 
         {
            stack[++top]=ct[w[last[j]]];
            ct[w[last[j]]].mark=1;
         }
         last[j]=pre[last[j]];
     }
}
int find(int x)
{
    int l=1,r=n,mid;
    while(l+1<r)
    {
       mid=(l+r)>>1;
       if(ct[mid].w<=x) l=mid;
       else r=mid;
    }
    if(ct[r].w<=x) return ct[r].rk;
    if(ct[l].w<=x) return ct[l].rk;
    return 0;
}
int main()
{
    int i;
    X=read();Y=read();P=read();R=read();n=read();//scanf("%d%d%d%lld%d",&X,&Y,&P,&R,&n);
    R*=R;
    for(i=1;i<=n;i++)  
    {
       ct[i].x=read();ct[i].y=read();ct[i].w=read();ct[i].p=read();ct[i].r=read();
       //scanf("%d%d%d%d%lld",&ct[i].x,&ct[i].y,&ct[i].w,&ct[i].p,&ct[i].r);
       ct[i].d=(long long)(ct[i].x-X)*(ct[i].x-X)+(long long)(ct[i].y-Y)*(ct[i].y-Y);
       ct[i].r*=ct[i].r;
    }
    sort(ct+1,ct+1+n,comp);
    ct[1].rk=1;
    for(i=2;i<=n;i++)  ct[i].rk=ct[i-1].rk+(ct[i].w!=ct[i-1].w);
    tot=ct[n].rk;
    for(i=1;i<=n;i++)  ct[i].p=find(ct[i].p);
    stack[1].p=find(P);stack[1].r=R;
    sort(ct+1,ct+1+n,cmp);
    for(i=1;i<=n;i++)  add(i);
    top=1;
    for(i=1;i<=top;i++) solve(stack[i].p,stack[i].r);
    printf("%d\n",top-1);
    return 0;
}