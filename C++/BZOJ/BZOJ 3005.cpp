#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const long long INF=1LL<<50;
int n,m,KSZ,SZ,st[350],ed[350],belong[100010],tubao[350][350],gs[350];
int stack[350],top;
long long h[100010],sx[350],gc[350];
inline int read()
{
    char ch=getchar();int x=0;
    while(!(ch>='0' && ch<='9')) ch=getchar();
    while(ch>='0' && ch<='9') {x=x*10+(ch-'0');ch=getchar();}
    return x;
}
inline void swap(long long &a,long long &b)
{
    long long t=a;a=b;b=t;
}
inline double G(int i,int j)
{
     return (double)(h[j]-h[i])/(j-i);
}
inline long long calc(int i)
{
     if(i==0 || i==n+1) return -INF;
     return h[i]+sx[belong[i]]+gc[belong[i]]*(i-st[belong[i]]);
}
void build(int x)
{
     top=0;stack[++top]=st[x];
     for(int i=st[x]+1;i<=ed[x];i++)
     {
         while(top>=2 && G(stack[top-1],stack[top])<G(stack[top-1],i)) top--;
         stack[++top]=i;
     }
     stack[0]=0;stack[top+1]=n+1;
     gs[x]=top;
     for(int i=0;i<=top+1;i++) tubao[x][i]=stack[i];
}
void downput(int x)
{
     int i;long long tmp=sx[x];
     for(i=st[x];i<=ed[x];i++)
     {
         h[i]+=tmp;tmp+=gc[x];
     }
     sx[x]=0;gc[x]=0;
}
void init()
{
    int i,j;    
    n=read();m=read();
    for(i=1;i<=n;i++) h[i]=read();
    h[0]=-INF;h[n+1]=-INF;
    KSZ=sqrt(n);j=KSZ+1;
    for(i=1;i<=n;i++)
    {
        if(j>KSZ) 
        {
            SZ++;st[SZ]=i;ed[SZ-1]=i-1;j=1;
        }
        j++;belong[i]=SZ;
    }
    ed[SZ]=n;
    for(i=1;i<=SZ;i++) build(i);
}
long long ask(int x)
{
     int l=1,r=gs[x],mid;
     long long h1,h2,h3;
     while(l+1<r)
     {
         mid=(l+r)>>1;
         h1=calc(tubao[x][mid-1]),h2=calc(tubao[x][mid]),h3=calc(tubao[x][mid+1]);
         if(h1<h2 && h2<h3)  l=mid; else
         if(h1>h2 && h2>h3)  r=mid; else
         return h2;
     }
     return max(calc(tubao[x][l]),calc(tubao[x][r]));
}
void solve()
{     
     int i,type,x,y,l,r;
     long long tmp,nans,k;     
     while(m--)
     {
         type=read();x=read();y=read();
         if(type==1)
         {
             l=belong[x];r=belong[y];nans=-INF;
             for(i=l+1;i<=r-1;i++)  nans=max(nans,ask(i));
             r=min(y,ed[l]);
             for(i=x;i<=r;i++) nans=max(nans,calc(i));
             if(belong[y]!=belong[x])
             {
                 for(i=st[belong[y]];i<=y;i++)  nans=max(nans,calc(i));
             }
             tmp=nans-calc(1);
             if(tmp>0) printf("%lld\n",tmp); else printf("0\n");
         } else        
         if(type==2)
         {
             l=belong[x];r=belong[y];
             downput(l);
             if(l!=r) downput(r);
             swap(h[x],h[y]);
             if(l!=r) build(r);
             build(l);
         }
         else
         {
              k=read();
              l=belong[x];r=belong[y];
              tmp=k*(st[l+1]-x+1);
              for(i=l+1;i<=r-1;i++)  
              {
                  sx[i]+=tmp;gc[i]+=k;
                  tmp+=k*KSZ;
              } 
              downput(l);
              tmp=k;r=min(y,ed[l]);
              for(i=x;i<=r;i++) h[i]+=tmp,tmp+=k;
              build(l);
              if(belong[y]!=belong[x])
              {
                  r=belong[y];downput(r);tmp=k*(st[r]-x+1);
                  for(i=st[r];i<=y;i++) h[i]+=tmp,tmp+=k;
                  build(r);
              }
         }
     }
}
int main()
{
     
    init();
    solve();
    return 0;
}