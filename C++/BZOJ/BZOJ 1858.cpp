#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#define N 500010
using namespace std;
int n,m,maxx1,rs1;
int l0[N],r0[N],l1[N],r1[N],max0[N],max1[N],sum0[N],sum1[N],gs[N];//gs[x]=1 :->1 gs[x]=2: ->0
bool qf[N];
void updata(int x,int l,int r)
{
    int y=x+x,z=x+x+1,mid=(l+r)>>1;
    if(l0[y]==mid-l+1)  l0[x]=l0[y]+l0[z]; else l0[x]=l0[y];
    if(r0[z]==r-mid)  r0[x]=r0[z]+r0[y]; else r0[x]=r0[z];
    if(l1[y]==mid-l+1)  l1[x]=l1[y]+l1[z]; else l1[x]=l1[y];
    if(r1[z]==r-mid)  r1[x]=r1[z]+r1[y]; else r1[x]=r1[z];
    max0[x]=max(max0[y],max0[z]);
    max0[x]=max(max0[x],r0[y]+l0[z]);
    max1[x]=max(max1[y],max1[z]);
    max1[x]=max(max1[x],r1[y]+l1[z]);
    sum0[x]=sum0[y]+sum0[z];
    sum1[x]=sum1[y]+sum1[z];
}
void swap(int &a,int &b)
{
    int t=a;a=b;b=t;
}
void downgo(int k,int l,int r)
{
    int y=k+k,z=k+k+1,mid=(l+r)>>1;
    if(gs[k]!=0)
    {
        if(gs[k]==1)
        {
            l1[y]=r1[y]=sum1[y]=max1[y]=mid-l+1;l0[y]=r0[y]=max0[y]=sum0[y]=0;
            l1[z]=r1[z]=sum1[z]=max1[z]=r-mid;l0[z]=r0[z]=sum0[z]=max0[z]=0;
        }
        else
        {
            l1[y]=r1[y]=sum1[y]=max1[y]=0;l0[y]=r0[y]=sum0[y]=max0[y]=mid-l+1;
            l1[z]=r1[z]=sum1[z]=max1[z]=0;l0[z]=r0[z]=sum0[z]=max0[z]=r-mid;
        }
        gs[y]=gs[k];gs[z]=gs[k];qf[y]=0;qf[z]=0;
        gs[k]=0;
    }
    if(qf[k])
    {
        swap(l1[y],l0[y]);swap(r1[y],r0[y]);swap(max0[y],max1[y]);swap(sum0[y],sum1[y]);
        swap(l1[z],l0[z]);swap(r1[z],r0[z]);swap(max0[z],max1[z]);swap(sum0[z],sum1[z]);
        qf[y]^=1;qf[z]^=1;qf[k]=0;
    }
}
void change(int k,int l,int r,int zuo,int you,int num)
{
    if(l>=zuo && r<=you) 
    {
        if(num==0)  
        {
            l0[k]=r0[k]=sum0[k]=max0[k]=r-l+1;
            l1[k]=r1[k]=sum1[k]=max1[k]=0;
            qf[k]=0;gs[k]=2;
        }else
        {
            l0[k]=r0[k]=sum0[k]=max0[k]=0;
            l1[k]=r1[k]=sum1[k]=max1[k]=r-l+1;
            qf[k]=0;gs[k]=1;
        }
        return;
    }
    if(gs[k]!=0 || qf[k]) downgo(k,l,r);
    int mid=(l+r)>>1;
    if(zuo<=mid)  change(k+k,l,mid,zuo,you,num);
    if(you>mid)  change(k+k+1,mid+1,r,zuo,you,num);
    updata(k,l,r);
}
void qufang(int k,int l,int r,int zuo,int you)
{
    if(l>=zuo && r<=you)
    {
        swap(l1[k],l0[k]);swap(r1[k],r0[k]);swap(max0[k],max1[k]);swap(sum0[k],sum1[k]);
        qf[k]^=1;
        return;
    }
    if(gs[k]!=0 || qf[k]) downgo(k,l,r);
    int mid=(l+r)>>1;
    if(zuo<=mid)  qufang(k+k,l,mid,zuo,you);
    if(you>mid)  qufang(k+1+k,mid+1,r,zuo,you);
    updata(k,l,r);
}
int asksum(int k,int l,int r,int zuo,int you)
{
    if(l>=zuo && r<=you)  return sum1[k];
    if(gs[k]!=0 || qf[k]) downgo(k,l,r);
    int p=0,mid=(l+r)>>1;
    if(zuo<=mid)  p+=asksum(k+k,l,mid,zuo,you);
    if(you>mid)  p+=asksum(k+k+1,mid+1,r,zuo,you);
    return p;
}
void askmaxx(int k,int l,int r,int zuo,int you)
{
    if(l>=zuo && r<=you)
    {
        maxx1=max(maxx1,max1[k]);
        maxx1=max(maxx1,rs1+l1[k]);
        if(sum1[k]==r-l+1)  rs1+=sum1[k]; else rs1=r1[k];
        return;
    }
    if(gs[k]!=0 || qf[k]) downgo(k,l,r);
    int mid=(l+r)>>1;
    if(zuo<=mid)  askmaxx(k+k,l,mid,zuo,you);
    if(you>mid)  askmaxx(k+k+1,mid+1,r,zuo,you);
}
int main()
{
    int i,k,l,r,x;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&x);
        change(1,1,n,i,i,x);
    }       
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&k,&l,&r);
        l++;r++;
        if(k==0)  change(1,1,n,l,r,0);  else
        if(k==1)  change(1,1,n,l,r,1);  else
        if(k==2)  qufang(1,1,n,l,r);   else    
        if(k==3)  printf("%d\n",asksum(1,1,n,l,r)); else
        {
            maxx1=0;rs1=0;
            askmaxx(1,1,n,l,r);
            printf("%d\n",maxx1);
        }
    }
    return 0;
}