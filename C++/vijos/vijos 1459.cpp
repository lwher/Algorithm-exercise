#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
long long f[1010][1010],ans;
int n,num[1010],mid[1010][1010];
int m,L,R;
int sz,pre[1010],last[2010];
int main()
{
	int i,j,k,l,big,small;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)  scanf("%d",&num[i]);
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{
		f[j][i]=f[j-1][i]+abs(num[j]-num[i]);
	}
	
	for(i=1;i<=n;i++)
	{
		memset(last,-1,sizeof(last));
        memset(pre,0,sizeof(pre));
        big=0;small=0;
		for(j=i;j>=1;j--)
		{
			if(num[j]<=num[i])  small++; else big++;
			k=big-small+1000;
			pre[j]=last[k];
			last[k]=j;
		}
		big=0;small=-1;
		for(j=i;j<=n;j++)
		{
			if(num[j]<=num[i])  small++; else big++;
			k=small-big+1000;
			l=last[k-1];
			while(l!=-1)
			{
				if(((j-l+1) & 1))  mid[l][j]=i;
				l=pre[l];
			}
			l=last[k];
			while(l!=-1)
			{
				if(!((j-l+1) & 1))  mid[l][j]=i;
				l=pre[l];
			}
			
		}
	}	
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&L,&R);
		k=mid[L][R];
		ans+=f[R][k]-f[L-1][k];
	}
	cout<<ans<<endl;
	//system("pause");
	return 0;
}
