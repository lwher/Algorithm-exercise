#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int sz,last,to[500010][26],step[500010],next[500010],sum[500010];
int cnt[250010],topsort[500010],f[250010];
char s[250010];
int newnode()
{
	sz++;step[sz]=0;next[sz]=0;
	memset(to[sz],0,sizeof(to[sz]));
	return sz;
}
void add(int id)
{
	int p=last,np=newnode();
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
			int nq=newnode();
			step[nq]=step[p]+1;next[nq]=next[q];
			next[q]=nq;next[np]=nq;
			for(int i=0;i<26;i++)  to[nq][i]=to[q][i];
			for(;p!=-1 && to[p][id]==q;p=next[p])  to[p][id]=nq;  
		}
	}
}
int main()
{
	int i,len,now,p;
	next[0]=-1;	
	while(scanf("%s",s+1)!=EOF)
	{		
		sz=0;len=strlen(s+1);
		memset(to[0],0,sizeof(to[0]));
		memset(cnt,0,sizeof(cnt));
		memset(sum,0,sizeof(sum));
		memset(f,0,sizeof(f));
		for(i=1;i<=len;i++)  add(s[i]-'a');
		for(i=0;i<=sz;i++)  cnt[step[i]]++;
		for(i=1;i<=len;i++)  cnt[i]+=cnt[i-1];
		for(i=0;i<=sz;i++)  topsort[cnt[step[i]]--]=i;		
		now=0;
		for(i=1;i<=len;i++)  {now=to[now][s[i]-'a'];sum[now]++;}
		for(i=sz+1;i>=1;i--)
		{
			p=topsort[i];
			f[step[p]]=max(f[step[p]],sum[p]);
			if(next[p]!=-1)  sum[next[p]]+=sum[p];
		}
		for(i=len-1;i>=1;i--)  f[i]=max(f[i],f[i+1]);
		for(i=1;i<=len;i++)  printf("%d\n",f[i]);
	}
	return 0;
}
