#include<iostream>
#include<cstdio> 
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
int n,A[1010][1010],B[1010][1010],C[1010][1010],D[1010];
int ans1[1010],ans2[1010];
void mul(int b[1010][1010],int a[1010],int c[1010])
{
    int i,j,ans[1010];
    for(i=1;i<=n;i++)
    {
        ans[i]=0;
        for(j=1;j<=n;j++)  ans[i]+=a[j]*b[i][j];
    }
    for(i=1;i<=n;i++)  c[i]=ans[i];
}
bool ok()
{
    for(int i=1;i<=n;i++)  if(ans1[i]!=ans2[i])  return 0;  return 1;
}
int main()
{
    int i,j;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)  for(j=1;j<=n;j++)  scanf("%d",&A[i][j]);
        for(i=1;i<=n;i++)  for(j=1;j<=n;j++)  scanf("%d",&B[i][j]);
        for(i=1;i<=n;i++)  for(j=1;j<=n;j++)  scanf("%d",&C[i][j]);
        for(i=1;i<=n;i++)  D[i]=rand()%2557+1;
        mul(B,D,ans1);
        mul(A,ans1,ans1);
        mul(C,D,ans2);
        if(ok())  printf("Yes\n");  else   printf("No\n");
    }
    return 0;
}