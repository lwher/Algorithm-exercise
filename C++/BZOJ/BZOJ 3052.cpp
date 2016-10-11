#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct sth
{
    int l,r,lca,pre,t;
}xw[100010];
struct lwh
{
    int x,y,t;
}xg[100010];
int n,m,q,tt,SZ,KSZ,xwsz,xgsz,dfsxu[200010],ft[100010],fa[100010][17],deep[100010];
int sz,to[200010],pre[200010],last[100010];
int belong[200010],ask[60][60],C[100010];
int gs[100010],sum[100010],kind[100010],top,w[100010],wn[100010];//w[i]:当前的第i个询问的位置 
// sum[i]:第i种糖的出现次数  gs[i]：第i个点出现的次数  kind: 每个点当前的糖 
long long V[100010],W[100010],ans[100010];
inline void Ins(int a,int b)
{
    sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
inline void swap(int &a,int &b)
{
    int t=a;a=b;b=t;
}
void dfs(int x)
{
     ft[x]=++tt;dfsxu[tt]=x;
     for(int i=1;i<=16;i++)  fa[x][i]=fa[fa[x][i-1]][i-1];
     for(int i=last[x];i;i=pre[i])
     {
         if(to[i]==fa[x][0]) continue;
         fa[to[i]][0]=x;
         deep[to[i]]=deep[x]+1;
         dfs(to[i]);
     }
     dfsxu[++tt]=x;
}
int LCA(int a,int b)
{
    if(deep[a]<deep[b])  swap(a,b);
    int i,c=deep[a]-deep[b];
    for(i=16;i>=0;i--) if(c>=(1<<i)) {c-=(1<<i);a=fa[a][i];}
    for(i=16;i>=0;i--) if(fa[a][i]!=fa[b][i]) {a=fa[a][i];b=fa[b][i];}
    if(a==b) return a; return fa[a][0];
}
void init()
{
     int i,a,b,c,L,R;
     scanf("%d%d%d",&n,&m,&q);
     for(i=1;i<=m;i++) scanf("%lld",&V[i]);
     for(i=1;i<=n;i++) scanf("%lld",&W[i]);
     for(i=1;i<n;i++)
     {
         scanf("%d%d",&a,&b);
         Ins(a,b);Ins(b,a);
     }
     for(i=1;i<=n;i++) scanf("%d",&C[i]);
     dfs(1);
     n<<=1;
     for(KSZ=1;KSZ*KSZ*KSZ<n;KSZ++); KSZ*=KSZ;
     c=KSZ+1;
     for(i=1;i<=n;i++)
     {
         if(c>KSZ) {SZ++;c=1;}
         belong[i]=SZ;
         c++;
     }          
     for(i=1;i<=q;i++)
     {
         scanf("%d%d%d",&a,&b,&c);
         if(a==0) xg[++xgsz].x=b,xg[xgsz].y=c,xg[xgsz].t=i;
         else
         {
             if(ft[b]+1<=ft[c]) L=ft[b]+1,R=ft[c];
             else  L=ft[c]+1,R=ft[b];
             xw[++xwsz].l=L;xw[xwsz].r=R;xw[xwsz].lca=LCA(b,c);xw[xwsz].t=i;
             xw[xwsz].pre=ask[belong[L]][belong[R]];ask[belong[L]][belong[R]]=xwsz;
         }
     }
}
void solve()
{     
     int i,j,k,p,L,R,q;long long now;     
     for(i=1;i<=SZ;i++) for(j=i;j<=SZ;j++)
     if(ask[i][j])
     {
         L=1;R=0;now=0;
         for(k=1;k<=n;k++)  kind[k]=C[k];
         memset(sum,0,sizeof(sum));
         memset(gs,0,sizeof(gs));
         top=0;
         for(k=ask[i][j];k;k=xw[k].pre) wn[++top]=k;
         for(k=1;k<=top;k++) w[k]=wn[top-k+1];
         p=1;
         for(k=1;k<=top;k++)
         {
             while(p<=xgsz && xg[p].t<xw[w[k]].t)
             {
                 q=xg[p].x;
                 if(gs[q]==1)
                 {
                     now-=V[kind[q]]*W[sum[kind[q]]];sum[kind[q]]--;
                     kind[q]=xg[p].y;
                     sum[kind[q]]++;now+=V[kind[q]]*W[sum[kind[q]]];
                 }
                 else kind[xg[p].x]=xg[p].y;
                 p++;
             }
             while(R<xw[w[k]].r)
             {
                 R++;
                 q=dfsxu[R];
                 gs[q]++;
                 if(gs[q]==1) {sum[kind[q]]++;now+=V[kind[q]]*W[sum[kind[q]]];}
                 else {now-=V[kind[q]]*W[sum[kind[q]]];sum[kind[q]]--;}
             }
             while(L>xw[w[k]].l)
             {
                 L--;
                 q=dfsxu[L];
                 gs[q]++;
                 if(gs[q]==1) {sum[kind[q]]++;now+=V[kind[q]]*W[sum[kind[q]]];}
                 else {now-=V[kind[q]]*W[sum[kind[q]]];sum[kind[q]]--;}
             }
             while(R>xw[w[k]].r)
             {
                 q=dfsxu[R];
                 gs[q]--;
                 if(gs[q]==1) {sum[kind[q]]++;now+=V[kind[q]]*W[sum[kind[q]]];}
                 else {now-=V[kind[q]]*W[sum[kind[q]]];sum[kind[q]]--;}
                 R--;
             }
             while(L<xw[w[k]].l)
             {
                 q=dfsxu[L];
                 gs[q]--;
                 if(gs[q]==1) {sum[kind[q]]++;now+=V[kind[q]]*W[sum[kind[q]]];}
                 else {now-=V[kind[q]]*W[sum[kind[q]]];sum[kind[q]]--;}
                 L++;
             }
             q=xw[w[k]].lca;
             ans[w[k]]=now+V[kind[q]]*W[sum[kind[q]]+1];
         }
     }
     for(i=1;i<=xwsz;i++) printf("%lld\n",ans[i]);
}
int main()
{
    init();
    solve();
   // system("pause");
    return 0;
}