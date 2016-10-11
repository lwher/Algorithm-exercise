#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cstring> 
#include<cmath> 
using namespace std; 
int last[6][6],now[6][6],a[6][6]; 
int dx[8]={-2,-2,-1,-1,1,1,2,2}; 
int dy[8]={1,-1,2,-2,2,-2,-1,1}; 
int white,black,qx,qy; 
void init() 
{ 
    int i,j; 
    char ch; 
    for(i=1;i<=5;i++)  for(j=1;j<=5;j++) 
    { 
        cin>>ch; 
        if(ch=='0')  a[i][j]=0;   else
        if(ch=='1')  a[i][j]=1;   else 
        {a[i][j]=-1;qx=i;qy=j;} 
    }  
    white=0;black=0; 
    for(i=1;i<=5;i++)  for(j=1;j<=5;j++) 
    { 
        now[i][j]=a[i][j]; 
        if(now[i][j]!=last[i][j])  {if(last[i][j]==0) white++;else if(last[i][j]==1) black++;} 
    } 
} 
void swap(int &a,int &b)  {int t;t=a;a=b;b=t;} 
bool dfs(int x,int y,int top,int wh,int bl) 
{ 
    if(wh==0 && bl==0)  return 1; 
    if(top==0 || wh+bl>top)  return 0; 
    int i,nx,ny; 
    for(i=0;i<8;i++) 
    { 
        nx=x+dx[i];ny=y+dy[i]; 
        if(nx<1 || nx>5 || ny<1 || ny>5)  continue; 
        if(last[x][y]==1 && now[nx][ny]==1)  bl--; 
        if(last[nx][ny]==1 && now[nx][ny]==1)  bl++; 
        if(last[x][y]==0 && now[nx][ny]==0)  wh--; 
        if(last[nx][ny]==0 && now[nx][ny]==0)  wh++; 
        swap(now[x][y],now[nx][ny]); 
        if(dfs(nx,ny,top-1,wh,bl))  return 1; 
        swap(now[x][y],now[nx][ny]); 
        if(last[x][y]==1 && now[nx][ny]==1)  bl++; 
        if(last[nx][ny]==1 && now[nx][ny]==1)  bl--; 
        if(last[x][y]==0 && now[nx][ny]==0)  wh++; 
        if(last[nx][ny]==0 && now[nx][ny]==0)  wh--; 
    } 
    return 0; 
} 
void solve() 
{ 
    int i,j,l=1,r=15,mid; 
    while(l<r) 
    { 
        if(l+1==r)  break; 
        mid=(l+r)>>1; 
        for(i=1;i<=5;i++)  for(j=1;j<=5;j++)   now[i][j]=a[i][j]; 
        if(dfs(qx,qy,mid,white,black))  r=mid; 
        else l=mid; 
    } 
    for(i=1;i<=5;i++)  for(j=1;j<=5;j++)   now[i][j]=a[i][j]; 
    if(dfs(qx,qy,l,white,black))  {printf("%d\n",l);return;} 
    for(i=1;i<=5;i++)  for(j=1;j<=5;j++)   now[i][j]=a[i][j]; 
    if(dfs(qx,qy,r,white,black))  {printf("%d\n",r);return;} 
    else  printf("-1\n"); 
} 
int main() 
{ 
    int i,j,t; 
    scanf("%d",&t); 
    for(i=1;i<=2;i++)  for(j=5;j>=i;j--)  last[i][j]=1; 
    for(i=3;i<=4;i++)  for(j=5;j>i;j--)   last[i][j]=1; 
    last[3][3]=-1; 
    while(t--) 
    { 
        init(); 
        solve(); 
    } 
    //system("pause"); 
    return 0; 
}