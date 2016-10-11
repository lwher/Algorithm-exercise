#include<iostream> 
#include<cstdio> 
#include<cstring> 
#include<cstdlib> 
#define N 200010 
using namespace std; 
char ch[N<<1]; 
int a[N<<1],n,k; 
int v[N<<1],sa[2][N<<1],rank[2][N<<1]; 
void init() 
{ 
    int i; 
    scanf("%s",ch+1); 
    n=strlen(ch+1); 
    for(i=1;i<=n;i++) 
    { 
        a[i]=int(ch[i]); 
        a[i+n]=a[i]; 
        ch[i+n]=ch[i]; 
    } 
    n*=2; 
} 
void Calc_SA(int sa[N<<1],int rank[N<<1],int SA[N<<1],int Rank[N<<1]) 
{ 
    int i; 
    for(i=1;i<=n;i++)   v[rank[sa[i]]]=i; 
    for(i=n;i>=1;i--) 
    if(sa[i]>k) 
    {SA[v[rank[sa[i]-k]]]=sa[i]-k;v[rank[sa[i]-k]]--;} 
    for(i=n-k+1;i<=n;i++) 
    {SA[v[rank[i]]]=i;v[rank[i]]--;} 
    for(i=1;i<=n;i++) 
    Rank[SA[i]]=Rank[SA[i-1]]+(rank[SA[i-1]]!=rank[SA[i]] || rank[SA[i-1]+k]!=rank[SA[i]+k]); 
} 
void PXSA() 
{ 
    int p=0,q=1,i;a[0]=-1; 
    for(i=1;i<=n;i++)  v[a[i]]++; 
    for(i=1;i<=256;i++)  v[i]+=v[i-1]; 
    for(i=1;i<=n;i++) 
    { 
        k=v[a[i]];sa[p][k]=i;v[a[i]]--; 
    } 
    for(i=1;i<=n;i++)   
    { 
    if(a[sa[p][i]]==a[sa[p][i-1]])  rank[p][sa[p][i]]=rank[p][sa[p][i-1]];  
    else  rank[p][sa[p][i]]=rank[p][sa[p][i-1]]+1;  
    }     
    k=1; 
    while(k<n) 
    { 
        Calc_SA(sa[p],rank[p],sa[q],rank[q]); 
        p^=1;q^=1;k=k<<1; 
    } 
      
    for(i=1;i<=n;i++) 
    { 
        if(sa[p][i]<=n/2) 
        printf("%c",ch[sa[p][i]+n/2-1]); 
    } 
    printf("\n"); 
} 
int main() 
{ 
    init(); 
    PXSA(); 
    //system("pause"); 
    return 0; 
}