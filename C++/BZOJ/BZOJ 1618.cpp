#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int f[100010];
int n,h;
int v[101],c[101];
int main()
{
    int i,j;
    scanf("%d%d",&n,&h);
    memset(f,127,sizeof(f));
    for(i=1;i<=n;i++)  scanf("%d%d",&v[i],&c[i]);
    f[0]=0;
    for(i=1;i<=n;i++)
    for(j=v[i];j<=h+6000;j++)
    {
        f[j]=min(f[j],f[j-v[i]]+c[i]);
    }
    int ans=1e20;
    for(i=h;i<=h+6000;i++)
    ans=min(ans,f[i]);
    cout<<ans<<endl;
    system("pause");
    return 0;
}
