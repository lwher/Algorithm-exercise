#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cmath> 
#include<cstring> 
using namespace std; 
int n,ans; 
int sz,to[5000010],pre[5000010],last[2010]; 
char map[2010][2010]; 
bool in[2010],bed[2010][2010]; 
int fl,belong[2010],stack[2010],top,dfn[2010],low[2010],tt,sum[2010]; 
int SZ,TO[5000010],PRE[5000010],LAST[2010]; 
int dui[2010],rd[2010]; 
int lt[2010][110]; 
void Ins(int a,int b) 
{ 
    sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz; 
} 
void Tarjan(int x) 
{ 
    dfn[x]=++tt;low[x]=tt; 
    stack[++top]=x;in[x]=1; 
    int i=last[x]; 
    while(i>0) 
    { 
        if(dfn[to[i]]==0)  {Tarjan(to[i]);low[x]=min(low[x],low[to[i]]);} 
        else if(in[to[i]])  low[x]=min(low[x],dfn[to[i]]); 
        i=pre[i]; 
    } 
    if(dfn[x]==low[x]) 
    { 
        fl++;int k; 
        while(stack[top]!=x) 
        { 
            k=stack[top];belong[k]=fl;in[k]=0;top--;sum[fl]++; 
        } 
        in[x]=0;belong[x]=fl;top--;sum[fl]++; 
    } 
} 
void init() 
{ 
    int i,j; 
    scanf("%d",&n); 
    for(i=1;i<=n;i++)  
    { 
        scanf("%s",map[i]+1); 
        for(j=1;j<=n;j++) if(i!=j && map[i][j]=='1')  Ins(i,j); 
    } 
    for(i=1;i<=n;i++)  if(!dfn[i])  Tarjan(i); 
} 
void reIns(int a,int b) 
{ 
    SZ++;TO[SZ]=b;PRE[SZ]=LAST[a];LAST[a]=SZ;rd[b]++; 
} 
void rebuild() 
{ 
    int i,j,k,limt,p; 
    for(i=1;i<=n;i++) 
    { 
        j=last[i]; 
        while(j>0) 
        { 
            if(belong[to[j]]!=belong[i] && !bed[belong[i]][belong[to[j]]]) 
            { 
                bed[belong[i]][belong[to[j]]]=1;reIns(belong[i],belong[to[j]]); 
            } 
            j=pre[j]; 
        } 
    } 
    int tou=1,wei=0,now; 
    for(i=1;i<=fl;i++)  if(rd[i]==0)  dui[++wei]=i; 
    while(tou<=wei) 
    { 
        now=dui[tou];tou++; 
        i=LAST[now]; 
        while(i>0) 
        { 
            rd[TO[i]]--; 
            if(rd[TO[i]]==0)  dui[++wei]=TO[i]; 
            i=PRE[i]; 
        } 
    } 
    limt=fl/30; 
    if(fl%30)  limt++; 
    for(j=wei;j>=1;j--) 
    { 
        now=dui[j]; 
        i=LAST[now]; 
        while(i>0) 
        { 
            for(k=1;k<=limt;k++)  lt[now][k]|=lt[TO[i]][k];  
            i=PRE[i]; 
        } 
        p=now/30; 
        if(now%30) {p++;lt[now][p]|=(1<<((now%30)-1));} 
        else  lt[now][p]|=(1<<29); 
        for(k=1;k<=limt;k++) 
        { 
            for(i=0;i<30;i++)   
            if((lt[now][k]>>i) & 1) 
            { 
                ans+=sum[now]*sum[(k-1)*30+(i+1)]; 
            } 
        } 
    } 
    printf("%d\n",ans); 
} 
int main() 
{ 
    init(); 
    rebuild(); 
    //system("pause"); 
    return 0; 
}