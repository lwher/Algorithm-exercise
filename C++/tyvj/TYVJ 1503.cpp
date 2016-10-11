#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
unsigned long long s[31];
int n;
unsigned long long cf[35];
int main()
{
	unsigned long long  k;
	int i;
	cf[0]=1;
	cin>>n;
	for(i=1;i<=n;i++)  cf[i]=cf[i-1]*2;
	s[0]=1;
	for(i=1;i<=n;i++)
	{
		k=cf[i-1]*cf[i-1];
		s[i]=s[i-1]+k;
	}
	cout<<s[n]<<endl;
	//system("pause");
	return 0;
}