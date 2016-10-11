#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 150010
#define INF 0x7fffffff
using namespace std;
int n,m,father[N],ans=INF;
int c[N][2],fa[N],val[N],q[N],mx[N];
bool fz[N];
struct edge{
       int u,v,a,b;
}e[N];
int find(int x){
    if(father[x]==0) return x;
    else return father[x]=find(father[x]);
}
inline bool comp(const edge &a,const edge &b){
       return a.a<b.a;
}
inline bool isroot(int x){
     return (c[fa[x]][0]!=x && c[fa[x]][1]!=x);
}
inline void swap(int &a,int &b){
       int t=a;a=b;b=t;
}
inline void updata(int x){
     int l=c[x][0],r=c[x][1];
     mx[x]=x;
     if(val[mx[l]]>val[mx[x]]) mx[x]=mx[l];
     if(val[mx[r]]>val[mx[x]]) mx[x]=mx[r];
}
inline void pushdown(int x){
     int l=c[x][0],r=c[x][1];
     fz[x]^=1;fz[l]^=1;fz[r]^=1;
     swap(c[x][0],c[x][1]);
}
void rotate(int x){
     int y=fa[x],z=fa[y],p,q;
     if(c[y][0]==x) p=0; else p=1;
     q=p^1;
     if(!isroot(y)){
                    if(c[z][0]==y) c[z][0]=x;
                    else c[z][1]=x;
     }               
     fa[x]=z;fa[y]=x;fa[c[x][q]]=y;
     c[y][p]=c[x][q];c[x][q]=y;
     updata(y);updata(x);
}
void splay(int x){
     int i,top=0;
     for(i=x;!isroot(i);i=fa[i]) q[++top]=i;
     q[++top]=i;
     for(int i=top;i;i--) if(fz[q[i]]) pushdown(q[i]);
     while(!isroot(x)){
                       int y=fa[x],z=fa[y];
                       if(!isroot(y)){
                                      if(c[y][0]==x ^ c[z][0]==y) rotate(x);
                                      else rotate(y);
                       }
                       rotate(x);
     }
}
inline void access(int x){
       int T=0;
       while(x>0){
                  splay(x);
                  c[x][1]=T;
                  updata(x);
                  T=x;
                  x=fa[x];
       }
}
inline void makeroot(int x){
       access(x);splay(x);fz[x]^=1;
}
inline void link(int x,int y){
       makeroot(x);fa[x]=y;
}
inline void cut(int x,int y){
       makeroot(x);access(y);splay(y);c[y][0]=fa[x]=0;
}
inline int query(int x,int y){
       makeroot(x);access(y);splay(y);return mx[y];
}
void solve(){
     int i,t,u,v,w,x,y;
     for(i=1;i<=m;i++){
                       u=e[i].u;v=e[i].v;w=e[i].b;
                       x=find(u);y=find(v);
                       if(x!=y){
                                father[x]=y;
                                link(u,n+i);link(v,n+i);
                       }
                       else {
                            t=query(u,v);
                            if(w<val[t]){
                                         cut(e[t-n].u,t);cut(e[t-n].v,t);
                                         link(u,i+n);link(v,i+n);
                            }
                       }
                       if(find(1)==find(n)) ans=min(ans,val[query(1,n)]+e[i].a);
     }
     if(ans==INF) printf("-1\n");
     else printf("%d\n",ans);
}
void init(){
     scanf("%d%d",&n,&m);
     for(int i=1;i<=m;i++) scanf("%d%d%d%d",&e[i].u,&e[i].v,&e[i].a,&e[i].b);
     sort(e+1,e+1+m,comp);
     for(int i=1;i<=m;i++){
             val[n+i]=e[i].b;
             mx[n+i]=n+i;
     }
}
int main(){    
    init();    
    solve();
    system("pause");
    return 0;
}
