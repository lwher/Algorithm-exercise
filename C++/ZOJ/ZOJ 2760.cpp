#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#define MID(x,y) ((x+y)/2)
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
const int MAXV = 105;
const int MAXE = 30005;
const int oo = 0x3fffffff;
struct node{
    int u, v, flow;
    int opp;
    int next;
};
struct Dinic{
    node arc[MAXE];
    int vn, en, head[MAXV];    
    int cur[MAXV];              
    int q[MAXV];                
    int path[MAXE], top;        
    int dep[MAXV];             
    void init(int n){
        vn = n;
        en = 0;
        mem(head, -1);
    }
    void insert_flow(int u, int v, int flow){
        arc[en].u = u;
        arc[en].v = v;
        arc[en].flow = flow;
        arc[en].opp = en + 1;
        arc[en].next = head[u];
        head[u] = en ++;
        arc[en].u = v;
        arc[en].v = u;
        arc[en].flow = 0;      
        arc[en].opp = en - 1;
        arc[en].next = head[v];
        head[v] = en ++;
    }
    bool bfs(int s, int t){
        mem(dep, -1);
        int lq = 0, rq = 1;
        dep[s] = 0;
        q[lq] = s;
        while(lq < rq){
            int u = q[lq ++];
            if (u == t){
                return true;
            }
            for (int i = head[u]; i != -1; i = arc[i].next){
                int v = arc[i].v;
                if (dep[v] == -1 && arc[i].flow > 0){
                    dep[v] = dep[u] + 1;
                    q[rq ++] = v;
                }
            }
        }
        return false;
    }
    int solve(int s, int t){
        int maxflow = 0;
        while(bfs(s, t)){
            int i, j;
            for (i = 1; i <= vn; i ++)  cur[i] = head[i];
            for (i = s, top = 0;;){
                if (i == t){
                    int mink;
                    int minflow = 0x3fffffff;
                    for (int k = 0; k < top; k ++)
                        if (minflow > arc[path[k]].flow){
                            minflow = arc[path[k]].flow;
                            mink = k;
                        }
                    for (int k = 0; k < top; k ++)
                        arc[path[k]].flow -= minflow, arc[arc[path[k]].opp].flow += minflow;
                    maxflow += minflow;
                    top = mink;		
                    i = arc[path[top]].u;
                }
                for (j = cur[i]; j != -1; cur[i] = j = arc[j].next){
                    int v = arc[j].v;
                    if (arc[j].flow && dep[v] == dep[i] + 1)
                        break;
                }
                if (j != -1){
                    path[top ++] = j;
                    i = arc[j].v;
                }
                else{
                    if (top == 0)   break;
                    dep[i] = -1;
                    i = arc[path[-- top]].u;
                }
            }
        }
        return maxflow;
    }
}dinic;
int dist[MAXV][MAXV];
int ori[MAXV][MAXV];
void floyd(int n){
    for (int k = 1; k <= n; k ++){
        for (int i = 1; i <= n; i ++){
            if (dist[i][k] == oo)    continue;
            for (int j = 1; j <= n; j ++){
                if (dist[k][j] == oo)    continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    return ;
}
int main(){
	int n, s, t;
	while(scanf("%d", &n) != EOF){
        for (int i = 1; i <= n; i ++){
            for (int j = 1; j <= n; j ++){
                scanf("%d", &ori[i][j]);
                if (i == j)     ori[i][j] = 0;
                if (ori[i][j] == -1)    ori[i][j] = oo;
                dist[i][j] = ori[i][j];
            }
        }
        scanf("%d %d", &s, &t);
        s++, t++;
        if (s == t){
            puts("inf");
            continue;
        }
        floyd(n);
        dinic.init(n);
        for (int i = 1; i <= n; i ++){
            if (dist[s][i] == oo)    continue;
            for (int j = 1; j <= n; j ++){
                if (i == t || dist[j][t] == oo || ori[i][j] == oo)    continue;
                if (dist[s][i] + ori[i][j] + dist[j][t] == dist[s][t]){
                    dinic.insert_flow(i, j, 1);
                }
            }
        }
        int res = dinic.solve(s, t);
        printf("%d\n", res);
	}
	return 0;
}
 

