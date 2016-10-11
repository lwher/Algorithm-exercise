#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int phi[1010];
int prime[1010],tot;
bool check[1010];
void getphi()
{
	int i,j;
	phi[1]=1;
	for(i=2;i<=1000;i++)
	{
		if(!check[i])  {tot++;prime[tot]=i;phi[i]=i-1;}
		for(j=1;j<=tot;j++)
		{
			if(i * prime[j]>1000)  break;
			check[i*prime[j]]=1;
			if(i % prime[j]==0)  
			{phi[i * prime[j]]=phi[i]*prime[j];break;}
			else
			phi[i * prime[j]]=phi[i]*(prime[j]-1);
		}
	}
}
int main()
{
	getphi();
	int i,t,n;
	for(i=2;i<=1000;i++)
	phi[i]+=phi[i-1];
	cin>>t;
	for(i=1;i<=t;i++)
	{
		scanf("%d",&n);
		printf("%d %d %d\n",i,n,phi[n]*2+1);
	}
	//system("pause");
	return 0;
}

