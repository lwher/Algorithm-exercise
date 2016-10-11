#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int map[201][201];  // 消除 
int kind[201],to[201][21][2];  //   变换  0->第一个  1->第二个
bool f[201][21][21];
int last[201][21][21];
char now[21];
int n,m,t; 
bool dfs(int ch,int l,int r)
{
     if(last[ch][l][r]==t)
     return f[ch][l][r];
     last[ch][l][r]=t;
     if(l==r)
     {
        if(map[ch][int(now[l])]==1)
        f[ch][l][r]=1;
        else
        f[ch][l][r]=0;
        return f[ch][l][r];
     }
     int i,j;
     for(i=1;i<=kind[ch];i++)
     for(j=l;j<r;j++)
     {
        if(dfs(to[ch][i][0],l,j) && dfs(to[ch][i][1],j+1,r))
        {
           f[ch][l][r]=1;
           return 1;
        }
     }
     f[ch][l][r]=0;
     return 0;
}
int main()
{
    int i,j;
    char s1,s2,s3;
    int s,ss,sss;
    scanf("%d%d",&n,&m);
    scanf("\n");
    for(i=1;i<=n;i++)
    {
       scanf("%c->%c\n",&s1,&s2);
       s=int(s1);ss=int(s2);
       map[s][ss]=1;
    }
    for(j=1;j<=m;j++)
    {
       scanf("%c->%c%c\n",&s1,&s2,&s3);
       s=int(s1);ss=int(s2);sss=int(s3);
       kind[s]++;
       to[s][kind[s]][0]=ss;
       to[s][kind[s]][1]=sss;
    }
    while(scanf("%s",now+1)!=EOF)
    {
        t++;
        if(dfs(int('S'),1,strlen(now+1)))  printf("YES\n");
        else printf("NO\n");
    }
    system("pause");
    return 0;
}
