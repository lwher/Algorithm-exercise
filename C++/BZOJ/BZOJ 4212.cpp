#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
struct sth
{
	string s;
	int ll;
}p[2010];
inline bool comp(sth a,sth b)
{
	return a.s<b.s;
}
int n,m,last;
int root[2010],sz,sum[2100000],t[2100000][26];
char ch[2100000];
string now;
void Ins(int q,int x,int y)
{
	int len=p[q].ll-1,i,k;
	root[y]=++sz;
	x=root[x];y=root[y];
	while(1)
	{
		sum[y]=sum[x]+1;
		if(len<0)  break;
		for(i=0;i<26;i++)  t[y][i]=t[x][i];
		k=p[q].s[len]-'a';
		t[y][k]=++sz;
		x=t[x][k];y=t[y][k];
		len--;
	}
}
int ask(int l,int r)
{
	int k,len=strlen(ch+1);
	while(len>0)
	{
		k=ch[len]-'a';
		l=t[l][k];r=t[r][k];
		len--;
	}
	return sum[r]-sum[l];
}
void init()
{
	int i,j,len;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%s",ch+1);len=strlen(ch+1);p[i].s="";
		for(j=1;j<=len;j++)  p[i].s+=ch[j]; 
		p[i].ll=len;
	}
	sort(p+1,p+1+n,comp);	
    for(i=1;i<=n;i++)  Ins(i,i-1,i);
}
int find()
{
	int l=1,r=n,mid;
	while(l+1<r)
	{
		mid=(l+r)>>1;
		if(p[mid].s>=now)  r=mid;
		else l=mid;  
	}
	if(p[r].s<now)  return r;
	if(p[l].s<now)  return l;
	return l-1;
}
void solve()
{
	int i,len,j,l,r,k;
	scanf("%d",&m);	
	
	for(i=1;i<=m;i++)
	{
		scanf("%s",ch+1);
		len=strlen(ch+1);
		last%=26;
		now="";
		for(j=1;j<=len;j++){k=ch[j]-'a';k=(k+last)%26;ch[j]=('a'+k);}
		for(j=1;j<=len;j++)  now+=ch[j];
		l=find();
		now+=('z'+1);
		r=find();
		scanf("%s",ch+1);	
		len=strlen(ch+1);	
		for(j=1;j<=len;j++){k=ch[j]-'a';k=(k+last)%26;ch[j]=('a'+k);}
		last=ask(root[l],root[r]);
		printf("%d\n",last);
	}
}
int main()
{
	//freopen("godcow.in","r",stdin);
	//freopen("godcow.out","w",stdout);
	init();
	solve();
	//system("pause");
	return 0;
}
