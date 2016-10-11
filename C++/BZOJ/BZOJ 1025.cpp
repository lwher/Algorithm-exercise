#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,sz;
int prime[200];
unsigned long long f[200][1010];
bool ok[1010],d[200][1010];
void getprime()
{
     int i,j;
     for(i=2;i<=n;i++)
     {
         if(!ok[i])  {sz++;prime[sz]=i;}
         for(j=1;j<=sz;j++)
         {
             if(i*prime[j]>n)  break;
             ok[i*prime[j]]=1;
             if(i%prime[j]==0) break;
         }
     }
}
unsigned long long dfs(int k,int left)
{
     if(d[k][left])  return f[k][left]; d[k][left]=1;
     if(!k)  return f[k][left]=1;
     int tmp=prime[k];
     f[k][left]=dfs(k-1,left);
     while(tmp<=left)
     {
         f[k][left]+=dfs(k-1,left-tmp); tmp*=prime[k];
     }
     return f[k][left];
}
int main()
{
    scanf("%d",&n);
    getprime();
    cout<<dfs(sz,n)<<endl;
    system("pause");
    return 0;
}
