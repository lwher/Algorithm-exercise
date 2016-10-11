#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
string s;
int num[27];
bool check(int k)
{
	int i;
	if(k==0 || k==1)  return 0;
	for(i=2;i*i<=k;i++)
	if(k % i==0) return 0;
	return 1;
}
int main()
{
	int i;
	cin>>s;
	for(i=0;i<s.size();i++)  num[s[i]-'a']++;
	int minn=300,maxx=0;
	for(i=0;i<27;i++)
	{
		if(num[i]>0) 
		{
			if(num[i]<minn)		minn=num[i];
			if(num[i]>maxx)     maxx=num[i];
		} 
	}
	if(check(maxx-minn))
	{
		cout<<"Lucky Word"<<endl;
		cout<<maxx-minn<<endl;
	}
	else
	{
		cout<<"No Answer"<<endl;
		cout<<0<<endl;
	}
//	system("pause");
	return 0;
}