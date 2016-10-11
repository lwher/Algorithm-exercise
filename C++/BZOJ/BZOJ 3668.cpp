#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,num[100010],ans;
char op[100010][5];
void init()
{
     scanf("%d%d",&n,&m);
     for(int i=1;i<=n;i++) scanf("%s%d",op[i]+1,&num[i]);
}
void work()
{
     int i,k,x0,x1,x,p;
     bool ok=0;
     for(k=30;k>=0;k--)
     {
         x0=0;x1=1;
         for(i=1;i<=n;i++)  
         {
             x=(num[i]>>k)&1;
             if(op[i][1]=='O') x0|=x,x1|=x; else
             if(op[i][1]=='A') x0&=x,x1&=x; else
             x0^=x,x1^=x;
         }
         p=(m>>k)&1;
         if(ok) 
         {
            if(x0 || x1) ans+=1<<k;
         } 
         else
         {
            if(x0)  
            {
               ans+=1<<k;
               if(p) ok=1; 
            }
            else if(p && x1) ans+=1<<k;
            else if(p) ok=1;
         }   
     }
     printf("%d\n",ans);
}
int main()
{
     init();
     work();
     system("pause");
     return 0;
}
