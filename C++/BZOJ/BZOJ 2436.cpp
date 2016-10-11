#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define INF 10000000
using namespace std;
int n,s[210],t[210],X[410];
int num[410][410],a[410][210],b[410][210];
int f[410][410];
int main()
{
    int i,j,k,x,y;
    scanf("%d",&n);
    for(i=1;i<=n;i++) 
    {
        scanf("%d%d",&s[i],&t[i]);
        t[i]+=s[i];
        X[i+i-1]=s[i];
        X[i+i]=t[i];
    }
    sort(X+1,X+1+n*2);
    int nx=unique(X+1,X+1+n*2)-X-1;
    for(i=1;i<=n;i++)
    {
        s[i]=lower_bound(X+1,X+nx+1,s[i])-X;
        t[i]=lower_bound(X+1,X+nx+1,t[i])-X;
    }
    for(i=1;i<=nx;i++) for(j=i;j<=nx;j++) for(k=1;k<=n;k++)
    if(s[k]>=i && t[k]<=j) num[i][j]++;
    for(i=1;i<=nx;i++) for(j=1;j<=n+1;j++) a[i][j]=b[i][j]=-INF;
    for(i=1;i<=nx;i++) for(j=num[1][i];j>=0;j--)
    {
        a[i][j]=a[i][j+1];
        for(k=0;k<i;k++)
        {
            a[i][j]=max(a[i][j],a[k][j]+num[k][i]);
            if(j>=num[k][j]) a[i][j]=max(a[i][j],a[k][j-num[k][i]]);
        }
    }
    for(i=nx;i;i--) for(j=num[i][nx];j>=0;j--)
    {
        b[i][j]=b[i][j+1];
        for(k=i+1;k<=nx+1;k++)
        {
            b[i][j]=max(b[i][j],b[k][j]+num[i][k]);
            if(j>=num[k][i]) b[i][j]=max(b[i][j],b[k][j-num[i][k]]);
        }
    }
    int ans=0;
    for(i=0;i<=n;i++) ans=max(ans,min(a[nx][i],i));
    printf("%d\n",ans);
    for(i=1;i<nx;i++) for(j=i+1;j<=nx;j++)
    {
        y=num[j][nx];
        for(x=0;x<=num[1][i];x++)
        {
            for(;y && min(x+y+num[i][j],a[i][x]+b[j][y])<=min(x+y-1+num[i][j],a[i][x]+b[j][y-1]);y--);
            f[i][j]=max(f[i][j],min(x+y+num[i][j],b[j][y]+a[i][x]));
        }
    }
    for(i=1;i<=n;i++)
    {
        ans=0;
        for(j=s[i];j;j--) for(k=t[i];k<=nx;k++) ans=max(ans,f[j][k]);
        printf("%d\n",ans);
    }
    return 0;
}