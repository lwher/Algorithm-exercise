#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int sz,last,to[50010][26],next[50010],step[50010],pos[50010];
char s[20010];
int newnode()
{
	sz++;step[sz]=0;pos[sz]=0;next[sz]=0;
    memset(to[sz],0,sizeof(to[sz]));
    return sz;
}
void add(int id,int P)
{
	int p=last,np=newnode();
	step[np]=step[p]+1;pos[np]=P;
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
			pos[nq]=P;next[nq]=next[q];step[nq]=step[p]+1;
			next[q]=nq;next[np]=nq;
			for(int i=0;i<26;i++)  to[nq][i]=to[q][i];
			for(;p!=-1 && to[p][id]==q;p=next[p])  to[p][id]=nq;  
		}
	}
}
int main()
{
	int i,j,T,len;
	next[0]=-1;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		len=strlen(s+1);last=0;sz=0;
		memset(to[0],0,sizeof(to[0]));
		for(i=1;i<=len;i++)  s[i+len]=s[i];
		for(i=1;i<=len+len;i++)  add(s[i]-'a',i);
		int now=0;
		for(i=1;i<=len;i++)
		{
			for(j=0;j<26;j++)
			if(to[now][j])
			{
				now=to[now][j];break;
			}
		}
		printf("%d\n",pos[now]-len+1);
	}
	return 0;
}