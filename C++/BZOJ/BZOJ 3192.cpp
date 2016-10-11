#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
struct sth
{
       int p,w;
}wp[100010];
int t[300025];
int n1,n2,mid,n;
long long tot;
int lowbit(int x)
{
    return (x & (-x));
}
void updata(int x,int k)
{
     while(x<=n)
     {
           t[x]+=k;
           x+=lowbit(x);
     }
}
int ask(int x)
{
     int sum=0;
     while(x>0)
     {
         sum+=t[x];
         x-=lowbit(x);
     }  
     return sum;
}
inline bool comp(sth a,sth b)
{
       return a.p>b.p;
}
int main()
{
    cin>>n1>>n2;
    int i,j;
    n=n1+n2+1;
    mid=n1+1;
    for(i=n1;i>=1;i--)
    {
       scanf("%d",&wp[i].p);
       wp[i].w=i;
       updata(i,1);
    }
    for(j=1;j<=n2;j++)
    {
       scanf("%d",&wp[n1+j].p);
       wp[n1+j].w=n1+j+1;
       updata(n1+j+1,1);
    } 
    sort(wp+1,wp+n,comp);
    for(i=1;i<=n-1;i++)
    {
        if(wp[i].w>mid)
        {tot+=ask(wp[i].w-1)-ask(mid);}
        else
        {tot-=ask(wp[i].w)-ask(mid);}
        updata(wp[i].w,-1);
        mid=wp[i].w;
    }
    cout << tot << endl;
    system("pause");
    return 0;
}
