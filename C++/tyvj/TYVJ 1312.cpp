#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int a[1010];
long long ans;
inline bool comp(int aa,int bb)
{
       return aa<bb;
}
int main()
{
    int i;
    int aa,bb;
    scanf("%d",&n);
    for(i=1;i<=n;i++)  scanf("%d",&a[i]);
    sort(a+1,a+1+n,comp);
    while(n>3)
    {
       aa=a[n]+a[2]*2+a[1];
       bb=a[1]*2+a[n]+a[n-1];
       ans+=min(aa,bb);
       n-=2;
    }
    if(n==3)  ans+=a[2]+a[3]+a[1];
    if(n==2)  ans+=a[2];
    if(n==1)  ans+=a[1];
    cout<<ans<<endl;
    system("pause");
    return 0;
}
