#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int n,t,stone[50010],ans;
void combine(int k)
{
    int i,j,tmp;
    tmp=stone[k-1]+stone[k];ans+=tmp;
    for(i=k;i<t;i++)  stone[i]=stone[i+1];
    t--;
    for(i=k-1;i>1 && stone[i-1]<tmp;i--)  stone[i]=stone[i-1];
    stone[i]=tmp;
    while(i>=3 && stone[i]>=stone[i-2])
    {
        int d=t-i;
        combine(i-1);
        i=t-d;
    }
}
int main()
{
    int i,x;
    scanf("%d",&n);
    t=0;ans=0;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&x);
        stone[++t]=x;
        while(t>=3 && stone[t-2]<=stone[t])  combine(t-1);
    }
    while(t>=2)  combine(t);
    printf("%d\n",ans);
    return 0;
}