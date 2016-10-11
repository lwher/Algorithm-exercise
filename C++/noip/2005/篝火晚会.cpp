#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,p[50010];
int l[50010],r[50010];
bool mark[50010];
int hash[50010],maxx;
void init()
{
     int i;
     scanf("%d",&n);
     for(i=1;i<=n;i++) scanf("%d%d",&l[i],&r[i]);
}
void solve()
{
     int i,j=1;     
     for(i=1;i<=n;i++)
     {
         p[i]=j;
         mark[j]=1;
         if(mark[l[j]])  j=r[j];  else  j=l[j];
         if(mark[j] && i!=n) {printf("-1\n");return;}
     }
     for(i=1;i<=n;i++)
     {
         if(p[i]>=i)  {hash[p[i]-i]++;if(hash[p[i]-i]>maxx) maxx=hash[p[i]-i];}
         else  {hash[p[i]-i+n]++;if(hash[p[i]-i+n]>maxx) maxx=hash[p[i]-i+n];}
     }
     memset(hash,0,sizeof(hash));
     for(i=n;i>=1;i--)
     {
         if(p[i]>=n-i+1)  {hash[p[i]-n+i-1]++;if(hash[p[i]-n+i-1]>maxx) maxx=hash[p[i]-n+i-1];}
         else  {hash[p[i]+i-1]++;if(hash[p[i]+i-1]>maxx) maxx=hash[p[i]+i-1];}
     }
     printf("%d\n",n-maxx);
}

int main()
{
    init();
    solve();
    system("pause");
    return 0;
}
