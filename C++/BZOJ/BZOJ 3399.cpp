#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define inf 0x7fffffff
#define ll long long
using namespace std;
int n,x,y;
int a[25005],b[25005];
ll ans;
int main()
{
	scanf("%d%d%d",&n,&x,&y);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)
	    if(a[i]<b[i])ans+=(b[i]-a[i])*x;
	    else ans+=(a[i]-b[i])*y;
	printf("%lld\n",ans);
	system("pause");
	return 0;
}
