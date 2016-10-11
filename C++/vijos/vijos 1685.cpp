#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int prime[32],tot;
double ln[32],nans;
int ans[32],now[32];long long n;
bool check(int x)
{
     int i,limt=sqrt(x);
     for(i=2;i<=limt;i++)  if(x%i==0)  return 0;
     return 1;
}
void dfs(int top,int last,double num,long long ys)
{
     int i;
     if(num>nans)   return;
     if(top>tot || ys>=n) 
     {
        if(ys==n && num<nans)  
        {
            memset(ans,0,sizeof(ans));
            for(i=1;i<=top-1;i++)  ans[i]=now[i];
            nans=num;         
        }
        return;
     }
     for(i=1;i<=last;i++)
     {
         if(n%(ys*(i+1))==0)
         {now[top]=i;dfs(top+1,i,num+i*ln[top],ys*(i+1));}
     }
}
int main()
{
    int i;
    for(i=2;i<=130;i++)  if(check(i))  prime[++tot]=i;
    for(i=1;i<=tot;i++)   ln[i]=log(prime[i]*1.00)/log(exp(1));
    cin>>n;      
    nans=1e20;dfs(1,10000,0,1);
    bool o=0;
    for(i=1;i<=31;i++)
    {
            if(ans[i]>0)
            {
                   if(!o) {o=1;printf("%d^%d",prime[i],ans[i]);}
                   else  printf("*%d^%d",prime[i],ans[i]);
            }
    }
    system("pause");
    return 0;
}
