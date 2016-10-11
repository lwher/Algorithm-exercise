#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int L,R;
bool check[50001];
bool mark[1000001];
int num[1000001];
int zs[50001],tot;
void solve()
{
	int i,j;
	int a,b;
	num[0]=0;
	memset(mark,0,sizeof(mark));
	for(i=1;i<=tot;i++)
	{
		if(L%zs[i]==0)
		a=L/zs[i];
		else
		a=L/zs[i]+1;
		b=R/zs[i];
		for(j=a;j<=b;j++)
		if(j>1) 
		mark[j*zs[i]-L]=1;
		if(zs[i]>R) break;
	}
	int maxx=-1,minn=2147483647;
	int c,d;
	if(L==1)  mark[0]=1;
	for(i=0;i<=R-L;i++)
	if(!mark[i])
	{
		num[0]++;num[num[0]]=i+L;	
	}
	if(num[0]<2)  
	printf("There are no adjacent primes.\n");
	else
	{
		for(i=1;i<=num[0]-1;i++)
		{
			if(maxx<num[i+1]-num[i])
			{maxx=num[i+1]-num[i];a=num[i];b=num[i+1];}
			if(minn>num[i+1]-num[i])
			{minn=num[i+1]-num[i];c=num[i];d=num[i+1];}
		}
		printf("%d,%d are closest, %d,%d are most distant.\n",c,d,a,b);
	}

}
int main()
{
	int i,j;
	for(i=2;i<=50000;i++)
	{
		if(!check[i])  {tot++;zs[tot]=i;}
		for(j=2*i;j<=50000;j+=i)
		check[j]=1;
	}
	
	while(cin>>L>>R)
	{
		solve();
	}
	//system("pause");
	return 0;
}

