#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
int num[10010],best[10010],lis[10010];
int ans;
int n,m;
int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    scanf("%d",&num[i]);
    int l,r,mid,k;
    best[0]=2147483647;  
    for(i=n;i>=1;i--)
    {
      l=0;r=ans;
      while(l<r)
      {
         if(l+1==r)  break;
         mid=(l+r)/2;
         if(best[mid]>num[i])
         l=mid;
         else
         r=mid;
      }
      if(best[r]>num[i])
      k=r;
      else
      k=l;
      if(k+1>ans) ans=k+1;
      best[k+1]=num[i];
      lis[i]=k+1;
    }
    cin>>m;
    int now=-2147483647;
    for(i=1;i<=m;i++)
    {
      scanf("%d",&k);
     if(k>ans)
     {printf("Impossible\n");}
     else
     {   
         now=-2147483647;
         for(j=1;j<=n;j++)
         if(lis[j]>=k && num[j]>now)
         {
           if(k==1)
           {printf("%d\n",num[j]);break;}
           else
           {
           printf("%d ",num[j]);
           k--;
           now=num[j];
           }
         }
     }
    }
    system("pause");
    return 0;
}
