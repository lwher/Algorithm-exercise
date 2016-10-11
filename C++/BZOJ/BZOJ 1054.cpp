#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
bool hash[300010][2];
int bs[300010][2];
int now[4][4],qi,zhong;
int dui[100010];
bool zf[100010];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int gethash(int a[][4])
{
    int i,j,k,hash=0;
    for(i=0;i<4;i++)  for(j=0;j<4;j++)
    {
        k=i*4+j;
        hash+=(1<<k)*a[i][j];
    }
    return hash;
}
void init()
{
     int i,j;
     char ch;
     for(i=0;i<=3;i++)  for(j=0;j<=3;j++)  
     {
         cin>>ch;now[i][j]=ch-'0';
     }
     qi=gethash(now);
     for(i=0;i<=3;i++)  for(j=0;j<=3;j++)  
     {
         cin>>ch;now[i][j]=ch-'0';
     }
     zhong=gethash(now);
}
void swap(int &a,int &b)
{
     int t=a;a=b;b=t;
}
void bfs()
{
     int tou=1,wei=2,i,j,k,K,jg,x,y,ZF;
     if(qi==zhong)  {cout<<0<<endl;return;}
     dui[1]=qi;dui[2]=zhong;zf[1]=0;zf[2]=1;
     hash[qi][0]=1;bs[qi][0]=0;
     hash[zhong][1]=1;bs[zhong][1]=0;
     while(tou<=wei)
     {
          K=dui[tou];ZF=zf[tou];tou++;
          for(i=0;i<16;i++)
          {
              if(K & (1<<i)) now[i/4][i%4]=1;
              else now[i/4][i%4]=0;
          }
          for(i=0;i<4;i++)  for(j=0;j<4;j++)
          if(now[i][j]==1)
          {
              for(k=0;k<4;k++)
              {
                   x=i+dx[k];y=j+dy[k];
                   if(x<0 || y<0 || x>3 || y>3)  continue;
                   if(now[x][y]==1)  continue;
                   swap(now[i][j],now[x][y]);
                   jg=gethash(now);
                   if(!hash[jg][ZF])
                   {
                   if(hash[jg][ZF^1])  
                   {
                       cout<<bs[K][ZF]+bs[jg][ZF^1]+1<<endl;
                       return;
                   }
                   hash[jg][ZF]=1;bs[jg][ZF]=bs[K][ZF]+1;
                   wei++;dui[wei]=jg;zf[wei]=ZF;
                   }
                   swap(now[i][j],now[x][y]);
              }
          }
     }
}
int main()
{
    init();
    bfs();
    system("pause");
    return 0;
}
