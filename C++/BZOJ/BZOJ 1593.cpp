#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 200010
using namespace std;
int n,m;
int la[N],ra[N],maxx[N],flag[N];//flag:  0 ->2   1->1
void updata(int k,int l,int r)
{
    int y=k+k,z=k+k+1,mid=(l+r)>>1;;
    maxx[k]=max(max(maxx[y],maxx[z]),ra[y]+la[z]);
    if(la[y]==mid-l+1)  la[k]=la[y]+la[z];  else la[k]=la[y];
    if(ra[z]==r-mid)  ra[k]=ra[z]+ra[y];  else ra[k]=ra[z];
}
void downgo(int k,int l,int r)
{
    int y=k+k,z=k+k+1,mid=(l+r)>>1;
    if(flag[k]==2)
    {
        la[y]=ra[y]=maxx[y]=mid-l+1;
        la[z]=ra[z]=maxx[z]=r-mid;
        flag[y]=flag[z]=2;
    }
    else
    {
        la[y]=ra[y]=maxx[y]=0;
        la[z]=ra[z]=maxx[z]=0;
        flag[y]=flag[z]=1;
    }
    flag[k]=0;
}
void change(int k,int l,int r,int zuo,int you,int ys)
{
    if(l>=zuo && r<=you)  
    {
        if(ys==1)  {la[k]=ra[k]=maxx[k]=0;flag[k]=1;}
        else {la[k]=ra[k]=maxx[k]=r-l+1;flag[k]=2;}
        return;
    }
    if(flag[k]!=0) downgo(k,l,r);
    int mid=(l+r)>>1;
    if(zuo<=mid)  change(k+k,l,mid,zuo,you,ys);
    if(you>mid)  change(k+k+1,mid+1,r,zuo,you,ys);
    updata(k,l,r);
}
int ask(int k,int l,int r,int len)
{
    if(flag[k]!=0) downgo(k,l,r);
    int y=k+k,z=k+1+k,mid=(l+r)>>1;
    if(maxx[y]>=len)  return ask(y,l,mid,len);  else
    if(ra[y]+la[z]>=len)  return mid-ra[y]+1;  else
    return ask(z,mid+1,r,len);
}
int main()
{
    int i,k,l,r,d,p;
    scanf("%d%d",&n,&m);
    change(1,1,n,1,n,2);
    for(i=1;i<=m;i++)
    {
        scanf("%d",&k);
        if(k==1)
        {
            scanf("%d",&d);
            if(maxx[1]<d)  printf("0\n");
            else
            {
                p=ask(1,1,n,d);
                printf("%d\n",p);
                change(1,1,n,p,p+d-1,1);
            }
        }
        else
        {
            scanf("%d%d",&l,&r);
            change(1,1,n,l,l+r-1,2);
        }
    }
    return 0;
}