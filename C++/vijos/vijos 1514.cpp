#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int f[200010][19];
int n,m;
int main()
{
	int i,j,k,l,r,ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++)  scanf("%d",&f[i][0]);
	for(i=1;i<=18;i++)
	{
	k=1<<i;
	for(j=1;j+k-1<=n;j++)   f[j][i]=max(f[j][i-1],f[j+(1<<(i-1))][i-1]);
    }
    scanf("%d",&m);
    for(i=1;i<=m;i++)
    {
		scanf("%d%d",&l,&r);
		k=log(r-l+1)/log(2.000);
		ans=max(f[l][k],f[r-(1<<k)+1][k]);
		printf("%d\n",ans);
	}
	//system("pause");
	return 0;
}
