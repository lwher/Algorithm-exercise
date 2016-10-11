#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const long long INF=1LL<<50;
int n,m,s,t,num[41][41],num1,num2,mx;
int dui[1610],h[1610],gap[1610];
int sz,to[30010],pre[30010],last[1610],cur[1610];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
long long sum1,sum2,v[30010];
inline void Ins(int a,int b,long long c)
{
    sz++;to[sz]=b;v[sz]=c;pre[sz]=last[a];last[a]=sz;
    sz++;to[sz]=a;v[sz]=0;pre[sz]=last[b];last[b]=sz;
}
void bfs()
{
     memset(h,-1,sizeof(h));
     memset(gap,0,sizeof(gap));
     int tou=1,wei=1,now,i;
     dui[1]=t;h[t]=1;gap[1]=1;
     while(tou<=wei)
     {
         now=dui[tou];tou++;
         for(i=last[now];i;i=pre[i])
         if(h[to[i]]==-1)
         {
             h[to[i]]=h[now]+1;
             gap[h[to[i]]]++;
             dui[++wei]=to[i];
         }
     }
}
long long dfs(int x,long long F)
{
     if(x==t) return F;
     long long used=0,w;
     for(int i=cur[x];i;i=pre[i])
     if(v[i]>0 && h[x]-1==h[to[i]])
     {
         w=min(F-used,v[i]);
         w=dfs(to[i],w);
         v[i]-=w;v[i^1]+=w;used+=w;
         if(v[i]>0) cur[x]=i;
         if(F==used) return F;
     }
     gap[h[x]]--;
     if(!gap[h[x]]) h[s]=t+2;
     gap[++h[x]]++;
     cur[x]=last[x];
     return used;
}
long long SAP()
{
     long long tmp=0;int i;
     bfs();
     for(i=1;i<=t;i++) cur[i]=last[i];
     while(h[s]<t+2) tmp+=dfs(s,INF);
     return tmp;
}
void build(long long x)
{
     int i,j,k,p,q,nx,ny;
     sz=1;memset(last,0,sizeof(last));
     for(i=1;i<=n;i++) for(j=1;j<=m;j++)
     {
         p=(i-1)*m+j;
         if((i+j) & 1)
         {
             Ins(s,p,x-num[i][j]);
             for(k=0;k<4;k++)
             {
                 nx=i+dx[k];ny=j+dy[k];
                 if(nx<1 || nx>n || ny<1 || ny>m) continue;
                 q=(nx-1)*m+ny;
                 Ins(p,q,INF);
             }
         }
         else  Ins(p,t,x-num[i][j]);
     }
}
void init()
{
     int i,j;
     scanf("%d%d",&n,&m);
     s=n*m+1;t=s+1;mx=0;sum1=0;sum2=0;num1=0;num2=0;
     for(i=1;i<=n;i++) for(j=1;j<=m;j++) 
     {
        scanf("%d",&num[i][j]);
        mx=max(mx,num[i][j]);
     }
     for(i=1;i<=n;i++) for(j=1;j<=m;j++)
     {
          if((i+j) & 1)  num2++,sum2+=num[i][j];
          else  num1++,sum1+=num[i][j];
     }
}
void solve()
{
      
     long long x;
     if(num1!=num2) 
     {
          x=(sum1-sum2)/(num1-num2);
          if(x*(num1-num2)!=sum1-sum2) {printf("-1\n");return;}
          if(x<mx) {printf("-1\n");return;}
          build(x);
          if(SAP()==x*num1-sum1) printf("%lld\n",x*num1-sum1);
          else  printf("-1\n");
     }
     else
     {
          long long l=mx,r=123456789876LL,mid;          
          while(l+1<r)
          {
              mid=(l+r)>>1;
              build(mid);
              if(SAP()==mid*num1-sum1) r=mid;
              else l=mid;
          }
          build(l);
          if(SAP()==l*num1-sum1) {printf("%lld\n",l*num1-sum1);return;}
          build(r);
          if(SAP()==r*num1-sum1) {printf("%lld\n",r*num1-sum1);return;}
          printf("-1\n");
     }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        init();     
        solve();
    }
    return 0;
}