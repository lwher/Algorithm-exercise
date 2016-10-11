#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int n,m;
int map[210][210];
int main()
{
    int i,j;
    long long d,tmp1=0,tmp2=0;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)  for(j=1;j<=m;j++)
    {
        scanf("%d",&map[i][j]);
        d=(i-1)*(i-1)+(j-1)*(j-1);
        tmp1+=d*map[i][j];
    }
    for(i=1;i<=n;i++)  for(j=1;j<=m;j++)
    {
        scanf("%d",&map[i][j]);
        d=(i-1)*(i-1)+(j-1)*(j-1);
        tmp2+=d*map[i][j];
    }
    cout<<(tmp1-tmp2)/2<<endl;
    system("pause");
    return 0;
}
