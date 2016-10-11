#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,m,f[10010],t[10010],x[10010],y[10010],maxx[10010];
int main()
{
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)  scanf("%d%d%d",&t[i],&x[i],&y[i]);
    f[1]=1;maxx[1]=1;
    for(i=2;i<=m;i++)
    {
        f[i]=1;
        for(j=i-1;j>=1;j--)  
        {
            if(maxx[j]+1<=f[i]) break;
            if(f[j]+1>f[i] && abs(x[i]-x[j])+abs(y[i]-y[j])<=t[i]-t[j])  f[i]=f[j]+1;
        }
        maxx[i]=max(f[i],maxx[i-1]);
    }
    int ans=0;
    for(i=1;i<=m;i++)  if(f[i]>ans)  ans=f[i];
    cout<<ans<<endl;
    //system("pause");
    return 0;
}