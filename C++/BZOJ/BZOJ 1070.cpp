#include<iostream>  
#include<cstring>  
#include<cstdio>  
#define INF 0x7fffffff  
using namespace std;  
int n,m,s,t;  
int sz=1,ans;  
int tt[65][15];  
int to[130010],pre[130010],v[130010],cost[130010],last[710];  
bool mark[710];  
int dis[710];  
int dui[200010];  
void Ins(int a,int b,int c,int d)  
{  
    sz++;  
    to[sz]=b;  
    v[sz]=c;  
    cost[sz]=d;  
    pre[sz]=last[a];  
    last[a]=sz;  
    sz++;  
    to[sz]=a;  
    v[sz]=0;  
    cost[sz]=-d;  
    pre[sz]=last[b];  
    last[b]=sz;  
}  
bool bfs()  
{  
    int i,now,tou=1,wei=1;  
    for(i=0;i<=700;i++)  dis[i]=INF;  
    memset(mark,0,sizeof(mark));  
    mark[s]=1;  
    dui[1]=s;  
    dis[s]=0;  
    while(tou<=wei)  
    {  
        now=dui[tou];  
        i=last[now];  
        while(i>0)  
        {  
            if(v[i]>0 && dis[to[i]]>dis[now]+cost[i])  
            {  
                dis[to[i]]=dis[now]+cost[i];  
                if(!mark[to[i]])  
                {  
                    wei++;  
                    dui[wei]=to[i];  
                    mark[to[i]]=1;  
                }  
            }  
            i=pre[i];  
        }  
        mark[now]=0;  
        tou++;  
    }  
    if(dis[t]==INF)    
    return 0;  
    return 1;  
}  
int dfs(int x,int F)  
{  
    if(x==t) {mark[x]=1; return F;}  
    int i=last[x];  
    int w,used=0;  
    mark[x]=1;  
    while(i>0)  
    {  
        if(v[i]>0  && !mark[to[i]] && dis[x]+cost[i]==dis[to[i]])  
        {  
            w=dfs(to[i],min(F-used,v[i]));  
            used+=w;  
            v[i]-=w;  
            v[i^1]+=w;  
            ans+=w*cost[i];  
            if(used==F)  
            return used;  
        }  
        i=pre[i];  
    }  
    return used;  
}  
void zkw()  
{  
    while(bfs())  
    {  
        mark[t]=1;  
        while(mark[t])  
        {  
            memset(mark,0,sizeof(mark));  
            dfs(s,INF);  
        }  
    }  
}  
void build()  
{  
    int i,j,k;  
    s=0;t=700;  
    for(i=1;i<=n*m;i++)  
    Ins(s,i,1,0);  
    for(i=n*m+1;i<=n*m+n;i++)  
    Ins(i,t,1,0);  
        
    for(k=0;k<m;k++)  
    for(i=1;i<=n;i++)  
    for(j=1;j<=n;j++)  
    {Ins(k*n+i,n*m+j,1,tt[j][k+1]*i);}  
}  
int main()  
{  
    int i,j;  
    scanf("%d%d",&m,&n);  
    for(i=1;i<=n;i++)  
    for(j=1;j<=m;j++)  
    scanf("%d",&tt[i][j]);  
    build();  
    zkw();  
    printf("%.2lf\n",double(ans)/n);  
    //system("pause");  
    return 0;  
}