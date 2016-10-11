#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
string s[7];
int p,k,m,f[210][50];
char ch[210];
void init()
{
     int i;
     scanf("%d%d",&p,&k);
     for(i=1;i<=p*20;i++)  cin>>ch[i];
     scanf("%d",&m);
     for(i=1;i<=m;i++)  cin>>s[i];
}
bool pipei(int cw,int sw)
{
     int i,len=s[sw].size();
     for(i=0;i<len;i++)
     if(ch[cw+i]!=s[sw][i])  break;
     if(i==len)  return 1;
     else return 0;
}
int g(int a,int b)
{
    int i,j,now=0,len;
    for(i=a;i<=b;i++)
    {
         for(j=1;j<=m;j++)
         {
             len=s[j].size();
             if(i+len-1>b) continue;
             if(pipei(i,j))  {now++;break;}
         }
    }
    return now;
}
void DP()
{
     int i,j,l;
     for(j=1;j<=k;j++)
     for(i=1;i<=p*20;i++)
     for(l=j;l<i;l++)
     f[i][j]=max(f[i][j],f[l-1][j-1]+g(l,i));
     cout<<f[p*20][k]<<endl;
}
int main()
{
    init();
    DP();
    system("pause");
    return 0;
}
