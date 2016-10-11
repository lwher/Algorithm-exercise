#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,prime[100010],tot,gs[100010];
long long ans;
bool mark[100010],two;
void getgs()
{
     int i,j;
     gs[1]=1;
     for(i=2;i<=100000;i++) 
     {
         if(!mark[i]) {prime[++tot]=i;gs[i]=gs[i-1];}
         for(j=1;j<=tot;j++)
         {
             if(i*prime[j]>100000) break;
             mark[i*prime[j]]=1;
             gs[i*prime[j]]=gs[i]+gs[prime[j]];
             if(i%prime[j]==0) break;
         }
     }
}
int main()
{
    int i,T,p,q;
    getgs();    
    scanf("%d",&T);
    while(T--)
    {
        ans=0;two=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&p,&q);
            if(p==2) two=1;
            ans+=(long long)(gs[p])*q;
        }
        if(!two) ans++;
        printf("%lld\n",ans);
    }
    system("pause");
    return 0;
}
