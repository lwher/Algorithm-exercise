#include<iostream> 
#include<cmath> 
using namespace std; 
long long ans,n,maxt; 
int tot,pri[100000]; 
bool flag[100000]; 
void dfs(long long now,long long num,long long cnt,long long maxi)
{ 
    if(cnt>maxt||(cnt==maxt&&num<ans))
    { 
        ans=num; 
        maxt=cnt; 
    } 
    if(now>=tot||num*pri[now]>n)return; 
    for(long long i=1,p=1;i<=maxi&&p*pri[now]*num<=n;i++,p*=pri[now]) 
    dfs(now+1,num*p*pri[now],cnt*(i+1),maxi); 
} 
int main()
{ 
    cin>>n; 
    for(long long i=2,maxi=(long long)sqrt(n+1);i<=maxi;){ 
    pri[tot++]=i; 
    for(long long j=i+i;j<=maxi;j+=i)flag[j]=1; 
    while(flag[++i]); 
    } 
    dfs(0,1,1,1000000); 
    cout<<ans<<endl; 
return 0; 
}
