#include<iostream> 
#include<cstdio> 
#include<cstring> 
using namespace std; 
int t; 
int n; 
int to[40010],pre[40010],last[210]; 
bool d[210]; 
int pipei[210]; 
int sz; 
void Ins(int a,int b) 
{ 
    sz++; 
    to[sz]=b; 
    pre[sz]=last[a]; 
    last[a]=sz; 
} 
bool find(int x) 
{ 
    int i=last[x]; 
    while(i>0) 
    { 
        if(!d[to[i]]) 
        { 
            d[to[i]]=1; 
            if(pipei[to[i]]==0 || find(pipei[to[i]])) 
            { 
                pipei[to[i]]=x; 
                return 1; 
            } 
        } 
        i=pre[i]; 
    } 
    return 0; 
} 
int main() 
{ 
    int k,i,j,now; 
    cin>>t; 
    while(t--) 
    { 
        sz=0; 
        memset(last,0,sizeof(last)); 
        memset(pipei,0,sizeof(pipei)); 
        scanf("%d",&n); 
        for(i=1;i<=n;i++) 
        for(j=1;j<=n;j++) 
        { 
         scanf("%d",&k); 
         if(k) Ins(i,j); 
        } 
        now=0; 
        for(i=1;i<=n;i++) 
        { 
            memset(d,0,sizeof(d)); 
            if(find(i))  now++; 
        } 
        if(now==n) 
        printf("Yes\n"); 
        else
        printf("No\n"); 
    } 
    //system("pause"); 
    return 0; 
}