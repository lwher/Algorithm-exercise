#include<iostream>
#include<cstdio>
using namespace std;
bool f[50010];
int n,v[50010],c;
int main()
{
    int i,j;
    scanf("%d%d",&c,&n);
    for(i=1;i<=n;i++)
    scanf("%d",&v[i]);
    f[0]=1;
    for(i=1;i<=n;i++)
    for(j=c;j>=v[i];j--)
    if(f[j-v[i]])  f[j]=1;
    for(i=c;i>=0;i--)
    if(f[i]) break;
    cout<<i<<endl;
    system("pause");
    return 0;
}
