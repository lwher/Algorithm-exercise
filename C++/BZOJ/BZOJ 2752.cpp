#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
long long sumi[500010],sum[500010],sumii[500010],si[100010],sii[100010],add[500010];
inline void downput(int x,int l,int r)
{
     int y=x<<1,z=x<<1|1,mid=(l+r)>>1;
     add[y]+=add[x];add[z]+=add[x];
     sum[y]+=(mid-l+1)*add[x];sum[z]+=(r-mid)*add[x];
     sumi[y]+=(si[mid]-si[l-1])*add[x];sumi[z]+=(si[r]-si[mid])*add[x];
     sumii[y]+=(sii[mid]-sii[l-1])*add[x];sumii[z]+=(sii[r]-sii[mid])*add[x];
     add[x]=0;
}
void updata(int k,int l,int r,int zuo,int you,int v)
{
     if(l>=zuo && r<=you)
     {
         add[k]+=v;
         sum[k]+=(r-l+1)*v;
         sumi[k]+=(si[r]-si[l-1])*v;
         sumii[k]+=(sii[r]-sii[l-1])*v;
         return;
     }
     if(add[k]!=0) downput(k,l,r);
     int mid=(l+r)>>1;
     if(zuo<=mid) updata(k<<1,l,mid,zuo,you,v);
     if(you>mid) updata(k<<1|1,mid+1,r,zuo,you,v);
     sum[k]=sum[k<<1]+sum[k<<1|1];
     sumi[k]=sumi[k<<1]+sumi[k<<1|1];
     sumii[k]=sumii[k<<1]+sumii[k<<1|1];
}
long long ask(int k,int l,int r,int zuo,int you)
{
     if(l>you || r<zuo) return 0;
     if(l>=zuo && r<=you) return sumi[k]*(you+zuo-1)+sum[k]*you-sum[k]*zuo*you-sumii[k];
     if(add[k]!=0) downput(k,l,r);
     int mid=(l+r)>>1;
     return ask(k<<1,l,mid,zuo,you)+ask(k<<1|1,mid+1,r,zuo,you);
}
long long gcd(long long a,long long b)
{
     if(b==0) return a;
     return gcd(b,a%b);
}
int main()
{
    int i,l,r,v;char s[3];
    long long fz,fm,d;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) si[i]=sii[i]=i;
    for(i=1;i<=n;i++) si[i]=si[i-1]+si[i],sii[i]=sii[i-1]+sii[i]*sii[i];       
    for(i=1;i<=m;i++)
    {
        scanf("%s%d%d",s,&l,&r);
        if(s[0]=='C') 
        {
           scanf("%d",&v);
           updata(1,1,n,l,r-1,v);
        }
        else
        {
            fz=ask(1,1,n,l,r);
            fm=(long long)(r-l)*(r-l+1)/2;
            d=gcd(fz,fm);
            fz/=d;fm/=d;
            printf("%lld/%lld\n",fz,fm);
        }
    }
    system("pause");
    return 0;
}
