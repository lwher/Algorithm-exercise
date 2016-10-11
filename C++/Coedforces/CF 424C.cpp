#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int data[1000010];
int s[1000010];
int n,ans=0;
int main()
{
    int tmp;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&data[i]);ans^=data[i];
    }
    for(int i=1;i<=n;i++)  s[i]=s[i-1]^i;
    for(int i=1;i<=n;i++)
    {
        tmp=n%(2*i);
        if(tmp==i) ans^=s[i-1];  else
        if(tmp>i)  {ans^=s[i-1]^s[tmp-i];}
        else  ans^=s[tmp];
    }
    printf("%d\n",ans);
    return 0;
}