#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
long long f[50][5][5];
int map[5][5];
int main()
{
    int i,j,k,n;
    long long a,b;
    for(i=1;i<=3;i++)  for(j=1;j<=3;j++)  scanf("%d",&map[i][j]);
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=3;j++)  for(k=1;k<=3;k++)
        if(j!=k)
        {
            a=f[i-1][j][6-j-k]+map[j][k]+f[i-1][6-j-k][k];
            b=f[i-1][j][k]+map[j][6-j-k]+f[i-1][k][j]+map[6-j-k][k]+f[i-1][j][k];
            f[i][j][k]=min(a,b);
        }
    }
    cout<<f[n][1][3]<<endl;
   // system("pause");
    return 0;
}