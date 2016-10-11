#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,bfs[200010],dfs[200010],change[200010];
int rank[200010],rem[200010],ans=2;
int main()
{
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&dfs[i]);
    for(i=1;i<=n;i++) scanf("%d",&bfs[i]);
    for(i=1;i<=n;i++) change[bfs[i]]=i;
    for(i=1;i<=n;i++) dfs[i]=change[dfs[i]];
    for(i=1;i<=n;i++) rank[dfs[i]]=i;
    for(i=1;i<=n;i++) rem[i]=max(rem[i-1],dfs[i]);
    for(i=1;i<n;i++)
    {
        if(i==1 || rank[i]>rank[i+1]) ans+=2;
        else if(rank[i]+1==rank[i+1] && i==rank[i] && rem[i]==i) ans++;
    }
    for(i=n;i>=1 && rank[i]-1==rank[i-1];i--) if(i!=rank[i]) ans++;
    double k=(double)(ans)/2;
    printf("%.3lf\n%.3lf\n%.3lf\n",k-0.001,k,k+0.001);
    system("pause");
    return 0;
}
