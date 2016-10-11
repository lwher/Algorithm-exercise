#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int n,m,tt,dfn[100010],low[100010],stack[100010],top;
int sz,to[300010],pre[300010],last[100010];
int fl,belong[100010],rd[100010],ans,size[100010];
bool in[100010],vis[100010];
void Ins(int a,int b)
{
    sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
void Tarjan(int x)
{
    dfn[x]=low[x]=++tt;
    stack[++top]=x;in[x]=1;
    for(int i=last[x];i;i=pre[i])
    {
        if(!dfn[to[i]])  {Tarjan(to[i]);low[x]=min(low[x],low[to[i]]);}
        else  if(in[to[i]])  low[x]=min(low[x],dfn[to[i]]);
    }
    if(dfn[x]==low[x])
    {
        ++fl;int k=stack[top];
        while(k!=x)
        {
            belong[k]=fl;size[fl]++;in[k]=0;top--;k=stack[top];
        }
        size[fl]++;belong[x]=fl;in[x]=0;top--;
    }
}
void false_build(){
	for(int i=1;i<=n;i++){
		for(int j=last[i];j;j=pre[j]){
			int u=belong[i],v=belong[to[j]];
			if(u!=v){
				vis[v]=1;rd[v]++;
			}
		}
		for(int j=last[i];j;j=pre[j]){
			vis[belong[to[j]]]=0;
		}
	}
}
bool judge(int x){
	if(rd[belong[x]]>0 || size[belong[x]]>1) return 0;
	for(int i=last[x];i;i=pre[i]) if(rd[belong[to[i]]]==1) return 0;
	return 1; 
}
int main()
{
    int i,a,b,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&a,&b);Ins(a,b);
    }
    if(n==1){
		printf("1.000000\n");
		return 0;
	}
    for(i=1;i<=n;i++)  if(!dfn[i])  Tarjan(i);
    false_build();
    for(i=1;i<=fl;i++)  if(rd[i]==0)  ans++;
    if(ans>1) for(i=1;i<=n;i++)  if(judge(i))  {ans--;break;}
    double p=1.00-double(ans)/n;
    printf("%.6lf\n",p);
    return 0;
}
