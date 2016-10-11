#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int n,K,s[20];
long long f[65537][17],ans;
int main()
{
    int i,j,k,m;
    scanf("%d%d",&n,&K);
    for(i=1;i<=n;i++)  scanf("%d",&s[i]);
    m=(1<<n);
    for(i=1;i<=n;i++)  f[1<<(i-1)][i]=1;
    for(i=1;i<m;i++)
    {
        for(j=1;j<=n;j++)
        if(f[i][j]>0)
        {
            for(k=1;k<=n;k++)
            if(!(i & (1<<(k-1))) && abs(s[k]-s[j])>K)
            {
                f[i|(1<<(k-1))][k]+=f[i][j];
            }
        }
    }
    for(i=1;i<=n;i++)   ans+=f[m-1][i];
    cout<<ans<<endl;
    //system("pause");
    return 0;
}