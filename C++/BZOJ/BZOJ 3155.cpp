#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int n,m,num[100010];
long long tsum[2][100010];// 0: sum(num[i])  1: sum((i-1)*num[i])
void add(int x,long long y,int top)
{
     for(int i=x;i<=n;i+=(i & (-i))) tsum[top][i]+=y;
}
long long ask(int x,int top)
{
     long long now=0;
     for(int i=x;i;i-=(i & (-i))) now+=tsum[top][i];
     return now;
}
int main()
{
    int i,a,b;
    char s[10];
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) 
    {
        scanf("%d",&num[i]);
        add(i,num[i],0);add(i,(long long)(num[i])*(i-1),1);
    }
    for(i=1;i<=m;i++)
    {
        scanf("%s",s);
        if(s[0]=='Q')  
        {
            scanf("%d",&a);
            printf("%lld\n",ask(a,0)*a-ask(a,1));
        }         
        else
        {
            scanf("%d%d",&a,&b);
            add(a,b-num[a],0);add(a,(long long)(b-num[a])*(a-1),1);
            num[a]=b;
        }
    }
    system("pause");
    return 0;
}
