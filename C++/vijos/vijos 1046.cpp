#include<iostream>
#include<cstdio>
#include<cstdlib>
#define INF 1e8
using namespace std;
int n,m,ans;
int map[110][110],dist[110][110];
void init()
{
     int a,b,c;
     int i,j;
     for(i=1;i<=n;i++) for(j=1;j<=n;j++)  {map[i][j]=INF;dist[i][j]=INF;}
     for(i=1;i<=m;i++)
     {
           scanf("%d%d%d",&a,&b,&c);
           map[a][b]=c;map[b][a]=c;
           dist[a][b]=c;dist[b][a]=c;
     }
}
void solve()
{
     int i,j,k;
     ans=1e8;
     for(k=1;k<=n;k++)
     {
          for(i=1;i<k;i++)
          for(j=i+1;j<k;j++)
          if(dist[i][j]+map[i][k]+map[k][j]<ans)   ans=dist[i][j]+map[i][k]+map[k][j];
          
          for(i=1;i<=n;i++)
          for(j=1;j<=n;j++)
          if(dist[i][k]+dist[k][j]<dist[i][j]) dist[i][j]=dist[i][k]+dist[k][j];
     }
     if(ans==1e8)  cout<<"No solution."<<endl;
     else cout<<ans<<endl;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
          init();solve();
    }
    system("pause");
    return 0;
}
