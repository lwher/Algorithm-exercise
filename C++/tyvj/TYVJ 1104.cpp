#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;
struct sth
{
       int hao,fen;
}a[10000];
int n,m;
inline bool comp(sth aa,sth bb)
{
   if(aa.fen==bb.fen)   return aa.hao<bb.hao;
   else return aa.fen>bb.fen;
}
int main()
{
    cin>>n>>m;
    int i;
    for(i=1;i<=n;i++)
    {scanf("%d%d",&a[i].hao,&a[i].fen);}
    sort(a+1,a+n+1,comp);
    int k;
    k=int(double(m)*1.5);
    while(a[k].fen==a[k+1].fen && k<n)
    {k++;}
    cout<<a[k].fen<<" "<<k<<endl;
    for(i=1;i<=k;i++)
    {printf("%d %d\n",a[i].hao,a[i].fen);}
    
    system("pause");
    return 0;
}
