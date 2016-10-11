#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define INF 100000000
using namespace std;
int n,map[310][310],v[310],path[310][310];
void floyd()
{
    int i,j,k;
    for(k=1;k<=n;k++)
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    {
        if(map[i][k]+map[k][j]+v[k]<map[i][j])
        {
            map[i][j]=map[i][k]+map[k][j]+v[k];path[i][j]=path[i][k];
        }else
        if(map[i][k]+map[k][j]+v[k]==map[i][j])
        {
            if(path[i][j]>path[i][k])  path[i][j]=path[i][k];
        }
    }
}
int main()
{
    int i,j,c,a,b;
    while(scanf("%d",&n) && n)
    {
        for(i=1;i<=n;i++)  for(j=1;j<=n;j++)  
        {
            path[i][j]=j;
            scanf("%d",&map[i][j]);
            if(map[i][j]==-1)  map[i][j]=INF;
        }
        for(i=1;i<=n;i++)  scanf("%d",&v[i]);
        floyd();
        while(scanf("%d%d",&a,&b))
        {
            if(a==-1 && b==-1)  break;
            printf("From %d to %d :\n",a,b);
            printf("Path: %d",a);
            c=a;
            while(c!=b)
            {
                c=path[c][b];
                printf("-->%d",c);
            }
            printf("\nTotal cost : %d\n",map[a][b]);
            printf("\n");
        }
    }
    //system("pause");
    return 0;
}
