#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define INF 0x7fffffff
using namespace std;
int n,m,d;
int s,t,sz=1;
int map[21][21],h[500],gap[550];
char tu[21][21];
int v[600010],to[600010],pre[600010],last[500];
long long ans;
void Ins(int a,int b,int c)
{
     sz++;
     to[sz]=b;
     pre[sz]=last[a];
     v[sz]=c;
     last[a]=sz;
     sz++;
     to[sz]=a;
     pre[sz]=last[b];
     v[sz]=0;
     last[b]=sz;
}
void bfs()
{
     memset(h,-1,sizeof(h));
     int i,now;
     int dui[500];
     int tou=1,wei=1;
     dui[1]=t;
     h[t]=1;
     gap[1]++;
     while(tou<=wei)
     {
        now=dui[tou];
        i=last[now];
        while(i>0)
        {
            if(h[to[i]]<0)
            {
               wei++;dui[wei]=to[i];h[to[i]]=h[now]+1;gap[h[to[i]]]++;
            }
            i=pre[i];
        }
        tou++;
     }
}
int dfs(int x,int F)
{
    if(x==t)  return F;
    int i;
    int w,used=0;
    i=last[x];
    while(i>0)
    {
        if(v[i]>0 && h[x]-1==h[to[i]])
        {
           w=F-used;
           w=dfs(to[i],min(v[i],w));
           v[i]-=w;
           v[i^1]+=w;
           used+=w;
           if(used==F)
           return F;
        }
        i=pre[i];
    }
    gap[h[x]]--;
    if(gap[h[x]]==0)
    {
       h[s]=n+1;
    }
    gap[++h[x]]++;
    return used;
}
void SAP()
{
     ans=0;
     while(h[s]<=n)
     {
       ans+=dfs(s,INF);
     }
}
int main()
{
   // scanf("%d%d%d",&n,&m,&d);
    while(cin>>m>>n)
	{
	memset(last,0,sizeof(last));
	memset(gap,0,sizeof(gap));
	sz=1;

	int i,j,aa,b,vv;
	int flow;
	for(i=1;i<=m;i++)
	{
	cin>>aa>>b>>vv;
	Ins(aa,b,vv);
	}
	
	s=1;t=n;
	bfs();
    SAP(); 
    cout<<ans<<endl; 
	}
    system("pause");
    return 0;
}
