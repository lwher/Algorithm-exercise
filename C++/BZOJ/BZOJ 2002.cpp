#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 200010
using namespace std;
int n,q,c[N][2],fa[N],size[N];
void updata(int x)
{
    size[x]=size[c[x][0]]+size[c[x][1]]+1;
}
bool isroot(int x)
{
    return (c[fa[x]][0]!=x && c[fa[x]][1]!=x);
}
void rotate(int x)
{
    int y=fa[x],z=fa[y],p,q;
    if(c[y][0]==x)  p=0; else p=1;
    q=p^1;
    if(!isroot(y))
    {
        if(c[z][0]==y)  c[z][0]=x;  else c[z][1]=x;
    }
    fa[y]=x;fa[x]=z;fa[c[x][q]]=y;
    c[y][p]=c[x][q];c[x][q]=y;
    updata(y);updata(x);
}
void splay(int x)
{
    int y,z;
    while(!isroot(x))
    {
        y=fa[x];z=fa[y];
        if(!isroot(y))
        {
            if((c[y][0]==x) ^ (c[z][0]==y))  rotate(x);
            else rotate(y);
        }
        rotate(x);
    }
}
void Access(int x)
{
    int v=0;
    while(x!=0)
    {
        splay(x);
        c[x][1]=v;
        updata(x);
        v=x; x=fa[x];
    }
}
int main()
{
    int i,k,x,y;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&fa[i]);
        fa[i]+=i;
        if(fa[i]>n)  fa[i]=n+1;
        size[i]=1;
    }
    size[n+1]=1;        
    scanf("%d",&q);
    for(i=1;i<=q;i++)
    {
        scanf("%d%d",&k,&x); x++;
        if(k==1) 
        {
            Access(x);          
            splay(x);
            printf("%d\n",size[x]-1);
        }
        else
        {
            scanf("%d",&y);
            splay(x);
            fa[c[x][0]]=fa[x];c[x][0]=0;
            updata(x);
            fa[x]=x+y;
            if(fa[x]>n) fa[x]=n+1;
        }
    }
    return 0;
}