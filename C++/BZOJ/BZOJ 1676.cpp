#include<cstdlib> 
#include<cstdio> 
#include<cstring> 
#include<iostream> 
using namespace std; 
struct node 
{ 
    int l,r; 
}; 
int s[2010]; 
int n,m,st,ed,ans,last_day; 
node a[110]; 
void Init() 
{ 
    scanf("%d%d%d%d",&n,&st,&ed,&last_day); 
    memset(s,0,sizeof(s)); 
    for (int i=1;i<=n;i++)  
    { 
        scanf("%d%d",&a[i].l,&a[i].r);  
        for (int j=a[i].l;j<=a[i].r;j++) s[j]++; 
    } 
} 
void Main() 
{ 
    int now=st-ed; 
    int i; 
    for (i=last_day;i>=1  &&  now>0;i--) now-=s[i]; 
    printf("%d\n",i+1); 
} 
int main() 
{ 
    Init(); 
    Main(); 
  //  system("pause"); 
    return 0; 
}