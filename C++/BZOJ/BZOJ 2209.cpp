#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int n,sz,q,rot;
int c[100010][2],sum[100010],v[100010],lmax[100010],lmin[100010],rmax[100010],rmin[100010],fa[100010],size[100010];
bool fz[100010],qf[100010];
int zhi[100010],bh[100010];
char s[100010];
void swap(int &a,int &b) {int t=a;a=b;b=t;}
void updata(int x)
{
    int y=c[x][0],z=c[x][1];
    size[x]=size[y]+size[z]+1;
    sum[x]=sum[y]+sum[z]+v[x];
    lmax[x]=max(max(lmax[y],sum[y]+v[x]),sum[y]+v[x]+lmax[z]);
    lmin[x]=min(min(lmin[y],sum[y]+v[x]),sum[y]+v[x]+lmin[z]);
    rmax[x]=max(max(rmax[z],sum[z]+v[x]),sum[z]+v[x]+rmax[y]);
    rmin[x]=min(min(rmin[z],sum[z]+v[x]),sum[z]+v[x]+rmin[y]);
}
void rotate(int x,int &root)
{
    int y=fa[x],z=fa[y],p,q;
    if(c[y][0]==x)  p=0; else p=1;
    q=p^1;
    if(y==root)  root=x;
    else
    {
        if(c[z][0]==y)  c[z][0]=x;  else c[z][1]=x;
    }
    fa[y]=x;fa[x]=z;fa[c[x][q]]=y;
    c[y][p]=c[x][q];c[x][q]=y;
    updata(y);updata(x);
}
void splay(int x,int &root)
{
    int y,z;
    while(x!=root)
    {
        y=fa[x];z=fa[y];
        if(y!=root)
        {
            if((c[y][0]==x) ^ (c[z][0]==y))  rotate(x,root);
            else rotate(y,root);
        }
        rotate(x,root);
    }
}
void downgo(int x)
{
    int y=c[x][0],z=c[x][1];
    if(fz[x])
    {
        swap(c[x][0],c[x][1]); 
        swap(lmin[y],rmin[y]);swap(lmax[y],rmax[y]);
        swap(lmin[z],rmin[z]);swap(lmax[z],rmax[z]);
        fz[y]^=1;fz[z]^=1;fz[x]=0;
    }
    if(qf[x])
    {
        sum[y]=-sum[y];sum[z]=-sum[z];v[y]=-v[y];v[z]=-v[z];
        int tmp;
        tmp=lmax[y];lmax[y]=-lmin[y];lmin[y]=-tmp;
        tmp=rmax[y];rmax[y]=-rmin[y];rmin[y]=-tmp;
        tmp=lmax[z];lmax[z]=-lmin[z];lmin[z]=-tmp;
        tmp=rmax[z];rmax[z]=-rmin[z];rmin[z]=-tmp;
        qf[y]^=1;qf[z]^=1;qf[x]=0;
    }
}
int find(int x,int k)
{
    downgo(x);
    int y=c[x][0],z=c[x][1];
    if(size[y]+1==k) return x;  else
    if(size[y]>=k)  return find(y,k);
    else return find(z,k-size[y]-1); 
}
void build(int l,int r,int last)
{
    if(l>r) return;
    if(l==r)
    {
        int t=bh[l];v[t]=zhi[l];updata(t);fa[t]=bh[last]; 
        if(l<last)  c[bh[last]][0]=t; else c[bh[last]][1]=t;
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid-1,mid);build(mid+1,r,mid);
    v[bh[mid]]=zhi[mid];fa[bh[mid]]=bh[last];
    updata(bh[mid]);
    if(mid<last)  c[bh[last]][0]=bh[mid];  else c[bh[last]][1]=bh[mid];
}
int ask(int a,int b)
{
    int x=find(rot,a),y=find(rot,b+2);
    splay(x,rot);splay(y,c[x][1]);
    int k=c[y][0];
    return (rmax[k]+1)/2-(lmin[k]-1)/2;
}
void fanzhuan(int a,int b)
{
    int x=find(rot,a),y=find(rot,b+2);
    splay(x,rot);splay(y,c[x][1]);
    int k=c[y][0];
    fz[k]^=1; 
    swap(lmin[k],rmin[k]);swap(lmax[k],rmax[k]);
}
void qufang(int a,int b)
{
    int x=find(rot,a),y=find(rot,b+2);
    splay(x,rot);splay(y,c[x][1]);
    int k=c[y][0];
    qf[k]^=1;
    sum[k]=-sum[k];v[k]=-v[k];
    int tmp;
    tmp=lmax[k];lmax[k]=-lmin[k];lmin[k]=-tmp;
    tmp=rmax[k];rmax[k]=-rmin[k];rmin[k]=-tmp;
}
int main()
{
    int i,k,a,b;
    scanf("%d%d",&n,&q);
    scanf("%s",s+1);
    for(i=1;i<=n;i++)
    {
        if(s[i]=='(')  zhi[i+1]=1;  else zhi[i+1]=-1;
    }
    n+=2;   
    for(i=1;i<=n;i++)  bh[i]=++sz;
    build(1,n,0);
    rot=(1+n)>>1; 
     
    for(i=1;i<=q;i++)
    {
        scanf("%d%d%d",&k,&a,&b);
        if(k==0)  printf("%d\n",ask(a,b));  else
        if(k==2)  fanzhuan(a,b);  else 
        qufang(a,b);
    }
    //system("pause");
    return 0;
}