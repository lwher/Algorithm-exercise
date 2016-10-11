#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int n,m,sz,num,root[500010],ls[10000010],rs[10000010],sum[10000010];
int read()
{
    char ch=getchar();
    while(!(ch>='0' && ch<='9'))  ch=getchar();
    int x=0;
    while(ch>='0' && ch<='9')  {x=x*10+(ch-'0');ch=getchar();}
    return x;
}
void updata(int l,int r,int x,int &y,int w)
{
     y=++sz;
     sum[y]=sum[x]+1;
     if(l==r) return;
     ls[y]=ls[x];rs[y]=rs[x];
     int mid=(l+r)>>1;
     if(w<=mid) updata(l,mid,ls[x],ls[y],w);
     else  updata(mid+1,r,rs[x],rs[y],w);
}
int query(int L,int R)
{
    int l=1,r=n,mid,x,y,tmp=(R-L+1)/2;
    x=root[L-1];y=root[R];
    while(l!=r)
    {
        if(sum[y]-sum[x]<=tmp)  return 0;
        mid=(l+r)>>1;
        if(sum[ls[y]]-sum[ls[x]]>tmp) 
        {
            r=mid;x=ls[x];y=ls[y];
        }else
        if(sum[rs[y]]-sum[rs[x]]>tmp)
        {
            l=mid+1;x=rs[x];y=rs[y];
        }
        else return 0;
    }
    return l;
}
int main()
{
    int i,l,r;
    n=read();m=read();
    for(i=1;i<=n;i++)  
    {
        num=read();
        updata(1,n,root[i-1],root[i],num);
    }        
    for(i=1;i<=m;i++)
    {
        l=read();r=read();
        printf("%d\n",query(l,r));
    }
    system("pause");
    return 0;
}
