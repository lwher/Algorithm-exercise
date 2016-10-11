#include<queue>   
  
#include<cstdio>   
  
#include<vector>   
  
#include<iostream>   
  
#define NO 1   
  
#define YES 0   
  
#define maxn 31000   
  
#define cp freopen   
  
#define pb push_back   
  
#define rep(i,a,b) for (int i=a;i<=b;i++)   
  
using namespace std;   
  
int p,c,n;   
  
bool v[maxn],D[maxn];   
  
vector<int> g[maxn];   
  
void add(int x,int y){g[x].pb(y);}   
  
int main()   
  
{   
  
cin>>p>>c>>n;   
  
rep(i,1,c)   
  
{   
  
int x,y;   
  
scanf("%d %d",&x,&y);   
  
add(x,y),add(y,x);   
  
}   
  
rep(i,1,n)   
  
{   
  
int x; scanf("%d",&x);   
  
v[x]=NO;   
  
rep(i,0,int(g[x].size()-1))   
  
v[g[x][i]]=NO;   
  
}   
  
queue<int> Q;   
  
Q.push(1); int ans=1;D[1]=1;   
  
while (!Q.empty())   
  
{   
  
int h=Q.front(); Q.pop();   
  
rep(i,0,int(g[h].size()-1))   
  
{   
  
int tmp;   
  
if (D[(tmp=g[h][i])]||v[tmp]==NO) continue;   
  
ans++,D[tmp]=1,Q.push(tmp);   
  
}   
  
}   
  
cout<<p-ans<<endl;   
  
return 0;   
  
}