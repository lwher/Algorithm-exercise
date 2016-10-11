#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
using namespace std;
int a[50002];
int L,N,M;
bool can_cross(int mid)
{
    int i,start=0,sum=0;
    for(i=1;i<=N;i++)
    {
        if(a[i]-start<mid)sum++;
        else start=a[i];
    }
    if(a[i]-start<mid) sum++;

    if(sum>M)return false;//¾àÀëÌ«´ó
    else return true;

}

int main()
{
   int i,left,right,mid,ans;
   scanf("%d%d%d",&L,&N,&M);
   
      for(i=1;i<=N;i++)
      scanf("%d",&a[i]);

      a[N+1]=L;
      sort(a+1,a+N+1);

      left=0;
      right=L;
      while(left<=right)
      {
          mid=(left+right)/2;

          if(can_cross(mid))
          {
             left=mid+1;
             ans=mid;
          }
          else right=mid-1;
      }
      printf("%d\n",ans);

   
   system("pause");
   return 0;

}
