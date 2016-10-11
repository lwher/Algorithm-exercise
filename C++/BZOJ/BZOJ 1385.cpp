#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int gcd(int a,int b)
{
    if(b==0)  return a;
    return gcd(b,a%b);
}
int n,num[10010];
void solve()
{
    int i;
    num[2]/=gcd(num[1],num[2]);
    for(i=3;i<=n;i++)  num[2]/=gcd(num[2],num[i]);
    if(num[2]==1)  printf("YES\n");  else  printf("NO\n");
}
int main()
{
    int i,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)  scanf("%d",&num[i]);
        solve();
    }
    //system("pause");
    return 0;
}