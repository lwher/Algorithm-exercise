#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
struct sth
{
    int l,r;
}p[151];
int n,ans;
inline bool comp(sth a,sth b)
{
    return a.l<b.l;
}
void swap(int &a,int &b)
{
    int t=a;a=b;b=t;
}
int main()
{
    int i,r0=0,r1=0,tmp;
    scanf("%d",&n);
    for(i=1;i<=n;i++)   scanf("%d%d",&p[i].l,&p[i].r);
    sort(p+1,p+1+n,comp);
    for(i=1;i<=n;i++)
    {
        if(p[i].l>=r1)  {ans++;r1=p[i].r;}
        else
        if(p[i].l>=r0)  
        {
            ans++;r0=p[i].r;
            if(r0>r1)  swap(r0,r1);
        }
        else
        {
            if(p[i].r<r0)  {r1=r0;r0=p[i].r;}
            else if(p[i].r<r1) r1=p[i].r;
        }
    }
    cout<<ans<<endl;
    //system("pause");
    return 0;
}