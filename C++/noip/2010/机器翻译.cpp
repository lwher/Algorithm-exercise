#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dui[100010];
int n,m,ans,tou=1,wei=0;
int num[1010];
bool mark[1010];
int main()
{
    int i;
    scanf("%d%d",&m,&n);
    for(i=1;i<=n;i++)  scanf("%d",&num[i]);
    if(n>0)  {ans++;wei++;dui[wei]=num[1];mark[num[1]]=1;}
    for(i=2;i<=n;i++)
    {
        if(!mark[num[i]])
        {
             ans++;
             mark[num[i]]=1;
             if(wei-tou+1<m)  
             {wei++;dui[wei]=num[i];}
             else
             {mark[dui[tou]]=0;tou++;wei++;dui[wei]=num[i];}
        }
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}
