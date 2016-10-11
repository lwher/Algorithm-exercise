#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,B;
int sz,to[2010],pre[2010],last[1010];
int col[1010],cnt,sh[1010],dengdai[1010][1010],sum[1010];
void Ins(int a,int b)
{
    sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
void dfs(int x,int fa)
{
    int i,j;
    for(i=last[x];i>0;i=pre[i])
    {
        if(to[i]==fa)  continue;
        dfs(to[i],x);
        for(j=1;j<=sum[to[i]];j++)  
        {
            sum[x]++;
            dengdai[x][sum[x]]=dengdai[to[i]][j];
        }
        if(sum[x]>=B)
        {
            cnt++;sh[cnt]=x;
            while(sum[x]>0)
            {
                col[dengdai[x][sum[x]]]=cnt;
                sum[x]--;
            }
        }
    }
    sum[x]++;dengdai[x][sum[x]]=x;
}
void solve()
{
    dfs(1,0);
    if(sum[1]>0 && cnt==0)  {printf("0\n");return;}
    int i;
    for(i=1;i<=sum[1];i++)  col[dengdai[1][i]]=cnt;
    printf("%d\n",cnt);
    for(i=1;i<n;i++)  printf("%d ",col[i]);  printf("%d\n",col[n]);
    for(i=1;i<cnt;i++)  printf("%d ",sh[i]);  printf("%d\n",sh[cnt]);  
}
int main()
{
    int i,a,b;
    scanf("%d%d",&n,&B);
    for(i=1;i<n;i++)  
    {
        scanf("%d%d",&a,&b);
        Ins(a,b);Ins(b,a);
    }
    solve();
//  system("pause");
    return 0;
}