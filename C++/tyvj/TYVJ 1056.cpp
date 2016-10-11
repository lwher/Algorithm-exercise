#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n;
int a[210],f[210][210];
int main()
{
    int i,j,k,l;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
    scanf("%d",&a[i]); 
    a[i+n]=a[i];
    }
    a[n*2+1]=a[1];
    for(l=1;l<=n;l++)
    for(i=1;i+l-1<=2*n;i++)
    {
        j=i+l-1;
        for(k=i;k<=j-1;k++)
        {
           f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]+a[i]*a[k+1]*a[j+1]);
        }
    }
    int ans=0;
    for(i=1;i<=n;i++)
    {
       ans=max(ans,f[i][i+n-1]);
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}
