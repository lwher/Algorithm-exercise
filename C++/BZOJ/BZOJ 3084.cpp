#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int n;
unsigned long long bit[200010],base=10007,h[200010];
char s[200010];
unsigned long long query(int l,int r)
{
    if(l>r)  return 0;
    return h[r]-h[l-1]*bit[r-l+1];  
}
bool check1(int len)
{
     bool del=0;int a,b,l,r,mid;
     for(a=len+1;a<=n;a+=len)
     {
         b=a+len-1;
         if(b<n)
         {
              if(h[len]!=query(a,b))
              {
                   if(del)  return 0;
                   l=0;r=len;del=1;
                   while(l+1<r)
                   {
                       mid=(l+r)>>1;
                       if(h[mid]==query(a,a+mid-1))  l=mid;
                       else r=mid;
                   }
                   if(query(a,a+l-1)*bit[len-l]+query(a+l+1,a+len)!=h[len]) return 0;
                   a++;
              }
         }
         else
         {
             if(h[n-a+1]!=query(a,n))
             {
                 if(del)  return 0;
                 del=1;l=0;r=n-a+1;
                 while(l+1<r)
                 {
                     mid=(l+r)>>1;
                     if(h[mid]==query(a,a+mid-1))  l=mid;
                     else r=mid;
                 }
                 if(query(a,a+l-1)*bit[n-a-l]+query(a+l+1,n)!=h[n-a]) return 0;
                 a++;
             }
         }
     }
     return 1;
}
bool check2(int len)
{
     int a,b,l,r,mid;
     if(len*2<=n-1)
     {
         unsigned long long preh=query(len+2,len+len+1);
         l=0;r=len+1;
         while(l+1<r)
         {
             mid=(l+r)>>1;
             if(h[mid]==query(len+2,len+mid+1))  l=mid;
             else r=mid; 
         }
        if(h[l]*bit[len-l]+query(l+2,len+1)!=preh) return 0;
        for(a=len+len+2;a<=n;a+=len)
        {
            int b=a+len-1;
            if(b<=n)
            {
                if(query(a,b)!=preh) return 0;
            }
            else
            {
                if(query(a,n)!=query(len+2,len+2+n-a)) return 0;
            }
        }
    }
    else
    {
        int l=0,r=n-len;
        while (l+1<r)
        {
            int mid=(l+r)>>1;
            if (h[mid]==query(len+2,len+mid+1)) l=mid;
            else r=mid;
        }
        if (h[l]*bit[n-l-len-1]+query(l+2,n-len)!=query(len+2,n)) return 0;
    }
    return 1;
}
int main()
{
    int i,T,ans;
    bit[0]=1;
    for(i=1;i<=200000;i++)  bit[i]=bit[i-1]*base;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%s",&n,s+1);
        for(i=1;i<=n;i++)  h[i]=h[i-1]*base+int(s[i]);
        for(ans=1;ans<n;ans++)   if(check1(ans) || check2(ans))  break;
        printf("%d\n",ans);
    }
    //system("pause");
    return 0;
}
