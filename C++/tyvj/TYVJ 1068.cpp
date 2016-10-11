#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int A,B,m;
char a[200010],b[200010];
int p[200010],next[200010],sum[200010];
void getnext()
{
     int i,j,k;
     next[0]=-1;
     k=-1;j=0;
     while(j<B)
     {
        if(k==-1 || b[j]==b[k])
        {
           j++;
           k++;
           next[j]=k;
        }
        else
        k=next[k];
     }
}
void kmp()
{
     int i,j=0,k=0;
     while(j<A)
     {
        if(k==-1 || a[j]==b[k])
        {
            k++;
            p[j]=k;
            j++;
            if(k==B)
            k=next[k];
        }
        else
        k=next[k];
     }
}
int main()
{
    int i,j,k;
    cin>>A>>B>>m;
    scanf("\n%s",a);
    scanf("\n%s",b);
    getnext();
    kmp();
    for(i=0;i<=A-1;i++)
    sum[p[i]]++;
    for(i=A-1;i>=0;i--)
    sum[next[i]]+=sum[i];
    for(i=1;i<=m;i++)
    {
                     scanf("%d",&j);
                     printf("%d\n",sum[j]-sum[j+1]);
    }
    system("pause");
    return 0;
}
