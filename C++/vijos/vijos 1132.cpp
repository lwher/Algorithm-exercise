#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
char zhong[10],hou[10];
int pm[10],n;
void build(int l,int r)
{
     if(l>r) return;
     if(l==r)
     {printf("%c",zhong[l]);return;}
     int i,k=0,w;
     for(i=l;i<=r;i++)
     if(pm[i]>k)
     {
        k=pm[i];w=i;
     }
     printf("%c",zhong[w]);
     build(l,w-1);build(w+1,r);
}
int main()
{
    int i,j;
    scanf("%s",zhong+1);
    scanf("%s",hou+1);
    n=strlen(zhong+1);
    for(i=1;i<=n;i++)  for(j=1;j<=n;j++)
    if(zhong[i]==hou[j])  {pm[i]=j;break;}
    build(1,n);
    system("pause");
    return 0;
}
