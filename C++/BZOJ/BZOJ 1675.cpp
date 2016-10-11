#include<cstdlib> 
#include<cstring> 
#include<cstdio> 
#include<iostream> 
using namespace std; 
struct node 
{ 
    int x,y,k; 
}; 
int map[6][6]; 
int ans,Find; 
node a[30][2]; 
int tot[2]; 
node c[10]; 
bool b[8][8]; 
void Init() 
{ 
    char temp; 
    for (int i=1;i<=5;i++) 
    { 
        for (int j=1;j<=5;j++)  
        { 
            scanf("%c",&temp); 
            if (temp=='J') 
            { 
                map[i][j]=1; 
                a[++tot[1]][1].x=i; 
                a[tot[1]][1].y=j; 
                a[tot[1]][1].k=1; 
            } 
            else
            { 
                map[i][j]=0; 
                a[++tot[0]][0].x=i; 
                a[tot[0]][0].y=j; 
                a[tot[0]][0].k=0; 
            } 
        } 
        scanf("%c",&temp); 
    } 
} 
void DFS(int x,int y) 
{ 
    b[x][y]=false; 
    Find++; 
    if (b[x+1][y]) DFS(x+1,y); 
    if (b[x-1][y]) DFS(x-1,y); 
    if (b[x][y+1]) DFS(x,y+1); 
    if (b[x][y-1]) DFS(x,y-1); 
} 
void Judge() 
{ 
     memset(b,false,sizeof(b)); 
     for (int i=1;i<=7;i++) b[c[i].x][c[i].y]=true; 
    Find=0; 
    DFS(c[1].x,c[1].y); 
    if (Find==7) ans++; 
} 
void Dfs(int x0,int x1,int now0,int now1) 
{ 
    if (x0>tot[0]  ||  x1>tot[1]) return;    
    if (now0>0  &&  now1>0) 
    { 
        c[now0+now1].x=a[x0][0].x; 
        c[now0+now1].y=a[x0][0].y; 
        now0--; 
        c[now0+now1].x=a[x1][1].x; 
        c[now0+now1].y=a[x1][1].y; 
        now1--; 
    } 
    else
    if (now0==0  &&  now1>0) 
    { 
        c[now0+now1].x=a[x1][1].x; 
        c[now0+now1].y=a[x1][1].y; 
        now1--;         
    }     
    if (now0==0  &&  now1==0) 
    { 
        Judge(); 
        return; 
    }   
    for (int i=x1+1;i<=tot[1];i++) 
    { 
        if (now0>0) 
        { 
            for (int j=x0+1;j<=tot[0];j++) Dfs(j,i,now0,now1); 
        } 
        else Dfs(x0,i,now0,now1); 
    } 
} 
void Main() 
{ 
    memset(c,0,sizeof(c)); 
    for (int i=1;i<=tot[0];i++) 
    { 
        for (int j=1;j<=tot[1];j++) 
        { 
            Dfs(i,j,3,4); 
            Dfs(i,j,2,5); 
            Dfs(i,j,1,6); 
        } 
    } 
    for (int i=1;i<=tot[1];i++) Dfs(0,i,0,7); 
    printf("%d\n",ans); 
} 
int main() 
{ 
    Init(); 
    Main(); 
  //  system("pause"); 
    return 0; 
}