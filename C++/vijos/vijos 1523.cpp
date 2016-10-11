#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int n,m,K,f[301][301][2];
int sz,to[700],pre[700],v[700],last[301];
void Ins(int a,int b,int c)
{
     sz++;to[sz]=b;v[sz]=c;pre[sz]=last[a];last[a]=sz;
}
void init()
{
     int i,a,b,c;
     scanf("%d%d%d",&n,&m,&K);
     for(i=1;i<n;i++)  
     {
         scanf("%d%d%d",&a,&b,&c);
         Ins(a,b,c);Ins(b,a,c);
     }
}
void dp1(int x,int fa)
{
     int i,j,k;
     f[x][1][1]=0;
     f[x][0][0]=0;
     i=last[x];
     while(i>0)
     {
         if(to[i]!=fa)
         {
                 dp1(to[i],x);
                 for(j=K;j>=0;j--)
                 for(k=0;k<=j;k++)
                 {
                     f[x][j][0]=min(f[x][j][0],f[x][j-k][0]+f[to[i]][k][1]);
                     f[x][j][0]=min(f[x][j][0],f[x][j-k][0]+f[to[i]][k][0]);
                     if(j!=0)
                     {
                             f[x][j][1]=min(f[x][j][1],f[x][j-k][1]+f[to[i]][k][0]);
                             f[x][j][1]=min(f[x][j][1],f[x][j-k][1]+f[to[i]][k][1]+v[i]);
                     }
                 }    
         }
         i=pre[i];
     }
}
void dp2(int x,int fa)
{
     int i,j,k;
     f[x][1][1]=0;
     f[x][0][0]=0;
     i=last[x];
     while(i>0)
     {
         if(to[i]!=fa)
         {
                 dp2(to[i],x);
                 for(j=K;j>=0;j--)
                 {
                     for(k=1;k<=K-j;k++)
                     {
                         f[x][j+k][0]=min(f[x][j+k][0],f[x][j][0]+f[to[i]][k][1]);
                         f[x][j+k][0]=min(f[x][j+k][0],f[x][j][0]+f[to[i]][k][0]+v[i]);
                         f[x][j+k][1]=min(f[x][j+k][1],f[x][j][1]+f[to[i]][k][0]);
                         f[x][j+k][1]=min(f[x][j+k][1],f[x][j][1]+f[to[i]][k][1]+v[i]);
                     }
                     if(f[to[i]][0][0]!=f[0][0][0])
                     {
                         f[x][j][0]+=f[to[i]][0][0]+v[i];
                         f[x][j][1]+=f[to[i]][0][0];
                     }
                     else
                     {
                         f[x][j][0]=f[0][0][0];f[x][j][1]=f[0][0][0];
                     }
                 }    
                 
         }
         i=pre[i];
     }
}
void solve()
{
     if(m-1+K>n)  {printf("-1\n");return;}
     memset(f,50,sizeof(f));
     if(m==2)  dp2(1,0);
     else dp1(1,0);
     cout<<f[1][K][1]<<endl;
}
int main()
{
    init();
    solve();
    system("pause");
    return 0;
}
