#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
long long f[1030][1010];
char s[21];
int num[21],n,d,gs[21];
int main()
{
    int T,i,j,k,p;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s %d",s,&d);
        n=strlen(s);
        memset(gs,0,sizeof(gs));
        for(i=0;i<n;i++)   {num[i]=s[i]-'0';gs[num[i]]++;}
        memset(f,0,sizeof(f));
        f[0][0]=1;
        for(i=0;i<(1<<n);i++)
        for(k=0;k<n;k++)
        if(!(i & (1<<k)))
        {
           p=i|(1<<k);
           for(j=0;j<d;j++)
           {
              f[p][(j*10+num[k])%d]+=f[i][j];
           }
        }
        for(i=0;i<=9;i++)
        {
           k=1;
           for(j=1;j<=gs[i];j++)  k*=j; 
           f[(1<<n)-1][0]/=k;
        }
        printf("%lld\n",f[(1<<n)-1][0]);
    }
    system("pause");
    return 0;
}
