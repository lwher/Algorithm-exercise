#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,ans[410],sum[410],gs[410];
bool check(int x)
{
     int i,j;bool flag;
     for(i=1;i<=n;i++)
     if(sum[i]>=2)
     {
         for(j=1;j<=n;j++)  gs[j]=sum[j];
         gs[i]-=2;flag=1;
         for(j=1;j<=n;j++)
         {
             gs[j]%=3;
             if(gs[j+1]<gs[j] || gs[j+2]<gs[j]) {flag=0;break;}    
             gs[j+1]-=gs[j];gs[j+2]-=gs[j];
         }
         if(flag) return 1;
     }
     return 0;
}
int main()
{
    int i,x;
    scanf("%d%d",&n,&m);
    m=3*m+1;
    for(i=1;i<=m;i++)  
    {
        scanf("%d",&x);
        sum[x]++;
    }
    for(i=1;i<=n;i++)
    {
        sum[i]++;
        if(check(i))  ans[++ans[0]]=i;
        sum[i]--;
    }
    if(!ans[0])  printf("NO\n");
    else
    {
        for(i=1;i<ans[0];i++)  printf("%d ",ans[i]);
        printf("%d\n",ans[ans[0]]);
    }
    return 0;
}