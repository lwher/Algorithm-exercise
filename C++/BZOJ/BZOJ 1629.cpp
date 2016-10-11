#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
struct sth
{
       int w,s;
}cow[50010];
int n,sum,ans=-1e20;
inline bool comp(sth a,sth b)
{
    return (a.w+a.s)>(b.w+b.s);
}
int main()
{
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {scanf("%d%d",&cow[i].w,&cow[i].s);sum+=cow[i].w;}
    sort(cow+1,cow+1+n,comp);
    for(i=1;i<=n;i++)
    {
       if(ans<sum-cow[i].w-cow[i].s)
       ans=sum-cow[i].w-cow[i].s;
       sum-=cow[i].w;
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}
