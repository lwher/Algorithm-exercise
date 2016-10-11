#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define N 100010
using namespace std;
int sa[2][N],rk[2][N];
int v[N],a[N],n,k,h[N],p,q,ans,height[N];
void init()
{
	int i;
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
	n--;
	for(i=1;i<=n;i++)
	a[i]=a[i+1]-a[i]+100;
}
void Calc_SA(int sa[N],int rk[N],int SA[N],int RK[N])
{
	int i;
	for(i=1;i<=n;i++) v[rk[sa[i]]]=i;
	for(i=n;i>=1;i--) if(sa[i]>k)  SA[v[rk[sa[i]-k]]--]=sa[i]-k;
	for(i=n-k+1;i<=n;i++)   SA[v[rk[i]]--]=i;
	for(i=1;i<=n;i++)RK[SA[i]]=RK[SA[i-1]]+(rk[SA[i]]!=rk[SA[i-1]] || rk[SA[i]+k]!=rk[SA[i-1]+k]);
}
void PXSA()
{
	
	int i;p=0;q=1;a[0]=-1;k=1;
	memset(v,0,sizeof(v));
	for(i=1;i<=n;i++)   v[a[i]]++;
	for(i=1;i<=200;i++)  v[i]+=v[i-1];
	for(i=1;i<=n;i++)   sa[0][v[a[i]]--]=i;
    for(i=1;i<=n;i++)   rk[0][sa[0][i]]=rk[0][sa[0][i-1]]+(a[sa[0][i-1]]!=a[sa[0][i]]);	    
	while(k<n)
    {
		Calc_SA(sa[p],rk[p],sa[q],rk[q]);
		p^=1;q^=1;k=k<<1;
	}
}
void getheight()
{
	memset(h,0,sizeof(h));
	int i,j;
	k=0;
	for(i=1;i<=n;i++)
	{
		if(rk[p][i]==1)  h[i]=0;
		else
		{
			j=sa[p][rk[p][i]-1];
			while(a[i+k]==a[j+k]) k++;
			h[i]=k;   if(k>0)  k--;
		}
	}
	for(i=1;i<=n;i++)  height[rk[p][i]]=h[i];
}
bool check(int mid)
{
	int i;
	int minn=sa[p][1],maxx=sa[p][1];
	for(i=2;i<=n;i++)
	{
		if(height[i]<mid)
		{minn=sa[p][i];maxx=sa[p][i];}
		else
		if(height[i]>=mid)
		{
		    if(sa[p][i]<minn)  minn=sa[p][i];
			if(sa[p][i]>maxx)  maxx=sa[p][i];
		    if(maxx-minn>=mid)  return 1;
		}
	}
	return 0;
}
void solve()
{
	int i;
	init();
	PXSA();
	getheight();
	int l=0,r=n/2,mid;
	while(l<r)
	{
		if(l+1==r)  break;
		mid=(l+r)>>1;
		if(check(mid))  l=mid;
		else  r=mid;
	}
	if(check(r))  ans=r;
	else ans=l;
	if(ans<4) printf("0\n");
	else   printf("%d\n",ans+1);
}
int main()
{
	while(scanf("%d",&n) && n)
	solve();
	//system("pause");
	return 0;
}

