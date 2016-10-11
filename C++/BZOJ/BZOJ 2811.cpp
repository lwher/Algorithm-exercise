#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 100010
struct segment
{
    int l,r;
}seg0[N],seg1[N],tmp[N];
segment Seg(int x,int y)
{
    segment a;a.l = x,a.r = y;return a;
}
int cnt1,cnt2,n,m,k,cnt,x,y,z,tot;
int la[N],can[N],sum[N],ans[N],f[N];
int cmp(segment a,segment b)
{
   if (a.l!=b.l) return a.l < b.l;
   return a.r<b.r;
}
int main(){
   scanf("%d%d%d",&n,&k,&m);
   for(int i=1;i<=m;i++)
   {
       scanf("%d%d%d",&x,&y,&z);
       if(z==0)  seg0[++cnt1].l=x-1,seg0[cnt1].r=y;
       else  seg1[++cnt2].l=x-1,seg1[cnt2].r=y;
   }
   sort(seg0+1,seg0+1+cnt1,cmp);
   int last=0;
   for(int i=1;i<=cnt1;i++)
   {
       if(seg0[i].r>last)
       {
           for(int j=max(seg0[i].l,last);j<seg0[i].r;j++) can[j]=1;
           last=seg0[i].r;
       }
   }
   sum[0]=0;
   for(int i=0;i<n;i++)
       if(!can[i]) sum[i+1]=sum[i]+1;
       else sum[i+1]=sum[i];
   last=-1;
   for(int i=0;i<n;i++)
   {
       if (!can[i]) last=i;
       la[i]=last;
   }
   if(sum[n]==k)
   {
       for(int i=0;i<n;i++) if (!can[i]) printf("%d\n",i+1);
       return 0;
   }
   sort(seg1+1,seg1+1+cnt2,cmp);
   last=n+1;
   for(int i=cnt2;i;i--)
       if(seg1[i].r<last)
       {
           tmp[++cnt]=seg1[i];
           last=seg1[i].r;
       } 
   for(int i=1;i<=cnt;i++)
   {
       if(sum[tmp[i].r]-sum[tmp[i].l]==1)
       {
           int x=la[tmp[i].r-1];
           if(!can[x]) ans[++tot]=x,can[x]=1;
       }
   }
   sum[0]=0;
   for(int i=0;i<n;i++)
       if(!can[i]) sum[i+1]=sum[i]+1;
       else sum[i+1]=sum[i];
   last=-1;
   for(int i=0;i<n;i++)
   {
       if(!can[i]) last=i;
       la[i]=last;
   }
   sort(ans+1,ans+1+tot);
   cnt2=0;
   for(int i=cnt;i;i--)
   {
       int a=lower_bound(ans+1,ans+1+tot,tmp[i].l)-ans;
       int b=lower_bound(ans+1,ans+1+tot,tmp[i].r)-ans;
       if(a==b) seg1[++cnt2]=tmp[i];
   }
   for(int i=cnt2;i;i--)
   {
       int x=la[seg1[i].r-1];
       int t=lower_bound(seg1+1,seg1+cnt2+1,Seg(x+1,0),cmp)-seg1;
       f[i]=f[t]+1;
   }
   k-=tot;
   last=-1;
   for(int i=1,c=0;i<=cnt2;i++)
   {
       if(seg1[i].l>last)
       {
           int x=la[seg1[i].r-1],y=la[x-1];
           int t=lower_bound(seg1+1,seg1+cnt2+1,Seg(y+1,0),cmp)-seg1;
           if(c+1+f[t]>k) ans[++tot]=x;
           last=x;c++;
       }
   }
   sort(ans+1,ans+1+tot);
   if(tot==0) puts("-1");
   else
   {
       for(int i=1;i<=tot;i++) printf("%d\n",ans[i]+1);
   }
  // system("pause");
   return 0;
}