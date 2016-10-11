#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cstring> 
#include<algorithm> 
using namespace std; 
struct sth 
{ 
    long long  t1,t2; 
}p[1000010]; 
int n; 
int top; 
long long heap[1000010]; 
inline bool comp(sth a,sth b) 
{ 
    if(a.t2==b.t2)  return a.t1<b.t1; 
    return a.t2<b.t2; 
} 
void get(int x) 
{ 
    int now=x,o; 
    while(heap[now]>heap[now/2]) 
    { 
        if(now==1)  break; 
        o=heap[now]; 
        heap[now]=heap[now/2]; 
        heap[now/2]=o; 
        now/=2; 
    } 
} 
void put(int x) 
{ 
    int now=x; 
    int o; 
    while(1) 
    { 
        if(now*2>top)  break; 
        if(heap[now]<heap[now*2] && heap[now*2]>heap[now*2+1]) 
        { 
           o=heap[now]; 
           heap[now]=heap[now*2]; 
           heap[now*2]=o; 
           now*=2; 
        } 
        else
        if(heap[now]<heap[now*2+1]) 
        { 
           o=heap[now]; 
           heap[now]=heap[now*2+1]; 
           heap[now*2+1]=o; 
           now=now*2+1; 
        }    
        else
        break; 
    } 
} 
int main() 
{ 
    int i,j; 
    long long  time=0; 
    scanf("%d",&n); 
    for(i=1;i<=n;i++) 
    scanf("%lld%lld",&p[i].t1,&p[i].t2); 
    memset(heap,-1,sizeof(heap)); 
    sort(p+1,p+1+n,comp); 
    for(i=1;i<=n;i++) 
    { 
       if(time+p[i].t1<=p[i].t2) 
       { 
            top++; 
            heap[top]=p[i].t1; 
            get(top); 
            time+=p[i].t1; 
       }     
       else
       if(heap[1]>p[i].t1) 
       {  
          time-=heap[1]; 
          time+=p[i].t1; 
          heap[1]=p[i].t1; 
          put(1); 
       } 
    } 
    printf("%d\n",top); 
    //system("pause"); 
    return 0; 
}