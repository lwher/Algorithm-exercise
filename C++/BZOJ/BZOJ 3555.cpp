#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const long long mod1=325325325253LL,mod2=303000250057LL;
int n,L,S;
char s[30010][210];
long long ha1[30010][210],ha2[30010][210],ha3[30010][210],ha4[30010][210];
long long hash1[30010],hash2[30010],hash3[30010],hash4[30010],ans;
int sz,pre[30010],sum[30010],last[10000007],stack[30010],top;
void init()
{
    int i;
    scanf("%d%d%d",&n,&L,&S);
    for(i=1;i<=n;i++)  scanf("%s",s[i]+1);
}
void hash(long long a,long long b,long long c,long long d)
{
    int i,k=((3*(25*a+3*b))%10000007+(25*(3*c+25*d))%10000007)%10000007;
    for(i=last[k];i;i=pre[i])
    if(hash1[i]==a && hash2[i]==b && hash3[i]==c && hash4[i]==d)
    {
        sum[i]++;return;
    }
    if(last[k]==0)   stack[++top]=k;
    sz++;hash1[sz]=a;hash2[sz]=b;hash3[sz]=c;hash4[sz]=d;sum[sz]=1;
    pre[sz]=last[k];last[k]=sz;
}
int get(char ch)
{
    if(ch>='0' && ch<='9')  return (ch-'0')+1;
    if(ch>='a' && ch<='z')  return (ch-'a')+11;
    if(ch>='A' && ch<='Z')  return (ch-'A')+37;
    if(ch=='_')  return 63;
    if(ch=='@')  return 64;
}
void solve()
{
    int i,j;
    for(i=1;i<=n;i++) 
    { 
       for(j=1;j<=L;j++)   
       {
            ha1[i][j]=(ha1[i][j-1]*S+get(s[i][j]))%mod1;
            ha3[i][j]=(ha3[i][j-1]*S+get(s[i][j]))%mod2;
       }
       for(j=L;j>=1;j--)   
       {
            ha2[i][j]=(ha2[i][j+1]*S+get(s[i][j]))%mod1;
            ha4[i][j]=(ha4[i][j+1]*S+get(s[i][j]))%mod2;
       }
    }
    for(j=1;j<=L;j++)
    {
        for(i=1;i<=n;i++)  hash(ha1[i][j-1],ha2[i][j+1],ha3[i][j-1],ha4[i][j+1]);
        for(i=1;i<=sz;i++)   ans+=((sum[i]-1)*sum[i])/2;
        sz=0;
        while(top>0)  {last[stack[top]]=0;top--;}
    }
}
int main()
{
    init();
    solve();
    cout<<ans<<endl;
    return 0;
}