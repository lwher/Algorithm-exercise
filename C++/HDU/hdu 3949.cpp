#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
long long a[10010];
void swap(long long &aa,long long &bb)
{
     long long u=aa;aa=bb;bb=u;
}
int n,q,t;
int guass()
{
     int i,j,k,ans=0;
     for(k=63;k>=0;k--)
     {
         for(i=ans+1;i<=n;i++)
         if(1 & (a[i]>>k))  break;
         if(i<=n)
         {  
            swap(a[ans+1],a[i]);
            for(j=1;j<=n;j++)
            if(j!=ans+1 && ((a[j]>>k) & 1))  a[j]^=a[ans+1];
            ans++;
         }
     }
     return ans;
}
int main()
{
    long long k,i,j,c,ans;
    int now=0;
    scanf("%d",&t);        
    while(t--)
    {
              now++;
              printf("Case #%d:\n",now);
              scanf("%d",&n);
              for(i=1;i<=n;i++)  scanf("%I64d",&a[i]);
              c=guass();
              scanf("%d",&q);
              for(i=1;i<=q;i++)
              {
                   scanf("%I64d",&k);
                   if(c<n)
                   {
                        if(k==1)  {printf("0\n");continue;}
                        else   k--;
                   }
                   if(k>=((long long)1<<c))  {printf("-1\n");continue;}
                   ans=0;
                   for(j=0;j<=63;j++)   
                   if((k>>j) & 1)  
                   ans^=a[c-j];
                   printf("%I64d\n",ans);
              }
    }
    system("pause");
    return 0;
}
