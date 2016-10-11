#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,q,w[100010],c[100010][2],size[100010],fa[100010];
void updata(int x)
{
     size[x]=size[c[x][0]]+size[c[x][1]]+1;
}
int getfa(int x)
{
    while(fa[x]!=0) x=fa[x]; return x;
}
void swap(int &a,int &b)
{
     int t=a;a=b;b=t;
}
void rotate(int x)
{
     int y=fa[x],z=fa[y],p,q;
     if(c[y][0]==x) p=0; else p=1;
     q=p^1;
     if(fa[y]!=0)
     {
        if(c[z][0]==y)  c[z][0]=x; else c[z][1]=x;
     }
     fa[x]=z;fa[y]=x;fa[c[x][q]]=y;
     c[y][p]=c[x][q];c[x][q]=y;
     updata(y);updata(x);
}
void splay(int x)
{
     int y,z;
     while(fa[x]!=0)
     {
        y=fa[x];z=fa[y];
        if(fa[y]!=0)
        {
            if((c[y][0]==x)^(c[z][0]==y))  rotate(x);
            else rotate(y);
        }
        rotate(x);
     }
}
void Ins(int &x,int last,int bh)
{
    if(!x) 
    {
       x=bh;fa[x]=last;size[x]=1;c[x][0]=c[x][1]=0;
       splay(x);return;
    }
    if(w[x]<w[bh])  Ins(c[x][1],x,bh);
    else  Ins(c[x][0],x,bh);
}
void dfs(int x,int b)
{
     if(!x) return;
     dfs(c[x][0],b);dfs(c[x][1],b);
     Ins(b,0,x);
}
void merge(int a,int b)
{
     a=getfa(a);b=getfa(b);
     if(a==b) return;
     if(size[a]>size[b])  swap(a,b);
     dfs(a,b);
}
int find(int x,int k)
{
    x=getfa(x);
    if(k>size[x]) return -1;
    while(x!=0)
    {
       if(size[c[x][0]]+1==k)  return x;
       if(size[c[x][0]]>=k)  x=c[x][0];
       else {k-=size[c[x][0]]+1;x=c[x][1];}
    }
}
int main()
{
    int i,a,b;char s[3];
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)  {scanf("%d",&w[i]);size[i]=1;}
    for(i=1;i<=m;i++)  
    {
       scanf("%d%d",&a,&b);
       merge(a,b);
    }
    scanf("%d",&q);
    while(q--)
    {
        scanf("%s",s);scanf("%d%d",&a,&b);
        if(s[0]=='B') merge(a,b);
        else  printf("%d\n",find(a,b));    
    }
    return 0;
}