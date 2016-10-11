#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
struct road{
       int u,v,cost;
}E[5000010];
inline bool comp(const road &a,const road &b){
       return a.cost < b.cost;
}
int n,m,fa[2010];
long long ans;
int find(int x){
    if (fa[x] == x) return x;
    else return fa[x] = find(fa[x]);
}
void init(){
     int i,j,C;
     scanf("%d",&n);
     for (i = 1;i <= n; i++) for (j = i;j <= n; j++) {
         scanf("%d",&C);
         E[++m].u = i-1;
         E[m].v = j;
         E[m].cost = C;
     }
}
void solve(){
     int i,x,y,p=0;
     for (i = 1;i <= n; i++) fa[i] = i;
     sort(E + 1,E + 1 + m,comp);
     for (i = 1;i <= m; i++){
         x = find(E[i].u);
         y = find(E[i].v);
         if (x != y){
               fa[x]=y;
               p++;
               ans += E[i].cost;
         }
         if (p == n) break;
     }
     cout << ans << endl;
}     
int main(){
    init();
    solve();
    system("pause");
    return 0;
}
