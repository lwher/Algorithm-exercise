#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct sth
{
	int num,id;
}shu[20010];
int a[20010],n,t,k,p,q;
int sa[2][40010],v[40010],rk[2][40010];
int h[20010],height[20010];
inline bool comp(sth a,sth b)
{
	return a.num<b.num;
}
void init()
{
	int i;
	scanf("%d%d",&n,&t);
	for(i=1;i<=n;i++)  {scanf("%d",&shu[i].num);shu[i].id=i;}
	sort(shu+1,shu+1+n,comp);
	shu[0].num=-1;
	for(i=1;i<=n;i++)
	{
		if(shu[i].num==shu[i-1].num)  a[shu[i].id]=a[shu[i-1].id];
		else a[shu[i].id]=a[shu[i-1].id]+1;
	}
}
void calc_sa(int sa[40010],int rk[40010],int SA[40010],int RK[40010])
{
	int i;
	for(i=1;i<=n;i++)   v[rk[sa[i]]]=i;
	for(i=n;i>=1;i--)   if(sa[i]>k)  SA[v[rk[sa[i]-k]]--]=sa[i]-k;
	for(i=n-k+1;i<=n;i++)   SA[v[rk[i]]--]=i;
	for(i=1;i<=n;i++)  RK[SA[i]]=RK[SA[i-1]]+(rk[SA[i]]!=rk[SA[i-1]] || rk[SA[i]+k]!=rk[SA[i-1]+k]);
}
void SA()
{
	int i;p=0;q=1;a[0]=-1;
	for(i=1;i<=n;i++)  v[a[i]]++;
	for(i=1;i<=20000;i++)  v[i]+=v[i-1];
	for(i=1;i<=n;i++)  sa[p][v[a[i]]--]=i;
	for(i=1;i<=n;i++)  rk[p][sa[p][i]]=rk[p][sa[p][i-1]]+(a[sa[p][i]]!=a[sa[p][i-1]]);
	k=1;
	while(k<n)
	{
		calc_sa(sa[p],rk[p],sa[q],rk[q]);
		p^=1;q^=1;k*=2;
	}  
}
void geth()
{
	int i,j=0,l;
	for(i=1;i<=n;i++)
	{
		if(rk[p][i]==1)  h[i]=0;
		else
		{
			l=sa[p][rk[p][i]-1];
			while(a[i+j]==a[l+j])  j++;
			h[i]=j;if(j) j--;
		}
	}
	for(i=1;i<=n;i++)   height[rk[p][i]]=h[i];
}
bool check(int x)
{
	int i,tt=0;
	for(i=1;i<=n;i++)
	{
		if(height[i]<x)  tt=0;
		else
		{
			tt++;
			if(tt>=t-1)  return 1;
		}
	}
	return 0;
}
void solve()
{
	int i;
	init();
	SA();
	geth();
	int l=0,r=n,mid;
	while(l<r)
	{
		if(l+1==r)  break;
		mid=(l+r)>>1;
		if(check(mid))  l=mid;
		else r=mid;
	}
	if(check(r))  cout<<r<<endl;
	else cout<<l<<endl;	
}
int main()
{
	solve();
	system("pause");
	return 0;
}

