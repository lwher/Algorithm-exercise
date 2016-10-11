#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int n,ans,w[16],c[16],l[16],x,y;// c:len l:red
int exgcd(int a,int b)
{
    if(!b) {x=1,y=0;return a;}
    int d=exgcd(b,a%b),t=x;
    x=y;y=t-a/b*y;
    return d;
}
bool ok(int sum)
{
     int i,j,L,W,d,b;
     for(i=1;i<n;i++) for(j=i+1;j<=n;j++)
     {
         L=c[i]-c[j];b=sum;W=w[j]-w[i];
         if(L<0) L*=-1,W*=-1;
         d=exgcd(L,b);
         if(W%d!=0) continue;
         L/=d;b/=d;W/=d;
         exgcd(L,b);
         x=(x%b+b)%b;
         x=(x*W%b+b)%b;
         if(!x) x+=b;
         if(x<=min(l[i],l[j])) return 0;
     }
     return 1;
}
int main()
{
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d%d",&w[i],&c[i],&l[i]);
        ans=max(ans,w[i]);
    }
    for(;;ans++) if(ok(ans)) break;
    cout<<ans<<endl;
    return 0;
}