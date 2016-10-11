#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cstring> 
#include<cmath> 
using namespace std; 
struct sth 
{ 
    int l,r,v; 
}dui[50010]; 
long long f[50010]; 
long long c[50010],L,sum[50010]; 
int n; 
long long calc(int x,int y) 
{ 
    return f[y]+(x-y+sum[x]-sum[y]-1-L)*(x-y+sum[x]-sum[y]-1-L); 
} 
int main() 
{ 
    int i,tou=1,wei=1,ll,rr,mid; 
    scanf("%d%lld",&n,&L); 
    for(i=1;i<=n;i++)  {scanf("%lld",&c[i]);sum[i]=sum[i-1]+c[i];} 
    f[0]=0; 
    dui[1].l=1;dui[1].r=n;dui[1].v=0; 
    for(i=1;i<=n;i++) 
    { 
        f[i]=calc(i,dui[tou].v); 
        dui[tou].l++; 
        if(dui[tou].l>dui[tou].r)  tou++; 
        while(tou<=wei && calc(dui[wei].l,dui[wei].v)>calc(dui[wei].l,i))  wei--; 
        if(tou>wei)  {wei++;dui[wei].l=i+1;dui[wei].r=n;dui[wei].v=i;continue;} 
        ll=dui[wei].l;rr=dui[wei].r+1; 
        while(ll+1<rr) 
        { 
            mid=(ll+rr)>>1; 
            if(calc(mid,i)<calc(mid,dui[wei].v))  rr=mid;   
            else ll=mid; 
        } 
        if(rr==n+1)  continue; 
        dui[wei].r=ll; 
        dui[++wei].l=rr;dui[wei].r=n;dui[wei].v=i; 
    } 
    printf("%lld\n",f[n]); 
    //system("pause"); 
    return 0; 
} 

