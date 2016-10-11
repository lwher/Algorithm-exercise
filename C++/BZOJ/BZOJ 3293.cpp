#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[100001];
long long c[100001];
long long tot,ans;
int read()
{
    char ch=getchar();
    int f=1,x=0;
    while(!(ch>='0'&&ch<='9')){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}
    return x*f;
}
int main()
{
    n=read();
    for(int i=1;i<=n;i++)
    {
        a[i]=read();
        tot+=a[i];
    }
    tot/=n;
    for(int i=2;i<=n;i++)
       c[i]=c[i-1]+(a[i-1]-tot);
    sort(c+1,c+n+1);
    int tmp=c[(n+1)/2];
    for(int i=1;i<=n;i++)
        ans+=abs(tmp-c[i]);
    printf("%lld",ans);
    return 0;
}