#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define INF 0x7fffffff
#define eps 1e-8
using namespace std;
int n,s1,t1,s2,t2,s,t;
double num[110][110];
int sz=1,to[100010],pre[100010],v[100010],last[310],cur[310];
int in[310],dui[310],h[310],gap[310];
void Ins(int a,int b,int c)
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
int dfs(int x,int F)
{
    if(x==t) return F;
    int used=0,w,i;
    for(i=cur[x];i;i=pre[i])
    if(v[i]>0 && h[x]-1==h[to[i]])
    {
        w=min(v[i],F-used);
        w=dfs(to[i],w);
        v[i]-=w;v[i^1]+=w;used+=w;
        if(v[i]>0) cur[x]=i;
        if(F==used) return F;
    }
    gap[h[x]]--;
    if(!gap[h[x]]) h[s]=t2+1;
    cur[x]=last[x];
    gap[++h[x]]++;
    return used;
}
int SAP()
{
    int i,tmp=0;
    bfs();
    for(i=1;i<=t2;i++) cur[i]=last[i];
    while(h[s]<t2+1) tmp+=dfs(s,INF);
    return tmp;
}
int main()
{
    int i,j,now,sum=0;
    double k,p;
    scanf("%d",&n);
    for(i=1;i<=n;i++) for(j=1;j<=n;j++)  scanf("%lf",&num[i][j]);
    s1=n+n+1;t1=s1+1;s2=t1+1;t2=s2+1;
    for(i=1;i<n;i++) 
    {
        k=floor(num[i][n]+eps);p=ceil(num[i][n]-eps);
        in[i]+=(int)(k);in[s1]-=(int)(k);
        if(p-k>0.8) Ins(s1,i,1);
    }
    for(i=1;i<n;i++) 
    {
        k=floor(num[n][i]+eps);p=ceil(num[n][i]-eps);
        in[i+n]-=(int)(k);in[t1]+=(int)(k);
        if(p-k>0.8) Ins(i+n,t1,1);
    }
    for(i=1;i<n;i++) for(j=1;j<n;j++)
    {
        k=floor(num[i][j]+eps);p=ceil(num[i][j]-eps);
        in[i]-=(int)(k);in[j+n]+=(int)(k);
        if(p-k>0.8) Ins(i,j+n,1);
    }
    for(i=1;i<=t1;i++) 
    {
        if(in[i]>0) {Ins(s2,i,in[i]);sum+=in[i];}
        else Ins(i,t2,-in[i]);
    }    
    Ins(t1,s1,INF);     
    s=s2;t=t2;
    now=SAP();
    if(now!=sum) printf("No\n");
    else
    {
        s=s1;t=t1;
        now=SAP();
        printf("%d\n",now*3);
    }
    //system("pause");
    return 0;
}
