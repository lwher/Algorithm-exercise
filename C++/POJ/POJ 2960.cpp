#include<iostream>
#include<cstdlib>
#include<stdio.h>
using namespace std;
int sg[10010],s[110];
int k,l,t,n;
int ans;
int dfs(int x)
{
     if(sg[x]!=-1) return sg[x];
     int i,j;
     bool mark[110]={0};
     for(i=1;i<=k;i++)
     {
        if(x-s[i]>=0)
        {
          mark[dfs(x-s[i])]=1;
        } 
     }
     for(j=0;j<=100;j++)
     if(!mark[j])
     return sg[x]=j;
}
int main()
{
    int i,j;
    while(scanf("%d",&k))
    {
      if(k==0)  break;
      for(i=1;i<=k;i++)
      scanf("%d",&s[i]);
      scanf("%d",&t);
      memset(sg,-1,sizeof(sg));
      sg[0]=0;
      while(t--)
      {
          ans=0;
          scanf("%d",&n);
          for(i=1;i<=n;i++)
          {scanf("%d",&l);ans=(ans^dfs(l));}
          if(ans)
          printf("W");
          else
          printf("L");
      }
      printf("\n");
    }
    system("pause");
    return 0;
}
