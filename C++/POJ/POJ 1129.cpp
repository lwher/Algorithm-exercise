#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,ans,Max[27],Alt[27][27];
bool map[27][27];
bool dfs(int last,int top)
{
     if(!last)
     {
         if(top>ans) {ans=top;return 1;}
         return 0;
     }
     int i,j,x,now;
     for(i=1;i<=last;i++)
     {
         if(last-i+1+top<=ans) return 0;
         x=Alt[top][i];now=0;
         if(top+Max[x]<=ans) return 0;
         for(j=i+1;j<=last;j++) if(map[x][Alt[top][j]]) Alt[top+1][++now]=Alt[top][j];
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
    int i,j,x,y,len;
    char s[30];
    while(scanf("%d",&n) && n) 
    {
        memset(map,0,sizeof(map));
        for(i=1;i<=n;i++)
        {
            scanf("%s",s);
            x=s[0]-'A'+1;
            len=strlen(s);
            for(j=2;j<len;j++) 
            {
                y=s[j]-'A'+1;
                map[x][y]=map[y][x]=1;
            }
        }
        getans();
        if(ans==1) printf("1 channel needed.\n");
        else printf("%d channels needed.\n",ans);
    }
    system("pause");
    return 0;
}
