#include<iostream> 
#include<cstdio> 
#include<cstring> 
#include<cstdlib> 
using namespace std; 
int n,m,sz,top,k; 
int to1[50010],pre1[50010],last1[10010]; 
int to2[50010],pre2[50010],last2[10010]; 
int xu[10010],fl[10010]; 
bool mark[10010],du[10010],vis[10010]; 
int sum[10010]; 
void Ins(int a,int b) 
{ 
    sz++; 
    to1[sz]=b; 
    pre1[sz]=last1[a]; 
    last1[a]=sz; 
    to2[sz]=a; 
    pre2[sz]=last2[b]; 
    last2[b]=sz; 
} 
void dfs1(int x) 
{ 
    int i; 
    i=last1[x]; 
    mark[x]=1; 
    while(i>0) 
    { 
        if(!mark[to1[i]]) 
        dfs1(to1[i]); 
        i=pre1[i]; 
    } 
    top++; 
    xu[top]=x; 
} 
void dfs2(int x) 
{ 
    int i; 
    mark[x]=1; 
    fl[x]=k; 
    sum[k]++; 
    i=last2[x]; 
    while(i>0) 
    { 
        if(!mark[to2[i]]) 
        dfs2(to2[i]); 
        i=pre2[i]; 
    } 
} 
void dfs(int x,int l) 
{ 
    int i=last1[x]; 
    mark[x]=1; 
    if(l!=fl[x]) 
    {du[l]=1;return;} 
    while(i>0) 
    { 
        if(!mark[to1[i]] || fl[to1[i]]!=l) 
        {dfs(to1[i],l);} 
        if(du[l])  return; 
        i=pre1[i]; 
    } 
} 
int main() 
{ 
    int i,j,a,b; 
    scanf("%d%d",&n,&m); 
    for(i=1;i<=m;i++) 
    { 
        scanf("%d%d",&a,&b); 
        Ins(a,b); 
    } 
    for(i=1;i<=n;i++) 
    if(!mark[i]) 
    {dfs1(i);} 
    memset(mark,0,sizeof(mark)); 
    for(i=top;i>=1;i--) 
    { 
      if(!mark[xu[i]]) 
      { 
          k++; 
          dfs2(xu[i]); 
      } 
    } 
    memset(mark,0,sizeof(mark)); 
    for(i=1;i<=n;i++) 
    { 
        if(!vis[fl[i]]) 
        { 
            vis[fl[i]]=1; 
            dfs(i,fl[i]); 
        } 
    } 
    int ans,gs=0; 
    for(i=1;i<=k;i++) 
    { 
        if(!du[i]) 
        {gs++;ans=sum[i];} 
    } 
    if(gs==1)  cout<<ans<<endl; 
    else
    cout<<0<<endl; 
    //system("pause"); 
    return 0; 
}