#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct sth
{
    int l,r,a;
}xw[1000010];
const int INF=0x7fffffff;
int n,m,xsz,sum;
int top,tot,num[1000010],shu[1000010];
int tmax[5000010],tadd[5000010];
inline bool comp(sth a,sth b)
{
    return a.r<b.r;
}
int find(int x)
{
    int l=1,r=tot,mid;
    while(l+1<r)
    {
        mid=(l+r)>>1;
        if(num[mid]==x) return mid;
        if(num[mid]>x) r=mid;
        else l=mid;
    }
    if(num[r]==x) return r;return l;
}
void downput(int k)
{
    tmax[k<<1]+=tadd[k];tmax[k<<1|1]+=tadd[k];
    tadd[k<<1]+=tadd[k];tadd[k<<1|1]+=tadd[k];
    tadd[k]=0;
}
void add(int k,int l,int r,int zuo,int you,int x)
{
    if(l>=zuo && r<=you) 
    {
       tadd[k]+=x;tmax[k]+=x;
       return;
    }
    if(tadd[k]>0) downput(k);
    int mid=(l+r)>>1;
    if(zuo<=mid) add(k<<1,l,mid,zuo,you,x);
    if(you>mid) add(k<<1|1,mid+1,r,zuo,you,x);
    tmax[k]=max(tmax[k<<1],tmax[k<<1|1]);
}
int askmax(int k,int l,int r,int zuo,int you)
{
    if(l>you || r<zuo) return -INF;
    if(l>=zuo && r<=you) return tmax[k];
    if(tadd[k]>0) downput(k);
    int mid=(l+r)>>1;
    return max(askmax(k<<1,l,mid,zuo,you),askmax(k<<1|1,mid+1,r,zuo,you));
}
bool solve()
{
     if(sum>m) return 0;
     sort(xw+1,xw+1+xsz,comp);
     int i;
     memset(tmax,0,sizeof(tmax));
     memset(tadd,0,sizeof(tadd));
     for(i=1;i<=tot;i++) add(1,1,tot,i,i,num[i]-1);
     for(i=1;i<xsz;i++)
     {
         add(1,1,tot,1,xw[i].l,xw[i].a);
         if(askmax(1,1,tot,1,xw[i].r)>num[xw[i].r]) return 0;
     }       
     return 1;
}
int main()
{
    int i,T,l,r,a;
    scanf("%d",&T);
    while(T--)
    {
        xsz=0;top=0;tot=0;sum=0;
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
        {
            scanf("%d%d%d",&l,&r,&a);
            l++;r++;sum+=a;
            if(l<=r)  
            {
                xw[++xsz].l=l;xw[xsz].r=r;xw[xsz].a=a;
                xw[++xsz].l=l+m;xw[xsz].r=r+m;xw[xsz].a=a;
            }
            else
            {
                xw[++xsz].l=l;xw[xsz].r=r+m;xw[xsz].a=a;
            }
        }    
        for(i=1;i<=xsz;i++)
        {
            shu[++top]=xw[i].l;shu[++top]=xw[i].r;
        } 
        sort(shu+1,shu+1+top);
        num[++tot]=1;
        for(i=2;i<=top;i++) if(shu[i]!=shu[i-1]) num[++tot]=shu[i];
        for(i=1;i<=xsz;i++) {xw[i].l=find(xw[i].l);xw[i].r=find(xw[i].r);}                
        if(solve()) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
