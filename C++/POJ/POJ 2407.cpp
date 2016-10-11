#include<iostream>
#include<cstdio>
using namespace std;
long long n;
int main()
{
	long long  i;
	long long sum;
	while(cin>>n && n)
	{
	    	sum=1;
	    	for(i=2;i*i<=n;i++)
	    	if(n%i==0)
			{
				n/=i;sum*=i-1;
				while(n%i==0)
				{
					n/=i;
					sum*=i;
				}
			}
			if(n>1)
			sum*=n-1;
			cout<<sum<<endl;
	}
	//system("pause");
	return 0;
}

