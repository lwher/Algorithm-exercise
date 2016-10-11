#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
long long GCD,LCM,K;
long long ys[100],tot;
long long minn,A,B;
void getrand()
{
	int tt=time(NULL);
	srand(tt);
}
long long mul(long long a,long long b,long long c)
{
	long long s=0;  a%=c;
	while(b>0)
	{
		if(b & 1) {s+=a;if(s>=c) s-=c;}
		a=a<<1; if(a>=c)  a-=c;
		b=b>>1;
	}
	return s;
}
long long qpow(long long a,long long b,long long c)
{
	long long now=1; a%=c;
	while(b>0)
	{
		if(b & 1)  now=mul(now,a,c);
		a=mul(a,a,c);
		b=b>>1;
	}
	return now;
} 
long long gcd(long long a,long long b)
{
	if(a==0)  return 1;
	if(a<0)  return gcd(-a,b);
	if(b==0) return a;
	return gcd(b,a%b);
}
bool check(long long n,long long a)
{
	long long m=n-1;
	int j=0,i;
	long long x,y;
	while(!(m & 1))
	{
		j++;
		m=m>>1;
	}
	x=qpow(a,m,n);
	for(i=1;i<=j;i++)
	{
		y=qpow(x,2,n);
		if(y==1 && x!=1 && x!=n-1)  return 1;
		x=y;
	}
	if(y!=1)  return 1;
	return 0;
}
bool pdss(long long n)
{
	if(n==1) return 0;
	if(n==2) return 1;
	if(!(n & 1))  return 0;
	int i;
	long long a;
	for(i=1;i<=12;i++)
	{
		a=rand()%(n-1)+1;
		if(check(n,a))
		return 0;
	}
	return 1;
}
long long getys(long long n,long long c)
{
	int k=2,i=1;
	long long x=rand()%n;
	long long y=x,d;
	while(1)
	{
		i++;
		x=(qpow(x,2,n)+c)%n;
		d=gcd(y-x,n);
		if(d!=1 && d!=n)  return d;
		if(y==x)  return n;
		if(i==k)
		{y=x;k=k<<1;}
	}
}
void fenjie(long long n)
{
	if(n==1) return;
	long long p;
	if(pdss(n))
	{
		tot++;
		ys[tot]=n;return;
	}
	p=n;
	while(p==n)
	p=getys(n,rand()%(n-1)+1);
	fenjie(p);fenjie(n/p);
}
void dfs(int top,long long now)
{
	if(top==tot+1)
	{
		if(gcd(now,K/now)==1 && now+K/now<minn)
		{
			minn=now+K/now;
			A=now;B=K/now;
		}
		return;
	}
	dfs(top+1,now*ys[top]);
	dfs(top+1,now);
}
int main()
{
	long long tt;
	while(cin>>GCD>>LCM)
	{
	   tot=0;
	   minn=1e20;
	   K=LCM/GCD;
	   fenjie(K);
	   dfs(1,1);
	   if(A>B)
	   {tt=A;A=B;B=tt;}
	   cout<<A*GCD<<" "<<B*GCD<<endl;
	}
	//system("pause");
	return 0;
}

