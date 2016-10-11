#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int bh[20][100010],fa[20][100010],gs[20];
int pre[100010];
int n,limt,sum,ans[100010];
int getw(int x)
{
    int res=0;
    while(x)
    {
       x=x>>1;res++;
    }
    return res-1;
}
void solve()
{
    int i,j;
    for(i=0;i<=18;i++) 
    {
        if((1<<i) & sum) 
        {
            if(gs[i]>0)
            {
                for(j=bh[i][gs[i]];j;j=pre[j]) ans[++ans[0]]=j;
                gs[i]--;
            }
            else {printf("-1\n");return;}
        }
        for(j=1;j<=gs[i];j+=2)
        {
            if(j+1<=gs[i])
            {
                pre[fa[i][j+1]]=bh[i][j];
                gs[i+1]++;bh[i+1][gs[i+1]]=bh[i][j+1];fa[i+1][gs[i+1]]=fa[i][j];
            }
        }
    }
    printf("%d\n",ans[0]);
    for(i=1;i<=ans[0];i++) printf("%d ",ans[i]);
}
int main()
{
    int i,x,y;
    cin>>sum>>limt;    
    for(i=1;i<=limt;i++)
    {
       x=(i & (-i));
       y=getw(x);
       gs[y]++;
       fa[y][gs[y]]=i;bh[y][gs[y]]=i;
    }
    solve();
    return 0;
}