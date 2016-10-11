#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
long long f[56];
int n,m;
int main()
{
	int i;
	f[0]=1;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		if(i<m)  f[i]=f[i-1]*2;
		else
		if(i==m) f[i]=f[i-1]*2-1;
		else
		f[i]=f[i-1]*2-f[i-m-1];
	}
	cout<<f[n]<<endl;
	//system("pause");
	return 0;
}
