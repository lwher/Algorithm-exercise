#include<iostream> 
#include<stdio.h> 
#include<cstring> 
using namespace std; 
int sg[1010]; 
int s[20],n,m,sz[20],k; 
bool mark[1010]; 
int maxx; 
int main() 
{ 
    int i,j; 
    while(scanf("%d",&n)!=EOF) 
    { 
    for(i=1;i<=n;i++) 
    { 
    scanf("%d",&sz[i]); 
    if(sz[i]>maxx)maxx=sz[i]; 
    } 
    scanf("%d",&m); 
    for(i=1;i<=m;i++) 
    scanf("%d",&s[i]); 
      
    sg[0]=0; 
    for(i=1;i<=maxx;i++) 
    { 
     memset(mark,0,sizeof(mark)); 
     for(j=1;j<=m;j++) 
    { 
      if(i-s[j]>=0) 
      mark[sg[i-s[j]]]=1; 
    } 
    j=0; 
    while(mark[j]) 
    j++; 
    sg[i]=j; 
    } 
      
      
    int ans=0; 
    for(i=1;i<=n;i++) 
    ans=(ans^sg[sz[i]]); 
    int now=0; 
    if(ans==0) 
    printf("NO\n"); 
    else
    {        
        bool o=0; 
        printf("YES\n"); 
        for(i=1;i<=n;i++) 
        { 
        now=ans; 
          
        now=(now ^ sg[sz[i]]); 
          
        for(j=1;j<=m;j++) 
        if(sz[i]>=s[j] && sg[sz[i]-s[j]]==now) 
        {cout<<i<<" "<<s[j]<<endl;o=1;break;} 
          
        if(o)break; 
        } 
    } 
    } 
    //system("pause"); 
    return 0; 
}