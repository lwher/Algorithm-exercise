#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define assign(x) (x)=++tot
#define swp(x,y) std::swap(h[x],h[y]);pos[h[x]]=(x);pos[h[y]]=(y);
const int maxn=500,maxm=60000,INF=1<<30;
int N,M,m,S,T,tot;
int P1[maxn],P2[maxn];
int fs[maxn],rev[maxm],cap[maxm],oth[maxm],cot[maxm],next[maxm];
int Q[maxn],dis[maxn],pree[maxn],pren[maxn];
int top,h[maxn],pos[maxn];
inline void add(const int &x,const int &y,const int &w,const int &c)
{
    oth[++m]=y;cap[m]=w;cot[m]=c;rev[m]=m+1;next[m]=fs[x];fs[x]=m;
    oth[++m]=x;cap[m]=0;cot[m]=-c;rev[m]=m-1;next[m]=fs[y];fs[y]=m;
}

inline void up(int x)
{
      while(x!=1&&dis[h[x]]<dis[h[x>>1]])
      {
        swp(x,x>>1);
        x>>=1;
      }
}
inline void down(int x)
{
      int y;
      while((x<<1)<=top){
        y=x<<1;
        if(y<top&&dis[h[y+1]]<dis[h[y]])++y;
        if(dis[h[x]]<=dis[h[y]])return;
        swp(x,y); x=y;
      }
}
inline int del()
{
      int t=h[1];
      pos[h[1]]=0;
      h[1]=h[top--];
      down(1);
      return t;
}
inline void ist(int x)
{
      h[++top]=x; pos[x]=top; 
      up(top);
} 
void spfa()
{
    int head,tail,u,i,t,th;
    memset(pos+1,0,sizeof(int)*tot);
    for(i=1;i<=tot;++i)dis[i]=INF;
    dis[S]=0; top=0; ist(S);
    while(top){
      u=del();
      for(i=fs[u];i;i=next[i])
        if(cap[i])
          if(dis[t=oth[i]]>dis[u]+cot[i]){
            dis[t]=dis[u]+cot[i];
            pren[t]=u; pree[t]=i;
            if(!pos[t])ist(t);else up(pos[t]);
          }
    }
}
int main()
{
  int i,x,y,w,maxf=0,minc=0;
  scanf("%d%d",&N,&M);
  assign(S); assign(T); 
  for(i=2;i<N;++i){assign(P1[i]);assign(P2[i]);}
  for(i=2;i<N;++i)add(P1[i],P2[i],1,0);
  P2[1]=S; P1[N]=T;
  while(M--)
  {
    scanf("%d%d%d",&x,&y,&w);
    if(x==N||y==1)continue;
    add(P2[x],P1[y],1,w);
  }
  while(1){
    spfa();
    if(dis[T]==INF)break;
    ++maxf; minc+=dis[T];
    for(i=T;i!=S;i=pren[i]){
      --cap[pree[i]];
      ++cap[rev[pree[i]]];
    }
  }
  printf("%d %d\n",maxf,minc);
  system("pause");
  return 0;
}

