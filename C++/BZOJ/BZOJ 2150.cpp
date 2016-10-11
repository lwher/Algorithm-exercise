#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cmath> 
#include<cstring> 
#include<algorithm> 
using namespace std; 
int n,m,r,c,tmp; 
char map[51][51]; 
int sz,to[300010],pre[300010],last[5100]; 
int pipei[5100]; 
int dx[4],dy[4]; 
bool vis[5100]; 
void Ins(int a,int b) 
{ 
    sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz; 
} 
bool find(int x) 
{ 
    int i=last[x]; 
    while(i>0) 
    { 
        if(!vis[to[i]]) 
        { 
            vis[to[i]]=1; 
            if(pipei[to[i]]==0 || find(pipei[to[i]])) 
            { 
                pipei[to[i]]=x; 
                return 1; 
            } 
        } 
        i=pre[i]; 
    } 
    return 0; 
} 
int main() 
{ 
    int i,j,k,a,nx,ny; 
    scanf("%d%d%d%d",&n,&m,&r,&c); 
    for(i=1;i<=n;i++)  for(j=1;j<=m;j++)  cin>>map[i][j]; 
    dx[0]=r;dy[0]=c; 
    dx[1]=r;dy[1]=-c; 
    dx[2]=c;dy[2]=r; 
    dx[3]=c;dy[3]=-r;    
    for(i=1;i<=n;i++)  for(j=1;j<=m;j++) 
    if(map[i][j]!='x') 
    { 
        a=(i-1)*m+j; 
        for(k=0;k<4;k++) 
        { 
            nx=i+dx[k];ny=j+dy[k]; 
            if(nx<1 || nx>n || ny<1 || ny>m || map[nx][ny]=='x')  continue; 
            Ins(a,(nx-1)*m+ny+n*m); 
        } 
    } 
    else tmp++; 
    for(i=1;i<=n*m;i++) 
    { 
        memset(vis,0,sizeof(vis)); 
        if(find(i))   tmp++; 
    } 
    cout<<n*m-tmp<<endl; 
    //system("pause"); 
    return 0; 
}