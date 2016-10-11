#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
int n,root,fa[1010];
int c[1010],t[1010],ans[1010];
double w[1010];
bool mark[1010];
int findmax()
{
    int i,j;double maxx=-1e9;
    for(i=1;i<=n;i++)
    {
        if(i!=root && !mark[i] && w[i]>maxx)
        {
             j=i;maxx=w[i];
        }
    }
    return j;
}
int main()
{
    int i,j,a,b;    
    while(scanf("%d%d",&n,&root))
    {
        memset(fa,0,sizeof(fa));
        memset(mark,0,sizeof(mark));
        if(n==0 && root==0)  break;
        for(i=1;i<=n;i++) scanf("%d",&c[i]);
        for(i=1;i<n;i++)  {scanf("%d%d",&a,&b);fa[b]=a;}        
        for(i=1;i<=n;i++) {ans[i]=c[i];w[i]=c[i]*1.00;t[i]=1;}
        for(i=1;i<n;i++)
        {
            a=findmax();
            for(j=1;j<=n;j++)  if(fa[j]==a)  fa[j]=fa[a];
            ans[fa[a]]+=ans[a]+t[fa[a]]*c[a];
            c[fa[a]]+=c[a];
            t[fa[a]]+=t[a];
            w[fa[a]]=c[fa[a]]*1.00/t[fa[a]];
            mark[a]=1;
        }
        printf("%d\n",ans[root]);
    }
    system("pause");
    return 0;
}
