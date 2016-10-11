#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int zys[100010][20],f[100010];
int n,price[51],maxp=-1;
void getzys()
{
    int i,j,k,p;
    for(i=2;i<=100000;i++)
    {
        k=sqrt(i);p=i;
        for(j=2;j<=k;j++)
        if(p%j==0)
        {
            zys[i][++zys[i][0]]=j;
            while(p%j==0) p/=j;
        }
        if(p>1)  zys[i][++zys[i][0]]=p;
    }
}
int main()
{
    int i,j,k,d,tmp;
    getzys();
    memset(f,127,sizeof(f));
    scanf("%d",&n);
    f[1]=0;
    for(i=1;i<=n;i++)  
    {
        scanf("%d",&price[i]);
        if(price[i]>maxp) maxp=price[i];
        f[1]+=price[i];
    }
    for(i=2;i<=maxp;i++)
    {
        for(j=1;j<=zys[i][0];j++)
        {
            d=zys[i][j];
            tmp=0;
            for(k=1;k<=n;k++)  tmp+=(price[k]/i)*(d-1);
            tmp=f[i/d]-tmp;
            f[i]=min(f[i],tmp);
        }
    }
    int ans=0x7fffffff;
    for(i=1;i<=maxp;i++)  ans=min(ans,f[i]);
    printf("%d\n",ans);
    return 0;
}