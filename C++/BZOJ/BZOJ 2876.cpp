#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
double e,l,r,s[10010],k[10010],v_[10010],v[10010],maxv[10010],L,R,mid,x,a,b,c,d,t,ans;
int n;
int main()
{
    int i,p,q;
    scanf("%d%lf",&n,&e);
    l=-1000;r=0;
    for(i=1;i<=n;i++)
    {
        scanf("%lf%lf%lf",&s[i],&k[i],&v_[i]);
        if(s[i]>0) maxv[i]=sqrt(e/(k[i]*s[i]))+v_[i];
        else maxv[i]=0;
    }
    for(p=1;p<=80;p++)
    {
        mid=(l+r)*0.5;t=0;
        for(i=1;i<=n;i++)
        {
            a=2*mid*k[i];b=-a*v_[i];d=1;
            L=max(v_[i],1e-6);R=maxv[i];
            for(q=1;q<=80;q++)
            {
                x=(L+R)*0.5;
                if(a*x*x*x+b*x*x+d>0) L=x; else R=x;
            }
            v[i]=(L+R)*0.5;
            t+=k[i]*s[i]*(v[i]-v_[i])*(v[i]-v_[i]);
        }
        if(t<e) l=mid; else r=mid;
    }
    for(i=1;i<=n;i++) ans+=s[i]/v[i];
    printf("%.9lf\n",ans);
    system("pause");
    return 0;
} 
