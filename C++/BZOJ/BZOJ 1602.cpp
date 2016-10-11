#include<cstdio>  
#include<cstdlib>  
#include<cstring>  
using namespace std;  
struct edge{  
    int to,l;  
    edge *next;  
}epool[5001],*E[1001],*etop;  
int dis[1001],father[1001];  
bool travel[1001];  
void dfs (int v)  
{  
    travel[v]=true;  
    for (edge *p=E[v];p;p=p->next)if (!travel[p->to]){  
        dis[p->to]=dis[v]+p->l;father[p->to]=v;  
        dfs(p->to);}  
    return;  
}  
int lca(int v,int v1)  
{  
    int V=v,V1=v1;  
    static int visit[1001];  
    memset(visit,false,sizeof(visit));visit[V]=true;  
    while (father[V]!=V) {V=father[V];visit[V]=true;}visit[V]=true;  
    while (!visit[V1]) V1=father[V1];  
    return V1;  
}  
int main()  
{  
    etop=epool;  
    int n,q;  
    scanf("%d%d",&n,&q);  
    memset(dis,127,sizeof(dis));  
    for (int i=1;i<=n;i++) father[i]=i;  
    for (int i=1;i<=n-1;i++)  
    {  
        int v,v1,len;  
        scanf("%d%d%d",&v,&v1,&len);  
        etop->to=v1;etop->l=len;etop->next=E[v];E[v]=etop;etop++;  
        etop->to=v;etop->l=len;etop->next=E[v1];E[v1]=etop;etop++;  
    }  
    int root=1;dis[root]=0;  
    dfs(root);  
    while (q--) {  
        int v,v1;  
        scanf("%d%d",&v,&v1);  
        printf("%d\n",dis[v]+dis[v1]-2*dis[lca(v,v1)]);  
    }  
    return 0;  
}