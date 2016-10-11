#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int n,k;
int l,r,w;
int now[2][100010];
int main()
{
    int i,j,p=0,q=1,u;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)  now[p][i]=i;
    while(k--)
    {
       scanf("%d%d%d",&l,&r,&w);
       j=w+1;u=1;
       for(i=l;i<=r;i++)  {now[q][j]=now[p][i];j++;}
       for(i=1;i<=w;i++)  
       {if(u==l) u=r+1;now[q][i]=now[p][u];u++;}
       for(i=j;i<=n;i++) {if(u==l) u=r+1;now[q][i]=now[p][u];u++;}
       p^=1;q^=1;
    }
    for(i=1;i<=10;i++)  printf("%d\n",now[p][i]);
    system("pause");
    return 0;
}
