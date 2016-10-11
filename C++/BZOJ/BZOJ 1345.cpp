#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,top;
int zhan[1000010];
long long ans;
int main()
{
    int i,a;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        while(top>1 && zhan[top]<a)
        {ans+=min(zhan[top-1],a);top--;}
        if(top==1 && zhan[top]<a)
        {ans+=a;top--;}
        top++;zhan[top]=a;
    }
    for(i=top-1;i>=1;i--)
    ans+=zhan[i];
    cout<<ans<<endl;
    system("pause");
    return 0;
}
