#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
struct sth
{
   int a,b;
}p[100010];
int n,sz,now;
int best[100010];
inline bool comp(sth aa,sth bb)
{
     if(aa.a==bb.a)  return aa.b<bb.b;
     return aa.a>bb.a;
}
int main()
{
    int i,x,l,r,mid,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if(x-i<=0)
        {
            sz++;
            p[sz].a=x-i;
            p[sz].b=x;
        }  
    }
    sort(p+1,p+1+sz,comp);
    best[0]=-1;now=0;
    for(i=1;i<=sz;i++)
    {
        l=0;r=now;
        while(l+1<r)
        {
            mid=(l+r)>>1;
            if(best[mid]<p[i].b)  l=mid;
            else r=mid;
        }
        if(best[r]<p[i].b)  k=r; else k=l;
        k++;
        if(k>now)  {now=k;best[k]=p[i].b;}
        best[k]=min(best[k],p[i].b);
    }
    cout<<now<<endl;
    system("pause");
    return 0;
}
