#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define mod 1000000007
using namespace std;
int n,m,ans,num[2010],pos[2010],f[2010][2010];
bool mark[2010];
int main()
{
    int i,j,sum;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d",&num[i]);
        mark[num[i]]=1;
    }
    for(i=1;i<=n;i++)
    {
        pos[i]=1;
        for(j=1;j<=m && num[j]!=i;j++)
        {
            pos[i]+=(num[j]<i);
        }
    }
    f[1][1]=1;
    for(i=2;i<=n;i++)
    {
        if(!mark[i])
        {
            sum=0;
            for(j=i;j>0;j--)
            {
                if(i-pos[i]>=j) f[i][j]=(f[i-1][j-1]+sum)%mod;
                else  f[i][j]=f[i-1][j-1];
                sum=(sum+f[i-1][j-1])%mod;
            }
        }
        else
        {
            if(pos[i]==i)
            {
                for(j=2;j<=n;j++) f[i][j]=f[i-1][j-1];
            }
            else
            {
                for(j=i-pos[i];j<i;j++) f[i][i-pos[i]]=(f[i][i-pos[i]]+f[i-1][j])%mod;
            }
        }
    }
    for(i=1;i<=n;i++) ans=(ans+f[n][i])%mod;
    printf("%d\n",ans);
   // system("pause");
    return 0;
}
