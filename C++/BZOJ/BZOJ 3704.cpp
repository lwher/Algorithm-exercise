#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int x[10000010],h[10000010];
int a[10000010],b[10000010];
inline int read()
{
    char ch=getchar();
    while(!(ch>='0' && ch<='9')) ch=getchar();
    return (ch-'0');
}
int n,ans,top,tot;
int main()
{
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++) a[i]=read();
    for(i=1;i<=n;i++) b[i]=read();
    for(i=1;i<=n;i++) 
    {
       x[i]=b[i]-a[i];
       if(x[i]<0) x[i]+=4;
    }
    top=0;
    for(i=1;i<=n;i++)
    if(x[i]!=x[i-1])
    {
        if(x[i]>x[i-1]) h[top+1]=h[top]+x[i]-x[i-1];
        else h[top+1]=h[top]+x[i]+4-x[i-1];
        top++;
    }
    n=top;
    ans=h[top];
    for(i=n;i>=1;i--) h[i]-=h[i-1];
    x[n+1]=0;
    for(i=n;i;i--)
    {
        x[i]=h[i]+x[i+1];
        if(x[i]>0) x[i]=0;
    }
    tot=0;
    for(i=1;i<=n;i++)
    {
        tot+=h[i];
        if(h[i]==3 && tot-4+x[i+1]>=0)
        {
            tot-=4;h[i]-=4;ans-=3;
        }
    }
    x[n+1]=0;
    for(i=n;i;i--)
    {
        x[i]=h[i]+x[i+1];
        if(x[i]>0) x[i]=0;
    }
    tot=0;
    for(i=1;i<=n;i++)
    {
        tot+=h[i];
        if(h[i]==2 && tot-4+x[i+1]>=0)
        {
            tot-=4;h[i]-=4;ans-=2;
        } 
    }
    x[n+1]=0;
    for(i=n;i;i--)
    {
        x[i]=h[i]+x[i+1];
        if(x[i]>0) x[i]=0;
    }
    tot=0;
    for(i=1;i<=n;i++)
    {
        tot+=h[i];
        if(h[i]==1 && tot-4+x[i+1]>=0)
        {
            tot-=4;h[i]-=4;ans-=1;
        } 
    }
    printf("%d\n",ans);
    //system("pause");
    return 0;
}
