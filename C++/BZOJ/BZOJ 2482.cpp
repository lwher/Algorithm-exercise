#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
struct sth
{
    int l,r,w,ans;
}xw[100010];
int tmax[500010],emax[500010],tag[500010],etag[500010],pre[200010];
int n,m,num[100010];
inline bool comp(sth a,sth b) {return a.r<b.r;}
inline bool cmp(sth a,sth b) {return a.w<b.w;}
void pushdown(int x)
{
    int y=(x<<1),z=(y|1);
    etag[y]=max(etag[y],tag[y]+etag[x]);
    etag[z]=max(etag[z],tag[z]+etag[x]);
    tag[y]+=tag[x];tag[z]+=tag[x];
    tag[x]=0;etag[x]=0;
}
void updata(int x)
{
    int y=(x<<1),z=(y|1);
    emax[x]=max(max(emax[y],tmax[y]+etag[y]),max(emax[z],tmax[z]+etag[z]));
    tmax[x]=max(tmax[y]+tag[y],tmax[z]+tag[z]);
}
void add(int k,int l,int r,int zuo,int you,int shu)
{
    if(l>=zuo && r<=you)  
    {
        tag[k]+=shu;etag[k]=max(etag[k],tag[k]);
        return;
    }
    if(tag[k]!=0 || etag[k]!=0)  pushdown(k);
    int mid=(l+r)>>1;
    if(zuo<=mid)  add(k+k,l,mid,zuo,you,shu);
    if(you>mid)  add(k+k+1,mid+1,r,zuo,you,shu);
    updata(k);
}
int query(int k,int l,int r,int zuo,int you)
{
    if(r<zuo || l>you)  return -INF;
    if(l>=zuo && r<=you)  return max(emax[k],tmax[k]+etag[k]);
    if(tag[k]!=0 || etag[k]!=0)  {pushdown(k);updata(k);}
    int mid=(l+r)>>1;
    return max(query(k+k,l,mid,zuo,you),query(k+k+1,mid+1,r,zuo,you));
}
int main()
{
    int i,now=1;
    scanf("%d",&n);
    for(i=1;i<=n;i++)  scanf("%d",&num[i]);
    scanf("%d",&m);
    for(i=1;i<=m;i++)  {scanf("%d%d",&xw[i].l,&xw[i].r);xw[i].w=i;}
    sort(xw+1,xw+1+m,comp); 
    for(i=1;i<=n;i++)
    {
        add(1,1,n,pre[num[i]+100000]+1,i,num[i]);
        pre[num[i]+100000]=i;
        while(xw[now].r==i)  
        {
            xw[now].ans=query(1,1,n,xw[now].l,i);
            now++;
        }
    }
    sort(xw+1,xw+1+m,cmp);
    for(i=1;i<=m;i++)  printf("%d\n",xw[i].ans);
    return 0;
}