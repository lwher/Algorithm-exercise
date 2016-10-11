#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int n,m,sz,top,t,ans;
int zhan[10010],to[50010],pre[50010],last[10010],low[10010],dfa[10010];
bool in[10010],v[10010];
void Ins(int a,int b)
{sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;}
void init_and_build()
{
     int i,a,b;
     scanf("%d%d",&n,&m);
     for(i=1;i<=m;i++) {scanf("%d%d",&a,&b);Ins(a,b);}
}
void tarjan(int x)
{
     int i,g;
     t++;dfa[x]=t;low[x]=t;
     top++;zhan[top]=x;in[x]=1;
     i=last[x];
     while(i>0)
     {
        g=to[i];
        if(!dfa[g])     {tarjan(g);low[x]=min(low[x],low[g]);} else   
        if(in[g])       low[x]=min(low[x],dfa[g]);
        i=pre[i];
     }
     if(low[x]==dfa[x])
     {
                       int cnt=1;
                       while(zhan[top]!=x)
                       {cnt++;in[zhan[top]]=0;top--;}
                       in[x]=0;top--;
                       if(cnt>=2)  ans++;
     }
}
int main()
{
    int i;
    init_and_build();  
    for(i=1;i<=n;i++)
    if(!dfa[i])
    tarjan(i);
    cout<<ans<<endl;
    system("pause");
    return 0;
}
