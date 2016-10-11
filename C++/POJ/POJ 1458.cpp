#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
char a[510],b[510];
int f[2][510],A,B;
int main()
{
	int i,j,q;
	while(scanf("%s%s",a+1,b+1)!=EOF)
	{
		A=strlen(a+1);B=strlen(b+1);		
		memset(f,0,sizeof(f));
		q=0;
		for(i=1;i<=A;i++) 
		{
			memset(f[q],0,sizeof(f[q]));
			for(j=1;j<=B;j++)
			{
				if(a[i]==b[j])  f[q][j]=f[q^1][j-1]+1;
				else f[q][j]=max(f[q^1][j],f[q][j-1]);
			}
			q^=1;
		}
		printf("%d\n",f[q^1][B]);
	}
	//system("pause");
	return 0;
}