#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long n,m,s1,t1;
char s[1000010],t[1000010];
int dp[1000010][27];
long long gcd(long long a,long long b)
{
	if(b==0)  return a;
	else return gcd(b,a%b);
}
int main()
{
	cin>>n>>m;
	scanf("%s %s",s,t);
	s1=strlen(s);t1=strlen(t);
	long long d=gcd(s1,t1);
	int i,j;
	long long ans=0;
	for(i=0;i<d;i++)  for(j=i;j<t1;j+=d)  dp[i][t[j]-'a']++;
	for(i=0;i<s1;i++)  ans+=dp[i%d][s[i]-'a'];  
	ans*=s1*n/(s1*t1/d);
	ans=s1*n-ans;
	cout<<ans<<endl;
	system("pause");
	return 0;
}
