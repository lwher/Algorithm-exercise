#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,pipei[20001],to[20001][4],ans[20001];
bool vis[20001],marka[20001],markb[20001];
void init()
{
    int i,t,T,x,y;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
       scanf("%d",&T);
       x=(i+T)%n;
       y=(i-T+n)%n;
       if(x>y) {t=x;x=y;y=t;}
       to[i][0]=x;to[i][1]=y;
    }
}
bool find(int x)
{
    if(marka[x]) return 0;
    for(int i=0;i<2;i++)
    if(!vis[to[x][i]] && !markb[to[x][i]])
    {
        vis[to[x][i]]=1;
        if(pipei[to[x][i]]==-1 || find(pipei[to[x][i]]))
        {
            pipei[to[x][i]]=x;
            return 1;
        }
    }
    return 0;
}
void solve()
{
    int i,k,p,sum=0;
    memset(pipei,-1,sizeof(pipei));
    for(i=0;i<n;i++)
    {
       memset(vis,0,sizeof(vis));
       if(find(i)) sum++;
    }
    if(sum<n)
    {
        printf("No Answer\n");
        return;
    }
    for(i=0;i<n;i++)
    {
        p=to[i][0];
        if(!markb[to[i][0]] && pipei[to[i][0]]!=i)
        {
            pipei[to[i][1]]=-1;
            k=pipei[to[i][0]];
            pipei[to[i][0]]=i;
            marka[i]=1;markb[to[i][0]]=1;
            memset(vis,0,sizeof(vis));
            if(find(k)) p=to[i][0];
            else
            {
                marka[i]=0;markb[to[i][0]]=0;
                pipei[to[i][1]]=i;
                pipei[to[i][0]]=k;
                p=to[i][1];
            }
        }
        marka[i]=1;markb[p]=1;
    }
    for(i=0;i<n;i++) ans[pipei[i]]=i;
    for(i=0;i<n-1;i++) printf("%d ",ans[i]);
    printf("%d\n",ans[n-1]);
}
int main()
{
    init();
    solve();
    return 0;
}