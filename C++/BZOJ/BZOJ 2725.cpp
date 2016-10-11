#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
int n,m,q,s,t,deep[200010],fa[200010][19];
int A[200010],B[200010],C[200010];
int sz,to[500010],v[500010],pre[500010],last[200010];
int dui[200010];
long long dists[200010],distt[200010],tag[1000010],ans[200010];
bool mark[200010];
inline int read()
{
    char ch=getchar();
    while(!(ch>='0' && ch<='9'))  ch=getchar();
    int x=0;
    while(ch>='0' && ch<='9')  {x=x*10+(ch-'0');ch=getchar();}
    return x;
}
struct node
{
    long long d;int bh;
}x,y;
struct cmp  
{  
    bool operator()(const node& a,const node& b)  
    {  
        return a.d>b.d;
    }  
};
void Ins(int a,int b,int c)
{
     sz++;to[sz]=b;v[sz]=c;pre[sz]=last[a];last[a]=sz;
}
void Dij(int qi,long long dist[200010])
{
     int i;node k,y;
     memset(mark,0,sizeof(mark));
     for(i=1;i<=n;i++)  dist[i]=1e30;
     priority_queue<node,vector<node>,cmp> q;  
     k.d=0;k.bh=qi;
     q.push(k);
     dist[qi]=0;
     while(!q.empty())
     {
         k=q.top();
         q.pop();
         if(!mark[k.bh])  
         {
             mark[k.bh]=1;
             for(i=last[k.bh];i;i=pre[i])
             if(dist[to[i]]>dist[k.bh]+v[i])
             {
                dist[to[i]]=dist[k.bh]+v[i];
                y.d=dist[to[i]];y.bh=to[i];
                q.push(y);
             }
         }
     }
}
void init()
{
     n=read();m=read();
     for(int i=1;i<=m;i++)
     {
         A[i]=read();B[i]=read();C[i]=read();
         Ins(A[i],B[i],C[i]);Ins(B[i],A[i],C[i]);
     }
     s=read();t=read();
}
void buildtree()
{
     int tou=1,wei=1,i,now;
     memset(mark,0,sizeof(mark));
     dui[1]=s;mark[s]=1;deep[s]=0;
     while(tou<=wei)
     {
         now=dui[tou];tou++;
         for(i=1;i<=18;i++) fa[now][i]=fa[fa[now][i-1]][i-1];
         for(i=last[now];i;i=pre[i])
         if(!mark[to[i]] && dists[now]+v[i]==dists[to[i]])
         {
             mark[to[i]]=1;
             fa[to[i]][0]=now; 
             deep[to[i]]=deep[now]+1;
             dui[++wei]=to[i];
         }
     }
}
int LCA(int a,int b)
{
    if(deep[a]<deep[b])  swap(a,b);
    int i,c=deep[a]-deep[b];
    for(i=18;i>=0;i--)  if(c>=(1<<i))  {c-=(1<<i);a=fa[a][i];}
    for(i=18;i>=0;i--)  if(fa[a][i]!=fa[b][i])  {a=fa[a][i];b=fa[b][i];}
    if(a==b) return a; return fa[a][0];
}
void updata(int k,int l,int r,int zuo,int you,long long x)
{
     if(l>=zuo && r<=you) 
     {
         if(tag[k]>x) tag[k]=x;
         return;
     }
     int mid=(l+r)>>1;
     if(zuo<=mid)  updata(k<<1,l,mid,zuo,you,x);
     if(you>mid)  updata(k<<1|1,mid+1,r,zuo,you,x);
}
long long ask(int k,int l,int r,int w)
{
     if(l==r)  return tag[k];
     int mid=(l+r)>>1;
     if(w<=mid)  return min(ask(k<<1,l,mid,w),tag[k]);
     else  return min(ask(k<<1|1,mid+1,r,w),tag[k]);
}
void check(int a,int b,int c) 
{
     if(fa[b][0]==a)  return;
     int x=LCA(a,t),y=LCA(b,t);
     x=deep[x]+1;y=deep[y];
     if(x>y) return;
     long long tmp=dists[a]+c+distt[b];
     updata(1,1,deep[t],x,y,tmp); 
}
void solveask(int a,int b)
{
     if(deep[a]>deep[b])  swap(a,b);
     if(fa[b][0]!=a || LCA(b,t)!=b) 
     {
        printf("%lld\n",dists[t]);
        return;
     }
     long long p=1e30;
     if(ans[deep[b]]==p)  printf("Infinity\n");
     else  printf("%lld\n",ans[deep[b]]);
}
void solve()
{
     int i,a,b;
     Dij(s,dists);
     Dij(t,distt);          
     buildtree();
     for(i=1;i<=n*4;i++) tag[i]=1e30;
     for(i=1;i<=m;i++)
     {
         check(A[i],B[i],C[i]);check(B[i],A[i],C[i]);
     }
     for(i=1;i<=deep[t];i++) ans[i]=ask(1,1,deep[t],i);     
     q=read();      
     for(i=1;i<=q;i++)
     {
         a=read();b=read();
         solveask(a,b);
     }
}
int main()
{
    init();
    solve();
    return 0;
}