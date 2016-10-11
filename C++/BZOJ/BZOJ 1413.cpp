#include<iostream> 
#include<stdio.h> 
#include<cmath> 
#include<cstdlib> 
using namespace std; 
int num[1010]; 
int main() 
{ 
    int i,n; 
    int t; 
    cin>>t; 
    while(t--) 
    { 
        scanf("%d",&n); 
        for(i=1;i<=n;i++) 
        scanf("%d",&num[i]); 
        if(abs(num[1]-num[n])<=1)  
        printf("0\n"); 
        else
        printf("1\n");   
    } 
    //system("pause"); 
    return 0; 
}