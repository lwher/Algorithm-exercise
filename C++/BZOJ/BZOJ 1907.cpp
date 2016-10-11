#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int n;
int ans;
int t,sz;
int to[20010],pre[20010],last[10010],fa[10010];
bool up[10010];
void Ins(int a,int b)
{
     sz++;
     to[sz]=b;
     pre[sz]=last[a];
     last[a]=sz;
     sz++;
     to[sz]=a;
     pre[sz]=last[b];
     last[b]=sz;  
}
void dfs(int x)
{
     int i=last[x];
     int down=0;
     while(i>0)
     {
         if(fa[x]!=to[i])
         {
            fa[to[i]]=x;
            dfs(to[i]);
            if(up[to[i]])  down++;
         }
         i=pre[i];
     }
     if(down<=1)
     up[x]=1;
     else
     ans+=down-1;
}
int main()
{
    int i,a,b;
    scanf("%d",&t);
    while(t--)
    {
       sz=0;ans=0;
       memset(fa,0,sizeof(fa));
       memset(up,0,sizeof(up));
       memset(last,0,sizeof(last));
       scanf("%d",&n);
       for(i=1;i<=n-1;i++)
       {
       scanf("%d%d",&a,&b);
       Ins(a,b);
       }
       dfs(1);
       if(up[1])
       ans++;
       cout<<ans<<endl;
    }
    system("pause");
    return 0;
}
