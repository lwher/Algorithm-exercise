#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int sg[2010];
bool mark[2010];
int main()
{
	int i,n,j;
	int a,b;
	sg[0]=0;sg[1]=1;sg[2]=1;sg[3]=1;sg[4]=2;sg[5]=2;
	for(i=6;i<=2000;i++)
	{
		memset(mark,0,sizeof(mark));
		for(j=1;j<=i;j++)
		{
			a=0;b=0;
			if(j-3>0)  a=sg[j-3];
			if(i-j-2>0) b=sg[i-j-2];
			mark[a^b]=1;
		}
		j=0;
		while(mark[j])
		j++;
		sg[i]=j;
	}
	while(cin>>n)
	{
		if(sg[n])  printf("1\n");
		else  printf("2\n");
	}
	//system("pause");
	return 0;
}

