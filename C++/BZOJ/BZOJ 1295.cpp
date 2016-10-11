#include<iostream> 
#include<cstdio> 
#include<cmath> 
#include<cstring> 
using namespace std; 
int n,m,T; 
double ans=0; 
bool mp[31][31],inq[31][31],vis[31][31]; 
int dis[31][31]; 
int dx[4]={1,-1,0,0}; 
int dy[4]={0,0,-1,1}; 
struct data{ 
int x,y; 
}q[100000]; 
void getans(int x,int y) 
{ 
    for(int i=x;i<=n;i++) 
       for(int j=1;j<=m;j++) 
          if(dis[i][j]<=T&&(y-j)*(y-j)+(x-i)*(x-i)>ans) 
             ans=(y-j)*(y-j)+(x-i)*(x-i); 
} 
void search(int xx,int yy) 
{ 
    int nowx,nowy,i,t=1,w=1,nx,ny; 
    q[1].x=xx;q[1].y=yy; 
    memset(inq,0,sizeof(inq)); 
    memset(dis,127,sizeof(dis)); 
    inq[xx][yy]=1;dis[xx][yy]=mp[xx][yy]; 
    while(t<=w) 
    { 
        nowx=q[t].x;nowy=q[t].y; 
        t++; 
        for(i=0;i<4;i++) 
        { 
            nx=nowx+dx[i];ny=nowy+dy[i]; 
            if(nx>n||nx<xx||ny>m||ny<1)continue; 
            if(dis[nowx][nowy]+mp[nx][ny]<dis[nx][ny]) 
            { 
                 dis[nx][ny]=dis[nowx][nowy]+mp[nx][ny]; 
                 if(!inq[nx][ny])    
                 { 
                    q[++w].x=nx;q[w].y=ny;inq[nx][ny]=1; 
                 }       
            } 
        } 
        inq[nowx][nowy]=0; 
    } 
    getans(xx,yy); 
} 
int main() 
{ 
    scanf("%d%d%d",&n,&m,&T); 
    char str[40]; 
    for(int i=1;i<=n;i++) 
    { 
        scanf("%s",str); 
        for(int j=0;j<m;j++) 
        mp[i][j+1]=str[j]-'0'; 
    } 
    for(int i=1;i<=n;i++) 
       for(int j=1;j<=m;j++) 
          {search(i,j);} 
    printf("%.6lf",sqrt(ans)); 
    return 0; 
}