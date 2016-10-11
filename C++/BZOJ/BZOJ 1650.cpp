#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int n,d[50010],L,m,f1[50010],f0[50010];
const int INF=1000010;
bool ok(int mid)
{
     int p=-1,i,k;
     memset(f0,0,sizeof(f0));memset(f1,0,sizeof(f1));
     for(i=1;i<=n;i++)
     {
        while(d[p+1]+mid<=d[i])  p++;
        if(p<0)  k=INF;  else k=min(f0[p],f1[p]);
        f1[i]=k+i-p-1;  f0[i]=min(f1[i-1],f0[i-1])+1;
     }
     if(f1[n]<=m)  return 1;    return 0;
}
int main()
{
    int i,l,r,mid;
    scanf("%d%d%d",&L,&n,&m);
    for(i=1;i<=n;i++)   scanf("%d",&d[i]);
    sort(d+1,d+1+n);
    d[n+1]=L;n++;l=0;r=L;
    while(l<r)
    {
        if(l+1==r)  break;
        mid = (l+r)>>1;
        if(ok(mid))  l=mid;  else r=mid;
    }
    if(ok(r))  cout<<r<<endl;  else cout<<l<<endl;
    system("pause");
    return 0;
}
