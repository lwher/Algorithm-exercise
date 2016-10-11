#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
int n, m;
int dist[110], a[10010], dis[110][110];
bool b[110];
struct node
{       
        int to, l;       
        bool operator < (const node &a) const       
        {              
        return a.l < l;       
        }
};vector <node> G[110];
void dijkstra(int st)
{       
        int i, j;       
        priority_queue <node> q;       
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
        {                     
                              if(G[u][i].l + x.l < dist[G[u][i].to])                     
        {                            
        dist[G[u][i].to] = G[u][i].l + x.l;                            
        node y;                            
        y.to = G[u][i].to; y.l = dist[G[u][i].to];                            
        q.push(y);                     
        }              
        }       
        }
}
int main()
{       int i, j, ans = 0;       
        cin>>n>>m;       
        for(i = 1; i <= m; i++) cin>>a[i];       
        for(i = 1; i <= n; i++) 
        for(j = 1; j <= n; j++)       
        {              
                       int x; cin>>x;              
                       if(i == j) continue;             
                       node p = {j, x};              
                       G[i].pb(p);       
        }       
        for(i = 1; i <= n; i++) 
        {
        dijkstra(i); 
        for(j = 1; j <= n; j++) 
        dis[i][j] = dist[j];
        }       
        for(i = 2; i <= m; i++) ans += dis[a[i - 1]][a[i]];       
        cout<<ans<<endl;
        system("pause");
        return 0;
}  
