#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
int lmax[2000000],rmax[2000000],mmax[2000000],sum[2000000];
bool o;
void add(int l,int r,int k,int x,int num)
{
     if(l==r)  {lmax[k]=num;rmax[k]=num;mmax[k]=num;sum[k]=num;return;}
     int mid=(l+r)>>1;
     if(x<=mid)  add(l,mid,k+k,x,num);
     if(x>mid) add(mid+1,r,k+k+1,x,num);
     mmax[k]=max(mmax[k+k],mmax[k+k+1]);
     sum[k]=sum[k+k]+sum[k+k+1];
     lmax[k]=max(lmax[k+k],lmax[k+k+1]+sum[k+k]);
     rmax[k]=max(rmax[k+k+1],sum[k+k+1]+rmax[k+k]);
     mmax[k]=max(mmax[k],rmax[k+k]+lmax[k+k+1]);
}
void ask(int l,int r,int k,int zuo,int you)
{
     if(l>=zuo && r<=you)
     {
     if(!o)
     {
           mmax[0]=mmax[k];
           lmax[0]=lmax[k];
           rmax[0]=rmax[k];
           sum[0]=sum[k];
           o=1;
     }
     else
     {
     mmax[0]=max(mmax[0],mmax[k]);
     mmax[0]=max(mmax[0],rmax[0]+lmax[k]);   
     lmax[0]=max(lmax[0],lmax[k]+sum[0]);
     rmax[0]=max(rmax[k],sum[k]+rmax[0]);  
     sum[0]=sum[0]+sum[k];
     }
     return;
     }
     int mid=(l+r)>>1;
     if(zuo<=mid)   ask(l,mid,k+k,zuo,you);
     if(you>mid)    ask(mid+1,r,k+k+1,zuo,you);
}
int main()
{
    int n,m,a,b,kk;
    int i,j;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
       scanf("%d",&a);
       add(1,n,1,i,a);
    }
    for(i=1;i<=m;i++)
    {
       scanf("%d%d%d",&kk,&a,&b);
       if(kk==2)
       {
               add(1,n,1,a,b);
       }
       else
       {
           if(a>b)
           {int p;p=a;a=b;b=p;}
           o=0;
           ask(1,n,1,a,b);
           printf("%d\n",mmax[0]);
       }
    }
    system("pause");
    return 0;
}
