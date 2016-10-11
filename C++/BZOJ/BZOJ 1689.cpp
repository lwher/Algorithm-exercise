#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
using namespace std; 
int a[10032][2], N, L, sum; 
int cmp(const void *a, const void *b) 
{ 
    return *(int*)a - *(int*)b; 
} 
int max(int a,int b) 
{ 
    return a>b? a:b; 
} 
int main() 
{ 
    int i, p, c; 
    cin>>N>>L; 
    for (i = 0; i < N; i++) 
    cin>>a[i][0]>>a[i][1];      
    qsort(a,N,sizeof(a[0]), cmp); 
    for (i=p= 0; p<N; p++) 
    { 
        i = max(i, a[p][0]);  
        c = (a[p][1]-i+L-1) / L;        
        sum += c;   
        i+= c*L; 
        if(p>N||i<a[p][1])   break;  
    }      
    cout<<sum<<endl; 
    //system("pause"); 
    return 0; 
}