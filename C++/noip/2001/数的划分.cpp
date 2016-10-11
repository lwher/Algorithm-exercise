#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
long long f[7][201][201],ans;
int n,K;
int main()
{
    scanf("%d%d",&n,&K);
    int i,j,k,l;
    for(i=1;i<=n;i++)  f[1][i][i]=1;
    for(i=1;i<K;i++)
    for(j=1;j<=n;j++)
    for(k=1;k<=j;k++)
    if(f[i][j][k])
    {
       for(l=k;l<=n-j;l++)
       f[i+1][j+l][l]+=f[i][j][k];
    }
    for(i=1;i<=k;i++)
    ans+=f[K][n][i];
    cout<<ans<<endl;
    system("pause");
    return 0;
}
