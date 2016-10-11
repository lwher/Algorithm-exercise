#include<iostream> 
#include<cstdio> 
#include<cstdlib>  
#include<cstring> 
#include<cmath> 
using namespace std; 
int n,m; 
bool mark[2010],o; 
int sz,to[20010],pre[20010],last[2010]; 
int ans[1010]; 
void Ins(int a,int b) 
{ 
    sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz; 
} 
void dfs(int x) 
{ 
    mark[x]=1; 
    int i=last[x]; 
    while(i>0) 
    { 
        if(!mark[to[i]])  dfs(to[i]); 
        i=pre[i]; 
    } 
} 
bool check(int x) 
{ 
    memset(mark,0,sizeof(mark)); 
    dfs(x); 
    for(int i=1;i<=n;i++)  if(mark[i] && mark[i+n])  return 0; 
    return 1; 
} 
int main() 
{ 
    int i,a,b; 
    bool p,q; 
    char A[3],B[3]; 
    scanf("%d%d",&n,&m); 
    for(i=1;i<=m;i++) 
    { 
        scanf("%d%s",&a,A);scanf("%d%s",&b,B); 
        if(A[0]=='Y')  p=1; else p=0; 
        if(B[0]=='Y')  q=1; else q=0; 
        if(p && q)   {Ins(a+n,b);Ins(b+n,a);}   // Y Y 
        if(p && !q)  {Ins(a+n,b+n);Ins(b,a);}   // Y N 
        if(!p && q)  {Ins(a,b);Ins(b+n,a+n);}   // N Y  
        if(!p && !q) {Ins(a,b+n);Ins(b,a+n);}   // N N                           
    }        
    for(i=1;i<=n;i++) 
    { 
        p=check(i); 
        q=check(i+n); 
        if(p && q)  ans[i]=1;  // ? 
        if(p && !q) ans[i]=2; //printf("Y"); 
        if(!p && q) ans[i]=3; //printf("N"); 
        if(!p && !q) {o=1;break;} 
    } 
    if(o)  printf("IMPOSSIBLE\n"); 
    else
    { 
        for(i=1;i<=n;i++) 
        { 
            if(ans[i]==1) printf("?"); 
            if(ans[i]==2) printf("Y"); 
            if(ans[i]==3) printf("N"); 
        } 
        printf("\n"); 
    } 
    //system("pause"); 
    return 0; 
}