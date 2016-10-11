#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int n;
int a[1010],b[1010];
int main()
{
    int i;
    int t;
    cin>>t;
    while(t--)
    {
    cin>>n;
    for(i=1;i<=n;i++)
    {
       scanf("%d",&a[i]);
    }
    memset(b,0,sizeof(b));
    if(n & 1)
    {
         b[1]=a[1];
         for(i=2;i<=n;i+=2)
         b[i/2+1]=a[i+1]-a[i];
    }
    else
    {
        for(i=1;i<=n;i+=2)
        b[i/2+1]=a[i+1]-a[i];
    }
    int ans=0;
    for(i=1;i<=n/2+1;i++)
    ans^=b[i];
    if(!ans)
    printf("NIE\n");
    else
    printf("TAK\n");
    }
    system("pause");
    return 0;
}
