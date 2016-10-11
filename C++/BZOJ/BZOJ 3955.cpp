#include<iostream>
#include<map>
#include<cmath>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define N 25010
#define M 130010
#define INF 0x7fffffff
using namespace std;
struct node{
    int id,D;
    node(int x,int d){
        id=x;D=d;
    }
    bool operator <(const node &b) const{
        return D>b.D;
    }
};
int n,m,ans,C,X[M],Y[M],Z[M],in[N];
int sz,to[M],pre[M],v[M],last[N],dist[N];
bool mark[N];
void Ins(int a,int b,int c){
    sz++;to[sz]=b;v[sz]=c;pre[sz]=last[a];last[a]=sz;
}
void init(){
    scanf("%d%d%d",&n,&m,&C);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&X[i],&Y[i],&Z[i]);
        Ins(X[i],Y[i],Z[i]);Ins(Y[i],X[i],Z[i]);
    }
    int x;
    for(int i=1;i<=C;i++){
        scanf("%d",&x);in[x]++;
    }
}
priority_queue<node> Q;
void Dij(){
    memset(dist,127,sizeof(dist));
    dist[1]=0;
    Q.push(node(1,0));
    while(!Q.empty()){
        node x=Q.top();Q.pop();
        int now=x.id;
        if(mark[now]) continue;
        mark[now]=1;
        for(int i=last[now];i;i=pre[i]){
            if(dist[now]+v[i]<dist[to[i]]){
                dist[to[i]]=dist[now]+v[i];
                Q.push(node(to[i],dist[to[i]]));
            }
        }
    }
}
int sz_flow,to_flow[M<<1],pre_flow[M<<1],v_flow[M<<1],last_flow[N],cur[N];
int S,T,h[N],gap[N],Q_flow[N];
inline void Ins_flow(int a,int b,int c){
    sz_flow++;to_flow[sz_flow]=b;v_flow[sz_flow]=c;pre_flow[sz_flow]=last_flow[a];last_flow[a]=sz_flow;
    sz_flow++;to_flow[sz_flow]=a;v_flow[sz_flow]=0;pre_flow[sz_flow]=last_flow[b];last_flow[b]=sz_flow;
}
void BFS(){
    memset(h,-1,sizeof(h));
    memset(gap,0,sizeof(gap));
    int t=1,w=1,now;
    h[T]=1;gap[1]=1;
    Q_flow[1]=T;
    while(t<=w){
        now=Q_flow[t];t++;
        for(int i=last_flow[now];i;i=pre_flow[i]){
            if(h[to_flow[i]]==-1){
                h[to_flow[i]]=h[now]+1;
                Q_flow[++w]=to_flow[i];
                gap[h[now]+1]++;
            }
        }
    }
}
int dfs(int x,int F){
    if(x==T) return F;
    int used=0,w;
    for(int i=cur[x];i;i=pre_flow[i]){
        if(v_flow[i]>0 && h[to_flow[i]]+1==h[x]){
            w=min(F-used,v_flow[i]);
            w=dfs(to_flow[i],w);
            v_flow[i]-=w;v_flow[i^1]+=w;used+=w;
            if(v_flow[i]>0) cur[x]=i;
            if(F==used) return F;
        }
    }
    gap[h[x]]--;
    if(!gap[h[x]]) h[S]=T+3;
    cur[x]=last_flow[x];
    gap[++h[x]]++;
    return used; 
}
int SAP(){
    int res=0;
    BFS();
    for(int i=1;i<=T;i++) cur[i]=last_flow[i];
    while(h[S]<T+3) res+=dfs(S,INF);
    return res;
}
int Dist[N],tot,DTX[M],DTY[M],size;
inline bool comp(const int &a,const int &b){
    return dist[a]<dist[b];
}
void Mapclear(){
    S=n+1;T=S+1;sz_flow=1;
    memset(last_flow,0,sizeof(last_flow));
    for(int i=1;i<=size;i++){
        Ins_flow(DTX[i],DTY[i],1);
    }         
    Ins_flow(1,T,INF);
}
void solve(){      
    for(int i=1;i<=m;i++){
        if(dist[X[i]]+Z[i]==dist[Y[i]]) DTX[++size]=Y[i],DTY[size]=X[i];
        if(dist[Y[i]]+Z[i]==dist[X[i]]) DTX[++size]=X[i],DTY[size]=Y[i];
    }
    for(int i=1;i<=n;i++) if(in[i]>0) Dist[++tot]=i;
    sort(Dist+1,Dist+1+tot,comp);
    for(int i=1;i<=tot;i++){
        int j=i;
        while(j<tot && dist[Dist[j+1]]==dist[Dist[i]]) j++;
        if(j==i && in[Dist[j]]==1) ans++;
        else{
            Mapclear();
            for(int k=i;k<=j;k++) Ins_flow(S,Dist[k],in[Dist[k]]);
            ans+=SAP();i=j;
        }
    }
    cout<<ans<<endl;
}
int main(){
    init();
    Dij();
    solve();
    return 0;
}
