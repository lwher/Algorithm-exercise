#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cmath> 
#include<cstdlib> 
#include<algorithm> 
using namespace std; 
int h[1000010],now[1000010]; 
int jia[1010]; 
int n,q,limt; 
inline bool comp(int a,int b) 
{ 
    return a>b; 
} 
void rebuild(int l,int r,int zuo,int you,int k) 
{ 
    int t=(l-1)/limt+1; 
    for(int i=l;i<=r;i++)  h[i]+=jia[t]; 
    for(int i=zuo;i<=you;i++)  h[i]+=k; 
    for(int i=l;i<=r;i++)  now[i]=h[i]; 
    sort(now+l,now+r+1,comp);jia[t]=0; 
} 
void build() 
{ 
    for(int i=1;i<=n;i+=limt)    
    if(i+limt<=n) sort(now+i,now+i+limt,comp); 
    else   sort(now+i,now+n+1,comp); 
} 
void updata(int zuo,int you,int k) 
{ 
    int i,l,t,r; 
    l=(zuo-1)/limt+1; 
    r=(you-1)/limt+1; 
    for(t=l+1;t<=r-1;t++)  jia[t]+=k; 
    t=(l-1)*limt+1; 
    rebuild(t,min(t+limt-1,n),zuo,min(t+limt-1,you),k); 
    if(l!=r) 
    { 
         t=(r-1)*limt+1; 
         rebuild(t,min(t+limt-1,n),t,you,k); 
    }  
} 
int ask(int zuo,int you,int c) 
{ 
    int l=zuo,r=you,mid; 
    c-=jia[(l-1)/limt+1]; 
    while(l+1<r) 
    { 
        int mid=(l+r)>>1; 
        if(now[mid]<c)  r=mid; 
        else l=mid; 
    } 
    if(now[r]>=c)  return r-zuo+1; 
    if(now[l]>=c)  return l-zuo+1; 
    return 0; 
} 
int solve(int zuo,int you,int c) 
{ 
    int l,r,t,p,ans=0; 
    l=(zuo-1)/limt+1; 
    r=(you-1)/limt+1; 
    for(t=l+1;t<=r-1;t++)  ans+=ask((t-1)*limt+1,t*limt,c); 
    p=min(you,l*limt); 
    for(t=zuo;t<=p;t++)  if(h[t]+jia[l]>=c)  ans++; 
    if(l!=r) 
    { 
        p=(r-1)*limt+1; 
        for(t=p;t<=you;t++)  if(h[t]+jia[r]>=c)  ans++; 
    } 
    return ans; 
} 
int main() 
{ 
    int i,l,r,w;char s[3]; 
    scanf("%d%d",&n,&q); 
    for(i=1;i<=n;i++)  {scanf("%d",&h[i]);now[i]=h[i];} 
    limt=3000; 
    build();     
    for(i=1;i<=q;i++) 
    { 
        scanf("%s",s); 
        scanf("%d%d%d",&l,&r,&w); 
        if(s[0]=='M')  updata(l,r,w); 
        else   printf("%d\n",solve(l,r,w)); 
    } 
    //system("pause"); 
    return 0; 
