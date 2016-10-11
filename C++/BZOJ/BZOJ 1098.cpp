#include <iostream> 
#include <cstdio> 
#include <cstring> 
#include <cstdlib> 
#include <queue> 
#include <vector> 
#include <algorithm> 
#define mm 2000100 
#define mn 100003 
using namespace std; 
queue<int> q; 
vector<int> v; 
int n,m,a,b,ans; 
bool vis[mn]; 
struct EDGE{ 
    int pnt; 
    EDGE *pre; 
    EDGE(){} 
    EDGE(int _pnt,EDGE *_pre):pnt(_pnt),pre(_pre){} 
}Edge[mm*2],*SP=Edge,*edge[mm]; 
struct LINE{ 
    int pre,next; 
    bool flag;   
}line[mn]; 
inline void addedge(int a,int b){ 
    edge[a]=new(++SP)EDGE(b,edge[a]); 
    edge[b]=new(++SP)EDGE(a,edge[b]); 
} 
void Del(int i){ 
    line[line[i].next].pre=line[i].pre; 
    line[line[i].pre].next=line[i].next; 
} 
void bfs(){ 
    while(line[0].next!=-1){ 
        q.push(line[0].next); 
        vis[line[0].next]=true; 
        Del(line[0].next); 
        int cnt=1; 
        while(!q.empty()){ 
            int i=q.front();q.pop(); 
            for(EDGE *j=edge[i];j;j=j->pre) line[j->pnt].flag=true; 
            for(int j=line[0].next;j>0;j=line[j].next) 
                if(!line[j].flag && !vis[j]){ 
                    q.push(j); 
                    vis[j]=true; 
                    Del(j); 
                    cnt++; 
                } 
            for(int j=line[0].next;j>0;j=line[j].next) line[j].flag=false; 
        } 
        ans++; 
        v.push_back(cnt); 
    } 
}                            
int main()
{ 
    scanf("%d%d",&n,&m); 
    for(int i=1;i<=m;i++)
    { 
        scanf("%d%d",&a,&b); 
        addedge(a,b); 
    } 
    for(int i=1;i<=n;i++)  
    line[i-1].next=i,line[i].pre=i-1; 
    line[n].next=-1; 
    bfs(); 
    sort(v.begin(),v.end()); 
    printf("%d\n",ans); 
    if(!v.empty()){ 
        for(int i=0;i<=v.size()-1;i++) printf("%d ",v[i]); 
        //printf("%d\n",v[v.size()-1]); 
    } 
    system("pause");
    return 0; 
} 
