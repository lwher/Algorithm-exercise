#include<cstdio>
#include<cstring>
#include<cstdlib> 
const int N = 10010;
struct node {
int v,w,sum;
node *next;
}*head[N],tree[2*N];
int n,m,ptr;
int vst[N],dp[N];
int max(int a, int b) {return a > b ? a : b;}
void init()
{
    ptr = 1;
    memset(vst, 0, sizeof(vst));
    memset(dp, 0, sizeof(dp));
    memset(head, 0, sizeof(head));
}
void AddEdge(int x,int y, int z)
{
    tree[ptr].v = y;
    tree[ptr].w = z;
    tree[ptr].next = head[x],head[x] = &tree[ptr++];
}
void dfs(int v)   
{
    vst[v] = 1;
    node *p = head[v];
    while (p != NULL)
    {
        if(vst[p->v]) {p = p->next; continue;}
        dfs(p->v);    
        dp[v] = max(dp[v], dp[p->v]+p->w);
        p->sum = dp[p->v]+p->w;
        p = p->next;
    }
}
void tree_dp(int fa, int son)
{
    if(vst[son]) return ;
    vst[son] = 1;
    int i,j,k,max1;
    node *p = head[fa];
    max1 = 0;
    while(p != NULL)  
    {
        if(p->v != son) max1 = max(max1, p->sum);
        p = p->next;
    }
    p = head[son];
    while(p != NULL) 
    {
        if(p->v == fa)
        {
            p->sum = p->w+max1;
            break;
        }
        p = p->next;
    }
    p = head[son];
    while(p != NULL)
    {
        dp[son] = max(dp[son], p->sum);
        tree_dp(son, p->v);
        p = p->next;
    }
} 


int main()
{
    int i,j,k;
    while(~scanf("%d", &n))
    {
        init();
        for(i = 2; i <= n; i++)
        {
            scanf("%d%d", &j, &k);
            AddEdge(i, j, k);
            AddEdge(j, i, k);
        }
        dfs(1);
        memset(vst, 0, sizeof(vst));
        node *p = head[1];
        while(p != NULL)
        {
            tree_dp(1, p->v);
            p = p->next;
        }
        for(i = 1; i <= n; i++)
            printf("%d\n", dp[i]);
    }
}
