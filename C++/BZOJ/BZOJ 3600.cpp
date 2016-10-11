#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>
#include<algorithm>
using namespace std;
const long long R=1LL<<63-1;
int n,m,root,num[100010],tmax[500010];
int sz,tx[500010],ty[500010],ls[500010],rs[500010],rnd[500010];
long long V[500010];
inline int read()
{
    char ch=getchar();
    while(!(ch>='0' && ch<='9'))  ch=getchar();
    int x=0;
    while(ch>='0' && ch<='9')  {x=x*10+(ch-'0');ch=getchar();}
    return x;
}
inline bool cmp(int a,int b)// 1: a>b 
{
    if(V[tx[a]]>V[tx[b]])  return 1;
    if(V[tx[a]]==V[tx[b]] && V[ty[a]]>V[ty[b]])  return 1;
    return 0;
}
inline void lturn(int &t)
{
     int k=rs[t];
     rs[t]=ls[k];ls[k]=t;
     t=k;
}
inline void rturn(int &t)
{
     int k=ls[t];
     ls[t]=rs[k];rs[k]=t;
     t=k;
}
void rebuild(int w,long long l,long long r)
{
     if(!w) return;
     long long mid=(l+r)>>1;
     V[w]=mid;
     rebuild(ls[w],l,mid);rebuild(rs[w],mid,r);
}
void Ins(int x,int &w,long long l,long long r)
{
     if(w==0) {w=x;V[w]=(l+r)>>1;return;}
     if(cmp(x,w))  
     {
        Ins(x,rs[w],(l+r)>>1,r);
        if(rnd[rs[w]]<rnd[w])  lturn(w);
        else if(rs[w]==x) rebuild(x,(l+r)>>1,r);
     }
     else
     {
        Ins(x,ls[w],l,(l+r)>>1);
        if(rnd[ls[w]]<rnd[w]) rturn(w);
        else if(ls[w]==x) rebuild(x,l,(l+r)>>1);
      
     }
}
inline int find(int w,int x,int y)
{
    if(!w) return -1;
    if(tx[w]==x && ty[w]==y)  return w;
    if(V[tx[w]]<V[x] || (V[tx[w]]==V[x] && V[ty[w]]<V[y])) return find(rs[w],x,y);
    else  return find(ls[w],x,y);
}
int charu(int x,int y)
{
     int k=find(root,x,y);
     if(k!=-1)  return k;
     sz++;tx[sz]=x;ty[sz]=y;rnd[sz]=rand();
     Ins(sz,root,1,R);
     if(root==sz) rebuild(root,1,R);
     return sz;
}
inline int Max(int a,int b)
{
    if(!a) return b;
    if(!b) return a;
    if(cmp(num[a],num[b])) return a;
    if(num[a]==num[b] && a<b) return a;
    return b;
}
void updata(int k,int l,int r,int w)
{
     if(l==r) {tmax[k]=w;return;}
     int mid=(l+r)>>1;
     if(w<=mid) updata(k<<1,l,mid,w);
     else updata(k<<1|1,mid+1,r,w);
     tmax[k]=Max(tmax[k<<1],tmax[k<<1|1]);
}
int askmax(int k,int l,int r,int zuo,int you)
{
    if(l>you || r<zuo) return 0;
    if(l>=zuo && r<=you)  return tmax[k];
    int mid=(l+r)>>1;
    int p=Max(askmax(k<<1,l,mid,zuo,you),askmax(k<<1|1,mid+1,r,zuo,you));
    return p;
}
char readchar()
{
     char ch=getchar();
     while(ch!='Q' && ch!='C')  ch=getchar();
     return ch;
}
int main()
{
    srand(time(0));
    int i,l,r,k;char s;
    V[0]=-1;
    n=read();m=read();
    charu(0,0);
    for(i=1;i<=n;i++)  
    {
       num[i]=1;
       updata(1,1,n,i);  
    }
    for(i=1;i<=m;i++)
    {
        s=readchar();
        l=read();r=read();
        if(s=='C')
        {
           k=read();
           num[k]=charu(num[l],num[r]);
           updata(1,1,n,k);
        }
        else
        {
            printf("%d\n",askmax(1,1,n,l,r));
        }
    } 
    return 0;
}