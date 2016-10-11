#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
int n,m;
int tmp,ans;
int f[1001][1001];
bool map[1001][1001];
int main()
{
    int i,j;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    scanf("%d",&map[i][j]);
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    if(map[i][j])
    {
       tmp=min(min(f[i-1][j-1],f[i-1][j]),f[i][j-1]);
       f[i][j]=tmp+1;
       if(tmp+1>ans)
       ans=tmp+1;
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}
