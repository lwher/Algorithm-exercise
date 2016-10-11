#include<iostream>
#include<cstdio>
#include<cstdlib>
int main()
{
    int n,m,i,j,k,a[201],b[201][201]={0},x;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=1;i<=m;i++)
    {
    scanf("%d%d%d",&j,&k,&x);
    x+=a[k];
    if((b[j][k]==0)||(x<b[j][k]))
    b[j][k]=x;
    }
    for(k=1;k<=n;k++)
    for(i=1;i<=n;i++)
    if(b[i][k])
    for(j=1;j<=n;j++)
    if((b[k][j])&&((b[k][j]+b[i][k]<b[i][j])||(!b[i][j])))
    b[i][j]=b[k][j]+b[i][k];
    if(!b[1][1])printf("-1\n");
    else printf("%d\n",b[1][1]);
    system("pause");
    return 0;
}
