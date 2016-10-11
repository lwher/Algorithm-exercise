#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define mod 1000000007
using namespace std;
int ln,m,sz,son[1510][10],fail[1510],dui[1510],ans,to[1510][10],dp[1210][1510],f[1210][1510][2];
char n[1210];
bool danger[1510];
void Ins(char s[1510])
{
     int i,k,len=strlen(s+1),now=0;
     for(i=1;i<=len;i++)
     {
        k=s[i]-'0';
        if(!son[now][k]) son[now][k]=++sz;
        now=son[now][k];
     }
     danger[now]=1;
}
void getfail()
{
     int now,i,tou=1,wei=1,k;
     dui[1]=0;fail[0]=-1;
     while(tou<=wei)
     {
         now=dui[tou];tou++;
         for(i=0;i<10;i++)
         if(son[now][i])
         {
             dui[++wei]=son[now][i];
             for(k=fail[now];k!=-1 && !son[k][i];k=fail[k]);
             if(k==-1) fail[son[now][i]]=0; else fail[son[now][i]]=son[k][i];   
             if(danger[fail[son[now][i]]]) danger[son[now][i]]=1;
         }
     }
}
void init()
{
     int i;char s[1510];
     scanf("%s%d",n+1,&m);
     for(i=1;i<=m;i++)
     {
        scanf("%s",s+1);
        Ins(s);
     }
     ln=strlen(n+1);
}
void solve()
{
     int i,j,k,z;
     getfail();
     for(i=0;i<=sz;i++)  for(j=0;j<10;j++)
     {
        for(k=i;k!=-1 && !son[k][j];k=fail[k]);
        if(k==-1) to[i][j]=0; else to[i][j]=son[k][j];
     }
     for(i=1;i<ln;i++)
     {
        for(j=1;j<10;j++)  if(!danger[to[0][j]])  dp[i][to[0][j]]=(dp[i][to[0][j]]+1)%mod;
        if(i==ln-1) break;
        for(j=0;j<=sz;j++)  if(dp[i][j])
        {
           for(k=0;k<10;k++)  if(!danger[to[j][k]])  dp[i+1][to[j][k]]=(dp[i+1][to[j][k]]+dp[i][j])%mod;
        }
     }
     for(i=0;i<=sz;i++)  ans=(ans+dp[ln-1][i])%mod;
     z=n[1]-'0';
     for(i=1;i<z;i++)  if(!danger[to[0][i]])  f[1][to[0][i]][0]++;
     if(!danger[to[0][z]])  f[1][to[0][z]][1]++;
     for(i=1;i<ln;i++)
     {
        for(j=0;j<=sz;j++)
        {
            if(f[i][j][0])
            {
                for(k=0;k<10;k++)  if(!danger[to[j][k]])  f[i+1][to[j][k]][0]=(f[i+1][to[j][k]][0]+f[i][j][0])%mod;
            }
            if(f[i][j][1])
            {
                z=n[i+1]-'0';
                for(k=0;k<z;k++)  if(!danger[to[j][k]])  f[i+1][to[j][k]][0]=(f[i+1][to[j][k]][0]+f[i][j][1])%mod;
                if(!danger[to[j][z]])  f[i+1][to[j][z]][1]=(f[i+1][to[j][z]][1]+f[i][j][1])%mod;
            }
        }
     }
     for(i=0;i<=sz;i++)  
     {
        ans=(ans+f[ln][i][0])%mod;
        ans=(ans+f[ln][i][1])%mod;
     }
     printf("%d\n",ans);
}
int main()
{
    init();
    solve();
    system("pause");
    return 0;
}
