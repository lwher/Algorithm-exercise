#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define inf 100000000
#define INF 0x7fffffff
using namespace std;
int n,s,t,tot,num[3010];
int sz=1,to[3000010],v[3000010],pre[3000010],last[7010],cur[7010];
int h[7010],gap[7010],dui[7010];
void Ins(int a,int b,int c)
{
     sz++;to[sz]=b;v[sz]=c;pre[sz]=last[a];last[a]=sz;
     sz++;to[sz]=a;v[sz]=0;pre[sz]=last[b];last[b]=sz;
}
void bfs()
{
     memset(h,-1,sizeof(h));
     int tou=1,wei=1,i,now;
     h[t]=1;gap[1]=1;dui[1]=t;
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
int dfs(int x,int F)
{
    if(x==t)  return F;
    int used=0,w,i;
    for(i=cur[x];i;i=pre[i])
    if(v[i]>0 && h[x]-1==h[to[i]])
    {
        w=min(v[i],F-used);
        w=dfs(to[i],w);
        v[i]-=w;
        v[i^1]+=w;
        used+=w;
        if(v[i]>0)  cur[x]=i;
        if(used==F)  return F;
    }
    gap[h[x]]--;
    if(!gap[h[x]])  h[s]=t+2;
    gap[++h[x]]++;
    cur[x]=last[x];
    return used;
}
int SAP()
{
   int i,tmp=0;
   for(i=1;i<=t;i++)  cur[i]=last[i];
   while(h[s]<t+2)  tmp+=dfs(s,INF);
   return tmp;
}  
int gcd(int a,int b)
{
    if(b==0)  return a;
    return gcd(b,a%b);
}
bool check(int i,int j)
{
     int a=num[i],b=num[j];
     int c=a*a+b*b,d;d=sqrt(c);
     if(d*d!=c) return 0;
     if(gcd(a,b)!=1) return 0;
     return 1;
}
int main()
{
    int i,j;
    scanf("%d",&n);
    s=n+n+1;t=s+1;
    for(i=1;i<=n;i++)  
    {
       scanf("%d",&num[i]);
       Ins(s,i,num[i]);Ins(i+n,t,num[i]);
       tot+=num[i];
    }
    for(i=1;i<=n;i++)  for(j=i+1;j<=n;j++)  if(check(i,j))
    {
        Ins(i,j+n,inf);
        Ins(j,i+n,inf);
    }  
    printf("%d\n",tot-SAP()/2);
    system("pause");
    return 0;
}
