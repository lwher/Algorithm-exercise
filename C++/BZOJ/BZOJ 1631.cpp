#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#define pb push_back
using namespace std;
int n, m, dist[1100], rdist[1100], T;
struct EDGE{int x, y, z;}edge[110000];
struct node
{       
        int to, l;       
        bool operator < (const node &a) const       
        {              return a.l < l;       }
};
vector <node> G[1100];
priority_queue <node> q; 
void dijkstra(int st)
{       
        int i, j;       
        memset(dist, 0x3f, sizeof(dist)); 
        dist[st] = 0;        
        node x;       
        x.to = st; x.l = 0;       
        q.push(x);       
        while(!q.empty())       
        {              
                       x = q.top(); q.pop();              
                       if(dist[x.to] != x.l) continue;              
                       int u = x.to;              
                       for(i = 0; i < G[u].size(); i++)                     
                       if(G[u][i].l + x.l < dist[G[u][i].to])                     
                       {                            
                       dist[G[u][i].to] = G[u][i].l + x.l;                            
                       node y;                            
                       y.to = G[u][i].to; y.l = dist[G[u][i].to];                            
                       q.push(y);                     
                       }       
        }
}int main()
{       
        int i;       
        scanf("%d%d%d", &n, &m, &T);       
        for(i = 1; i <= m; i++) 
        scanf("%d%d%d", &edge[i].x, &edge[i].y, &edge[i].z);       
        for(i = 1; i <= m; i++)       
        {              
                       node p; p.to = edge[i].x; p.l = edge[i].z;              
                       G[edge[i].y].pb(p);       
        }       
        dijkstra(T);       
        for(i = 1; i <= n; i++) rdist[i] = dist[i];       
        for(i = 1; i <= n; i++) G[i].clear();       
        for(i = 1; i <= m; i++)       
        {              
        node p; p.to = edge[i].y; p.l = edge[i].z;              
        G[edge[i].x].pb(p);       
        }       
        dijkstra(T);       
        int ans = 0;       
        for(i = 1; i <= n; i++)       
        {              
        if(i == T) continue;              
        ans = max(ans, dist[i] + rdist[i]);       
        }       
        printf("%d", ans);
        return 0;
}
