#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
using namespace std; 
int n,m; 
int h[2010][2010],l[2010][2010],r[2010][2010]; 
int map[2010][2010]; 
int ans1,ans2; 
int main() 
{ 
    int i,j,k; 
    scanf("%d%d",&n,&m); 
    for(i=1;i<=n;i++) 
    for(j=1;j<=m;j++) 
    { 
        scanf("%d",&map[i][j]); 
        if(i==1)  h[i][j]=1; 
        else
        if(map[i][j]!=map[i-1][j]) 
        h[i][j]=h[i-1][j]+1; 
        else
        h[i][j]=1; 
    } 
      
    for(i=1;i<=n;i++) 
    { 
       for(j=1;j<=m;j++) 
       { 
            l[i][j]=j; 
            while(l[i][j]>1 && h[i][l[i][j]-1]>=h[i][j] && map[i][l[i][j]]!=map[i][l[i][j]-1]) 
            l[i][j]=l[i][l[i][j]-1]; 
       } 
       for(j=m;j>=1;j--) 
       { 
            r[i][j]=j; 
            while(r[i][j]<m && h[i][r[i][j]+1]>=h[i][j] && map[i][r[i][j]]!=map[i][r[i][j]+1]) 
            r[i][j]=r[i][r[i][j]+1]; 
  
            k=r[i][j]-l[i][j]+1; 
            if(k*h[i][j]>ans2)  ans2=k*h[i][j]; 
            k=min(k,h[i][j]); 
            if(ans1<k*k)  ans1=k*k; 
        } 
          
    } 
  
    cout<<ans1<<endl<<ans2<<endl; 
  
    //system("pause"); 
    return 0; 
} 

