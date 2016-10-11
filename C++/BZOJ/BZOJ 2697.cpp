#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,k;
int c[310];
inline bool comp(int a,int b)  {return a>b;}
int main()
{
    int i;
    scanf("%d%d",&n,&k);
    for(i=1;i<=k;i++)  scanf("%d",&c[i]);
    sort(c+1,c+1+k,comp);
    long long ans=0;
    for(i=1;i<=k;i++)
    {
       ans+=c[i]*(n-1);
       n-=2;
       if(n<2)  break;
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}
