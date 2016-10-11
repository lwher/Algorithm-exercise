#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,top;
int yl[50010];
int zhan[50010];
int h[50010],v[50010];
int main()
{
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)  scanf("%d%d",&h[i],&v[i]);
    top=1;zhan[1]=1;
    for(i=2;i<=n;i++)
    {
       while(top>=1 && h[zhan[top]]<h[i])   {yl[i]+=v[zhan[top]];top--;}
       top++;zhan[top]=i;
    }
    top=1;zhan[1]=n;
    for(i=n-1;i>=1;i--)
    {
       while(top>=1 && h[zhan[top]]<h[i])   {yl[i]+=v[zhan[top]];top--;}
       top++;zhan[top]=i;
    }
    int ans=0;
    for(i=1;i<=n;i++)
    if(yl[i]>ans)  ans=yl[i];
    cout<<ans<<endl;
    system("pause");
    return 0;
}
