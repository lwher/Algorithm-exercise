#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int q[200010],n;double x[200010];
double r[200010];
double calc(int j,int k)
{
       if(fabs(r[k]-r[j])<0.0001)  return 1e20;
       return (sqrt(r[k])*x[j]-sqrt(r[j])*x[k])/(sqrt(r[k])-sqrt(r[j]));
}
double getans(int a,int b)
{
       if(r[b]<0.0001)   return 1e20;
       return (double(x[a])-x[b])*(x[a]-x[b])/(4.000*r[b]);
}
int main()
{
    //freopen("balloon.in","r",stdin);
    //freopen("balloon.out","w",stdout);
    int top=1,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)  scanf("%lf%lf",&x[i],&r[i]);
    q[1]=1;
    for(i=2;i<=n;i++)
    {
        while(top>1 && calc(q[top-1],q[top])<x[i])  top--;
        r[i]=min(r[i],getans(i,q[top]));
        while(top>0 && r[q[top]]<=r[i])  top--;
        while(top>1 && calc(q[top-1],q[top])<calc(q[top],i))  top--;
        top++;q[top]=i;
    }
    for(i=1;i<=n;i++) printf("%.3lf\n",r[i]);
    //system("pause");
    return 0;
}
