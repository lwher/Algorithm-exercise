#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int a[501],b[501],f[501],A,B;
int main()
{
    int i,j,T,maxx,tt;
    scanf("%d",&T);
    while(T--)
    {
        memset(f,0,sizeof(f));
        scanf("%d",&A);  for(i=1;i<=A;i++)  scanf("%d",&a[i]);
        scanf("%d",&B);  for(i=1;i<=B;i++)  scanf("%d",&b[i]);
        for(i=1;i<=A;i++)
        {
            maxx=0;
            for(j=1;j<=B;j++)
            {
                tt=f[j];
                if(a[i]==b[j])  f[j]=max(f[j],maxx+1);
                if(b[j]<a[i] && tt>maxx)  maxx=tt;
            }
        }
        maxx=0;
        for(i=1;i<=B;i++)  if(f[i]>maxx)  maxx=f[i];
        printf("%d\n",maxx);
    }
    system("pause");
    return 0;
}
