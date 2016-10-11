#include <iostream>
#include <algorithm>
#include<cstdio>
using namespace std;

long long data[1000005];
long long total[1000005];

int main()
{
	int n;
	scanf("%d",&n);
	
		for(int i=0;i<n;i++)
		{
			scanf("%d",&data[i]);
			if(i>0)
				total[i]=total[i-1]+data[i];
			else total[i]=data[i];
		}
		long long avg=total[n-1]/n;
		for(int i=0;i<n;i++)
			total[i]=total[i]-(i+1)*avg;
		sort(total,total+n);
		long long mid=total[n/2];
		long long result=0;
		for(int i=0;i<n;i++)
		{
			result+=abs(total[i]-mid);
		}
		
		cout<<result<<endl;
	
	system("pause");
	return 0;
}
