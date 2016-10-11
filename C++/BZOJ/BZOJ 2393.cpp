#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cmath> 
#include<cstring> 
#include<algorithm> 
using namespace std; 
long long gcd(long long a,long long b) 
{ 
    if(b==0)  return a;  return gcd(b,a%b); 
} 
long long ans,limt,tmp; 
long long shu[5010],num[5010]; 
bool mark[5010]; 
int top,tot; 
inline bool comp(long long a,long long b) {return a<b;} 
inline bool cmp(long long a,long long b) {return a>b;} 
void dfs(long long now) 
{ 
    if(now>limt)  return; 
    if(now>0)  shu[++top]=now; 
    dfs(now*10+2); 
    dfs(now*10+9); 
} 
void solve(int step,long long now,int gs) 
{ 
    if(step==tot+1) 
    { 
        if(gs>0) 
        { 
            if(gs & 1)  ans+=limt/now; 
            else ans-=limt/now; 
        } 
        return; 
    } 
    long long t=gcd(now,num[step]); 
//  if(double(now)/t<double(limt)/num[step] || fabs(double(now)/t-double(limt)/num[step])<0.0000001)   
    if(now/t<=limt/num[step])  solve(step+1,now/t*num[step],gs+1); 
    solve(step+1,now,gs); 
} 
void calc(long long x) 
{ 
    int i,j; 
    ans=0;limt=x;top=0; 
    if(x<2) return; 
    dfs(0); 
    sort(shu+1,shu+1+top,comp); 
    memset(mark,0,sizeof(mark));     
    for(i=2;i<=top;i++)   
    for(j=1;j<i;j++)   
    if(shu[i]%shu[j]==0)   
    {mark[i]=1;break;} 
    tot=0; 
    for(i=1;i<=top;i++)  if(!mark[i])  num[++tot]=shu[i];     
    sort(num+1,num+tot+1,cmp);   
    solve(1,1,0); 
} 
int main() 
{ 
    long long a,b; 
    cin>>a>>b; 
    calc(a-1); 
    tmp=ans; 
    calc(b); 
    cout<<ans-tmp<<endl; 
    //system("pause"); 
    return 0; 
}