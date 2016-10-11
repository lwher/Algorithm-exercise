#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,v,ans,f[100010],s[100010];
int main()
{
    int i,j,k,p,x,y,g;
    scanf("%d%d",&n,&v);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&p,&g);
        for(j=1;j<=v;j++) s[j]=f[j];
        for(j=1;j<=g;j++)
        {
            scanf("%d%d",&x,&y);
            for(k=v;k>=x;k--) s[k]=max(s[k],s[k-x]+y);
        }
        for(j=p;j<=v;j++) f[j]=max(f[j],s[j-p]);
    }
    for(j=1;j<=v;j++) ans=max(ans,f[j]);
    cout<<ans<<endl;
    return 0;
}