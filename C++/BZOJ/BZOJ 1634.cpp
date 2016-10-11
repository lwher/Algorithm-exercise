#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define ll long long
#define Maxn 100005
using namespace std;
int n,now,t[Maxn],d[Maxn],sa[Maxn];
double v[Maxn];
bool cmp(int a,int b){return v[a]<v[b];}
int main()
{
    int i; ll ans=0;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%d%d",t+i,d+i);
        v[i]=(double)t[i]/d[i]; now+=d[i];
        sa[i]=i;
    }
    sort(sa+1,sa+1+n,cmp);
    for (i=1;i<=n;i++)
    {
        now-=d[sa[i]];
        ans+=(ll)now*t[sa[i]];
    }
    ans<<=1;
    cout<<ans<<endl;
    system("pause");
    return 0;
}


