#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
char s[300010],g[100010],z2[300010];
int sz,n,b[300010];
long long a[300010],bb[300010];
int top1,top2;
int z3[300010];
void chuli()
{
	int i;bool o;
	for(i=1;i<=n;i++)
	{
		o=0;
		if(g[i]=='+' && g[i-1]!=')' && g[i-1]!='+' && g[i-1]!='*')  
		{sz++;s[sz]='1';b[sz]=1;o=1;sz++;s[sz]='+';b[sz]=2;}
		if(g[i]=='+' && g[i+1]!='(')  
		{if(!o) {o=1;sz++;s[sz]='+';b[sz]=2;}sz++;s[sz]='1';b[sz]=1;}
		if(g[i]=='*' && g[i-1]!=')' && g[i-1]!='+' && g[i-1]!='*')  
		{sz++;s[sz]='1';b[sz]=1;o=1;sz++;s[sz]='*';b[sz]=3;}
		if(g[i]=='*' && g[i+1]!='(')  
		{if(!o) {o=1;sz++;s[sz]='*';b[sz]=3;}sz++;s[sz]='1';b[sz]=1;}
		if(!o)
		{
			sz++;
			s[sz]=g[i];
			if(g[i]=='+')  b[sz]=2;
			if(g[i]=='*')  b[sz]=3;
			if(g[i]=='(')  b[sz]=1;
			if(g[i]==')')  b[sz]=1;
		}
	}
	sz++;s[sz]=')';b[sz]=1;
}
void DP()
{
	int i;bool o;
	long long A,B;
	for(i=1;i<=sz;i++)
	{
		if(s[i]=='1')
		{top1++;a[top1]=1;bb[top1]=1;}
		else
		{
			o=0;
			if(s[i]=='(')  {top2++;z2[top2]=s[i];z3[top2]=b[i];continue;}
		    while(top2>0 && z3[top2]>=b[i])
			{
				if(z2[top2]=='(' && s[i]==')')  {o=1;top2--;break;}
				if(z2[top2]=='+')
				{
				    A=(a[top1-1]*a[top1])%10007;	
					B=(a[top1-1]*bb[top1]+a[top1]*bb[top1-1]+bb[top1]*bb[top1-1])%10007;\
					top1--;
					a[top1]=A;bb[top1]=B;
				}
				if(z2[top2]=='*')
				{
				    B=(bb[top1-1]*bb[top1])%10007;	
					A=(a[top1-1]*bb[top1]+a[top1]*bb[top1-1]+a[top1]*a[top1-1])%10007;\
					top1--;
					a[top1]=A;bb[top1]=B;
				}
				top2--;
			}
			if(!o)
			{
				top2++;z2[top2]=s[i];z3[top2]=b[i];
			}	
		}
	}
}
int main()
{
	scanf("%d",&n);
	scanf("%s",g+1);
	chuli();
	DP();
	cout<<a[1]<<endl;
	//system("pause");
	return 0;
}
