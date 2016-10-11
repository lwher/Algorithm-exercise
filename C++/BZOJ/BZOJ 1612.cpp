#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,m;
int ans;
int map[101][101];
int main()
{
    int i,j,k;
    int a,b;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)  map[i][i]=1;
    for(i=1;i<=m;i++)
    {scanf("%d%d",&a,&b);map[a][b]=1;}
    for(k=1;k<=n;k++)
    for(i=1;i<=n;i++)
    if(map[i][k])
    for(j=1;j<=n;j++)
    if(map[k][j])
    map[i][j]=1;
    bool o;
    o=1;
    for(i=1;i<=n;i++)
    {
    o=1;
    for(j=1;j<=n;j++)
    {
                     if(!map[i][j] && !map[j][i])  {o=0;break;}
    }
    if(o) 
    ans++;
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}
