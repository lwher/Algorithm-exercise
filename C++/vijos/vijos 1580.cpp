#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int zhan[100010],top,len[100010],n,h[100010];
int ans;
void solve()
{
     memset(len,0,sizeof(len));
     memset(zhan,0,sizeof(zhan));
     top=0;ans=0;
     int nlen,i;     
     for(i=1;i<=n;i++)
     {
         nlen=0;
         while(top>0 && zhan[top]>=h[i])
         {
             nlen+=len[top];
             if(zhan[top]*nlen>ans)  ans=zhan[top]*nlen;
             top--;
         }
         nlen++;
         top++;zhan[top]=h[i];len[top]=nlen;
     }
     nlen=0;
     for(i=top;i>=1;i--)
     {
        nlen+=len[i];
        if(ans<zhan[i]*nlen)  ans=zhan[i]*nlen;
     }
}
int main()
{
    int i;
    while(cin>>n)
    {
         for(i=1;i<=n;i++) scanf("%d",&h[i]);
         
         solve();
         printf("%d\n",ans);
    }
    printf("0\n");
    system("pause");
    return 0;
}
