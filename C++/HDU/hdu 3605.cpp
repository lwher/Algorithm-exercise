#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
bool map[100010][10],d[11];
int num[11],pipei[11][100010],C[11];
bool find(int x)
{
    int i,j;
    for(i=1;i<=m;i++) 
    if(!d[i] && map[x][i])
    {
        d[i]=1;
        if(num[i]<C[i]) 
        {
            pipei[i][++num[i]]=x;
            return 1;
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
int main()
{
    int i,j;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(num,0,sizeof(num));
        for(i=1;i<=n;i++)  for(j=1;j<=m;j++)  scanf("%d",&map[i][j]);
        for(i=1;i<=m;i++)  scanf("%d",&C[i]);
        bool o=0;
        for(i=1;i<=n;i++)
        {
            memset(d,0,sizeof(d));
            if(!find(i))  {o=1;break;}
        }
        if(o)  printf("NO\n");  else printf("YES\n");
    }
    //system("pause");
    return 0;
}