#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAXN 100001
struct node 
{
    int t,d;
    node *next;
}*head[MAXN];
int n;
long long s[MAXN],w[MAXN];
long long c[MAXN];
long long cost=0;
long long ans;
node *q[MAXN];
void INSERT(int s,int t,int d)
{
    node *p=new(node);
    p->t=t;
    p->d=d;
    p->next=head[s];
    head[s]=p;
    p=new(node);
    p->t=s;
    p->d=d;
    p->next=head[t];
    head[t]=p;
}
bool f[MAXN];
long long z;
void Dfs(int v)
{
    f[v]=false;
    s[v]=w[v];
    c[v]=0;
    for(q[v]=head[v];q[v];q[v]=q[v]->next)
    {
        if(f[q[v]->t])
        {
            Dfs(q[v]->t);
            s[v]+=s[q[v]->t];
            c[v]+=s[q[v]->t]*q[v]->d;
            c[v]+=c[q[v]->t];
        }
    }
}
 
void dfs(int v)
{
    f[v]=false;
    ans=min(ans,c[v]);
    for (q[v]=head[v];q[v];q[v]=q[v]->next)
    {
        if (f[q[v]->t])
        {
            c[q[v]->t]=c[v];
            c[q[v]->t]+=(long long)(s[1]*q[v]->d);
            c[q[v]->t]-=(long long)(2*s[q[v]->t]*q[v]->d);
            dfs(q[v]->t);
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i++<n;)
    {
        scanf("%lld",&w[i]);
        head[i]=NULL;
    }
    for(int i=0;i++<n-1;)
    {
        int s,t,d;
        scanf("%d%d%d",&s,&t,&d);
        INSERT(s,t,d);
    }
    memset(f,true,sizeof(f));
    Dfs(1);
    ans=c[1];
    memset(f,true,sizeof(f));
    dfs(1);
    printf("%lld\n",ans);
    system("pause");
    return 0;
}
