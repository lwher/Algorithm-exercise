#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,C,m,now,nsumc,nrc;
int lc[3000010],rc[3000010],sumc[3000010];
bool mark[3000010];
bool dir;
inline void downput(int k)
{
    mark[k]=0;mark[k<<1]=1;mark[k<<1|1]=1;
    lc[k<<1]=lc[k];rc[k<<1]=rc[k];
    lc[k<<1|1]=lc[k];rc[k<<1|1]=rc[k];
    sumc[k<<1]=sumc[k<<1|1]=1;
}
inline void updata(int k)
{
    sumc[k]=sumc[k<<1]+sumc[k<<1|1];
    if(rc[k<<1]==lc[k<<1|1]) sumc[k]--;
    lc[k]=lc[k<<1];rc[k]=rc[k<<1|1];
}
void change(int k,int l,int r,int zuo,int you,int c)
{
    if(l>=zuo && r<=you) 
    {
        mark[k]=1;sumc[k]=1;
        lc[k]=rc[k]=c;
        return; 
    }
    if(mark[k]) downput(k);
    int mid=(l+r)>>1;
    if(zuo<=mid) change(k<<1,l,mid,zuo,you,c);
    if(you>mid) change(k<<1|1,mid+1,r,zuo,you,c);
    updata(k);
}
void ask(int k,int l,int r,int zuo,int you)
{
    if(l>=zuo && r<=you)
    {
        nsumc+=sumc[k];
        if(nrc==lc[k]) nsumc--;
        nrc=rc[k];
        return;
    }
    if(mark[k]) downput(k);
    int mid=(l+r)>>1;
    if(zuo<=mid) ask(k<<1,l,mid,zuo,you);
    if(you>mid) ask(k<<1|1,mid+1,r,zuo,you);
}
int findc(int k,int l,int r,int w)
{
    if(l==r) return lc[k];
    if(mark[k]) downput(k);
    int mid=(l+r)>>1;
    if(w<=mid) return findc(k<<1,l,mid,w);
    else return findc(k<<1|1,mid+1,r,w);
}
void init()
{
    int i,c;
    scanf("%d%d",&n,&C);
    for(i=1;i<=n;i++) 
    {
        scanf("%d",&c);
        change(1,1,n,i,i,c);
    }
    now=1;
}
inline void move(int x)
{
    if(!dir) {now-=x;if(now<=0) now+=n;}
    else {now+=x;if(now>n) now-=n;}
}
inline int find(int x)
{
    int k;
    if(!dir) {k=now+x-1;if(k>n) k-=n;}
    else {k=now-x+1;if(k<=0) k+=n;}
    return k;
}
void solveP(int l,int r,int c)
{
     if(!dir)
     {
         if(l<=r) change(1,1,n,l,r,c);
         else
         {
             change(1,1,n,1,r,c);
             change(1,1,n,l,n,c);
         }
     }
     else
     {
         if(l>=r) change(1,1,n,r,l,c);
         else
         {
             change(1,1,n,1,l,c);
             change(1,1,n,r,n,c);
         }
     }
}
int solveCS(int l,int r)
{
    nsumc=0;nrc=C+1;
    if(!dir) 
    {
        if(l<=r) ask(1,1,n,l,r);
        else
        {
            ask(1,1,n,l,n);
            ask(1,1,n,1,r);
        } 
    }
    else
    {
        if(l>=r) ask(1,1,n,r,l);
        else
        {
            ask(1,1,n,r,n);
            ask(1,1,n,1,l);
        }
    }
    return nsumc;
}
void solve()
{
     int i,a,b,x,y,c;
     char ch[3];     
     scanf("%d",&m);     
     for(i=1;i<=m;i++)
     {
        scanf("%s",ch);
        if(ch[0]=='R')
        {
           scanf("%d",&x);
           move(x);
        } else
        if(ch[0]=='F') dir^=1; else
        if(ch[0]=='S')
        {
            scanf("%d%d",&a,&b);
            a=find(a);b=find(b);
            x=findc(1,1,n,a);
            y=findc(1,1,n,b);
            change(1,1,n,a,a,y);
            change(1,1,n,b,b,x);
        } else
        if(ch[0]=='P')
        {
            scanf("%d%d%d",&a,&b,&c);
            a=find(a);b=find(b);
            solveP(a,b,c);
        } else
        if(ch[0]=='C' && ch[1]=='S')
        {
            scanf("%d%d",&a,&b);
            a=find(a);b=find(b);
            printf("%d\n",solveCS(a,b));
        }
        else
        {
            x=sumc[1];
            if(lc[1]==rc[1]) x--;
            if(!x) x++;
            printf("%d\n",x);
        }
     }
}
int main()
{
    init();
    solve();
    return 0;
}