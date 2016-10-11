#include<iostream> 
#include<cstdio> 
#include<cstring> 
using namespace std; 
int n,k,sz,INF; 
int to[50010],pre[50010],last[1010]; 
int dui[30010],d[1010]; 
bool mark[1010]; 
void spfa() 
{ 
    int tou=1,wei=1,now,i; 
    memset(d,127,sizeof(d)); 
    INF=d[0]; 
    dui[1]=1;mark[1]=1;d[1]=0; 
    while(tou<=wei) 
    { 
        now=dui[tou]; 
        tou++; 
        i=last[now]; 
        while(i) 
        { 
            if(d[to[i]]>d[now]+1) 
            { 
                d[to[i]]=d[now]+1; 
                if(!mark[to[i]]) 
                { 
                    wei++;dui[wei]=to[i];mark[to[i]]=1; 
                } 
            } 
            i=pre[i]; 
        } 
        mark[now]=0; 
    } 
} 
int main() 
{ 
    int i,a,b; 
    scanf("%d%d",&k,&n); 
    for(i=1;i<=k;i++) 
    { 
        scanf("%d%d",&a,&b); 
        sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz; 
    } 
    spfa(); 
    if(d[n]==INF)  cout<<"-1"<<endl; 
    else cout<<d[n]+1<<endl; 
    //system("pause"); 
    return 0; 
}