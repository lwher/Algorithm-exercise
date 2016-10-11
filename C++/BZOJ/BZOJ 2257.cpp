#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,k,a[10000010],top;
void find(int x)
{
    int i,b,limt=sqrt(x);
    for(i=1;i<=limt;i++)
    if(x%i==0)
    {
        a[++top]=i;
        b=x/i;
        if(b!=i)  a[++top]=b;
    }
}
inline bool comp(int a,int b)  {return a>b;}
int main()
{
    int i,x;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)  
    {
        scanf("%d",&x);
        find(x);
    }
    sort(a+1,a+1+top,comp);
    for(i=1;i<=top;i++)
    {
        if(a[i]!=a[i-1])  x=1;
        else x++;
        if(x>=k)  {printf("%d\n",a[i]);break;}
    }
    return 0;
}