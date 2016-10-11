#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int n,k,ans;
int main()
{
	int i,x,now;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
	{
		now=0;
		while(scanf("%d",&x)!=EOF)
		{
			if(x==0) break;
			now++;
		}
		if(now>=k)  ans++;
	}
	cout<<ans<<endl;
	//system("pause");
	return 0;
}
