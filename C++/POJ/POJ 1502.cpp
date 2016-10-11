#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define INF 999999999;
using namespace std;
int dui[105];
int map[105][105],d[105];
int n;
bool mark[105];
void spfa()
{
     int tou=0,wei=1,now,i;
     dui[1]=1;
     mark[1]=1;
     for(i=2;i<=n;i++)
     d[i]=INF;
     d[1]=0;
     
     while(tou!=wei)
     {
         tou++;
         now=dui[tou];
         if(tou==100)  tou=0;
         for(i=1;i<=n;i++)
         if(i!=now)
         {
             if(map[now][i]==999999999)  continue;
             if(d[i]>d[now]+map[now][i])
             {
                d[i]=d[now]+map[now][i];
                if(!mark[i])
                {wei++;dui[wei]=i;mark[i]=1;if(wei==100) wei=0;}
             }
         }
         mark[now]=0;
     }
     
}
int main()
{
    int i,j,x,y,maxx;
    int rec[105];
    char t[110];
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=n;j++)
             {
                 if(i==j) map[i][j]=0;
                 else map[i][j]=INF;
             }
        }
       for(j=2;j<=n;j++)
       {
           for(i=1;i<=j-1;i++)
           {
               scanf("%s",t);
               if(t[0]=='x')
               {
                   map[j][i]=INF;
                   map[i][j]=INF;
               }
               else
               {
                   map[j][i]=atoi(t);  
                   map[i][j]=atoi(t);
               }
           }
       }
           spfa();
           maxx=0;
           for(i=2;i<=n;i++)
           {
               if(maxx<d[i]) 
               {maxx=d[i];}
           }
           printf("%d\n",maxx);
    }
    return 0;
}
