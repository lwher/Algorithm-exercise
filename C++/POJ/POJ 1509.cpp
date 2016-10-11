#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
char s[20010];
int len;
int main()
{
	int i,j,k,t,a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		len=strlen(s+1);
		for(i=1;i<=len;i++)  s[i+len]=s[i];
		i=1;j=2;k=0;
		while(i<=len && j<=len && k<=len)
		{
			a=s[i+k];b=s[j+k];
			if(a==b)  k++;
			else
			{
				if(a<b) j=j+k+1;
				else  i=i+k+1;
				if(i==j) j++;
				k=0;
			}
		}
		i=min(i,j);
		printf("%d\n",i);
	}
	return 0;
}