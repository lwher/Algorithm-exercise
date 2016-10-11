//适用于二分图某一边的点可以匹配多个点的最大匹配 网络流可代替 POJ 2112
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int K,n,c,m,l,r,mid;
int num[31],pipei[31][350],map[350][350];
bool d[31];
bool find(int x)
{
     int i,j;
     for(i=1;i<=K;i++)
     {       
        if(d[i] || map[x][i]>mid)  continue;     
        d[i]=1;
        if(num[i]<m)   
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
     for(i=K+1;i<=n;i++)
     {
         memset(d,0,sizeof(d));
         if(!find(i))  return 0;
     }
     return 1;
}
void floyd()
{
     int i,j,k;
     for(k=1;k<=n;k++) for(i=1;i<=n;i++) for(j=1;j<=n;j++)
     if(map[i][k]+map[k][j]<map[i][j])    map[i][j]=map[i][k]+map[k][j];
}
int main()
{
    int i,j;
    scanf("%d%d%d",&K,&c,&m);
    n=K+c;
    for(i=1;i<=n;i++)  for(j=1;j<=n;j++)  
    {
       scanf("%d",&map[i][j]);
       if(i!=j && map[i][j]==0)  map[i][j]=1e8;
    }
    floyd();
    l=0;r=1e9;        
    while(l+1<r)
    {
        mid=(l+r)>>1;
        if(check())  r=mid;  
        else l=mid;
    }
    mid=l; if(check())  printf("%d\n",l);  else  printf("%d\n",r);
    system("pause");
    return 0;
}
