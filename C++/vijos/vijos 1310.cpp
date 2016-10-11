#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int prime[13]={0,2,3,5,7,11,13,17,19,23,29,31,37};  // tot=12
double ln[13],nans;
int ans[13],n,now[13];
void dfs(int top,int last,double num,int ys)
{
     int i;
     if(num>nans)   return;
     if(top>12 || ys>=n) 
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
    int T,i;
    for(i=1;i<=12;i++)   ln[i]=log(prime[i]*1.00)/log(exp(1));
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        if(n==1)  printf("1\n");
        else
        {            
            nans=1e20;dfs(1,n+1,0,1);
            bool o=0;
            for(i=1;i<=12;i++)
            {
                if(ans[i]==1)  
                {
                   if(!o) {o=1;printf("%d",prime[i]);}
                   else  printf("*%d",prime[i]);
                }
                if(ans[i]>1)
                {
                   if(!o) {o=1;printf("%d^%d",prime[i],ans[i]);}
                   else  printf("*%d^%d",prime[i],ans[i]);
                }
            }
            printf("\n");
        }
    }
    system("pause");
    return 0;
}
