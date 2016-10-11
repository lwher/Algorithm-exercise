#include<iostream> 
#include<cstdlib> 
#include<cstdio> 
#include<cstring> 
using namespace std; 
int n; 
int from[1000010],too[1000010],cc[1000010]; 
int last[1000010],to[2000010],v[2000010],pre[2000010],sz; 
int sum[1000010],fa[1000010]; 
int dui[1000010]; 
bool mark[1000010]; 
long long ans; 
long long mabs(long long a) 
{ 
    if(a<0)  a=-a; 
    return a; 
} 
void Ins(int a,int b,int c) 
{ 
    sz++;to[sz]=b;v[sz]=c;pre[sz]=last[a];last[a]=sz; 
    sz++;to[sz]=a;v[sz]=c;pre[sz]=last[b];last[b]=sz; 
} 
void init() 
{ 
    int i,j; 
    int a,b,c; 
    scanf("%d",&n); 
    for(i=1;i<n;i++) 
    { 
        scanf("%d%d%d",&a,&b,&c); 
        from[i]=a;too[i]=b;cc[i]=c; 
        Ins(a,b,c); 
    } 
} 
void bfs() 
{ 
    int i,now,pp; 
    int tou=1,wei=1; 
    dui[1]=1;mark[1]=1; 
    while(tou<=wei) 
    { 
        now=dui[tou]; 
        sum[now]=1; 
        i=last[now]; 
        while(i>0) 
        { 
             pp=to[i]; 
             if(!mark[pp]) 
             { 
                    wei++; 
                    dui[wei]=pp; 
                    fa[pp]=now; 
                    mark[pp]=1; 
             } 
             i=pre[i]; 
        } 
        tou++; 
    } 
    for(i=n;i>1;i--) 
    { 
        sum[fa[dui[i]]]+=sum[dui[i]]; 
    } 
} 
void solve() 
{ 
    long long k; 
    int i; 
    int a,b; 
    for(i=1;i<=n-1;i++) 
    { 
        a=from[i]; 
        b=too[i]; 
        if(a!=fa[b]) 
        { 
            a=too[i]; 
            b=from[i]; 
        } 
        k=mabs(n-2*sum[b]); 
        ans+=k*cc[i]; 
    } 
    cout<<ans<<endl; 
} 
int main() 
{ 
    init(); 
    bfs(); 
    solve(); 
    //system("pause"); 
    return 0; 
}