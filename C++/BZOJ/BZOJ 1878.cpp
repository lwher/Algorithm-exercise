#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
struct sth
{
    int l,r,id;
}q[200010];
int n,m,pre[50010],last[1000010];
int t[50010],ans[200010];
inline bool comp(sth a,sth b)
{
    return a.r<b.r;
}
void updata(int x,int k)
{
     for(int i=x;i<=n;i+=(i & (-i))) t[i]+=k;
}
int ask(int x)
{
    int sum=0;
    for(int i=x;i>0;i-=(i & (-i)))  sum+=t[i];
    return sum;
}
int main()
{
    int i,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&k);
        pre[i]=last[k];last[k]=i;
    } 
    scanf("%d",&m);
    for(i=1;i<=m;i++)  scanf("%d%d",&q[i].l,&q[i].r),q[i].id=i;
    sort(q+1,q+1+m,comp);
    int now=0;
    for(i=1;i<=m;i++)
    {
        while(now<q[i].r)
        {
            now++;
            updata(pre[now]+1,1);
            updata(now+1,-1);
        }
        ans[q[i].id]=ask(q[i].l);
    }
    for(i=1;i<=m;i++)  printf("%d\n",ans[i]);
    system("pause");
    return 0;
}
