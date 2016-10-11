#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
int k, n, m;
int a[110], s[1100];
bool b[1010];
vector <int> G[1010];
void dfs(int p)
{       
        ++s[p];       
        for(int i = 0; i < G[p].size(); i++)       
        {              
                       int u = G[p][i];              
                       if(!b[u])              
                       {                     
                                             b[u] = 1;                     
                                             dfs(u);              
                       }       
        }
}
int main()
{       
        int i;       
        cin>>k>>n>>m;       
        for(i = 1; i <= k; i++) cin>>a[i];       
        for(i = 1; i <= m; i++)        
        {              
                       int x, y; cin>>x>>y;              
                       G[x].push_back(y);       
        }       
        memset(s, 0, sizeof(s));       
        for(i = 1; i <= k; i++)       
        {              
                       memset(b, false, sizeof(b));              
                       b[a[i]] = 1; dfs(a[i]);       
        }       
        int ans = 0;       
        for(i = 1; i <= n; i++) 
        if(s[i] == k) ++ans;       
        cout<<ans<<endl;
        system("pause");
        return 0;
}   
