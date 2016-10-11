#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
char a[5010],b[5010];
int f[5010],sum[5010];
void add(int &t,int p)
{
     t+=p; if(t>=100000000) t-=100000000;
}
int main()
{
    int i,j,s,maxx,tf,ts;
    scanf("%s%s",a+1,b+1);        
    for(i=1;a[i]!='.';i++)
    {
       maxx=0;s=1;
       for(j=1;b[j]!='.';j++)
       {
           tf=f[j];ts=sum[j];
           if(a[i]==b[j])
           {
               if(maxx+1>f[j])   {f[j]=maxx+1;sum[j]=s;}
               else if(maxx+1==f[j])  add(sum[j],s);
           }
           if(maxx<tf)  {maxx=tf;s=ts;}
           else if(maxx==tf)  add(s,ts);
           
       }
    }
    maxx=0;s=0;
    for(i=1;b[i]!='.';i++)
    {
        if(maxx<f[i])  {maxx=f[i];s=sum[i];}
        else if(maxx==f[i])  add(s,sum[i]);
    }
    printf("%d\n%d\n",maxx,s);
    system("pause");
    return 0;
}
