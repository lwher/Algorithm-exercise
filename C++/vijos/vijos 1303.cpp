#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int h[210],n;
int f[210],g[210];
int ans1,ans2;
void init()
{
	char ch;
	ch=getchar();
	while(ch!='\n')
	{
		while(!(ch>='0' && ch<='9'))  ch=getchar();
		n++;
		while(ch>='0' && ch<='9')  {h[n]=h[n]*10+(ch-'0');ch=getchar();}
	}
}
int main()
{
	init();
	int i,j;
	for(i=1;i<=n;i++)
	{
		f[i]=1;
		for(j=1;j<i;j++)  if(h[j]>=h[i])  f[i]=max(f[i],f[j]+1);
        if(ans1<f[i])  ans1=f[i];
	}
	for(i=1;i<=n;i++)
	{
		g[i]=1;
		for(j=1;j<i;j++)  if(h[j]<h[i])  g[i]=max(g[i],g[j]+1);
        if(ans2<g[i])  ans2=g[i];
	}
	cout<<ans1<<","<<ans2-1<<endl;
	//system("pause");
	return 0;
}
