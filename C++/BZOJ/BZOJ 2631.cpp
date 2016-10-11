#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define mod 51061
using namespace std;
int n,q,fa[100010],c[100010][2],size[100010];
int tsum[100010],v[100010],chen[100010],jia[100010];
int stack[100010],top;
int sz,to[200010],pre[200010],last[100010];
bool fz[100010];
inline int read()
{
    char ch=getchar();
    while(!(ch>='0' && ch<='9'))  ch=getchar();
    int x=0; 
    while(ch>='0' && ch<='9') {x=x*10+(ch-'0');ch=getchar();}
    return x;
}
inline char readchar()
{
    char ch=getchar();
    while(ch!='-' && ch!='+' && ch!='*' && ch!='/')  ch=getchar();
    return ch;
}
void Ins(int a,int b)
{
     sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
inline bool isroot(int x)
{
    return (c[fa[x]][0]!=x && c[fa[x]][1]!=x);
}
inline void swap(int &a,int &b)
{
    int t=a;a=b;b=t;
}
inline void downupdata(int x,int y)
{
    if(fz[x]) fz[y]^=1;
    if(chen[x]!=1)  
    {
        chen[y]=((long long)chen[y]*chen[x])%mod;
        jia[y]=((long long)jia[y]*chen[x])%mod;
        v[y]=((long long)v[y]*chen[x])%mod;
        tsum[y]=((long long)tsum[y]*chen[x])%mod;
    }
    if(jia[x]!=0)
    {
        jia[y]=(jia[y]+jia[x])%mod;
        v[y]=(v[y]+jia[x])%mod;
        tsum[y]=(tsum[y]+((long long)jia[x]*size[y])%mod)%mod;
    }
}
inline void downput(int x)
{
    if(fz[x])  swap(c[x][0],c[x][1]);
    int y=c[x][0],z=c[x][1];
    if(y) downupdata(x,y);
    if(z) downupdata(x,z);
    chen[x]=1;jia[x]=0;fz[x]=0;
}
inline void updata(int x)
{
    int y=c[x][0],z=c[x][1];
    size[x]=size[y]+size[z]+1;
    tsum[x]=(tsum[y]+tsum[z]+v[x])%mod;
}
void rotate(int x)
{
     int y=fa[x],z=fa[y],p,q;
     if(c[y][0]==x) p=0; else p=1;
     q=p^1;
     if(!isroot(y))
     {
        if(c[z][0]==y) c[z][0]=x;
        else c[z][1]=x;
     }
     fa[x]=z;fa[y]=x;fa[c[x][q]]=y;
     c[y][p]=c[x][q];c[x][q]=y;
     updata(y);updata(x); 
}
void splay(int x)
{
     int y,z=x;top=0;
     while(!isroot(z)) {stack[++top]=z;z=fa[z];}
     stack[++top]=z;
     while(top) 
     {
         if(chen[stack[top]]!=1 || jia[stack[top]]!=0 || fz[stack[top]])  downput(stack[top]);
         top--;
     }
     while(!isroot(x))
     {
         y=fa[x];z=fa[y];
         if(!isroot(y))
         {
             if((c[z][0]==y)^(c[y][0]==x)) rotate(x);
             else rotate(y);
         }
         rotate(x);
     }
}
inline void Access(int x)
{
    int V=0;
    while(x!=0)
    {
        splay(x);
        c[x][1]=V;
        updata(x);
        V=x;x=fa[x];
    }
} 
inline void cut(int a,int b)
{
     Access(a);splay(b);
     if(fa[b]==a) fa[b]=0;
     else
     {
         Access(b);
         splay(a);
         fa[a]=0;
     }
} 
inline void link(int a,int b)
{
     Access(a);splay(a);fz[a]^=1;fa[a]=b;
}
void dfs(int x)
{
     size[x]=1;v[x]=1;
     for(int i=last[x];i;i=pre[i])
     {
        if(to[i]==fa[x])  continue;
        fa[to[i]]=x;
        dfs(to[i]);
     }
}
void init()
{
    int i,a,b;
    n=read();q=read();
    for(i=1;i<n;i++)
    {
       a=read();b=read();
       Ins(a,b);Ins(b,a);
    }
    dfs((n+1)>>1);
}
void solve()
{
     char s;
     int a,b,c,d;     
     while(q--)
     {
         s=readchar();
         if(s=='+')  
         {
             a=read();b=read();c=read();
             Access(a);splay(a);fz[a]^=1;
             Access(b);splay(b);
             tsum[b]=(tsum[b]+((long long)c*size[b])%mod)%mod;
             v[b]=(v[b]+c)%mod;
             jia[b]=(jia[b]+c)%mod;
         } else
         if(s=='-')
         {
             a=read();b=read();c=read();d=read();
             cut(a,b);link(c,d);
         } else
         if(s=='*')
         {
             a=read();b=read();c=read();
             Access(a);splay(a);fz[a]^=1;
             Access(b);splay(b);
             tsum[b]=(tsum[b]*c)%mod;
             v[b]=(v[b]*c)%mod;
             chen[b]=(chen[b]*c)%mod;
             jia[b]=(jia[b]*c)%mod;
         } 
         else
         {
             a=read();b=read();
             Access(a);splay(a);fz[a]^=1;
             Access(b);splay(b);
             printf("%d\n",tsum[b]);
         }
     }
}
int main()
{
    init();
    solve();
    return 0;
}