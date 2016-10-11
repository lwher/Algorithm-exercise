#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
using namespace std; 
int m,d; 
int wei=0; 
long long t,dui[200010],p[200010]; 
int main() 
{ 
    int i,j,num,sz=0,K; 
    long long last=0; 
    char ch; 
    scanf("%d%d",&m,&d); 
    for(i=1;i<=m;i++) 
    { 
        scanf("\n%c",&ch); 
        scanf("%d",&num); 
        if(ch=='A') 
        { 
            sz++; 
            K=(num+last)%d; 
            while(wei && dui[wei]<K)  wei--; 
            wei++; 
            dui[wei]=K; 
            p[wei]=sz; 
        } 
        if(ch=='Q') 
        { 
            for(j=1;j<=wei;j++) 
            { 
                if(p[j]>=sz-num+1) 
                { 
                    printf("%d\n",dui[j]); 
                    last=dui[j]; 
                    break; 
                } 
            } 
        } 
    } 
    //system("pause"); 
    return 0; 
}