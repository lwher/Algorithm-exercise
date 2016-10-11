#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cstring> 
#include<cmath> 
using namespace std; 
int n,num[35010]; 
int sz,to[35010],pre[35010],last[35010]; 
int f[35010],best[35010]; 
long long g[35010],sum1[35010],sum2[35010]; 
void Ins(int a,int b) 
{ 
     sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz; 
} 
int find(int l,int r,int p) 
{ 
    while(l<r) 
    { 
        int mid=(l+r)>>1; 
        if(best[mid]<=p)  l=mid+1; 
        else r=mid; 
    } 
    return l; 
} 
void work() 
{ 
     int i,j,k,top=0; 
     num[++n]=1<<30; 
     best[++top]=num[1];f[1]=1; 
     for(i=2;i<=n;i++)   
     { 
         int id=find(1,top+1,num[i]); 
         best[id]=num[i];top=max(top,id); 
         f[i]=id; 
     } 
     printf("%d\n",n-f[n]); 
     for(i=n;i>=0;i--) 
     { 
        g[i]=1LL<<50; 
        Ins(f[i],i); 
     } 
     g[0]=0;num[0]=-num[n]; 
     for(i=1;i<=n;i++) 
     { 
        j=last[f[i]-1]; 
        while(j>0) 
        { 
            int p=to[j]; 
            if(p>i)  break; 
            if(num[p]>num[i])  {j=pre[j];continue;} 
            for(k=p;k<=i;k++) 
            { 
               sum1[k]=abs(num[p]-num[k]); 
               sum2[k]=abs(num[i]-num[k]); 
            } 
            for(k=p+1;k<=i;k++)  sum1[k]+=sum1[k-1],sum2[k]+=sum2[k-1]; 
            for(k=p;k<i;k++) g[i]=min(g[i],g[p]+sum1[k]-sum1[p]+sum2[i]-sum2[k]); 
            j=pre[j]; 
        } 
     } 
     cout<<g[n]<<endl; 
} 
int main() 
{ 
    int i; 
    scanf("%d",&n); 
    for(i=1;i<=n;i++)  {scanf("%d",&num[i]);num[i]-=i;} 
    work(); 
  //  system("pause"); 
    return 0; 
}