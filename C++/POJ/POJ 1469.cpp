#include<iostream>
#include<stdio.h>
#include<string.h> 
using namespace std;
int n,m;
bool d[310];
int lianbian[110];
int pre[100010],to[100010],last[310];
int sz;
int ans;
void xiulu(int a,int b)
{
	sz++;
	to[sz]=b;
	pre[sz]=last[a];
	last[a]=sz;
}
bool dfs(int x)
{
	int i=last[x];
	while(i>0)
	{
	   if(!d[to[i]])
	   {
			d[to[i]]=1;
		  if(lianbian[to[i]]==0 || dfs(lianbian[to[i]])==1)
		  {
			 lianbian[to[i]]=x;
			 return 1;
		  }
	   }
	   i=pre[i];
	}
	return 0;
}
int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
	 scanf("%d%d",&m,&n);	
	 ans=0;
	 memset(d,0,sizeof(d));
	 memset(lianbian,0,sizeof(lianbian));
	 memset(last,0,sizeof(last));
	 sz=0;
  	int i,j,a,b;
	
	for(i=1;i<=m;i++)
	{
	scanf("%d",&a);
	for(j=1;j<=a;j++)
	{
	scanf("%d",&b);
	xiulu(b,i);
	}
	}
	
	for(i=1;i<=n;i++)
	{
	  memset(d,0,sizeof(d));
	  if(dfs(i))
	  ans++;
	}
	
	if(ans==m)
	{printf("YES\n");}
	else 
	{printf("NO\n");}
    
} 
	system("pause");
	return 0;
}
