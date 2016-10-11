#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,R,dui[400010];
int sz,son[400010][10],fail[400010],to[400010][10];
long long f[70][400010],ans1,ans2;
char s[25];
bool danger[400010];
void Ins()
{
	int len=strlen(s+1),i,k,now=0;
	for(i=1;i<=len;i++)
	{
		k=s[i]-'0';
		if(!son[now][k])  son[now][k]=++sz;
		now=son[now][k];
	}
	danger[now]=1;
}
void init()
{
	int i;
	scanf("%d%d%d",&n,&m,&R);
	for(i=1;i<=m;i++)  
	{
	   scanf("%s",s+1);
	   Ins();
	}	
}
void getfail()
{
	int i,now,k,tou=1,wei=1,j;
	dui[1]=0;fail[0]=-1;
	while(tou<=wei)
	{
		now=dui[tou];tou++;
		for(i=1;i<=R;i++)
		if(son[now][i])
		{
			j=son[now][i];k=fail[now];
			while(k!=-1 && !son[k][i]) k=fail[k];
			if(k==-1)  fail[j]=0;
			else fail[j]=son[k][i];
			dui[++wei]=j;
			if(danger[fail[j]])  danger[j]=1;
		}
	}
}
void getto()
{
	int i,j,k;
	for(i=0;i<=sz;i++)
	{
		for(j=1;j<=R;j++)
		{
			for(k=i;k!=-1 && !son[k][j];k=fail[k]);
			if(k==-1)  to[i][j]=0;
			else  to[i][j]=son[k][j];	
		}
	}
}
void solve()
{
	getfail();
	getto();
	int i,j,k;	
	f[0][0]=1;
	for(i=0;i<n;i++)  for(j=0;j<=sz;j++)
	if(f[i][j])
	{
	    for(k=1;k<=R;k++)  if(!danger[to[j][k]])  f[i+1][to[j][k]]+=f[i][j];
	}
	for(i=0;i<=sz;i++)  if(!danger[i])  ans1+=f[n][i];
	ans2=1;
	for(i=1;i<=n;i++)  ans2*=R;
	printf("%.5lf\n",double(ans2-ans1)/ans2);  
}
int main()
{
	init();
	solve();
	return 0;
}
