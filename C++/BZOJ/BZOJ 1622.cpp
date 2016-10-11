#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int n,m;
char dc[1010][1010];
char good[110][31];
int dcc[1010],gc[1010],zz[31];
int main()
{
    int i,j,k;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
      scanf("%s",dc[i]+1);
      dcc[i]=strlen(dc[i]+1);
      for(j=1;j<=dcc[i];j++)
      if(int(dc[i][j])>90)   dc[i][j]-=32;
    }
    for(i=1;i<=m;i++)
    {
      scanf("%s",good[i]+1);
      gc[i]=strlen(good[i]+1);
      for(j=1;j<=gc[i];j++)
      if(int(good[i][j])>90)   good[i][j]-=32;
    }
    int ans;
    
    for(i=1;i<=n;i++)
    {
        ans=0;
        for(k=1;k<=m;k++)  zz[k]=1;
        
        for(j=1;j<=dcc[i];j++)
        {
           for(k=1;k<=m;k++)
           if(zz[k]<=gc[k])
           {
             if(good[k][zz[k]]==dc[i][j])
             {
                 zz[k]++;
                 if(zz[k]>gc[k])  ans++;
             }
           }
        }
        
        printf("%d\n",ans); 
    }
    
    system("pause");
    return 0;
}
