#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int i,n,m,ID;
char S[200],T[200];
int s[200],t[200],d[200],stk[200],num;
int dfs(int tt,int now,int light){
    int tmp=0;
    if(light>ID)return 0;
    if(now>num)return 0;
    if(tt>n-m+1){
    for(int i=tt;i<=n;i++)if(s[i])light++;
    if(light>ID)return 0;
    if(now>num)return 0;
    for(int i=1;i<=now;i++)stk[i]=d[i];
    num=now; return 1;
    }
    for(int i=tt;i<=tt+m-1;i++)s[i]^=t[i-tt+1];
    d[now+1]=tt;
    tmp=dfs(tt+1,now+1,light+s[tt])||tmp;
    d[now+1]=0;
    for(int i=tt;i<=tt+m-1;i++)s[i]^=t[i-tt+1];
    tmp=dfs(tt+1,now,light+s[tt])||tmp;
    return tmp;
}
int main(){
  cin>>n>>m;
  num=777;
  scanf("%s",S+1);
  scanf("%s",T+1);
  for(i=1;i<=n;i++)s[i]=S[i]-48;
  for(i=1;i<=m;i++)t[i]=T[i]-48;
  for(ID=0;ID<=n;ID++)
    if(dfs(1,0,0))break;
  printf("%d\n",num);
  for(i=1;i<=num;i++)printf("%d\n",stk[i]);
  return 0;
 
}
