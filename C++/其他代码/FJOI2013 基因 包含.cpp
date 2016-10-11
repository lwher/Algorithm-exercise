#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int n,m,p,f[2][301][301];
char a[301],b[301],c[301];
int main()
{
    int i,j,k,q;
    scanf("%d%d%d",&n,&m,&p);
    scanf("%s",a+1);scanf("%s",b+1);scanf("%s",c+1);
    q=0;
    for(k=0;k<=p;k++)
    {
        memset(f[q],-1,sizeof(f[q]));
        if(k==0)
        {
            f[0][0][0]=0;
            for(i=1;i<=n;i++)  f[0][i][0]=0;
            for(j=1;j<=m;j++)  f[0][0][j]=0;
        }
        for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            f[q][i][j]=max(f[q][i-1][j],f[q][i][j-1]);
            if(a[i]==b[j])
            {
                if(k>0 && a[i]==c[k] && f[q^1][i-1][j-1]!=-1)   f[q][i][j]=max(f[q][i][j],f[q^1][i-1][j-1]+1);
                else  if(f[q][i-1][j-1]!=-1)  f[q][i][j]=max(f[q][i][j],f[q][i-1][j-1]+1);
            }
        }
        q^=1;
    }
    cout<<f[q^1][n][m]<<endl;
    //system("pause");
    return 0;
}