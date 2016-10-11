#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int n,c[51];
int main()
{
    int i,l,r,mid;long long t;
    scanf("%d%d",&n,&c[0]);
    for(i=1;i<=n;i++)  scanf("%d",&c[i]);
    l=0;r=1000000000;
    while(l+1<r)
    {
        mid=(l+r)>>1;t=0;
        for(i=0;i<=n;i++)  if(c[i]<mid)  t+=mid-c[i];
        if(t<=mid) l=mid; else r=mid;
    }
    t=0;
    for(i=0;i<=n;i++)  if(c[i]<r)  t+=r-c[i];
    if(t<=r)  printf("%d\n",r); else printf("%d\n",l);
    return 0;
}