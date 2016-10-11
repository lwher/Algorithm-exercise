#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int n,num[2000010];
int getans()
{
    if(n==1) return 0;
    if(num[1]==1) return -1;
    priority_queue<int> Q;
    int now=num[1]-1,ans=1;
    for(int i=2;i<=n;i++)
    {
       if(now>0)  now--; else
       if(Q.empty() || Q.top()==1)  return -1; 
       else
       {
          now=Q.top()-2;
          Q.pop();
          ans++;
       }
       Q.push(num[i]);
    }
    return ans;
}
int main()
{
    int T,i;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)  scanf("%d",&num[i]);
        printf("%d\n",getans());
    }
    system("pause");
    return 0;
}
