#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int n;
int map[1010][1010];
int d[1010],last[1010];
int dui[30010];
bool mark[1010];
void init()
{
     int i,j;
     scanf("%d",&n);
     for(i=1;i<=n;i++)  for(j=1;j<=n;j++)  scanf("%d",&map[i][j]);
}
void spfa()
{
     memset(d,127,sizeof(d));
     int tou=1,wei=1,i,now;
     dui[1]=1;mark[1]=1;d[1]=0;
     while(tou<=wei)
     {
        now=dui[tou];tou++;
        for(i=1;i<=n;i++)
        {
            if(map[now][i]>0)
            {
                if(d[now]+map[now][i]<d[i])
                {
                    d[i]=d[now]+map[now][i];last[i]=now;
                    if(!mark[i])  {mark[i]=1;wei++;dui[wei]=i;}
                }
            } 
        }
        mark[now]=0;
     }
}
void print(int x)
{
     if(x==0)  return;
     print(last[x]);
     printf("%d ",x);
}
int main()
{
    init();
    spfa();
    print(n);
    printf("\n%d\n",d[n]);
    system("pause");
    return 0;
}
