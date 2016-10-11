#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct sth
{
    int pos,shu,num;
}xl[100010];
int n,pl[100010],bh[100010],rot;
int c[100010][2],size[100010],fa[100010],stack[100010],top;
bool fz[100010];
inline bool comp(sth a,sth b)
{
    if(a.shu==b.shu)  return a.pos<b.pos;
    return a.shu<b.shu;
}
inline bool cmp(sth a,sth b)
{
    return a.pos<b.pos;
}
void updata(int x)
{
    size[x]=size[c[x][0]]+size[c[x][1]]+1;
}
void swap(int &a,int &b)
{
    int t=a;a=b;b=t;
}
void downput(int x)
{
    int y=c[x][0],z=c[x][1];
    swap(c[x][0],c[x][1]);
    if(y) fz[y]^=1;
    if(z) fz[z]^=1;
    fz[x]=0;
}
void build(int l,int r,int last)
{
    if(l>r) return;
    if(l==r)
    {
        fa[l]=last;size[l]=1;if(l<last)  c[last][0]=l; else c[last][1]=l;
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid-1,mid);build(mid+1,r,mid);fa[mid]=last;updata(mid);
    if(mid<last)  c[last][0]=mid; else c[last][1]=mid;
}
void rotate(int x,int &root)
{
    int y=fa[x],z=fa[y],p,q;
    if(c[y][0]==x)  p=0; else p=1;
    q=p^1;
    if(y==root)  root=x;
    else
    {
        if(c[z][0]==y)  c[z][0]=x; else c[z][1]=x;
    }
    fa[x]=z;fa[y]=x;fa[c[x][q]]=y;
    c[y][p]=c[x][q];c[x][q]=y;
    updata(y);updata(x);
}
void splay(int x,int &root)
{
    int y,z;
    z=x;top=0;
    while(z!=root)  {stack[++top]=z;z=fa[z];}
    stack[++top]=z;
    while(top>0)  
    {
        y=stack[top];
        if(fz[y])  downput(y);
        top--;    
    }
    while(x!=root)
    {
        y=fa[x];z=fa[y];
        if(y!=root)
        {
            if((c[y][0]==x) ^ (c[z][0]==y))  rotate(x,root);
            else  rotate(y,root);
        }
        rotate(x,root);
    }
}
void solve()
{
    int i,x,y,z;
    for(i=1;i<n;i++)
    {
        x=pl[i];splay(x,rot);
        y=c[x][0];z=c[x][1];
        printf("%d ",size[y]+i);
        if(y) fz[y]^=1;
        if(z)
        {
            if(fz[z])  downput(z);
            while(c[z][0]!=0)
            {
                z=c[z][0];
                if(fz[z])  downput(z);
            }
            splay(z,c[x][1]);
            fa[z]=0;c[z][0]=y;fa[y]=z;rot=z;
            updata(z);
        }
        else {rot=y;fa[rot]=0;}
    }
    printf("%d\n",n);
}
int main()
{
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++) 
    { 
       scanf("%d",&xl[i].shu);
       xl[i].pos=i;
    }
    sort(xl+1,xl+1+n,comp);
    for(i=1;i<=n;i++)  {xl[i].num=i;pl[i]=xl[i].pos;}
    sort(xl+1,xl+1+n,cmp);
    build(1,n,0);   
    rot=n>>1;         
    solve();
    return 0;
} 