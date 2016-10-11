#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
long long a,b;
long long ans1[10],ans2[10],ans[10];
long long sum[14],cf[14],sum1[14];
void cal(long long x)
{
	int i,j;
	int mi=0;
	long long cnt=x;
	long long k=1;
	int num[13]={0};
    while(x>0)
	{
       num[0]++;
       num[num[0]]=x%10;
       x/=10;
       k*=10;
       mi++;
    }
    k/=10;mi--;
	ans[0]-=sum1[mi+1];
	for(j=num[0];j>=1;j--)
	{
	   for(i=0;i<=9;i++)
	   ans[i]+=(num[j])*sum[mi];
	   for(i=0;i<num[j];i++)
	   ans[i]+=cf[mi];
	   ans[num[j]]+=cnt%k+1;
	   cnt%=k;
	   k/=10;
	   mi--;
	}
}
int main()
{
	int i,j;
	cin>>a>>b;
	cf[0]=1;
	for(i=1;i<=13;i++)
	cf[i]=cf[i-1]*10;
	sum1[1]=1;
	for(i=2;i<=13;i++)
	sum1[i]=sum1[i-1]*10+1;
	for(i=1;i<=13;i++)
    sum[i]=i*cf[i-1];
	cal(a-1);
	for(i=0;i<=9;i++)
	ans1[i]=ans[i];
	memset(ans,0,sizeof(ans));
	cal(b);
	for(i=0;i<=8;i++)
	cout<<ans[i]-ans1[i]<<" ";
	cout<<ans[9]-ans1[9]<<endl;
	system("pause");
	return 0;
}
