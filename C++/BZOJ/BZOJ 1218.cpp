#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,r;
unsigned int f[5010][5010],ans;
int main()
{
    int i,j,x,y,w,h,s;
    scanf("%d%d",&n,&r);
    h=0;s=0;
    for(i=1;i<=n;i++)  
    {
        scanf("%d%d%d",&x,&y,&w);
        f[x+1][y+1]=w;
        h=max(x+1,h);s=max(y+1,s);
    }
    h=min(h+r,5001);s=min(s+r,5001);
    for(i=1;i<=h;i++)  for(j=1;j<=s;j++)
    {
        f[i][j]+=f[i-1][j]+f[i][j-1]-f[i-1][j-1];
        if(i>=r && j>=r)  ans=max(ans,f[i][j]-f[i-r][j]-f[i][j-r]+f[i-r][j-r]);
    }
    cout<<ans<<endl;
    //system("pause");
    return 0;
}