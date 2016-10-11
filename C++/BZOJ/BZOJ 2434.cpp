#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define tt t[x]
using namespace std;
struct sth
{
	int ez[26],next;
}t[100010];
int m,sz,top,tailw[100010],ans[100010],kind,dui[100010],jd[100010],maxx;
int t1,Y[100010],X[100010],bh[100010],pre[100010];// 每个询问y对应的x，链表串起来 
int t2,num[100010],yy[100010],shang[100010];// 每个节点所有的y 
int SZ,TO[200010],PRE[200010],LAST[100010];
char s[100010],ch[100010];
int tot,ft[100010],sd[100010];
int sum[100010];
void Ins(int a,int b)
{
     SZ++;TO[SZ]=b;PRE[SZ]=LAST[a];LAST[a]=SZ;
}
void add(int x,int now)
{
	if(now>top)  {t2++;num[t2]=kind;shang[t2]=yy[x];yy[x]=t2;tailw[kind]=x;return;}
	int k=s[now]-'a';
	if(t[x].ez[k]==0)  {sz++;t[x].ez[k]=sz;}
	jd[now]=t[x].ez[k];maxx=now;
    add(t[x].ez[k],now+1);
}
void bfs()
{
	int i,j,now,tou=1,wei=1;
	dui[1]=0;t[0].next=-1;
	while(tou<=wei)
	{
		now=dui[tou];tou++;
		for(i=0;i<26;i++)
		if(t[now].ez[i])
		{
			j=t[now].next;
			while(j!=-1)
			{
				if(t[j].ez[i])  {t[t[now].ez[i]].next=t[j].ez[i];break;}
				j=t[j].next;
			}
			if(j==-1)  t[t[now].ez[i]].next=0;
			dui[++wei]=t[now].ez[i];
		}
	}
}
void dfs(int x,int fa)
{
     ft[x]=++tot;
     int i=LAST[x];
     while(i>0)
     {
         if(TO[i]!=fa)  dfs(TO[i],x);
         i=PRE[i];
     }
     sd[x]=tot;
}
void build()
{
     int i;
     for(i=1;i<=sz;i++)
     {
         Ins(i,t[i].next);Ins(t[i].next,i);
     }
     dfs(0,-1);
}
int lowbit(int x)  
{
    return x & (-x);
}
void ADD(int k,int ss)
{
     while(k<=tot)
     {
         sum[k]+=ss;
         k+=lowbit(k);
     }
}
int ask(int x)
{
    int q=0;
    while(x>0)
    {
         q+=sum[x];
         x-=lowbit(x); 
    }
    return q;
}
void solve(int x)
{
     ADD(ft[x],1);
     int i,j;
     i=yy[x];
     while(i>0)
     {
           j=Y[num[i]];
           while(j>0)
           {
                ans[bh[j]]=ask(sd[tailw[X[j]]])-ask(ft[tailw[X[j]]]-1);
                j=pre[j];
           }   
           i=shang[i];
     }
     for(i=0;i<26;i++)  if(t[x].ez[i])  solve(t[x].ez[i]);
     ADD(ft[x],-1);
}
int main()
{
    freopen("type.in","r",stdin);
    freopen("type.out","w",stdout);
	int i,len;top=0;
	int x,y;	
	scanf("%s",ch+1);len=strlen(ch+1);	
	for(i=1;i<=len;i++)
	{
		if(ch[i]=='P')  {kind++;add(jd[maxx],maxx+1); }  else
		if(ch[i]=='B')  top--,maxx=min(maxx,top);  else
		top++,s[top]=ch[i],jd[top]=0;
	}
	scanf("%d",&m);
	for(i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        t1++;X[t1]=x;bh[t1]=i;pre[t1]=Y[y];Y[y]=t1;
    }
    bfs();    
    build();
    solve(0);
    for(i=1;i<=m;i++)  printf("%d\n",ans[i]);
//	system("pause");
	return 0;
}
