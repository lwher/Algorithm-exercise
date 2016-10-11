#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;
int n, m, h0[5010], num = 0, f[5010], g[5010];
vector <int> G[5010], G2[5010]; 
void dp1(int p)
{       
        if(!G2[p].size()) 
        {f[p] = 1; return;}       
        for(int i = 0; i < G2[p].size(); i++)       
        {              
        int u = G2[p][i];              
        if(!f[u]) dp1(u);              
        f[p] += f[u];       
        }
} 
void dp2(int p)
{       
        if(!G[p].size()) 
        {g[p] = 1; return;}       
        for(int i = 0; i < G[p].size(); i++)       
        {              
        int u = G[p][i];              
        if(!g[u]) dp2(u);              
        g[p] += g[u];       
        }
} 
int main()
{       
      int i;             
      cin >> n >> m;       
      memset(f, 0, sizeof(f)); 
      memset(g, 0, sizeof(g));       
      for(i = 1; i <= m; i++)       
      {              
                     int x, y; 
                     cin >> x >> y; 
                     if(x > y) swap(x, y);              
                     G[x].push_back(y); G2[y].push_back(x);       
      }       
      dp1(n); 
      dp2(1);      
      int ans = 0;       
      for(i = 1; i < n; i++)              
      for(int j = 0; j < G[i].size(); j++)              
      {                     
                            int u = G[i][j];                     
                            ans = max(ans, f[i] * g[u]);              
      }       
      cout << ans << endl;
      system("pause");
      return 0;
}        
