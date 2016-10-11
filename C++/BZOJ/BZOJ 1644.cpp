#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<iostream>
#define N 105
using namespace std;
const int dx[5]={0,-1,1,0,0};
const int dy[5]={0,0,0,-1,1};
struct dui
{
    int x,y,p;
}que[1000000];
int f[N][N][5];
bool b[N][N][5];
int n,ans,sx,sy,ex,ey,head,tail;
int map[N][N];
void Init()
{
    scanf("%d",&n);
    memset(map,0,sizeof map);
    for (int i=1;i<=n;i++)
    {
        char temp;
        for (int j=1;j<=n;j++)
        {
            cin>>temp;
            if (temp=='.'  ||  temp=='A'  ||  temp=='B') map[i][j]=1;
            if (temp=='A') sx=i,sy=j;
            if (temp=='B') ex=i,ey=j;
        }    
    }
}
bool Judge(int x,int y)
{
    if (x<1  ||  x>n  ||  y<1  ||  y>n  ||  !map[x][y]) return false;
    return true;
}
void Main()
{
    head=1; tail=0;
    memset(b,false,sizeof b);
    memset(f,100,sizeof f);
    for (int i=1;i<=4;i++)
    {
        que[++tail].x=sx;
        que[tail].y=sy;
        que[tail].p=i;
        f[sx][sy][i]=0;
    }
    while (head<=tail)
    {
        int x=que[head].x;
        int y=que[head].y;
        int p=que[head].p;
        for (int i=1;i<=4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if (!Judge(nx,ny)) continue;
            int d=f[x][y][p]+(bool)(p!=i);
            if (d<f[nx][ny][i])
            {
                f[nx][ny][i]=d;
                if (!b[nx][ny][i])
                {
                    que[++tail].x=nx;
                    que[tail].y=ny;
                    que[tail].p=i;
                    b[nx][ny][i]=true;
                }
            }
        }
        head++;
        b[x][y][p]=false;
    }
    ans=0x7fffffff;
    for (int i=1;i<=4;i++)
        if (f[ex][ey][i]<ans) ans=f[ex][ey][i];
    printf("%d\n",ans);
}
int main()
{
    Init();
    Main();
    system("pause");
    return 0;
}

