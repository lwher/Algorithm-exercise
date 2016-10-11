#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
long long x[2010],y[2010];
int n;
long long now=1e20;
int a,b;
int main()
{
    int i,j;
    cin>>n;
    for(i=1;i<=n;i++)
    cin>>x[i]>>y[i];
    for(i=1;i<n;i++)
    for(j=i+1;j<=n;j++)
    {
       if((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])<now)
       {now=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);a=i;b=j;}
    }
    cout<<a<<" "<<b<<endl;
    system("pause");
    return 0;
}
