#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define inf 1e9
using namespace std;
int n,a[2010],c[2010];
int f[2010][2010],m[2010][2010],ans;
inline bool comp(int aa,int bb) {return aa>bb;}
int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)  
    {
        scanf("%d",&a[i]);c[i]=a[i];
    }
    sort(c+1,c+1+n);
    for(i=1;i<=n;i++)  m[i][0]=inf;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)  
        {
            f[i][j]=m[i-1][j]+abs(a[i]-c[j]);
            m[i][j]=min(m[i][j-1],f[i][j]);
        }
    }
    ans=m[n][n];
    sort(c+1,c+1+n,comp);
    memset(f,0,sizeof(f));
    memset(m,0,sizeof(m));
    for(i=1;i<=n;i++)  m[i][0]=inf;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)  
        {
            f[i][j]=m[i-1][j]+abs(a[i]-c[j]);
            m[i][j]=min(m[i][j-1],f[i][j]);
        }
    }
    ans=min(ans,m[n][n]);
    printf("%d\n",ans);
    return 0;
}