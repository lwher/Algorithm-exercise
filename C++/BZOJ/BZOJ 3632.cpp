#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,ans,Alt[51][51],Max[51];
bool map[51][51];
bool dfs(int last,int top)
{
     if(!last)
     {
         if(top>ans) {ans=top;return 1;}
         return 0;
     }
     int i,j,u,now;
     for(i=1;i<=last;i++)
     {
         if(top+last-i+1<=ans) return 0;
         u=Alt[top][i];
         if(top+Max[u]<=ans) return 0;
         now=0;
         for(j=i+1;j<=last;j++) if(map[u][Alt[top][j]]) Alt[top+1][++now]=Alt[top][j];
         if(dfs(now,top+1)) return 1;
     }
     return 0;
}
void getans()
{
     int i,j,now;
     ans=1;Max[n]=1;
     for(i=n-1;i>=1;i--)
     {
         now=0;
         for(j=i+1;j<=n;j++) if(map[i][j]) Alt[1][++now]=j;
         dfs(now,1);
         Max[i]=ans;
     }
}
int main()
{
    int a,b;
    scanf("%d",&n);
    while(scanf("%d%d",&a,&b)!=EOF) map[a][b]=map[b][a]=1;
    getans();
    cout<<ans<<endl;
    return 0;
}