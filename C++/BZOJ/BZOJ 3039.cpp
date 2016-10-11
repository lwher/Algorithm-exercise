#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cmath> 
using namespace std; 
int n,m; 
bool map[1010][1010]; 
int high[1010][1010]; 
int gao[1010],kuang[1010]; 
int top; 
int nk; 
int ans; 
int main() 
{ 
    cin>>n>>m; 
    int i,j; 
    char ch; 
    for(i=1;i<=n;i++)  
    for(j=1;j<=m;j++)   
    { 
        cin>>ch; 
        if(ch=='F') 
        map[i][j]=1; 
    } 
    for(j=1;j<=m;j++) 
    for(i=1;i<=n;i++) 
    if(map[i][j]) high[i][j]=high[i-1][j]+1; 
      
    for(i=1;i<=n;i++) 
    { 
        for(j=1;j<=m;j++) 
        { 
            if(high[i][j]==0) 
            { 
                while(top>1) 
               { 
                kuang[top-1]+=kuang[top]; 
                top--; 
                if(kuang[top]*gao[top]>ans)  
                ans=kuang[top]*gao[top]; 
                } 
                top=0; 
                continue; 
            } 
            nk=1; 
            while(top>0 && gao[top]>high[i][j]) 
            { 
            nk+=kuang[top]; 
            top--; 
            if(gao[top]*(nk+kuang[top]-1)>ans) 
            ans=gao[top]*(nk+kuang[top]-1); 
            } 
              
            top++; 
            kuang[top]=nk;gao[top]=high[i][j]; 
              
            if(top>1 && (kuang[top-1]+kuang[top])*gao[top-1]>ans) 
            ans=(kuang[top-1]+kuang[top])*gao[top-1]; 
              
            if(kuang[top]*gao[top]>ans) 
            ans=kuang[top]*gao[top]; 
        } 
        while(top>1) 
        { 
            kuang[top-1]+=kuang[top]; 
            top--; 
            if(kuang[top]*gao[top]>ans)  
            ans=kuang[top]*gao[top]; 
        } 
        top=0; 
    } 
    cout<< ans*3 <<endl; 
  
    //system("pause"); 
    return 0; 
}