#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
#define MAXN 110
int n,k,na;
struct saver 
{
    int v[MAXN];
}r[MAXN];
bool cmp(saver x,saver y) 
{
    for(int i=0;i++<na;) 
    {
        if(x.v[i]>y.v[i]) return false;
        if(x.v[i]<y.v[i]) return true;
    }
    return true;
}
struct Saver 
{
    string s;
    int t;
}d[MAXN];
bool Cmp(Saver x,Saver y) 
{
    return x.s<y.s;
}
string adj[MAXN][MAXN],b[MAXN][MAXN];
int nd[MAXN],s[MAXN],m[MAXN],ans[MAXN],delta=0;
int main() 
{
    cin>>n>>k;
    for(int i=0;i++<n;) 
    {
        string s;
        for(cin>>s;s!="no";cin>>s) ;
        for(na=0,cin>>s;s!="cow.";cin>>s) adj[i][++na]=s;
    }
    for(int i=0;i++<na;) 
    {
        for(int j=0;j++<n;) d[j].s=adj[j][i],d[j].t=j;
        sort(d+1,d+n+1,Cmp);
        nd[i]=0;
        d[0].s="&";
        for(int j=0;j++<n;) 
        {
            if(d[j].s!=d[j-1].s) b[i][++nd[i]]=d[j].s;  
            r[d[j].t].v[i]=nd[i];
        }
    }
    sort(r+1,r+n+1,cmp);
    m[na]=1;
    for(int i=na-1;i;i--) m[i]=m[i+1]*nd[i+1];
    for(int i=0;i++<na;) r[0].v[i]=1;
    r[0].v[na]=0;
    for(int i=0;i++<n;) 
    {
        bool flag=true;
        for(int j=0;j++<na;) if(r[i].v[j]!=r[i-1].v[j]) flag=false;
        if(flag) {s[i]=s[i-1];continue;}
        s[i]=s[i-1]-1;
        for(int j=0;j++<na;) s[i]+=m[j]*(r[i].v[j]-r[i-1].v[j]);
    }
    s[n+1]=0x7fffffff;
    for(int i=0;i<=n;i++) if(s[i]<k&&k<=s[i+1]) 
    {
        for(int j=0;j++<na;) ans[j]=r[i].v[j];
        delta=k-s[i];
        for(int i=0;i++<na;) 
        {
            if(delta>=m[i]) {ans[i]+=delta/m[i];delta%=m[i];}
        } 
    }
    m[0]=0x7fffffff;
    for(int i=na;i;i--) 
    {
        if(ans[i]>nd[i]) 
        {
            if (ans[i]%nd[i]) {ans[i-1]+=ans[i]/nd[i];ans[i]%=nd[i];} 
            else {ans[i-1]+=(ans[i]/nd[i]-1);ans[i]=nd[i];}
        }
    }
    for(int i=0;i++<na-1;) cout<<b[i][ans[i]]<<" ";
    cout<<b[na][ans[na]]<<endl;
   // system("pause");
    return 0;
}