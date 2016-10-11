#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define INF 1000000000
using namespace std;
int n,m,A[151][501],sumx[151][501],sumy[151][501],ans=-INF; 
int fn[501],fo[501][501],fi[501]; 
int f[502][153][153][3],ff[501][153][153],B[501],Fmax[501]; 
// 0: 起头矩形 1:结尾矩形 2中介矩形 
int FMAX[501][153][153];
void getN()
{
     int i,j,k,l,x,y,x1,y1,Max;
     for(i=0;i<=m;i++) for(j=0;j<=n;j++) for(k=0;k<=n;k++) 
     {
        FMAX[i][j][k]=-INF;ff[i][j][k]=-INF;
        for(l=0;l<3;l++) f[i][j][k][l]=-INF;
     }     
     for(i=1;i<=m;i++)
     {
         fn[i]=-INF;
         for(x=1;x<=n;x++) 
         {
             for(y=n-1;y>=x;y--)
             {
                 l=sumy[y][i]-sumy[x-1][i];
                 ff[i][x][y]=max(ff[i][x][y+1]-A[y+1][i],f[i-1][x][y+1][0]+l);
             }
             for(y=x;y<=n;y++)
             { 
                 l=sumy[y][i]-sumy[x-1][i];
                 //0:
                 f[i][x][y][0]=max(f[i-1][x][y][0],0)+l;
                 //2:
                 if(x==y) f[i][x][y][2]=max(FMAX[i-1][x-1][y-1],FMAX[i-1][x][y])+l;
                 else f[i][x][y][2]=max(f[i][x][y-1][2]+A[y][i],FMAX[i-1][x][y]+l);
             }
             for(y=x;y<=n;y++) 
             {
                 f[i][x][y][2]=max(ff[i][x][y],f[i][x][y][2]);
                 FMAX[i][x][y]=max(FMAX[i][x-1][y],f[i][x][y][2]);
             }
         }
         for(y=1;y<=n;y++) for(x=y-1;x>=1;x--)
         {
             //1:
             l=sumy[y][i]-sumy[x-1][i];
             f[i][x][y][1]=max(f[i][x][y][1],f[i][x+1][y][1]+A[x][i]);
             f[i][x][y][1]=max(f[i][x][y][1],f[i-1][x+1][y][2]+l);
              
         } 
         for(y=1;y<=n;y++) for(x=y-1;x>=1;x--)
         {
             l=sumy[y][i]-sumy[x-1][i];
             f[i][x][y][1]=max(f[i-1][x][y][1]+l,f[i][x][y][1]);
             fn[i]=max(fn[i],f[i][x][y][1]);
         }
     }
     for(i=4;i<=m;i++) fn[i]=max(fn[i],fn[i-1]);
} 
inline int calc(int i,int j,int x,int y)
{
     int k;
     k=sumx[x][j]-sumx[x][i-1]+sumx[y][j]-sumx[y][i-1];
     k+=sumy[y][j]-sumy[x-1][j]+sumy[y][i]-sumy[x-1][i];
     k-=A[x][i]+A[x][j]+A[y][i]+A[y][j];
     return k;
}
void getO()
{
     int i,j,x,y,k,l;
     for(i=0;i<=m;i++) for(j=0;j<=m;j++) fo[i][j]=-INF;     
     for(i=4;i<=m;i++) for(j=i+2;j<=m;j++) 
     {
         x=1;
         for(y=3;y<=n;y++)
         {
             k=calc(i,j,x,y);
             fo[i][j]=max(fo[i][j],k);
             if(calc(i,j,x,y+1)<calc(i,j,y-1,y+1)) x=y-1;
         }
     }          
     for(l=4;l<=m;l++)
     {
         for(x=4;x<=m;x++)
         {
            y=x+l-1;
            if(y>m-3) break;
            k=max(fo[x+1][y],fo[x][y-1]);
            fo[x][y]=max(fo[x][y],k);
         }
     }     
}
void getI()
{
     int i,j,k,l,x,y,Max;
     for(i=0;i<=m+1;i++) for(j=0;j<=n+1;j++) for(k=0;k<=n+1;k++) for(l=0;l<3;l++) f[i][j][k][l]=-INF;
     for(i=0;i<=m;i++) fi[i]=-INF;
     for(i=m;i>=1;i--)
     {
         for(x=1;x<=n;x++) for(y=x+2;y<=n;y++)
         {
             f[i][x][y][0]=max(0,f[i+1][x][y][0])+A[x][i]+A[y][i];
             f[i][x][y][1]=max(f[i+1][x][y][0],f[i+1][x][y][1])+sumy[y][i]-sumy[x-1][i];
             f[i][x][y][2]=max(f[i+1][x][y][2],f[i+1][x][y][1])+A[x][i]+A[y][i];
             fi[i]=max(fi[i],f[i][x][y][2]);
         }
     }
     for(i=m-3;i>=1;i--) fi[i]=max(fi[i+1],fi[i]);
}
int main()
{    
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) for(j=1;j<=m;j++) scanf("%d",&A[i][j]);
    for(i=1;i<=n;i++) for(j=1;j<=m;j++) sumx[i][j]=sumx[i][j-1]+A[i][j];
    for(j=1;j<=m;j++) for(i=1;i<=n;i++) sumy[i][j]=sumy[i-1][j]+A[i][j];
    getN();
    getO();
    getI();                        
    for(i=4;i<=m;i++) for(j=i+4;j<m-2;j++) ans=max(ans,fn[i-1]+fo[i+1][j-1]+fi[j+1]);
    printf("%d\n",ans);
    return 0;
}