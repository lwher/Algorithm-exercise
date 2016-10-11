#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cstring> 
using namespace std; 
int quan[11],n,m,d; 
char map[11][11]; 
int dp[520][25][25]; 
bool mark[520][25][25]; 
int ddx[11],ddy[11]; 
int dz[3000025],dx[3000025],dy[3000025]; 
int tou=1,wei=1,ans; 
int go[4][2]; 
void init() 
{ 
    go[0][0]=1;go[0][1]=0; 
    go[1][0]=0;go[1][1]=1; 
    go[2][0]=-1;go[2][1]=0; 
    go[3][0]=0;go[3][1]=-1; 
    int i,j,k; 
    scanf("%d%d%d",&n,&m,&d); 
    for(i=1;i<=d;i++) 
    scanf("%d",&quan[i]); 
    for(i=1;i<=n;i++) 
    for(j=1;j<=m;j++) 
    { 
       cin>>map[i][j]; 
       if(map[i][j]-'0'>=1 && map[i][j]-'0'<=9) 
       { 
            k=map[i][j]-'0'; 
            ddx[k]=i;ddy[k]=j; 
       } 
    } 
} 
int change(int x,int y) 
{ 
    int i,j,l,now; 
    now=dz[tou];i=dx[tou];j=dy[tou]; 
    for(l=1;l<=d;l++) 
    { 
        if(j>ddy[l] && ((i<=ddx[l] && x>ddx[l]) || (i>ddx[l] && x<=ddx[l]))) 
        now^=(1<<(l-1)); 
    } 
    return now; 
} 
void dping(int x,int y) 
{ 
    int i,j,k,now,l,t,nx,ny; 
    tou=1;wei=1; 
    dz[1]=0; 
    dx[1]=x;dy[1]=y; 
    dp[0][x][y]=0; 
    mark[0][x][y]=1; 
    while(tou<=wei) 
    { 
        i=dx[tou]; 
        j=dy[tou]; 
        now=dz[tou]; 
        for(l=0;l<=3;l++) 
        { 
            nx=i+go[l][0];ny=j+go[l][1]; 
            if(map[nx][ny]!='0')  continue; 
            if(nx>=1 && nx<=n && ny>=1 && ny<=m) 
            { 
                t=change(nx,ny); 
                if(dp[t][nx][ny]>dp[now][i][j]+1)  
                {  
                 dp[t][nx][ny]=dp[now][i][j]+1;  
                 if(!mark[t][nx][ny])  
                {  
                 wei++;dx[wei]=nx;dy[wei]=ny;dz[wei]=t;  
                 mark[t][nx][ny]=1;  
                }  
                } 
  
            } 
        } 
        tou++; 
        mark[now][i][j]=0; 
    }    
} 
int getsum(int now) 
{ 
    int i,k,sum=0; 
    for(i=1;i<=d;i++) 
    { 
        k=1<<(i-1); 
        if((now & k)==k) 
        sum+=quan[i]; 
    } 
    return sum; 
} 
void solve() 
{ 
    int i,j,k; 
      
    for(i=1;i<=n;i++) 
    for(j=1;j<=m;j++) 
    if(map[i][j]=='0') 
    { 
    memset(dp,127,sizeof(dp)); 
    memset(mark,0,sizeof(mark)); 
    dping(i,j); 
    for(k=0;k<(1<<d);k++) 
    if(ans<getsum(k)-dp[k][i][j]) 
    ans=getsum(k)-dp[k][i][j]; 
    } 
    cout<<ans<<endl; 
} 
int main() 
{ 
    init(); 
    solve(); 
    //system("pause"); 
    return 0; 
}