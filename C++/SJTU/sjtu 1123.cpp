#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define mod 100007
using namespace std;
struct sth
{
	int x,y;
}p[50010];
int f[50010][11][2][2],t[2][11][2][100010];// 0/1:0:1-100000 1:100000-1  ∫Û√Ê 0:down 1:up 
int n,K;
inline bool comp(const sth &a,const sth &b)
{
	return a.x<b.x;
}
void add(int p,int k,int du,int w,int x)
{
	for(int i=w;i<=100000;i+=(i & (-i))) t[p][k][du][i]=(t[p][k][du][i]+x)%mod;
}
int ask(int p,int k,int du,int w)
{
	int i,sum=0;
	for(i=w;i>0;i-=(i & (-i))) sum=(sum+t[p][k][du][i])%mod;
	return sum;
}
int main()
{
	int i,j,k;
	scanf("%d%d",&n,&K);
	for(i=1;i<=n;i++) scanf("%d%d",&p[i].x,&p[i].y);
	sort(p+1,p+1+n,comp);	
	for(i=1;i<=n;i++)
	{
	    for(k=1;k<=K;k++)
	    {
			f[i][k][0][0]=(f[i-1][k][0][0]+f[i-1][k][1][0])%mod;
			f[i][k][0][1]=(f[i-1][k][0][1]+f[i-1][k][1][1])%mod;
			f[i][k][1][0]=(f[i][k][1][0]+ask(1,k,0,(100000-p[i].y))+ask(1,k-1,1,(100000-p[i].y)))%mod;
			f[i][k][1][1]=(f[i][k][1][1]+ask(0,k,1,p[i].y-1)+ask(0,k-1,0,p[i].y-1))%mod;
		}
		for(k=1;k<=K;k++)
		{
			add(0,k,0,p[i].y,f[i][k][1][0]);add(1,k,0,100000-p[i].y+1,f[i][k][1][0]);
			add(0,k,1,p[i].y,f[i][k][1][1]);add(1,k,1,100000-p[i].y+1,f[i][k][1][1]);
		}
		f[i][0][1][0]=f[i][0][1][1]=1;
		add(0,0,1,p[i].y,1);add(1,0,1,100000-p[i].y+1,1);
		add(0,0,0,p[i].y,1);add(1,0,0,100000-p[i].y+1,1);
	}
	int ans=0;
	for(i=0;i<2;i++) for(j=0;j<2;j++) ans=(ans+f[n][K][i][j])%mod;
	cout<<ans<<endl;
	return 0;
}
