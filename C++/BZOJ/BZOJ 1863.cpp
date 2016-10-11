#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,a[20010],l[20010],r[20010],ans;
bool check(int k)
{
     l[1]=r[1]=a[1];
     for(int i=2;i<=n;i++)
     {
         l[i]=0;r[i]=a[i];
         r[i]=min(a[1]-l[i-1],r[i]);
         l[i]=max(l[i],a[1]+a[i-1]+a[i]-r[i-1]-k);
     }
     if(l[n]==0)  return 1;
     else return 0;
}
int main()
{
    int i,L,R,mid;
    scanf("%d",&n);
    for(i=1;i<=n;i++)  
    {
       scanf("%d",&a[i]);
       ans=max(ans,a[i]+a[i-1]);
    }
    L=ans;R=ans*2;
    while(L+1<R)
    {
       mid=(L+R)>>1;
       if(check(mid))  R=mid;
       else  L=mid;
    }
    if(check(L))   printf("%d\n",L);
    else  printf("%d\n",R);
    system("pause");
    return 0;
}
