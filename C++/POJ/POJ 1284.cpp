#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#define N 65537
using namespace std;
long long phi[N];
int prime[10010],tot;
bool check[N];
void getphi()
{
	int i,j;
	phi[1]=1;
	for(i=2;i<=N;i++)
	{
		if(!check[i])  {tot++;prime[tot]=i;phi[i]=i-1;}
		for(j=1;j<=tot;j++)
		{
			if(i*prime[j]>N) break;
			check[i*prime[j]]=1;
			if(i % prime[j]==0)
			{phi[i * prime[j]]=phi[i]*prime[j];break;}
			else
			{phi[i * prime[j]]=phi[i]*(prime[j]-1);}
		}
	}
}
int main()
{
	getphi();
	int k;
	while(scanf("%d",&k)!=EOF)
	{
		printf("%d\n",phi[k-1]);
	}
	//system("pause");
	return 0;
}

