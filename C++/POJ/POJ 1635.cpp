#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int t;
char p[3010];
int A=2503,B=1314,C=5203,mod=1000007;
int hash(int &i)
{
    int j,sum=A,top=0;
    int q[3010];
    while(p[i]=='0')
    {
        q[++top]=hash(++i);
        i++;
    }
    if(top==0)  return sum;
    sort(q+1,q+1+top);
    sum=q[1];
    for(j=2;j<=top;j++)
    {
        sum*=B;sum^=q[j];
    }
    return (sum*C)%mod;
}
int main()
{
    int i,AA,BB;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",p);
        i=0;
        AA=hash(i);
        scanf("%s",p);
        i=0;
        BB=hash(i);
        if(AA==BB)  printf("same\n");
        else printf("different\n");
    }
    //system("pause");
    return 0;
}

