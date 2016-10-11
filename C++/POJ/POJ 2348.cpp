#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
bool solve(long long a,long long b)
{
	if(a==b) return 1;
	if(a<b)
	{int t;t=a;a=b;b=t;}
	if(a>=2*b) return 1;
	return !(solve(a-b,b));
}
int main()
{
	long long a,b;
	while(cin>>a>>b)
	{
		if(a==0 && b==0)  break;
	    if(a<b)
	    {int t;t=a;a=b;b=t;}
	    if(solve(a,b))
	    printf("Stan wins\n");
	    else
	    printf("Ollie wins\n");
	}
	//system("pause");
	return 0;
}

