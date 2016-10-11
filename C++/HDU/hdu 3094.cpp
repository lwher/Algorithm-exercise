#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int t;
int n,sz;
int sg[100010];
int to[200010],pre[200010],last[100010];
bool vis[100010];
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
    vis[x]=1;
    int now=0;
    while(i>0)
    {
        if(!vis[to[i]])
        {
            dfs(to[i]);
            now^=(sg[to[i]]+1);
        }
        i=pre[i];
    }
    sg[x]=now;
}
int main()
{
    int i,j;
    int a,b;
    scanf("%d",&t);
    while(t--)
    {
        sz=0;
        memset(vis,0,sizeof(vis));
        memset(sg,0,sizeof(sg));
        memset(last,0,sizeof(last));
        scanf("%d",&n);
        for(i=1;i<=n-1;i++)
        {
             scanf("%d%d",&a,&b);
             Ins(a,b);
        }
        dfs(1);
        if(sg[1])
        printf("Alice\n");
        else
        printf("Bob\n");
    }
   // system("pause");
    return 0;
}
