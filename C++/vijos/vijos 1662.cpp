#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int a[100010],b[100010],n,k;
long long ans;
inline bool comp(int a,int b)
{
       return a<b;
}
inline bool cmp(int a,int b)
{
       return a>b;
}
int main()
{
    int i,j,now1,now2;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    for(i=1;i<=n;i++) scanf("%d",&b[i]);
    sort(a+1,a+1+n,comp);
    sort(b+1,b+1+n,cmp);
    i=1;j=n;
    while(k>0)
    {
         now1=abs(a[i]-b[i]);
         now2=abs(a[j]-b[j]);
         if(now1>now2)  {ans+=now1;i++;}
         else           {ans+=now2;j--;}
         k--;
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}
