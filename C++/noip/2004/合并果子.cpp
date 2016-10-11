#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
struct node
{
	int num;
}x,y;
struct cmp
{
	bool operator()(const node& a,const node& b)
	{
		return a.num>b.num;
	}
};
int n;
long long ans;
int main()
{
	int i,k;
	priority_queue<node,vector<node>,cmp> q;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&k);
		x.num=k;
		q.push(x);
	}
	for(i=1;i<n;i++)
	{
		x=q.top();
		q.pop();
		y=q.top();
		q.pop();
		x.num+=y.num;
		ans+=x.num;
		q.push(x);
	}
	cout<<ans<<endl;
	//system("pause");
	return 0;
}
