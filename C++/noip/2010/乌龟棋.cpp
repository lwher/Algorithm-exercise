#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int n,m;
int f[41][41][41][41];
int gs[5];
int v[351];
int ans;
int main()
{
    int i,j,k,p,x;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)  scanf("%d",&v[i]);
    for(i=1;i<=m;i++)
    {
        scanf("%d",&x);
        gs[x]++;
    }
    memset(f,-1,sizeof(f));
    f[0][0][0][0]=v[1];
    for(i=0;i<=gs[1];i++)
    for(j=0;j<=gs[2];j++)
    for(k=0;k<=gs[3];k++)
    for(p=0;p<=gs[4];p++)
    if(f[i][j][k][p]!=-1)
    {
        if(i<gs[1])  f[i+1][j][k][p]=max(f[i+1][j][k][p],f[i][j][k][p]+v[1+(i+1)+j*2+k*3+p*4]);
        if(j<gs[2])  f[i][j+1][k][p]=max(f[i][j+1][k][p],f[i][j][k][p]+v[1+i+(j+1)*2+k*3+p*4]);
        if(k<gs[3])  f[i][j][k+1][p]=max(f[i][j][k+1][p],f[i][j][k][p]+v[1+i+j*2+(k+1)*3+p*4]);
        if(p<gs[4])  f[i][j][k][p+1]=max(f[i][j][k][p+1],f[i][j][k][p]+v[1+i+j*2+k*3+(p+1)*4]);
    }
    cout<<f[gs[1]][gs[2]][gs[3]][gs[4]]<<endl;
    system("pause");
    return 0;
}
