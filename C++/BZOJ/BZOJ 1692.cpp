#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int p,q,n,tot,k,a[100010],sa[2][200010],rk[2][200010],v[200010];
void init()
{
	int i;char ch;
	scanf("%d",&n);
	for(i=1;i<=n;i++)  
	{
		ch=getchar();
		while(!(ch>='A' && ch<='Z'))  ch=getchar();
		a[++tot]=(ch-'A')+1;
	}
	a[++tot]=0;
	for(i=n;i>=1;i--)  a[++tot]=a[i];
}
void Calc_SA(int sa[200010],int rk[200010],int SA[200010],int RK[200010])
{
	int i;
	for(i=1;i<=tot;i++)  v[rk[sa[i]]]=i;
	for(i=tot;i>=1;i--)  if(sa[i]>k)  SA[v[rk[sa[i]-k]]--]=sa[i]-k;	
	for(i=tot-k+1;i<=tot;i++)  SA[v[rk[i]--]]=i;
	for(i=1;i<=tot;i++)  RK[SA[i]]=RK[SA[i-1]]+(rk[SA[i]]!=rk[SA[i-1]] || rk[SA[i]+k]!=rk[SA[i-1]+k]);
}
void PX_SA()
{
	int i;p=0;q=1;k=1;a[0]=-1;
	for(i=1;i<=tot;i++)  v[a[i]]++;
	for(i=1;i<=35;i++)  v[i]+=v[i-1];
	for(i=1;i<=tot;i++)  sa[p][v[a[i]]--]=i;
	for(i=1;i<=tot;i++)  rk[p][sa[p][i]]=rk[p][sa[p][i-1]]+(a[sa[p][i]]!=a[sa[p][i-1]]);
	while(k<tot)
	{
		Calc_SA(sa[p],rk[p],sa[q],rk[q]);
		p^=1;q^=1;k=k<<1;
	}
}
int main()
{
	init();
	PX_SA();
	int l=1,r=n+2,now=0;
	while(l+r-3<2*n)
	{
		if(rk[p][l]<rk[p][r])  putchar((a[l++]-1)+'A');
		else putchar((a[r++]-1)+'A');
		if((l+r-n-3)%80==0)  printf("\n");
	}
	//system("pause");
	return 0;
}

