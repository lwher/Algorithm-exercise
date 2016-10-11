#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int ZJ[100010],FJ[100010];
int n,ans;
inline bool comp(int a,int b)
{
       return a>b;
}
int main()
{
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)  scanf("%d",&ZJ[i]);
    for(i=1;i<=n;i++)  scanf("%d",&FJ[i]);
    sort(ZJ+1,ZJ+1+n,comp);sort(FJ+1,FJ+1+n,comp);
    int ZL=1,FL=1,ZR=n,FR=n;    
    while(ZL<=ZR)
    {
         while(ZJ[ZL]>FJ[FL] && ZL<=ZR)  {ans+=2;ZL++;FL++;}
         while(ZJ[ZR]>FJ[FR] && ZL<=ZR)  {ans+=2;ZR--;FR--;}
         if(ZL<=ZR)  
         {
             if(ZJ[ZR]==FJ[FL]) ans++;
             ZR--;FL++;
         }
    }
    cout<<ans<<" ";
    ZL=1;FL=1;ZR=n;FR=n; ans=0;
    while(ZL<=ZR)
    {
         while(ZJ[ZL]<FJ[FL] && ZL<=ZR)  {ZL++;FL++;}
         while(ZJ[ZR]<FJ[FR] && ZL<=ZR)  {ZR--;FR--;}
         if(ZL<=ZR)  
         {
             if(ZJ[ZL]>FJ[FR]) ans+=2;  else   
             if(ZJ[ZL]==FJ[FR]) ans++;
             ZL++;FR--;
         }
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}
