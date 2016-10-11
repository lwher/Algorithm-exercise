#include<iostream>
using namespace std;
int main()
{
	bool a[1000005];
	int i,j,n;
	for(i=1; i<=1000000; i++)
		a[i]=true;
	for(i=2; i<=500000; i++)
	{
		j=i+i;
		while(j<=1000000)
		{
			a[j]=false;
			j+=i;
		}
	}
	while(1)
	{
		cin>>n;
		if(n==0)
			break;
		for(i=2; i<=n/2; i++)
			if(a[i]==true && a[n-i]==true)
				break;
		if(i!=n/2+1)
		    cout<<n<<" = "<<i<<" + "<<n-i<<endl;
		else
			cout<<"Goldbach's conjecture is wrong."<<endl;
	}
	return 0;

}
