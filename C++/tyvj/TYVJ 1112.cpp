#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
using namespace std;
int n,k;
bool mark[300];
int map[300][300],rd[300];
int dui[1000],tou=1,wei=0;
int main()
{
    cin>>n>>k;
    int i,a;
    for(i=1;i<=n;i++)
    {
      while(scanf("%d",&a))
      {
        if(a==0)  break;
        rd[a]++;
        map[i][0]++;
        map[i][map[i][0]]=a;
      }
    }
    for(i=1;i<=n;i++)
    {
    if(rd[i]<k) 
    {wei++;dui[wei]=i;mark[i]=1;}
    }
    int now;
    while(tou<=wei)
    {
       now=dui[tou];
       for(i=1;i<=map[now][0];i++)
       {
         rd[map[now][i]]--;
         if(rd[map[now][i]]<k && !mark[map[now][i]])
         {mark[map[now][i]]=1;wei++;
         dui[wei]=map[now][i];
         }
       }
       tou++;
    }
    cout<<n-wei<<endl;
    system("pause");
    return 0;
}
