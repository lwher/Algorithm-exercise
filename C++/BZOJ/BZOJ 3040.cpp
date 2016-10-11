#include<iostream> 
#include<stdio.h> 
#include<cstdlib> 
#include<cmath> 
#include<string.h> 
using namespace std; 
int n,m; 
int t,rxa,rxc,rya,ryc,rp; 
int v[10000010],to[10000010],last[1000010],pre[10000010]; 
int x,y,z,a,b; 
int sz=0; 
int dis[1000010],bh[1000010]; 
int wz[1000010]; 
bool mark[1000010]; 
void Ins(int s,int tt,int val) 
{ 
    sz++; 
    v[sz]=val; 
    to[sz]=tt; 
    pre[sz]=last[s]; 
    last[s]=sz; 
} 
void add(int x) 
{ 
    int k,now=x; 
    while(dis[now]<dis[now/2]) 
    { 
        wz[bh[now]]=now/2; 
        wz[bh[now/2]]=now; 
        k=dis[now]; 
        dis[now]=dis[now/2]; 
        dis[now/2]=k; 
        k=bh[now]; 
        bh[now]=bh[now/2]; 
        bh[now/2]=k; 
        now/=2; 
    } 
} 
void get(int x) 
{ 
    int k,now=x; 
    while(1) 
    { 
        if(now*2+1<=n && dis[now]>dis[now*2] && dis[now*2]<=dis[now*2+1]) 
        { 
        wz[bh[now]]=now*2; 
        wz[bh[now*2]]=now; 
        k=dis[now]; 
        dis[now]=dis[now*2]; 
        dis[now*2]=k; 
        k=bh[now]; 
        bh[now]=bh[now*2]; 
        bh[now*2]=k; 
        now*=2; 
        } 
        else
        if(now*2+1<=n && dis[now]>dis[now*2+1]) 
        { 
        wz[bh[now]]=now*2+1; 
        wz[bh[now*2+1]]=now; 
        k=dis[now]; 
        dis[now]=dis[now*2+1]; 
        dis[now*2+1]=k; 
        k=bh[now]; 
        bh[now]=bh[now*2+1]; 
        bh[now*2+1]=k; 
        now=now*2+1;     
        } 
        else
        if(now*2<=n && dis[now*2]<dis[now]) 
        { 
        wz[bh[now]]=now*2; 
        wz[bh[now*2]]=now; 
        k=dis[now]; 
        dis[now]=dis[now*2]; 
        dis[now*2]=k; 
        k=bh[now]; 
        bh[now]=bh[now*2]; 
        bh[now*2]=k; 
        now*=2;  
        } 
        else
        break; 
    } 
} 
int main() 
{ 
    int i,j; 
    int minn,now,cj; 
    scanf("%d%d",&n,&m); 
    scanf("%d%d%d%d%d%d",&t,&rxa,&rxc,&rya,&ryc,&rp); 
    x=0; 
    y=0; 
    z=0; 
    for(i=1;i<=t;i++) 
    { 
       x=(x*rxa+rxc)%rp; 
       y=(y*rya+ryc)%rp; 
       a=min(x%n+1,y%n+1); 
       b=max(y%n+1,y%n+1); 
       Ins(a,b,100000000-100*a); 
    } 
    for(i=t+1;i<=m;i++) 
    { 
        scanf("%d%d%d",&x,&y,&z); 
        Ins(x,y,z); 
    } 
    memset(dis,127,sizeof(dis)); 
    dis[1]=0;dis[0]=-2147483647; 
    for(i=1;i<=n;i++) 
    {bh[i]=i;wz[i]=i;} 
      
    for(i=1;i<=n;i++) 
    { 
        if(bh[1]==n)  break; 
        now=bh[1]; 
        cj=dis[1]; 
        dis[1]=2147483647; 
        get(1); 
        j=last[now]; 
        while(j>0) 
        { 
            if(cj+v[j]<dis[wz[to[j]]]) 
            {dis[wz[to[j]]]=cj+v[j];add(wz[to[j]]);} 
            j=pre[j]; 
        } 
    } 
    printf("%d\n",dis[wz[n]]); 
//  system("pause"); 
    return 0; 
}