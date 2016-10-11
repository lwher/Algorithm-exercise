#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int k,n,sz;
long long prime[110];
int now[110];
long long num[100010];
int main()
{
    int i,j;
    long long nmin;
    scanf("%d%d",&k,&n);n++;
    for(i=1;i<=k;i++)  cin>>prime[i];//scanf("%d",&prime[i]);
    sort(prime+1,prime+1+k);
    for(i=1;i<=k;i++)  now[i]=1;
    num[++sz]=1;
    while(sz<=n)
    {
         nmin=10000000000LL;
         for(i=1;i<=k;i++)
         {
         while(num[now[i]]*prime[i]<=num[sz])  now[i]++;
         if(num[now[i]]*prime[i]<nmin)
         {
             nmin=num[now[i]]*prime[i];j=i;
         }
         }
         now[j]++;
         num[++sz]=nmin;
    }
    cout<<num[n]<<endl;
    system("pause");
    return 0;
}
