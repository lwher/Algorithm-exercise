#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int type[2]={1,-1};
int n,m,p,digit[210][210],add[210][210];
int C[210][210],L[210][210],R[210][210];
void init()
{
    int i,j;
    scanf("%d%d%d",&n,&m,&p);
    for(i=1;i<=n;i++)  for(j=1;j<=m;j++)
    {
        scanf("%d",&digit[i][j]);
        L[i][j]=0;R[i][j]=p-1;C[i][j]=digit[i][j]-C[i-1][j]-C[i][j-1]-C[i-1][j-1];
    }
}
inline void swap(int &a,int &b)
{
    int t=a;a=b;b=t;
}
bool dfs(int j)
{
    if(j>m) return 1;
    for(add[1][j]=0;add[1][j]<p;add[1][j]++)
    {
        bool flag=1;
        for(int i=2;i<=n && flag;i++)
        {
            int tmp1=(C[i][j]+add[1][1]*type[(i+j+1)&1]+type[(i-1)&1]*add[1][j]-0)*type[j&1];
            int tmp2=(C[i][j]+add[1][1]*type[(i+j+1)&1]+type[(i-1)&1]*add[1][j]-p+1)*type[j&1];
            if(tmp2>tmp1)  swap(tmp1,tmp2);
            L[i][j]=max(L[i][j-1],tmp2);R[i][j]=min(R[i][j-1],tmp1);
            if(L[i][j]>R[i][j])  flag=0;
        }
        if(flag && dfs(j+1))  return 1;
    }
    return 0;
}
void print()
{
    for(add[1][1]=0;!dfs(2);add[1][1]++);
    for(int i=2;i<=n;i++)  add[i][1]=L[i][m];
    for(int i=1;i<=n;i++)  for(int j=1;j<=m;j++)
     printf("%d%c",C[i][j]+type[(i+j+1)&1]*add[1][1]+type[(i-1)&1]*add[1][j]+type[(j-1)&1]*add[i][1],j<m?' ':'\n');
}
int main()
{
    init();
    print();
    return 0;
}