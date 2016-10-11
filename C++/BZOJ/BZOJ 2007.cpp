#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cmath> 
#include<cstring> 
using namespace std; 
int n,s,t; 
int sz,to[2000010],pre[2000010],v[2000010],last[250010]; 
int d[250010]; 
bool mark[250010]; 
int dui[5000010]; 
int read() 
{ 
    int x=0;char ch; 
    ch=getchar(); 
    while(!(ch>='0' && ch<='9'))  ch=getchar(); 
    while(ch>='0' && ch<='9') {x=x*10+(ch-'0');ch=getchar();} 
    return x; 
} 
void Ins(int a,int b,int c) 
{ 
    sz++;to[sz]=b;pre[sz]=last[a];v[sz]=c;last[a]=sz; 
} 
void init() 
{ 
    int i,j,k,p; 
    n=read(); 
    s=n*n+1;t=s+1; 
    //¡ú  
    for(i=1;i<=n;i++)  {p=read();Ins(i,t,p);} 
    for(i=1;i<n;i++)   for(j=1;j<=n;j++){p=read();Ins(i*n+j,(i-1)*n+j,p);}  
    for(i=1;i<=n;i++)  {p=read();Ins(s,n*(n-1)+i,p);} 
    //¡ý  
    for(i=1;i<=n;i++)  
    { 
       p=read();Ins(s,(i-1)*n+1,p); 
       for(j=1;j<n;j++) 
       {p=read();Ins((i-1)*n+j,(i-1)*n+j+1,p);} 
       p=read();Ins(i*n,t,p);  
    } 
    //¡û 
    for(i=1;i<=n;i++)  {p=read();Ins(t,i,p);} 
    for(i=1;i<n;i++)   for(j=1;j<=n;j++){p=read();Ins((i-1)*n+j,i*n+j,p);}  
    for(i=1;i<=n;i++)  {p=read();Ins(n*(n-1)+i,s,p);} 
    //¡ü 
    for(i=1;i<=n;i++)  
    { 
       p=read();Ins((i-1)*n+1,s,p); 
       for(j=1;j<n;j++) 
       {p=read();Ins((i-1)*n+j+1,(i-1)*n+j,p);} 
       p=read();Ins(t,i*n,p);  
    } 
} 
void spfa() 
{ 
    int tou=0,wei=1,now,i; 
    memset(d,127,sizeof(d)); 
    dui[1]=s;d[s]=0;mark[s]=1; 
    while(tou!=wei) 
    { 
        tou++;if(tou==5000000)  tou=0; 
        now=dui[tou]; 
        i=last[now]; 
        while(i>0) 
        { 
            if(d[to[i]]>d[now]+v[i]) 
            { 
                d[to[i]]=d[now]+v[i]; 
                if(!mark[to[i]]) 
                {mark[to[i]]=1;wei++;if(wei==5000000)  wei=0;dui[wei]=to[i];} 
            } 
            i=pre[i]; 
        } 
        mark[now]=0; 
    } 
} 
int main() 
{ 
    init(); 
    spfa(); 
    cout<<d[t]<<endl; 
    //system("pause"); 
    return 0; 
}