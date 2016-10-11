#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
struct sth
{
    int l,r,v;
    bool D;
}road[1000010];
int n,m,q,K[100010],A[100010],B[100010],stack[300010],v[100010];
int sz,fa[300010],fmax[300010],quan[300010],c[300010][2];//fmax[i]:以i为根的子树中值最大的点的编号 
int zuo[300010],you[300010],father[100010],ans[100010];
bool fz[300010];
int read()
{
    char ch=getchar();
    while(!(ch>='0' && ch<='9'))  ch=getchar();
    int x=0;
    while(ch>='0' && ch<='9')  {x=x*10+(ch-'0');ch=getchar();}
    return x;
}
bool isroot(int x)
{
     return (c[fa[x]][0]!=x && c[fa[x]][1]!=x);
}
void swap(int &a,int &b)
{
     int t=a;a=b;b=t;
}
void updata(int x)
{
     int y=c[x][0],z=c[x][1];
     fmax[x]=x;
     if(y && quan[fmax[y]]>quan[fmax[x]])  fmax[x]=fmax[y];
     if(z && quan[fmax[z]]>quan[fmax[x]])  fmax[x]=fmax[z];
}
void downput(int x)
{
     int y=c[x][0],z=c[x][1];
     swap(c[x][0],c[x][1]);
     if(y)  fz[y]^=1;
     if(z)  fz[z]^=1;
     fz[x]=0;
}
void rotate(int x)
{
     int y=fa[x],z=fa[y],p,q;
     if(c[y][0]==x)  p=0; else p=1;
     q=p^1;
     if(!isroot(y))
     {
         if(c[z][0]==y)  c[z][0]=x; else c[z][1]=x;
     }
     fa[y]=x;fa[x]=z;fa[c[x][q]]=y;
     c[y][p]=c[x][q];c[x][q]=y;
     updata(y);updata(x);
}
void splay(int x)
{
     int y,z,top=0;
     z=x;
     while(!isroot(z))
     {
         stack[++top]=z;z=fa[z];
     }
     stack[++top]=z;
     while(top>0)  {if(fz[stack[top]]) downput(stack[top]); top--;}
     while(!isroot(x))
     {
         y=fa[x];z=fa[y];
         if(!isroot(y))
         {
            if((c[y][0]==x) ^ (c[z][0]==y))  rotate(x);
            else  rotate(y);
         }
         rotate(x);
     }
}
void Access(int x)
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
void link(int x,int y)
{
     Access(x);splay(x);
     fz[x]^=1;fa[x]=y;
}
void cut(int x,int y)
{
     Access(x);splay(y);
     if(c[y][1]==x)
     {
         Access(y);splay(x);fa[x]=0;
     }
     else  fa[y]=0;
}
inline bool cmp(sth a,sth b)  
{
    if(a.l==b.l) return a.r<b.r; return a.l<b.l;
}
inline bool comp(sth a,sth b)  {return a.v<b.v;}
void find(int a,int b,int bh)
{
     int l=1,r=m,mid;
     while(l+1<r)
     {
         mid=(l+r)>>1;
         if(road[mid].l==a)
         {
             if(road[mid].r<b)  l=mid;  else  r=mid;
         }else
         if(road[mid].l<a)  l=mid;  else r=mid;
     }
     if(road[l].l==a && road[l].r==b)  {road[l].D=1;v[bh]=road[l].v;}
     if(road[r].l==a && road[r].r==b)  {road[r].D=1;v[bh]=road[r].v;}
}
void init()
{
     int i;
     n=read();m=read();q=read();
     for(i=1;i<=m;i++)  
     {
        road[i].l=read();road[i].r=read();road[i].v=read();
        if(road[i].l>road[i].r)  swap(road[i].l,road[i].r);
     }
     for(i=1;i<=q;i++) 
     {
         K[i]=read();A[i]=read();B[i]=read();
         if(A[i]>B[i]) swap(A[i],B[i]);
     }
     sort(road+1,road+1+m,cmp);
     for(i=1;i<=q;i++)  if(K[i]==2)  find(A[i],B[i],i);     
}
int getfa(int x)
{
    if(father[x]==0)  return x;
    else return father[x]=getfa(father[x]);
}
void solve()
{     
     int i,x,y,z;
     sz=n;quan[0]=-1e8;
     for(i=1;i<=n;i++)  {quan[i]=0;fmax[i]=i;}
     sort(road+1,road+1+m,comp);
     for(i=1;i<=m;i++)
     if(!road[i].D)
     {
         x=getfa(road[i].l);y=getfa(road[i].r);
         if(x!=y)
         {
             father[x]=y;
             quan[++sz]=road[i].v;fmax[sz]=sz;zuo[sz]=road[i].l;you[sz]=road[i].r;
             link(sz,zuo[sz]);link(sz,you[sz]);
         }
     }
     for(i=q;i>=1;i--)
     {
         if(K[i]==2)
         {
             x=A[i];y=B[i];
             Access(x);splay(x);
             fz[x]^=1;
             Access(y);splay(y);
             z=fmax[y];
             if(v[i]<quan[z])
             {
                 cut(z,zuo[z]);cut(z,you[z]);
                 quan[++sz]=v[i];fmax[sz]=sz;zuo[sz]=x;you[sz]=y;
                 link(sz,x);link(sz,y);
             }
         }
         else
         {
             x=A[i];y=B[i];
             Access(x);splay(x);
             fz[x]^=1;
             Access(y);splay(y);
             z=fmax[y];
             ans[i]=quan[z];
         }
     }
     for(i=1;i<=q;i++) if(K[i]==1)  printf("%d\n",ans[i]);
}
int main()
{
    init();
    solve();
    return 0;
}
