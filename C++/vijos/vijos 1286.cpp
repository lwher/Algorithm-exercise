#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
unsigned long long  f[2][513][21],c[81][21];
int cnt[513];
int n,m,K;
void swap(int &a,int &b)
{
	int t=a;a=b;b=t;
}
void getC()
{
	int i,j,k;
	c[0][0]=1;
	for(i=1;i<=80;i++)
	{
		k=min(i,20);c[i][0]=1;
		for(j=1;j<=k;j++)  c[i][j]=c[i-1][j]+c[i-1][j-1];
    }
} 
int calc(int x)
{
	int sum=0;
	for(int i=0;i<=10;i++)  if((x>>i) & 1)  sum++;
	return sum;
}
unsigned long long gcd(unsigned long long a,unsigned long long b)
{
	if(b==0)  return a;
	else return gcd(b,a%b);
}
int main()
{
	int i,j,k,p,l,q=0;
	scanf("%d%d%d",&n,&m,&K);
	if(n<m)  swap(n,m);
	getC();
	for(i=1;i<=512;i++)   cnt[i]=calc(i);
	f[0][0][0]=1;  p=(1<<m);
	for(i=0;i<n;i++)
	{
		memset(f[q^1],0,sizeof(f[q^1]));
		for(j=0;j<p;j++)
		if(!(j & (j<<1)))
		{
			for(k=0;k<=K;k++)
			if(f[q][j][k])
			{
				for(l=0;l<p;l++)  if(!(l & (l<<1)) && k+cnt[l]<=K && !(j & l))  f[q^1][l][k+cnt[l]]+=f[q][j][k];  
			}
		}
		q^=1;
    }
	unsigned long long fz=0,fm=0,D;
	fz=c[n*m][K];	
	for(i=0;i<p;i++)   fm+=f[q][i][K];
	if(fm==0)  cout<<"Impossible!"<<endl;
	else
	{
		D=gcd(fz,fm);
		cout<<fz/D<<"/"<<fm/D<<endl;
	}
	//system("pause");
	return 0;
}