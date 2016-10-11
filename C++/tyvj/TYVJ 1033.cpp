#include<iostream>
#include<stdio.h>
using namespace std;
int p;
int map[1001][3];
int answer;
void dfs(int x,int ans)
{
     if(map[x][1]==0) 
     {if(ans>answer) answer=ans;}
     else   dfs(map[x][1],ans+1);
     if(map[x][2]==0) 
     {if(ans>answer) answer=ans;}
     else   dfs(map[x][2],ans+1);
}
int main()
{
    cin>>p;
    int i,a;
    for(i=1;i<=p-1;i++)
    {
       scanf("%d",&a);
       scanf("%d%d",&map[a][1],&map[a][2]);
    }
    dfs(1,1);
    cout<<answer;
    system("pause");
    return 0;
}
