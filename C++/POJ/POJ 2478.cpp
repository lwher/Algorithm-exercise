#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#define N 1000010
using namespace std;
long long phi[1000010];
int prime[100010],tot;
bool check[1000010];
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
	int i;
	for(i=3;i<=N;i++)
	phi[i]=phi[i-1]+phi[i];
	int k;
	while(scanf("%d",&k))
	{
		if(!k)  break;
		printf("%I64d\n",phi[k]);
		//cout<<phi[k]<<endl;
	}
	//system("pause");
	return 0;
}

