#include<iostream>
#include<cstdio>
#include<algorithm> 
using namespace std;
int a[2010][2010],b[2010][2010];
int n,m;
int main()
{
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)for(j=1;j<=n;j++){scanf("%d",&a[i][j]);a[i][j]+=a[i-1][j];}
    for(i=1;i<=n;i++)for(j=1;j<=n;j++){scanf("%d",&b[i][j]);b[i][j]+=b[i][j-1];}
    int x,y,X,Y;
    int t;
    long long ans=0;
    while(m--)
    {
       scanf("%d%d%d%d",&x,&y,&X,&Y);
       if (x>X)  swap(x, X);
       if (y>Y)  swap(y, Y);
       ans=0;
       for(i=1;i<=n;i++)
       ans+=(long long)((a[X][i])-a[x-1][i])*(b[i][Y]-b[i][y-1]);
       printf("%lld\n",ans);
    }
    system("pause");
    return 0;
}
