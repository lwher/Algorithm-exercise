#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int t,ans,lcm=23*28*33;
int p,e,r,d;
int main()
{
    while(scanf("%d%d%d%d",&p,&e,&r,&d)!=EOF)
    {
         if(p==-1 && e==-1 && r==-1 && d==-1)  break;
         t++;
         p%=23;e%=28;r%=33;
         ans=((p*5544)%lcm+(e*14421)%lcm+(r*1288)%lcm)%lcm;
         ans-=d;
         while(ans<=0)  ans+=lcm;
         printf("Case %d: the next triple peak occurs in %d days.\n",t,ans);
    }
    system("pause");
    return 0;
}
