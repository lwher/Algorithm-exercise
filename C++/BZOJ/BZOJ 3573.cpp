#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define eps 1e-10
using namespace std;
int n,w[500010],fa[500010],ans;
int sz,to[1000010],pre[1000010],last[500010];
double f[500010];
inline int read()
{
    char ch=getchar();
    while(!(ch>='0' && ch<='9')) ch=getchar();
    int x=0;
    while(ch>='0' && ch<='9') {x=x*10+(ch-'0');ch=getchar();}
    return x;
}
inline void Ins(int a,int b)
{
    sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
void dfs(int x,double now)
{
    int i,tmp=0;
    f[x]=now+log(w[x]);
    for(i=last[x];i;i=pre[i]) if(to[i]!=fa[x]) tmp++;
    for(i=last[x];i;i=pre[i])
    {
        if(to[i]==fa[x]) continue;
        double k=log(tmp);
        fa[to[i]]=x;
        dfs(to[i],now+k);
    }
}
int main()
{
    int i,a,b,t;
    n=read();
    for(i=1;i<=n;i++) w[i]=read();
    for(i=1;i<n;i++)
    {
        a=read();b=read();
        Ins(a,b);Ins(b,a);
    }
    dfs(1,0);    
    sort(f+1,f+1+n);
    t=0;
    for(i=1;i<=n;i++)
    {
        if(fabs(f[i]-f[i-1])<eps) t++;
        else {ans=max(ans,t);t=1;}
    }
    ans=max(ans,t);
    cout<<n-ans<<endl;
    system("pause");
    return 0;
}
