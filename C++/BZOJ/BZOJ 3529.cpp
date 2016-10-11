#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 100000
#define INF 0x7fffffff
using namespace std;
struct sth
{
    int i;long long fi;
}xx[100010];
struct xxx
{
    int bh,a,n,m;
}xw[100010];
int T,tot,prime[100010],u[100010],L;
long long t[100010],ans[100010];
bool mark[100010];
inline bool comp(sth a,sth b) {return a.fi<b.fi;}
inline bool cmp(xxx a,xxx b) {return a.a<b.a;}
void work()
{
   int i,j;
   u[1]=1;
   for(i=2;i<=N;i++)
   {
       if(!mark[i]) {prime[++tot]=i;u[i]=-1;}
       for(j=1;j<=tot;j++)
       {
          if(i*prime[j]>N) break;
          mark[i*prime[j]]=1;
          if(i%prime[j]==0)  
          {
             u[i*prime[j]]=0;
             break;
          }
          else u[i*prime[j]]=-u[i];
       }
   }
}
void Ins(int x,long long k)
{
     for(int i=x;i<=N;i+=(i & (-i))) t[i]+=k;
}
long long ask(int x)
{
     long long now=0;
     for(int i=x;i>0;i-=(i & (-i))) now+=t[i];
     return now;
}
void Insert(long long A)
{
     while(L<=N && xx[L].fi<=A)
     {
         for(int i=1;i*xx[L].i<=N;i++)  Ins(xx[L].i*i,xx[L].fi*u[i]);
         L++;
     }
}
int main()
{
   int i,j,k,p,n,m;long long tmp;
   work();
   scanf("%d",&T);
   for(i=1;i<=T;i++)  
   {
      scanf("%d%d%d",&xw[i].n,&xw[i].m,&xw[i].a);
      xw[i].bh=i;
   }   
   for(i=1;i<=N;i++)
   {
      tmp=0;
      for(j=1;j*j<i;j++) if(i%j==0) tmp+=j+(i/j);
      if(j*j==i)  tmp+=j;
      xx[i].i=i;xx[i].fi=tmp;
   }      
   sort(xx+1,xx+1+N,comp);
   sort(xw+1,xw+1+T,cmp);   
   L=1;   
   for(i=1;i<=T;i++)
   {
      Insert(xw[i].a);
      p=min(xw[i].n,xw[i].m);
      n=xw[i].n;m=xw[i].m;
      for(j=1;j<=p;j=k+1)
      {
         k=min(n/(n/j),m/(m/j));
         ans[xw[i].bh]+=(ask(k)-ask(j-1))*(n/j)*(m/j);
      }
   }
   for(i=1;i<=T;i++)  printf("%d\n",ans[i]&INF);
   return 0;   
}