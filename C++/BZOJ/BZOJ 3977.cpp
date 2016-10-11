#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#define INF 0x7fffffff
using namespace std;
int n,m;
int map[21][21],ans=0x7fffffff;
int fs[1050000][22],ft[1050000][22];
int tot,numq[22],numh[22];
bool mark[22];
void DPS()
{
    int i,j,k,q;
    k=1<<(n-2);
    memset(fs,63,sizeof(fs));
    for(i=1;i<=n-2;i++)  fs[1<<(i-1)][i-1]=map[0][i];
    for(i=1;i<k;i++)  
    {
        for(j=1;j<=n-2;j++)
        if(i & (1<<(j-1)))
        {
            for(q=1;q<=n-2;q++)
            if(!((1<<(q-1)) & i))
            {
                fs[i | (1<<(q-1))][q-1]=min(fs[i | (1<<(q-1))][q-1],fs[i][j-1]+map[j][q]);
            }
        }
    }
}
void DPT()
{
    int i,j,k,q;
    k=1<<(n-2);
    memset(ft,63,sizeof(ft));
    for(i=1;i<=n-2;i++)  ft[1<<(i-1)][i-1]=map[n-1][i];
    for(i=1;i<k;i++)  
    {
        for(j=1;j<=n-2;j++)
        if(i & (1<<(j-1)))
        {
            for(q=1;q<=n-2;q++)
            if(!((1<<(q-1)) & i))
            {
                ft[i | (1<<(q-1))][q-1]=min(ft[i | (1<<(q-1))][q-1],ft[i][j-1]+map[j][q]);
            }
        }
    }
}
void solve()
{
     DPS();DPT();     
     int i,j,k,p,stack[22],top,h=(n-2)/2,mindist1,mindist2;
     p=(1<<(n-2))-1;     
     for(i=0;i<=p;i++)
     {
         top=0;
         for(j=1;j<=n-2;j++)  if(i & (1<<(j-1)))  stack[++top]=j;
         if(top!=h) continue;
         mindist1=1<<29;mindist2=1<<29;
         for(j=1;j<=top;j++)
         for(k=1;k<=n-2;k++)
         if(!(i & (1<<(k-1))))
         {
                mindist1=min(mindist1,fs[i][stack[j]-1]+ft[p ^ i][k-1]+map[stack[j]][k]);
                mindist2=min(mindist2,ft[i][stack[j]-1]+fs[p ^ i][k-1]+map[stack[j]][k]);
         }
         ans=min(ans,mindist1+mindist2);
     }
     if(n==3)  ans=(map[0][1]+map[1][2])*2;
     cout<<"Case 1: "<<ans<<endl;
}
int main()
{
    int i,j,k,a,b,tt;
    scanf("%d%d",&n,&m);
    memset(map,63,sizeof(map));
    for(i=0;i<n;i++)   map[i][i]=0;
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&a,&b,&tt);
        map[a][b]=tt;map[b][a]=tt;
    }
    for(k=0;k<n;k++)  for(i=0;i<n;i++)  for(j=0;j<n;j++)
    if(map[i][k]+map[k][j]<map[i][j])  map[i][j]=map[i][k]+map[k][j];
    solve();
    return 0;
}
