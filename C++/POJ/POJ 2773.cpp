#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
bool check[1000010];
int zs[1000010],tot;
int phi[1000010];
bool mark[1000010];
int m,k;
void getzs()
{
	int i,j;
	phi[1]=1;
	for(i=2;i<=1000000;i++)
	{
		if(!check[i]) {tot++;zs[tot]=i;phi[i]=i-1;}
		for(j=1;j<=tot;j++)
		{
			if(i*zs[j]>1000000) break;
			check[i*zs[j]]=1;
			if(i%zs[j]==0)  
			{phi[i*zs[j]]=phi[i]*zs[j];break;}
			else
			{phi[i*zs[j]]=phi[i]*(zs[j]-1);}
		}
	}
}
void solve()
{ 
	long long kk;
	int i=1,j;
	int n=m;
	memset(mark,0,sizeof(mark));
	while(1)
	{
		kk=zs[i];
		if(kk*kk>m) break;
		if(n%zs[i]==0)
		{
			for(j=zs[i];j<=m;j+=zs[i])
			mark[j]=1;
			while(n%zs[i]==0)
			n/=zs[i];
		}
		i++;
    }
    if(n>1)
    {
		for(j=n;j<=m;j+=n)
		mark[j]=1;
	}
	long long a,b;
	a=k/phi[m];
	b=k%phi[m];
	if(b==0)
	{
		a--;
		b=phi[m];
	}
	int now=0;
	for(i=1;i<=m;i++)
	{
		if(!mark[i])  now++;
		if(now==b)
		{
			cout<<a*m+i<<endl;
			return;
		}  
	}
}
int main()
{
	getzs();
	while(cin>>m>>k)
	{
		solve();
	}
	//system("pause");
	return 0;
}

