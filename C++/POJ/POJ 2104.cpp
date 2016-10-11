#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
struct sth
{
	int sum[100001];
	int num[100001],pm[100001];
	
}p[21];
struct aaa
{
	int sz;
	int yuanpai;
	int paiming;
}paixu[100001];
int n,m,k;
int ans;
inline bool cmp(aaa aa,aaa bb)
{
	return aa.yuanpai<bb.yuanpai;
}
inline bool comp(aaa aa,aaa bb)
{
	return aa.sz<bb.sz;
}
void build(int l,int r,int t)
{
	if(l==r) return;
	int i;
	int le=0,ri=1;
	int mid=(l+r)>>1;
	for(i=l;i<=r;i++)
	{
		if(p[t].pm[i]<=mid)
		{
		   p[t+1].num[l+le]=p[t].num[i];
		   p[t+1].pm[l+le]=p[t].pm[i];
		   p[t].sum[i]=p[t].sum[i-1]+1;
		   le++;
		}
		else
		{
		   p[t+1].num[mid+ri]=p[t].num[i];
		   p[t+1].pm[mid+ri]=p[t].pm[i];
		   p[t].sum[i]=p[t].sum[i-1];
		   ri++;
		}
	}
	build(l,mid,t+1);
	build(mid+1,r,t+1);
}
void find(int l,int r,int t,int zuo,int you)
{
	 if(l==r) 
	 {ans=p[t].num[l];return;}
	 int mid=(zuo+you)>>1;
	 if(p[t].sum[r]-p[t].sum[l-1]>=k)
     {
       find(zuo+p[t].sum[l-1]-p[t].sum[zuo-1],zuo+p[t].sum[r]-p[t].sum[zuo-1]-1,t+1,zuo,mid);
     }
     else
     {
         k=k-(p[t].sum[r]-p[t].sum[l-1]);
         find(mid+1+(l-zuo)-(p[t].sum[l-1]-p[t].sum[zuo-1]),mid+1+(r-zuo+1)-(p[t].sum[r]-p[t].sum[zuo-1])-1,t+1,mid+1,you);
     }
}
int main()
{
	int l,r;
	scanf("%d%d",&n,&m);
	int i,j;
	for(i=1;i<=n;i++)
	{scanf("%d",&p[1].num[i]);
	paixu[i].sz=p[1].num[i];
	paixu[i].yuanpai=i;}
    sort(paixu+1,paixu+1+n,comp);	
    for(i=1;i<=n;i++)
    paixu[i].paiming=i;
    sort(paixu+1,paixu+1+n,cmp);
    for(i=1;i<=n;i++)
    p[1].pm[i]=paixu[i].paiming;
    build(1,n,1);
    for(i=1;i<=m;i++)
    {
		scanf("%d%d%d",&l,&r,&k);
		
		find(l,r,1,1,n);
		printf("%d\n",ans);
	}
    
	system("pause");
	return 0;
}
