#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int n,m,mod;
int c[310][310],det[310],f[310][310];
void getc()
{
    int i,j;
    for(i=0;i<=300;i++) 
    {
        c[i][0]=1;c[i][i]=1;
        for(j=1;j<i;j++)   c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
    }
}
void solve()
{
    int i,j,k,a,b;
    long long tmp;
    memset(det,0,sizeof(det));
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&a,&b);det[b]++;
    }
    for(i=n;i>=1;i--)  det[i]+=det[i+1];
    for(i=1;i<=n;i++)  if(n-i+1<det[i])  {printf("NO\n");return;}
    memset(f,0,sizeof(f));
    f[n+1][0]=1;
    for(i=n;i>=1;i--)
    {
        for(j=0;j<=n-i+1-det[i];j++)
        {
            tmp=0;
            for(k=0;k<=j;k++)
            {
                tmp=(tmp+(long long)(f[i+1][j-k])*c[j][k])%mod;
            }
            f[i][j]=(int)(tmp);
        }
    }
    printf("YES %d\n",f[1][n-m]);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&mod);
        getc();
        solve();
    }
    //system("pause");
    return 0;
}