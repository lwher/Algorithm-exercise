#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
struct sth
{long long int zuo,you,v,last;};
sth a[1001];
long long int end[201];
int n,m,s,t;
long long int sz=1;
int h[201];
long long inf=999999999; 
long long ans; 
void haiba(int x,int gao)
{
	int i=end[x];
	if((h[x]>0)&&(h[x]<gao))  return;
	h[x]=gao;	
	while(i>0)
	{
	if(a[i].v==0)
	{haiba(a[i].you,gao+1);}
	i=a[i].last;
    }
}
void cl(long long int aa,long long int bb,long long int cc)
{
	sz++;
	a[sz].zuo=aa;
	a[sz].you=bb;
	a[sz].v=cc;
	a[sz].last=end[aa];
	end[aa]=sz;
	sz++;
	a[sz].zuo=bb;
	a[sz].you=aa;
	a[sz].last=end[bb];
	end[bb]=sz;
}
void init()
{
	int i,j,aa,b,vv;
	int flow;
	for(i=1;i<=m;i++)
	{
	cin>>aa>>b>>vv;
	cl(aa,b,vv);
	}
	haiba(n,0);
}
int dfs(int x,long long  F)
{
	if(x==n)return F; 
	long long int i=end[x];
	long long w,used=0;
    while(i>0)
	{
		if((a[i].v>0)&&(h[x]-1==h[a[i].you])) 
		{
			 w=F-used;
			 w=dfs(a[i].you,min(w,a[i].v)); 
			 a[i].v-=w;
			 a[i^1].v+=w; 
			 used+=w; 
			 if(used==F)
			 return used; 
		} 
		i=a[i].last;
	} 
    if(used<F)
	h[x]++;
	return used; 
} 
void wll()
{
	while(h[1]<n)
	ans+=dfs(1,inf); 
} 
int main()
{
    while(cin>>m>>n)
	{
	memset(a,0,sizeof(a));
	memset(h,0,sizeof(h));
	memset(end,0,sizeof(h));
	ans=0;sz=1;
	init();
    wll(); 
    cout<<ans<<endl; 
	}
	system("pause");
	return 0;
}
