#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int n,k,to[210],chang;
int sz,belong[210],len[210];
char s[210],ans[210];
bool vis[210];
void build()
{
     int i,j;sz=0;
     memset(belong,0,sizeof(belong));
     memset(len,0,sizeof(len));
     memset(vis,0,sizeof(vis));
     for(i=1;i<=n;i++)
     if(!vis[i])
     {
         sz++;j=i;
         while(!vis[j])  {vis[j]=1;len[sz]++;belong[j]=sz;j=to[j];}
     }
}
void doing(int index)
{
      int i=index,now = 0;
      while (now<k%len[belong[index]])
      {
            i=to[i];
            now++;
      }
      ans[i]=s[index];
}
void solve()
{
     int i;
     memset(ans,0,sizeof(ans));
     for(i=1;i<=n;i++)  doing(i);
     for (i =n; i > 0; i--)
     if(ans[i] != ' ')
     {
        ans[i+1]= '\0';
        break;
     }
}
int main()
{
    int i,j;    
    while(scanf("%d",&n))
    {
        if(n==0) break;
        for(i=1;i<=n;i++)  scanf("%d",&to[i]);
        build();
        while(scanf("%d",&k))
        {
            if(k==0)  break;
            gets(s);
            chang=strlen(s);
            for(i=chang;i<=n;i++)  s[i]=' ';
            solve();
            i=1;
            while(ans[i])
            printf("%c",ans[i++]);
            printf("\n");
        }
        printf("\n");
    }
    system("pause");
    return 0;
}
