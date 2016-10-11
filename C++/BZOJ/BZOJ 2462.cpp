#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
unsigned long long hash[1010][1010],hash2[1010][1010];
unsigned long long ha1[1010][1100],ha2[1010][1010];
int map[1010][1010],tu[1010][1010];
char mm[1010][1010];
int n,m,A,B,q;
int main()
{
	int i,j;
	scanf("%d%d%d%d",&n,&m,&A,&B);
	for(i=1;i<=n;i++) 
	{
		scanf("%s",mm[i]+1);
		for(j=1;j<=m;j++) map[i][j]=mm[i][j]-'0';
	}
	unsigned long long limt1=1,limt2=1;
	for(i=1;i<B;i++)  limt1=limt1*3;
	for(i=1;i<A;i++)  limt2=limt2*5;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=B;j++)  hash[i][j]=hash[i][j-1]*3+map[i][j];
		for(j=B+1;j<=m;j++) 
		{
			hash[i][j]=(hash[i][j-1]-map[i][j-B]*limt1)*3+map[i][j];
		}
	}
	for(j=1;j<=m;j++)
	{
		for(i=1;i<=A;i++)  hash2[i][j]=hash2[i-1][j]*5+hash[i][j];
		for(i=A+1;i<=n;i++)
		{
			hash2[i][j]=((hash2[i-1][j]-hash[i-A][j]*limt2)*5)+hash[i][j];
		}
	}
	scanf("%d",&q);
	bool o;
	while(q--)
	{
		o=0;
		for(i=1;i<=A;i++) 
	    {
			scanf("%s",mm[i]+1);
			for(j=1;j<=B;j++) tu[i][j]=mm[i][j]-'0';
	    }
	    for(i=1;i<=A;i++)  for(j=1;j<=B;j++)  ha1[i][j]=ha1[i][j-1]*3+tu[i][j];
		for(i=1;i<=A;i++)  ha2[i][B]=ha2[i-1][B]*5+ha1[i][B];  
	    for(i=A;i<=n;i++)  for(j=B;j<=m;j++)  if(hash2[i][j]==ha2[A][B])  {o=1;break;}
	    if(o) printf("1\n"); else printf("0\n");
	}
	system("pause");
	return 0;
}
