#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int n,sum,d[160];
int prime[160],tot,gs[160];
bool check(int x)
{
     int i,limt=sqrt(x);
     for(i=2;i<=limt;i++) if(x%i==0) return 0;
     return 1;
}
void getprime()
{
     for(int i=2;i<=150;i++) if(check(i)) prime[++tot]=i;
}
void fenjie(int x,int d)
{
     for(int i=1;i<=tot;i++)
     while(x%prime[i]==0)
     {
         gs[i]+=d;
         x/=prime[i];
     }
}
void solve()
{
     int i,j;long long ans=1;
     scanf("%d",&n);
     if(n==1)
     {
         scanf("%d",&d[1]);
         if(!d[1]) printf("1\n");
         else  printf("0\n");
         return;
     }
     for(i=1;i<=n;i++)
     {
         scanf("%d",&d[i]);
         if(!d[i]) {printf("0\n");return;}
         d[i]--;
         sum+=d[i];
     }
     if(sum!=n-2) {printf("0\n");return;}
     
     getprime();
     for(i=2;i<=sum;i++) fenjie(i,1);
     for(i=1;i<=n;i++) for(j=2;j<=d[i];j++) fenjie(j,-1);
     for(i=1;i<=tot;i++) while(gs[i]--) ans*=prime[i];
     cout<<ans<<endl;
} 
int main()
{
    solve();
    system("pause");
    return 0;
}
