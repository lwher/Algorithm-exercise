#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[19];
int b[19];
int s[19][19];
void fun()
{
    int i,j;
    memset(s,0,sizeof(s));
    for(i=1;i<=10;i++)  {s[i][i]=1;s[i][1]=1;}
    for(i=3;i<=10;i++)  for(j=2;j<i;j++)  s[i][j]=s[i-1][j]+s[i-1][j-1];
}
int main()
{
    int n,m;
    fun();
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int i;
        for(i=1;i<=n;i++)  a[i]=i;
        do
        {
            int sum=0;
            for(i=1;i<=n;i++)   sum+=a[i]*s[n][i];
            if(sum==m)  break;
        }while(next_permutation(&a[1],&a[n+1]));
        printf("%d",a[1]);
        for(i=2;i<=n;i++)   printf(" %d",a[i]);
        printf("\n");
    }
    system("pause");
    return 0;
}
