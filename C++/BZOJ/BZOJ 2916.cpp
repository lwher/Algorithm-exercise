#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int n,m,d[1010],ans,tmp;
int main()
{
    int i,a,b;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++) 
    {
        scanf("%d%d",&a,&b);
        d[a]++;d[b]++;
    } 
    ans=n*(n-1)*(n-2)/6;
    for(i=1;i<=n;i++)  tmp+=d[i]*(n-1-d[i]);
    tmp/=2;
    ans-=tmp;
    cout<<ans<<endl;
    system("pause");
    return 0;
}
