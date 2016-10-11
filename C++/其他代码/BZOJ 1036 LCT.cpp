#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,FA[30010][16],v[30010],deep[30010];
int fa[30010],fmax[30010],fsum[30010],c[30010][2];
int sz,to[100010],pre[100010],last[30010];
void swap(int &a,int &b)
{
    int t=a;a=b;b=t;
}
void Ins(int a,int b)
{
    sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
bool isroot(int x)
{
    return (c[fa[x]][0]!=x && c[fa[x]][1]!=x);
}
void updata(int x)
{
    int y=c[x][0],z=c[x][1];
    fmax[x]=max(v[x],max(fmax[y],fmax[z]));
    fsum[x]=fsum[y]+fsum[z]+v[x];
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
    fa[x]=z;fa[y]=x;fa[c[x][q]]=y;
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
    int vv=0;
    while(x!=0)
    {
        splay(x);
        c[x][1]=vv;
        updata(x);
        vv=x;x=fa[x];
    }
}
void dfs(int x,int from)
{
    int i;
    for(i=1;i<=15;i++)  FA[x][i]=FA[FA[x][i-1]][i-1];
    for(i=last[x];i;i=pre[i])
    {
        if(to[i]==from)  continue;
        FA[to[i]][0]=x;
        deep[to[i]]=deep[x]+1;
        dfs(to[i],x);
    }
}
void init()
{
    int i,a,b;
    fmax[0]=-1e8;fsum[0]=0;
    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        Ins(a,b);Ins(b,a);
    }
    deep[1]=1;
    dfs(1,0);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&v[i]);
        fa[i]=FA[i][0];
        fmax[i]=v[i];fsum[i]=v[i];
    }
}
int LCA(int a,int b)
{
    int i,p;
    if(deep[a]<deep[b])  swap(a,b);
    p=deep[a]-deep[b];
    for(i=15;i>=0;i--)
    if(p>=(1<<i))
    {
        p-=(1<<i);a=FA[a][i];
    }
    for(i=15;i>=0;i--)
    if(FA[a][i]!=FA[b][i])
    {
        a=FA[a][i];b=FA[b][i];
    }
    if(a==b) return a; return FA[a][0];
}
int Qsum(int a,int b)
{
    int sum=0,p=LCA(a,b);
    Access(a);splay(p);
    sum+=fsum[c[p][1]]+v[p];
    Access(b);splay(p);
    sum+=fsum[c[p][1]];
    return sum;
}
int Qmax(int a,int b)
{
    int maxx=-1e8,p=LCA(a,b);
    Access(a);splay(p);
    maxx=max(maxx,fmax[c[p][1]]);
    Access(b);splay(p);
    maxx=max(maxx,fmax[c[p][1]]);
    maxx=max(maxx,v[p]);
    return maxx;
}
void solve()
{
    int i,a,b;
    char ch[10];
    scanf("%d",&m);
    for(i=1;i<=m;i++)
    {
        scanf("%s",ch);scanf("%d%d",&a,&b);
        if(ch[0]=='C')
        {
            splay(a);v[a]=b;updata(a);
        }else
        if(ch[1]=='S')  printf("%d\n",Qsum(a,b));
        else  printf("%d\n",Qmax(a,b));
    }
}
int main()
{
    init();
    solve();
//  system("pause");
    return 0;
}