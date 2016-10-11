#include<iostream>
#include<cstdio>
#include<cstdlib>
#define N 400010
using namespace std;
int sa[2][N],rk[2][N];
int v[N],a[N],len,n,k,h[N],p,q,ans;
void init()
{
	int i;
	char s[N],s2[N];
	scanf("%s",s+1);
	len=strlen(s+1);n=len;	
	for(i=1;i<=n;i++)
	a[i]=int(s[i])-96;
	scanf("%s",s2+1);
	n=strlen(s2+1);
	for(i=1;i<=n;i++)
	a[i+len+1]=int(s2[i])-96;
	a[len+1]=30;n+=len+1;
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
	for(i=1;i<=n;i++)   v[a[i]]++;
	for(i=1;i<=31;i++)  v[i]+=v[i-1];
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
	int i,j;
	k=0;
	for(i=1;i<=n;i++)
	{
		if(rk[p][i]==1)  h[i]=0;
		else
		{
			j=sa[p][rk[p][i]-1];
			while(a[i+k]==a[j+k]) k++;
			h[i]=k;   if(k>0)	k--;
		}
	}
	//for(i=1;i<=n;i++)  height[rk[p][i]]=h[i];
}
void solve()
{
	int i;
	init();
	PXSA();
	getheight();
	ans=0;
	for(i=1;i<=len;i++)
	if(sa[p][rk[p][i]-1]>len+1 && h[i]>ans)  
	ans=h[i];
	for(i=len+2;i<=n;i++)
	if(sa[p][rk[p][i]-1]<=len && h[i]>ans)   
	ans=h[i];
	cout<<ans<<endl;
}
int main()
{
	solve();
	//system("pause");
	return 0;
}

