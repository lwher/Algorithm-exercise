#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int k[7],p[7];
long long num[6325007];
int last[6325007],pre[6325007],gs[6325007],sz;
int sum;
int aas(int kk)
{
     if(kk<0) kk=-kk;
     return kk;
}
int qpow(int a,int  b)
{
    int now=1;
    while(b>0)
    {
       if(b & 1)  now*=a;
       a=a*a;
       b=b>>1;
    }
    return now;
}
void hash(int nn)
{
     int kk=(aas(nn+1)*3+7+25*3)%6325007;
     int i=last[kk];
     while(i>0)
     {
        if(num[i]==nn)
        {gs[i]++;return;}
        i=pre[i];
     }
     sz++;
     pre[sz]=last[kk];
     num[sz]=nn;
     gs[sz]=1;
     last[kk]=sz;
}
int find(int nn)
{
    int kk=(aas(nn+1)*3+7+25*3)%6325007;
    int i=last[kk];
    while(i>0)
    {
              if(num[i]==nn) return i;
              i=pre[i];
    }
    return 0;
}
int main()
{
    int i,j,K,l;
    int now;
    cin>>n>>m;
    for(i=1;i<=n;i++)  
    cin>>k[i]>>p[i];
    if(n==1)
    {
       for(i=1;i<=m;i++)
       if(k[1]*qpow(i,p[1])==0)
       sum++;
    }
    if(n==2)
    {
       for(i=1;i<=m;i++)
       {now=k[1]*qpow(i,p[1]);hash(now);}
       for(i=1;i<=m;i++)
       {
       now=k[2]*qpow(i,p[2]);
       l=find(-now);
       sum+=gs[l];
       }
    }
    if(n==3)
    {
       for(i=1;i<=m;i++)
       for(j=1;j<=m;j++)
       {now=k[1]*qpow(i,p[1])+k[2]*qpow(j,p[2]);hash(now);}
       for(i=1;i<=m;i++)
       {
       now=k[3]*qpow(i,p[3]);
       l=find(-now);
       sum+=gs[l];
       }
    }
    if(n==4)
    {
       for(i=1;i<=m;i++)
       for(j=1;j<=m;j++)
       {now=k[1]*qpow(i,p[1])+k[2]*qpow(j,p[2]);hash(now);}
       for(i=1;i<=m;i++)
       for(j=1;j<=m;j++)
       {
       now=k[3]*qpow(i,p[3])+k[4]*qpow(j,p[4]);
       l=find(-now);
       sum+=gs[l];
       }
    }
    if(n==5)
    {
       for(i=1;i<=m;i++)
       for(j=1;j<=m;j++)
       for(K=1;K<=m;K++)
       {now=k[1]*qpow(i,p[1])+k[2]*qpow(j,p[2])+k[3]*qpow(K,p[3]);hash(now);}
       for(i=1;i<=m;i++)
       for(j=1;j<=m;j++)
       {
       now=k[5]*qpow(i,p[5])+k[4]*qpow(j,p[4]);
       l=find(-now);
       sum+=gs[l];
       }
    }
    if(n==6)
    {
       for(i=1;i<=m;i++)
       for(j=1;j<=m;j++)
       for(K=1;K<=m;K++)
       {now=k[1]*qpow(i,p[1])+k[2]*qpow(j,p[2])+k[3]*qpow(K,p[3]);hash(now);}
       for(i=1;i<=m;i++)
       for(j=1;j<=m;j++)
       for(K=1;K<=m;K++)
       {
       now=k[5]*qpow(i,p[5])+k[4]*qpow(j,p[4])+k[6]*qpow(K,p[6]);
       l=find(-now);
       sum+=gs[l];
       }
    }
    cout<<sum<<endl;
    system("pause");
    return 0;
}
