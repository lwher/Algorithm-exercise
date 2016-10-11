#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,sz,sum,num[210];
int f[700010],nmax=0;
bool g[2][1400010];
int main()
{
	int i,j,k,Q1=0,tmp;
	scanf("%d",&n);
	for(i=1;i<=n;i++) 
	{
	   scanf("%d",&num[i]);
	   sum+=num[i];
	   num[i+n]=num[i];
    }    
    for(i=1;i<=n+n-1;i++)
    {
	   for(j=sum;j>=num[i];j--) f[j]=max(f[j],f[j-num[i]]);
	   f[num[i]]=i;
	   if(i>=n)
	   {
           tmp=0;
           for(j=1;j<=sum;j++) if(f[j]>i-n+1) tmp++;
           if(tmp>nmax)
           {
			   nmax=tmp;
			   Q1=i-n+1;
		   }
	   }
	}
	sum+=10;num[Q1]=0;
	g[0][sum]=1;
	int p=0,q=1;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=sum*2;j++)
		{
			g[q][j]=0;
		    g[q][j]|=g[p][j];
		    if(j>=num[i]) g[q][j]|=g[p][j-num[i]];
		    if(j+num[i]<=sum*2) g[q][j]|=g[p][j+num[i]];
		}
		p^=1;q^=1;
	}
	for(i=sum+1;i<=sum*2;i++) if(!g[p][i]) break;
	printf("%d\n%d\n",Q1,i-sum);
	return 0;
}