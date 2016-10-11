#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int n,top,root[1000010],l[1000010],r[1000010];
int cnt[1000010],dis[1000010],ls[1000010],rs[1000010];
long long num[1000010],ans;
void swap(int &a,int &b)
{
     int t=a;a=b;b=t;
}
int merge(int a,int b)
{
    if(!a || !b)  return a+b;
    if(num[a]<num[b])  swap(a,b);
    rs[a]=merge(rs[a],b);
    if(dis[ls[a]]<dis[rs[a]])  swap(ls[a],rs[a]);
    dis[a]=dis[rs[a]]+1;
    cnt[a]=cnt[ls[a]]+cnt[rs[a]]+1;
    return a;  
}
long long abs(long long a,long long b)
{
     if(a<b)  return b-a; return a-b;
}
int main()
{
    int i,t,k;
    scanf("%d",&n);
    dis[0]=-1;
    for(i=1;i<=n;i++)  
    {
        scanf("%lld",&num[i]);
        num[i]-=i;
    }        
    for(i=1;i<=n;i++)
    {
        root[++top]=i;l[top]=r[top]=i;cnt[i]=1;
        while(top>1 && num[root[top]]<=num[root[top-1]])
        {
            t=merge(root[top-1],root[top]);
            r[top-1]=r[top];top--;
            k=r[top]-l[top]+2;
            while(cnt[t]>k/2)  t=merge(ls[t],rs[t]);
            root[top]=t;
        }
    }
    for(k=1;k<=top;k++)
    {
        for(i=l[k];i<=r[k];i++)  ans+=abs(num[i],num[root[k]]);
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}
