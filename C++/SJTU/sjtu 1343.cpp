#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 1000010
using namespace std;
int n,ans,col[N],sum[26][N],Min[26][26],testMin[26][26];
char s[N];
int main()
{
	scanf("%d",&n);
	scanf("%s",s);
	for(int i=0;i<n;i++)
	{
		int k=s[i]-'a';
		if(i!=0) for(int j=0;j<26;j++) sum[j][i]=sum[j][i-1];
		sum[k][i]++;
	}
	for(int i=0;i<n;i++)
	{
		int k=s[i]-'a';
		for(int j=0;j<26;j++) Min[j][k]=testMin[j][k];
		for(int j=0;j<26;j++) if(sum[j][i])
		{
			if(ans<sum[k][i]-sum[j][i]-Min[k][j]) ans=sum[k][i]-sum[j][i]-Min[k][j];
		}
		for(int j=0;j<26;j++)
		{
			if(testMin[j][k]>sum[j][i]-sum[k][i]) testMin[j][k]=sum[j][i]-sum[k][i];
		}
	}
	cout<<ans<<endl;
	return 0;
}

