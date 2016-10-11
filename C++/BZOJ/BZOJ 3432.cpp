#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<cstring>
#define MAX 501
using namespace std;
const int dy[]={-1,0,1,0},dx[]={0,-1,0,1};
int m,n,mat[MAX][MAX],wp[MAX][MAX],mark[MAX][MAX],wy,wx;
void floodfill(int d)
{
    queue<pair<int,int> > q;
    q.push(make_pair(wy,wx));
    mark[wy][wx]=1;
    while(!q.empty())
    {
        pair<int,int> p=q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            int ny=p.first+dy[i],nx=p.second+dx[i];
            if(ny>=0 && ny<m && nx>=0 && nx<n)
                if(!mark[ny][nx] && abs(mat[p.first][p.second]-mat[ny][nx])<=d)
                {
                    q.push(make_pair(ny,nx));
                    mark[ny][nx]=1;
                }
        }
    }
}
bool reachable(int d)
{
    for(int i=0;i<m;i++)  for(int j=0;j<n;j++) mark[i][j]=0;
    floodfill(d);
    for(int i=0;i<m;i++)  for(int j=0;j<n;j++) if(wp[i][j] && !mark[i][j]) return 0;
    return 1;
}
int main()
{
    cin>>m>>n;
    for(int i=0;i<m;i++)  for(int j=0;j<n;j++)  scanf("%d",&mat[i][j]);
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        {
            scanf("%d",&wp[i][j]);
            if(wp[i][j]) wy=i,wx=j;
        }
    int dmin=0,dmax=1000000000;
    while(dmin<dmax)
    {
        int d=(dmin+dmax)/2;
        if(reachable(d)) dmax=d;
        else dmin=d+1;
    }
    cout<<dmin<<endl;
    //system("pause");
    return 0;
}