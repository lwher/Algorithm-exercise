#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
using namespace std;
long long minn;
void getrand()
{
	int tt=time(NULL);
	srand(tt);
}
long long qchen(long long a,long long b,long long c) // a*b % c
{
	long long s=0;
	a%=c;
	while(b>0)
	{
		if(b & 1) {s+=a;if(s>=c) s-=c;}
	    a=a<<1;
	    if(a>=c) a-=c;
	    b=b>>1;
	}
	return s;
}
long long qpow(long long a,long long b,long long c)  // a^b % c
{
	long long s=1;
	a%=c;
	while(b>0)
	{
		if(b & 1)  s=qchen(s,a,c);
		a=qchen(a,a,c);
		b=b>>1;
	}
	return s;
}
bool check(long long a,long long n)
{
	long long m=n-1;
    int j=0,i;
    while(!(m & 1))
    {
		j++;
		m=m>>1;
	}
	long long x,y;
	x=qpow(a,m,n);
	for(i=1;i<=j;i++)
	{
		y=qpow(x,2,n);
		if(y==1 && x!=1 && x!=n-1) return 1;
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
		if(check(a,n))
		return 0;
	}
	return 1;
}
long long gcd(long long a,long long b)
{
	if(a==0)  return 1;
	if(b==0)  return a;
	if(a<0)  return gcd(-a,b);
	return gcd(b,a%b);
}
long long getyz(long long n,long long c)
{
	long long x,y,d;
	x=rand()%n;
	y=x;
	int i=1,k=2;
	while(1)
	{
		i++;
		x=(qchen(x,x,n)+c)%n;
		d=gcd(y-x,n);
		if(d!=1 && d!=n)  return d;
		if(x==y) return n;
		if(i==k)
		{y=x;k=k<<1;}
	}
}
void fenjie(long long n)
{
	if(n==1)  return;
	if(pdss(n))
	{
		if(n<minn)  minn=n;
		return;
	}
	long long p=n;
	while(p==n)  p=getyz(n,rand()%(n-1)+1);
    fenjie(p);fenjie(n/p);
}
int main()
{
	getrand();
    long long n;
    int t;
    cin>>t;
    while(t--)
    {
		cin>>n;
		if(pdss(n))
		cout<<"Prime"<<endl;
		else
		{
				minn=1e20;
				fenjie(n);
				cout<<minn<<endl;
		}
	}
	//system("pause");
	return 0;
}

