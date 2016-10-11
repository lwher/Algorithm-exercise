#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m;
unsigned long long C[1000010][5],ans;
void getC()
{
    int i,j,k;
    C[0][0]=1;
    for(i=1;i<=1000000;i++)
    {
        C[i][0]=1;k=min(3,i);
        for(j=1;j<=k;j++)  C[i][j]=C[i-1][j]+C[i-1][j-1];
    }
}
int gcd(int a,int b)
{
    if(b==0)  return a;
    return gcd(b,a%b);
}
int main()
{
    int i,j,gs;
    unsigned long long tmp;
    getC();
    scanf("%d%d",&n,&m);
    ans=C[(n+1)*(m+1)][3];
    for(i=1;i<=n;i++) for(j=1;j<=m;j++)
    {
        gs=gcd(i,j)+1;
        if(gs<3)  continue;
        tmp=gs-2;
        tmp*=2;
        tmp*=(n-i+1)*(m-j+1);
        ans-=tmp;
    }
    tmp=C[n+1][3];tmp*=(m+1);ans-=tmp;
    tmp=C[m+1][3];tmp*=(n+1);ans-=tmp;
    cout<<ans<<endl;
    return 0;
}