#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
long long t[300010],chen[300010],jia[300010];
int m,n;
long long p;
void updata(int l,int r,int k,int zuo,int you,bool o,int x)
{
     if(l==r)  
     {
         if(o) {t[k]+=x;t[k]%=p;return;}
         if(!o){t[k]*=x;t[k]%=p;return;}
     }
     if(l>=zuo && r<=you)
     {
         if(!o)
         {
         chen[k]*=x;chen[k]%=p;
         jia[k]*=x;jia[k]%=p;  
         t[k]*=x;t[k]%=p;
         }
         else
         {jia[k]+=x;jia[k]%=p;t[k]+=x*(r-l+1);t[k]%=p;}
         return;
     }
     int mid=(l+r)>>1;
     
             t[k<<1]=(t[k<<1]*chen[k]+jia[k]*(mid-l+1))%p;
             chen[k<<1]*=chen[k];chen[k<<1]%=p;
             jia[k<<1]=(jia[k<<1]*chen[k]+jia[k])%p;
             t[k<<1|1]=(t[k<<1|1]*chen[k]+jia[k]*(r-mid))%p;
             chen[k<<1|1]*=chen[k];chen[k<<1|1]%=p;
             jia[k<<1|1]=(jia[k<<1|1]*chen[k]+jia[k])%p;
             chen[k]=1;jia[k]=0;
    
     if(zuo<=mid) updata(l,mid,k<<1,zuo,you,o,x);
     if(you>mid)  updata(mid+1,r,k<<1|1,zuo,you,o,x);
     t[k]=(t[k<<1]+t[k<<1|1])%p;
}
long long ask(int l,int r,int k,int zuo,int you)
{
     if(l>you || r<zuo)  return 0;
     if(l==r)  return t[k];
     if(l>=zuo && r<=you)  return t[k];
     int mid=(l+r)>>1;
    
             t[k<<1]=(t[k<<1]*chen[k]+jia[k]*(mid-l+1))%p;
             chen[k<<1]*=chen[k];chen[k<<1]%=p;
             jia[k<<1]=(jia[k<<1]*chen[k]+jia[k])%p;
             t[k<<1|1]=(t[k<<1|1]*chen[k]+jia[k]*(r-mid))%p;
             chen[k<<1|1]*=chen[k];chen[k<<1|1]%=p;
             jia[k<<1|1]=(jia[k<<1|1]*chen[k]+jia[k])%p;
             chen[k]=1;jia[k]=0;
    
     return (ask(l,mid,k<<1,zuo,you)+ask(mid+1,r,k<<1|1,zuo,you))%p;
    
}
int main()
{
    int i,j;
    long long num;
    int a,b,c;
    for(i=1;i<=300009;i++)
    chen[i]=1;
    scanf("%d%lld",&n,&p);
    for(i=1;i<=n;i++)
    {
           scanf("%lld",&num);
           updata(1,n,1,i,i,1,num);          
    }
    scanf("%d",&m);
    for(i=1;i<=m;i++)
    {
                     scanf("%d%d%d",&j,&a,&b);
                     if(j==1) {scanf("%d",&c);updata(1,n,1,a,b,0,c);}
                     if(j==2) {scanf("%d",&c);updata(1,n,1,a,b,1,c);}
                     if(j==3)
                     {num=ask(1,n,1,a,b);printf("%lld\n",num);}
    }
    system("pause");
    return 0;
}
