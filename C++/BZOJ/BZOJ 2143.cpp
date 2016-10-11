#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
#define limt 9000000
using namespace std;
struct node
{
    int x,y,s;
    long long d;
    bool operator <(const node &b) const
    {
         return d>b.d;
    } 
};
int n,m,S,Xx,Xy,Yx,Yy,Zx,Zy;
int A[151][151],B[151][151];
int dx[5]={0,0,1,-1,0};
int dy[5]={1,-1,0,0,0};
long long dist[151][151][300];
bool mark[151][151][300];
void Dij(int qx,int qy)
{
    priority_queue<node> q;
    memset(mark,0,sizeof(mark));
    int i,j,k,nx,ny,nowx,nowy,nows;
    for(i=1;i<=n;i++) for(j=1;j<=m;j++) for(k=0;k<=S;k++) dist[i][j][k]=(1LL<<50);
    dist[qx][qy][0]=0;
    node p;
    p.x=qx;p.y=qy;p.s=0;p.d=0;
    q.push(p);
    int N=n*m*S;
    while(!q.empty() && (!mark[Xx][Xy][0] || !mark[Yx][Yy][0] || !mark[Zx][Zy][0]))
    {
        p=q.top();q.pop();
        nowx=p.x;nowy=p.y;nows=p.s;
        if(!mark[nowx][nowy][nows])
        {
            mark[nowx][nowy][nows]=1;
            if(A[nowx][nowy] && nows==0 && dist[nowx][nowy][A[nowx][nowy]]>dist[nowx][nowy][nows]+B[nowx][nowy])
            {
                dist[nowx][nowy][A[nowx][nowy]]=dist[nowx][nowy][nows]+B[nowx][nowy];
                p.x=nowx;p.y=nowy;p.s=A[nowx][nowy];p.d=dist[nowx][nowy][A[nowx][nowy]];
                q.push(p);
            }
            if(nows>0)
            {
                for(k=0;k<5;k++)
                {
                    nx=nowx+dx[k];ny=nowy+dy[k];
                    if(nx<1 || nx>n || ny<1 || ny>m) continue;
                    if(dist[nx][ny][nows-1]>dist[nowx][nowy][nows])
                    {
                        dist[nx][ny][nows-1]=dist[nowx][nowy][nows];
                        p.x=nx;p.y=ny;p.s=nows-1;p.d=dist[nx][ny][nows-1];
                        q.push(p);
                    }
                }
            }
        }
    }
}
int main()
{
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) for(j=1;j<=m;j++) scanf("%d",&A[i][j]);
    for(i=1;i<=n;i++) for(j=1;j<=m;j++) scanf("%d",&B[i][j]);
    S=n+m-2;
    for(i=1;i<=n;i++) for(j=1;j<=m;j++) if(A[i][j]>S) A[i][j]=S;
    scanf("%d%d",&Xx,&Xy);
    scanf("%d%d",&Yx,&Yy);
    scanf("%d%d",&Zx,&Zy);
    long long ans=1LL<<50,A1=0,A2=0,A3=0;
    char ansch;
    Dij(Xx,Xy);    
    A2+=dist[Yx][Yy][0];A3+=dist[Zx][Zy][0];
    Dij(Yx,Yy);
    A1+=dist[Xx][Xy][0];A3+=dist[Zx][Zy][0];
    Dij(Zx,Zy);
    A1+=dist[Xx][Xy][0];A2+=dist[Yx][Yy][0];
    if(A1<ans) {ans=A1;ansch='X';}
    if(A2<ans) {ans=A2;ansch='Y';}
    if(A3<ans) {ans=A3;ansch='Z';}
    if(ans>=(1LL<<50)) cout<<"NO\n"<<endl;
    else cout<<ansch<<endl<<ans<<endl;
    return 0;
}