 
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,top,q[100010],h[100010],orz[100010];
int main()
{
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&h[i]);
    for(i=1;i<=n;i++)
    {
        while(top>0 && h[i]>h[q[top]])  
        {
            orz[q[top]]=i;top--;
        }
        q[++top]=i;
    }
    for(i=1;i<=n;i++)  printf("%d\n",orz[i]);
    return 0;
}