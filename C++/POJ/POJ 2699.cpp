#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define N 310
#define M 30010
#define INF 0x7fffffff
using namespace std;
int n,s,t,tot;
int sz=1,to[M],pre[M],v[M],last[N];
int h[N],gap[N],dui[N];
int score[11],m[11][11];
void Ins(int a,int b,int c)
{
	sz++;to[sz]=b;v[sz]=c;pre[sz]=last[a];last[a]=sz;
	sz++;to[sz]=a;v[sz]=0;pre[sz]=last[b];last[b]=sz;
}
void bfs()
{
	memset(h,-1,sizeof(h));
	memset(gap,0,sizeof(gap));
	int tou=1,wei=1,now,i;
	dui[1]=t;h[t]=1;gap[1]=1;
	while(tou<=wei)
	{
		now=dui[tou];tou++;
		i=last[now];
		while(i>0)
		{
			if(h[to[i]]==-1)
			{
				h[to[i]]=h[now]+1;
				gap[h[now]+1]++;
				dui[++wei]=to[i];
			}
			i=pre[i];
		}
	}
}
int dfs(int x,int F)
{
	if(x==t)  return F;
	int i,used=0,w;
	i=last[x];
	while(i>0)
	{
		if(v[i] && h[x]-1==h[to[i]])
		{
			w=min(v[i],F-used);
			w=dfs(to[i],w);
			used+=w;
			v[i]-=w;
			v[i^1]+=w;
			if(used==F)  return F;
		}
		i=pre[i];
	}
	gap[h[x]]--;
	if(gap[h[x]]==0)  h[s]=t+2;
	gap[++h[x]]++;
	return used;
}
int sap()
{
	int tmp=0;
	bfs();
	while(h[s]<t+2)  tmp+=dfs(s,INF);
	return tmp;
}
void build(int x)
{
     int i,j;
     sz=1;memset(last,0,sizeof(last));
     for(i=1;i<=n;i++)  Ins(i,t,score[i]);
     for(i=1;i<=tot;i++)  Ins(s,n+i,1);
     for(i=1;i<n;i++)  for(j=i+1;j<=n;j++)
     {
         if(i>x && j>x && score[j]>score[i])   Ins(m[i][j],i,1);
         else  {Ins(m[i][j],i,1);Ins(m[i][j],j,1);}
     }
}
int main()
{
	int i,j,k,a,b,T;bool o;
	char ch;
    scanf("%d",&T);ch=getchar();
    while(ch!='\n')  ch=getchar();        
	while(T--)
    {
        n=0;memset(m,0,sizeof(m));o=0;
        while(1)
        {
           ch=getchar(); 
           if(ch=='\n')  break;
           while(!(ch>='0' && ch<='9'))  {ch=getchar();if(ch=='\n')  {o=1;break;}}
           if(o)  break;
           k=0;  while(ch>='0' && ch<='9')  {k=k*10+(ch-'0');ch=getchar();}
           score[++n]=k;  if(ch=='\n')  break;  
        }
        tot=n;
        for(i=1;i<=n;i++)  for(j=i+1;j<=n;j++)  m[i][j]=++tot;
        s=n+tot+1;t=s+1;
        for(i=n;i>=1;i--)
        {
            build(n-i);
            if(sap()==n*(n-1)/2)  break;
        }
        printf("%d\n",i);
    }
    system("pause");
	return 0;
}

