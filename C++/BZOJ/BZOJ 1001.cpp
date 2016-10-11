#include<iostream> 
#include<cmath> 
#include<cstring> 
#include<stdio.h> 
using namespace std; 
struct sth 
{int zuo,you,last,v;}; 
sth a[6000001]; 
int end[1000001]; 
int gap[1000001]; 
int n,m; 
int sz=1; 
int h[1000001]; 
long long inf=2147483647;  
long long ans;  
int dui[1000001]; 
bool mark[1000001]; 
void bfs(int x) 
{ 
    int tou=1,wei=1,now,i; 
    dui[1]=x; 
    h[x]=0; 
    gap[0]++; 
    mark[x]=1; 
    while(tou<=wei) 
    { 
        now=dui[tou]; 
        i=end[now]; 
        while(i>0) 
        { 
           if(!mark[a[i].you]) 
           { 
            wei++; 
            h[a[i].you]=h[now]+1; 
            gap[h[a[i].you]]++; 
            mark[a[i].you]=1; 
            dui[wei]=a[i].you; 
           } 
           i=a[i].last; 
        } 
        tou++; 
    } 
} 
void cl(int aa,int bb,int cc) 
{ 
    sz++; 
    a[sz].zuo=aa; 
    a[sz].you=bb; 
    a[sz].v=cc; 
    a[sz].last=end[aa]; 
    end[aa]=sz; 
    sz++; 
    a[sz].zuo=bb; 
    a[sz].you=aa; 
    a[sz].v=cc; 
    a[sz].last=end[bb]; 
    end[bb]=sz; 
} 
void init() 
{ 
    int i,j,vv; 
    cin>>n>>m; 
    for(i=1;i<=n;i++) 
    for(j=1;j<=m-1;j++) 
    { 
      scanf("%d",&vv); 
      cl((i-1)*m+j,(i-1)*m+j+1,vv); 
    } 
    for(i=1;i<=n-1;i++) 
    for(j=1;j<=m;j++) 
    { 
      scanf("%d",&vv); 
      cl((i-1)*m+j,i*m+j,vv); 
    } 
    for(i=1;i<=n-1;i++) 
    for(j=1;j<=m-1;j++) 
    { 
      scanf("%d",&vv); 
      cl((i-1)*m+j,(i*m+j+1),vv); 
    } 
} 
long long dfs(int x,long long  F) 
{ 
    if(x==m*n)return F;  
    int i=end[x]; 
    long long w,used=0; 
    while(i>0) 
    { 
        if((a[i].v>0)&&(h[x]-1==h[a[i].you]))  
        { 
             w=F-used; 
             w=dfs(a[i].you,min(w,(long long) (a[i].v)));  
             a[i].v-=w; 
             a[i^1].v+=w;  
             used+=w;  
             if(used==F) 
             return used;  
        }  
        i=a[i].last; 
    }  
    gap[h[x]]--; 
    if(gap[h[x]]==0) 
    h[1]=n*m; 
    gap[++h[x]]++; 
    return used;  
} 
void wll() 
{ 
    while(h[1]<n*m) 
    ans+=dfs(1,inf);  
}  
int main() 
{ 
    init(); 
    bfs(n*m); 
      
    wll(); 
    cout<<ans<<endl; 
    //system("pause"); 
    return 0; 
} 

