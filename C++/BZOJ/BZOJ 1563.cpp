#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
struct sth
{
    int l,r,d; 
}dui[100010];
int n,L,p,sum[100010];
char s[50];
long double f[100010];
long double qpow(long double a,int b)
{
     long double res=1;
     while(b>0)
     {
         if(b & 1)  res*=a;
         b=b>>1;
         a*=a;
     }
     return res;
}
long double calc(int j,int i)
{
     long double tmp=sum[i]-sum[j]+i-j-1-L;
     if(tmp<0)  tmp=-tmp;
     return f[j]+qpow(tmp,p);
}
int main()
{
    int i,t,len,l,r,mid;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&L,&p);
        for(i=1;i<=n;i++)
        {
            scanf("%s",s+1);
            len=strlen(s+1);
            sum[i]=sum[i-1]+len;
        }        
        int tou=1,wei=1;
        dui[1].l=1;dui[1].r=n;dui[1].d=0;
        for(i=1;i<=n;i++)
        {
            f[i]=calc(dui[tou].d,i);
            dui[tou].l++;
            if(dui[tou].l>dui[tou].r) tou++;
            while(calc(dui[wei].d,dui[wei].l)>calc(i,dui[wei].l))  wei--;
            if(tou<=wei)
            {
                l=dui[wei].l;r=dui[wei].r+1;
                while(l+1<r)
                {
                    mid=(l+r)>>1;
                    if(calc(dui[wei].d,mid)<calc(i,mid))  l=mid;
                    else r=mid;
                }
                if(r!=n+1)
                {
                    dui[wei].r=l;
                    dui[++wei].l=r;dui[wei].r=n;dui[wei].d=i;
                }
            }
            else
            {
                 dui[++wei].l=i+1;dui[wei].r=n;dui[wei].d=i;
            }  
        }        
        if(f[n]>1e18)  printf("Too hard to arrange\n");
        else  printf("%lld\n",(long long)(f[n]));
        for(i=1;i<=20;i++) putchar('-');
        printf("\n");
    }
    return 0;
}