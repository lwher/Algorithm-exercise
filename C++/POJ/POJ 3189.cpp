#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,l,r;
int num[21],pipei[21][1010],map[1010][21],C[21];
bool d[21];
bool find(int x)
{
     int i,j;
     for(i=1;i<=m;i++)
     {       
        if(d[i] || map[x][i]<l || map[x][i]>r)  continue;     
        d[i]=1;
        if(num[i]<C[i])   
        {
           pipei[i][++num[i]]=x;return 1;
        }
        for(j=1;j<=num[i];j++)
        {
           if(find(pipei[i][j]))
           {
               pipei[i][j]=x;return 1;
           }
        }
     }
     return 0;
}
bool check()
{
     int i;
     memset(num,0,sizeof(num));
     for(i=1;i<=n;i++)
     {
         memset(d,0,sizeof(d));
         if(!find(i))  return 0;
     }
     return 1;
}
int main()
{
    int i,j,k,ans;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)  for(j=1;j<=m;j++)  {scanf("%d",&k);map[i][k]=j;}
    for(i=1;i<=m;i++)  scanf("%d",&C[i]);
    l=1;r=1;ans=1e8;
    while(l<=r && r<=m)
    {
        if(check())  {ans=min(ans,r-l+1);l++;} else r++;
    }
    printf("%d\n",ans);
    system("pause");
    return 0;
}
