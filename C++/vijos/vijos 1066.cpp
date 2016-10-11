#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
struct sth
{
       int x,y;
}dian[15010];
int bh[15010];
int ans[15010];
int n;
int t[32010];
inline bool comp(sth a,sth b)
{
       if(a.x==b.x)  return a.y<b.y;
       return a.x<b.x;
}
int lowbit(int x)
{
    return (x & (-x));
}
void add(int x)
{
     while(x<=32000)
     {
          t[x]++;
          x+=lowbit(x);
     }
}
int getans(int x)
{
    int sum=0;
    while(x>0)
    {
        sum+=t[x];
        x-=lowbit(x);
    }
    return sum;
}
int main()
{
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)  scanf("%d%d",&dian[i].x,&dian[i].y);
    sort(dian+1,dian+1+n,comp);
    for(i=1;i<=n;i++)
    {
         bh[i]=getans(dian[i].y);
         add(dian[i].y);   
    }
    for(i=n-1;i>=1;i--)  if(dian[i].x==dian[i+1].x && dian[i].y==dian[i+1].y)  bh[i]=bh[i+1];
    for(i=1;i<=n;i++)  ans[bh[i]]++;
    for(i=0;i<=n-1;i++)
    {
        printf("%d\n",ans[i]);
    }
    system("pause");
    return 0;
}
