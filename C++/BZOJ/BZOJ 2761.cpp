#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
struct node
{
       int x,id;
}a[555556];
bool cmp1(node a1, node a2)
{
     if(a1.x == a2.x) return a1.id < a2.id; 
     else return a1.x < a2.x;
}
bool cmp2(node a1, node a2)
{
     return a1.id < a2.id;
}
int n;
int main()
{    
     int T;    
     scanf("%d", &T);    
     while(T--)    
     {          
        int i,n,t;                  
        scanf("%d", &n);          
        for(i=1;i<=n;i++) {scanf("%d", &a[i].x);a[i].id=i;}          
        sort(a+1,a+1+n,cmp1);          
        int k=n;
        for(i=1;i<=n;i++)          
        {                
             while(a[i+1].x==a[i].x) a[++i].id=9999999,k--;          
        }          
        sort(a+1,a+1+n,cmp2);          
        for(i=1;i<=n;i++)   if(a[i].id<999999) 
        {
            if(k==1)  printf("%d\n",a[i].x);
            else printf("%d ",a[i].x),k--;
        }           
        }    
        system("pause");
        return 0;   
}
