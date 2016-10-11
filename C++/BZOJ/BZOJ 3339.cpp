#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define N 200002
using namespace std;
struct sth
{
    int l,r,bh;
}xw[200010];
int n,q,tmin[800010],A[200010],ans[200010];
int read()
{
    char ch=getchar();
    while(!(ch>='0' && ch<='9'))  ch=getchar();
    int x=0;
    while(ch>='0' && ch<='9')  {x=x*10+(ch-'0');ch=getchar();}
    return x;
}
void updata(int k,int l,int r,int x,int num)
{
     if(l==r) {tmin[k]=num;return;}
     int mid=(l+r)>>1;
     if(x<=mid) updata(k+k,l,mid,x,num);
     else  updata(k+k+1,mid+1,r,x,num);
     tmin[k]=min(tmin[k+k],tmin[k+k+1]);
}
inline bool comp(sth a,sth b)
{
     return a.r<b.r; 
}
int query(int x)
{
    int k=1,l=1,r=N,mid;
    while(l!=r)
    {
       mid=(l+r)>>1;
       if(tmin[k+k]<x) {k<<=1;r=mid;}
       else  {k=k+k+1;l=mid+1;}
    }
    return l-1;
}
int main()
{
    int i,now=1;
    n=read();q=read();//scanf("%d%d",&n,&q);
    for(i=1;i<=n;i++)  A[i]=read();//scanf("%d",&A[i]);
    for(i=1;i<=q;i++)
    {
       xw[i].l=read();xw[i].r=read();//scanf("%d%d",&xw[i].l,&xw[i].r);
       xw[i].bh=i;
    } 
    sort(xw+1,xw+1+q,comp);
    for(i=1;i<=n;i++)
    {
        updata(1,1,N,A[i]+1,i);
        while(now<=q && xw[now].r==i)
        {
            ans[xw[now].bh]=query(xw[now].l);
            now++;
        }
    }
    for(i=1;i<=q;i++)  printf("%d\n",ans[i]);
    return 0;
}