#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,sz,last,to[180010][26],next[180010],step[180010],sum[180010];
int cnt[90010],topsort[180010],trans[180010][27],bs[180010];
char s[90010],ch[180010][27],ans[90010];
void add(int id)
{
	int p=last,np=++sz;
	step[np]=step[p]+1;
	last=np;
	for(;p!=-1 && !to[p][id];p=next[p])  to[p][id]=np;
	if(p==-1)  next[np]=0;
	else
	{
		int q=to[p][id];
		if(step[q]==step[p]+1)  next[np]=q;
		else
		{
			int nq=++sz;
			step[nq]=step[p]+1;next[nq]=next[q];
			next[q]=nq;next[np]=nq;
			for(int i=0;i<26;i++)  to[nq][i]=to[q][i];
			for(;p!=-1 && to[p][id]==q;p=next[p])  to[p][id]=nq;
		}
	}
}
int main()
{
	next[0]=-1;
	int i,j,p,T,k,len,now;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(i=1;i<=n;i++) add(s[i]-'a');
	for(i=0;i<=sz;i++)  cnt[step[i]]++;
	for(i=1;i<=n;i++)  cnt[i]+=cnt[i-1];
	for(i=0;i<=sz;i++)  topsort[cnt[step[i]]--]=i;
	for(i=sz+1;i>=1;i--)
	{
		p=topsort[i];
		for(j=0;j<26;j++) if(to[p][j]) sum[p]+=sum[to[p][j]];
		sum[p]++;
	}
	for(i=0;i<=sz;i++)
	{
		for(j=0;j<26;j++) 
		if(to[i][j])
		{
			bs[i]++;
			trans[i][bs[i]]=to[i][j];
			ch[i][bs[i]]=j+'a';
		}
	}
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&k);
		now=0;len=0;
		while(k!=0)
		{
		   for(i=1;i<=bs[now];i++)  if(k>sum[trans[now][i]])  k-=sum[trans[now][i]];  else break;
		   ans[++len]=ch[now][i];
		   now=trans[now][i];
		   k--;
		}
		for(i=1;i<=len;i++)  putchar(ans[i]);
		putchar('\n');
	}
	return 0;
}

