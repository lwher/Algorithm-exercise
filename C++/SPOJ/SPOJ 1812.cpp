#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int sz,last,ans,to[200010][26],next[200010],step[200010],maxl[200010],minl[200010];
int cnt[100010],topsort[200010];
char s[100010];
void add(int id)
{
	int p=last,np=++sz;step[np]=step[p]+1;
	last=np;
	for(;p!=-1 && !to[p][id];p=next[p])  to[p][id]=np;
	if(p==-1)  next[np]=0;
	else
    {
		int q=to[p][id];
		if(step[q]==step[p]+1)  next[np]=q;
		else
		{
			int nq=++sz;step[nq]=step[p]+1;
			next[nq]=next[q];
			next[q]=nq;next[np]=nq;
			for(int i=0;i<26;i++)  to[nq][i]=to[q][i];
			for(;p!=-1 && to[p][id]==q;p=next[p])  to[p][id]=nq;
		}
	}  
}
int main()
{
	next[0]=-1;
	memset(minl,127,sizeof(minl));
	scanf("%s",s+1);int i,k,now,l,len=strlen(s+1);
	for(i=1;i<=len;i++)  add(s[i]-'a');
	for(i=0;i<=sz;i++)  cnt[step[i]]++;
	for(i=1;i<=len;i++)  cnt[i]+=cnt[i-1];
	for(i=0;i<=sz;i++)  topsort[cnt[step[i]]--]=i;
	while(scanf("%s",s+1)!=EOF)
	{
		l=strlen(s+1);
		len=0;now=0;
		for(i=1;i<=l;i++)
	    {
			k=s[i]-'a';
			if(to[now][k])  {now=to[now][k];len++;}
			else
			{
				for(;now!=-1 && !to[now][k];now=next[now]);
				if(now==-1)  {now=0;len=0;}
				else  {len=step[now]+1;now=to[now][k];}
			}
			if(len>maxl[now])  maxl[now]=len;
		}
		for(i=sz+1;i>=1;i--)
		{
			now=topsort[i];
			if(maxl[now]<minl[now])  minl[now]=maxl[now];
			if(next[now]!=-1 && maxl[now]>maxl[next[now]])
			{
				maxl[next[now]]=maxl[now];
				if(maxl[next[now]]>step[next[now]])  maxl[next[now]]=step[next[now]];
			}
			maxl[now]=0;  
		}
	}
	for(i=0;i<=sz;i++)  if(ans<minl[i])  ans=minl[i];
	printf("%d\n",ans);
//	system("pause");
	return 0;
}

