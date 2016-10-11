#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
long long x,y;
long long exgcd(long long a,long long b)
{
	long long d,t;
	if(b==0)
	{x=1;y=0;return a;}
	d=exgcd(b,a%b);
	t=x;x=y;y=t-a/b*y;
	return d;
}
int main()
{
	int i;
	long long a,b,c,k;
	long long d;
	
	while(cin>>a>>b>>c>>k)
	{
		if(a==0 && b==0 && c==0 && k==0)  break;
		if(a==b)  {cout<<0<<endl;continue;}
		d=1;
		for(i=1;i<=k;i++)  d*=2; 
		k=exgcd(c,d);
		b-=a;
		if(b%k!=0)
		printf("FOREVER\n");
		else
		{
			x*=b/k;
			x=(x%(d/k)+(d/k))%(d/k);
			if(x==0)
			x+=d/k;
			cout<<x<<endl;
		}
	}
	//system("pause");
	return 0;
}

