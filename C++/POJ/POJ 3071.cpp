#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int n,m;
double p[130][130],f[10][130];;
int main()
{
    int i,j,k;
    while(scanf("%d",&n))
    {
       if(n==-1)  break;
       m=1<<n;
       memset(f,0,sizeof(f));
       for(i=0;i<m;i++)  f[0][i]=1;
       for(i=0;i<m;i++)  for(j=0;j<m;j++)  scanf("%lf",&p[i][j]);       
       for(i=1;i<=n;i++)
       for(j=0;j<m;j++)
       for(k=0;k<m;k++)
       if(((k>>(i-1))^1)==(j>>(i-1)))
       f[i][j]+=f[i-1][j]*f[i-1][k]*p[j][k];
       int ans;double now=-1;
       for(j=0;j<m;j++)  if(f[n][j]>now)  {now=f[n][j];ans=j;}
       printf("%d\n",ans+1);
    }
    system("pause");
    return 0;
}
