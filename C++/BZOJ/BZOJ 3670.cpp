#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
const int mo=1000000007;
int n,next[1000010],top,cnt,st[1000010];
int sz,to[1000010],pre[1000010],last[1000010];
long long ans;
char s[1000010];
inline void Ins(int a,int b)
{
    sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
void init()
{
     scanf("%s",s+1);
     n=strlen(s+1);
     sz=0;ans=1;
     memset(last,0,sizeof(last));
}
void getnext()
{
     int i,k;
     next[0]=-1;
     for(i=1;i<=n;i++)
     {
         k=next[i-1];
         for(;k!=-1 && s[k+1]!=s[i];k=next[k]);
         next[i]=k+1;
     }
     for(i=1;i<=n;i++) Ins(next[i],i);
}
void dfs(int x)
{
     ans=ans*(cnt+1)%mo;int t;
     for(int i=last[x];i;i=pre[i])
     {
         st[++top]=to[i]; t=cnt;
         while(st[cnt+1]*2<=to[i]) cnt++;
         dfs(to[i]);
         top--;cnt=t;
     }
}
int main()
{
     int T;
     scanf("%d",&T);
     while(T--)
     {
        init();
        getnext();
        ans=1;top=cnt=0;
        dfs(0);
        cout<<ans<<endl;
     }
     return 0;
}