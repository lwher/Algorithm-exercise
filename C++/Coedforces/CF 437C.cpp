#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int n,m,v[1010];
long long ans;
int main()
{
    int i,a,b;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) scanf("%d",&v[i]);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
        ans+=min(v[a],v[b]);
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}
