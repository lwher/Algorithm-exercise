#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int map[35][35],ans[35];
void init()
{
     int i;
     memset(map,0,sizeof(map));
     for(i=0;i<30;i++)
     {
          scanf("%d",&map[i][30]);
          ans[i]=0;
     }
}
void build()
{
     int i,j,nx,ny,x,y;
     for(i=0;i<30;i++)
     {
        nx=i/6;ny=i%6;
        for(j=0;j<30;j++)
        {
            x=j/6;y=j%6;
            if(abs(nx-x)+abs(ny-y)<=1)  map[i][j]=1;
            else map[i][j]=0;
        }
     }
}
void swap(int &a,int &b)
{
     int t=a;a=b;b=t;
}
bool Gauss()
{
     int i,j,k,r;
     for(k=0;k<30;k++)
     {
         i=k;
         while(i<30 && map[i][k]==0)  i++;
         if(i>k) for(r=0;r<=30;r++)  swap(map[k][r],map[i][r]);
         for(i=0;i<30;i++)
         {
             if(i==k || map[i][k]==0)  continue;
             for(j=0;j<=30;j++)  map[i][j]^=map[k][j];  
         }
     }
     for(i=0;i<30;i++)
     {
         if(map[i][30])
         {
         for(j=0;j<30 && !map[i][j];j++);
         if(j==30)  return 0;
         ans[j]=map[i][30];
         }
     }
     return 1;
}
int main()
{
    int t,tt=0;;
    scanf("%d",&t);
    while(t--)
    {
         init();
         build();
         tt++;
         printf("PUZZLE #%d\n",tt);
         Gauss();
         for(int i=0;i<30;i++)
         {
                 printf("%d",ans[i]);
                 if(i%6==5)  printf("\n");
                 else  printf(" ");
         }
       
    }
    system("pause");
    return 0;
}
