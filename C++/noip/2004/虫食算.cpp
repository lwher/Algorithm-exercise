#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
int n,nmax;
int ss[30][3],num[27];
int sz,xulie[27];
bool used[27],o,given[27];
void init()
{
     int i,j;
     char ch;
     scanf("%d",&n);
     for(i=0;i<3;i++) for(j=1;j<=n;j++) {cin>>ch;ss[j][i]=ch-'A';}
     for(j=n;j>=1;j--)  for(i=0;i<3;i++)
     if(!used[ss[j][i]])
     {
         used[ss[j][i]]=1;sz++;xulie[sz]=ss[j][i];
     }  
     memset(used,0,sizeof(used));
}
bool check()
{
     int i,j,k,d,jin;
     for(i=n;i>=1;i--)
     {
        k=0;
        for(j=0;j<3;j++)  if(given[ss[i][j]])  k++;
        if(k==3)
        {
            if(i<n)
            {
                if(d==3)
                {
                    if((jin+num[ss[i][0]]+num[ss[i][1]])%n!=num[ss[i][2]])  return 0;
                    if(jin+num[ss[i][0]]+num[ss[i][1]]>=n)  jin=1; else jin=0;
                }
                else
                {
            if(!((num[ss[i][0]]+num[ss[i][1]])%n==num[ss[i][2]]) && !((num[ss[i][0]]+num[ss[i][1]]+1)%n==num[ss[i][2]]))  return 0;
                if(jin+num[ss[i][0]]+num[ss[i][1]]>=n)  jin=1; else jin=0;
                }
            }
            else
            {
                if((num[ss[i][0]]+num[ss[i][1]])%n!=num[ss[i][2]])  return 0;
                if(num[ss[i][0]]+num[ss[i][1]]>=n)  jin=1;else jin=0;
            }
        }
        else
        if(given[ss[i][0]] && given[ss[i][1]])
        {
             d=num[ss[i][0]]+num[ss[i][1]];d%=n;
             if(used[d] && used[(d+1)%n]) return 0;
             jin=0;
        }
        else jin=0;
        d=k;
     }
     return 1;
}
void dfs(int top)
{
     if(!check())  return;
     if(top==n+1)   
     {
     o=1;
     int i;
     for(i=0;i<n;i++)  cout<<num[i]<<" ";
     cout<<endl;
     return;
     }
     int i;
     for(i=n-1;i>=0;i--)
     if(!used[i])
     {
        used[i]=1;num[xulie[top]]=i;given[xulie[top]]=1;
        dfs(top+1);
        if(o)  return;
        used[i]=0;given[xulie[top]]=0;
     }
}
int main()
{
    int i;
    init();    
    dfs(1);
    system("pause");
    return 0;
}
