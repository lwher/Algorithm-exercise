#include<iostream>
#include<cstdio>
using namespace std;
int f[1001][100];
int n,k,i,j,l;
int main()
{
        scanf("%d%d",&n,&k);
        f[0][1]=1;
        for(i=1;i<=k;++i)
        for(j=i;j<=n;++j)
        {
         for(l=1;l<=40;++l)
         f[j][l]=f[j][l]+f[j-i][l];
         for(l=1;l<=40;++l)
         {
         f[j][l+1]=f[j][l+1]+f[j][l]/10;
         f[j][l]%=10;
         }
         }
         j=40;
         while(f[n][j]==0)--j;
         for(i=j;i>=1;--i)
         printf("%d",f[n][i]);
         printf("\n");
         system("pause");
         return 0;
}
