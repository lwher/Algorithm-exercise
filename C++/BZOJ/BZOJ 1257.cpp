#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
long long p=1,n,k,ans;
int main()
{
    cin>>n>>k;
    ans=n*k;
    long long l,r,mid,q;
    while(p<=n)
    {
        l=p;r=n;
        while(l+1<r)
        {
            mid=(l+r)>>1;
            if(k/mid<k/p)  r=mid;  else l=mid;
        }
        if(k/r==k/p)  q=r;  else q=l;
        ans-=(q-p+1)*(q+p)/2*(k/p);
        p=q+1;
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}
