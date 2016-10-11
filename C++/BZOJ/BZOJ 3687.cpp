#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<bitset>
using namespace std;
int n,total,sum;
bitset<2000010> ans;
int main()
{
	int i,x;
	scanf("%d",&n);
	ans[0]=1;
	for(i=1;i<=n;i++) 
	{
		scanf("%d",&x);
		sum+=x;
		ans^=(ans<<x);
	}
	for(i=1;i<=sum;i++) if(ans[i]==1) total^=i;
	cout<<total<<endl;
	return 0;
}
